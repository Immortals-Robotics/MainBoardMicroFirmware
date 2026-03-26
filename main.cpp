#include <stdio.h>
#include <string.h>
#include <memory>

#include <pico/stdlib.h>
#include <pico/multicore.h>

#include "ball-detector.h"
#include "mikona.h"
#include "ioex.h"
#include "power_monitor.h"
#include "protocol.h"

struct Context
{
    std::unique_ptr<Ioex>         ioex;
    std::unique_ptr<Mikona>       mikona;
    std::unique_ptr<PowerMonitor> powerMonitor;
    std::unique_ptr<BallDetector> ballDetector;
    std::unique_ptr<Protocol>     protocol;

    bool faultMicro     = false;
    bool faultMainBoard = false;
} g_context;

void core0_entry()
{
    while(true)
    {
        g_context.ioex->read();

        // Consume command
        MicroCommand command = {};
        if (g_context.protocol->consume_rx_buffer(&command))
        {
            const bool charge    = command.flags & (1 << 0);
            const bool discharge = command.flags & (1 << 1);
            const bool wifi_connected = command.flags & (1 << 2);
            const bool wifi_activity  = command.flags & (1 << 3);
            const bool fault     = command.flags & (1 << 4);
            const bool buzzer    = command.flags & (1 << 5);

            g_context.mikona->setCharge(charge);
            g_context.mikona->setDischarge(discharge);

            g_context.mikona->kickA(command.kick_a);
            g_context.mikona->kickB(command.kick_b);

            if (wifi_activity)
                g_context.ioex->setLedWifi(Ioex::LedWifi::Activity);
            else if (wifi_connected)
                g_context.ioex->setLedWifi(Ioex::LedWifi::Connected);
            else
                g_context.ioex->setLedWifi(Ioex::LedWifi::None);

            g_context.faultMainBoard = fault;
            g_context.ioex->setLedFault(g_context.faultMainBoard || g_context.faultMicro);

            // TODO: improve buzzer
            //gpio_put(MAIN_BOARD_BUZZER_PIN, buzzer);
        }

        // Fill status
        {
            MicroStatus status = {};

            status.robot_id = g_context.ioex->getId();

            status.flags = 0;
            if (g_context.ioex->getDip(1)) status.flags |= (1 << 0);
            if (g_context.ioex->getDip(2)) status.flags |= (1 << 1);
            if (g_context.ioex->getDip(3)) status.flags |= (1 << 2);
            if (g_context.ioex->getDip(4)) status.flags |= (1 << 3);
            if (g_context.ioex->getButton()) status.flags |= (1 << 4);
            if (g_context.ballDetector->ball_detected()) status.flags |= (1 << 5);

            const Mikona::Status mikonaStatus = g_context.mikona->getStatus();
            status.mikona_flags = 0;
            if (g_context.mikona->isConnected()) status.mikona_flags |= (1 << 0);
            if (mikonaStatus.charge)             status.mikona_flags |= (1 << 1);
            if (mikonaStatus.discharge)          status.mikona_flags |= (1 << 2);
            if (mikonaStatus.done)               status.mikona_flags |= (1 << 3);
            if (mikonaStatus.fault)              status.mikona_flags |= (1 << 4);
            status.mikona_v_out = g_context.mikona->getVoltage();

            status.motor_flags = 0;
            status.motor_flags |= (gpio_get(MAIN_BOARD_M1_CTRL_STATUS_PIN) ? (1 << 0) : 0);
            status.motor_flags |= (gpio_get(MAIN_BOARD_M1_DRV_FAULT_PIN)  ? (1 << 1) : 0);
            status.motor_flags |= (gpio_get(MAIN_BOARD_M2_CTRL_STATUS_PIN) ? (1 << 2) : 0);
            status.motor_flags |= (gpio_get(MAIN_BOARD_M2_DRV_FAULT_PIN)  ? (1 << 3) : 0);
            status.motor_flags |= (gpio_get(MAIN_BOARD_M3_CTRL_STATUS_PIN) ? (1 << 4) : 0);
            status.motor_flags |= (gpio_get(MAIN_BOARD_M3_DRV_FAULT_PIN)  ? (1 << 5) : 0);
            status.motor_flags |= (gpio_get(MAIN_BOARD_M4_CTRL_STATUS_PIN) ? (1 << 6) : 0);
            status.motor_flags |= (gpio_get(MAIN_BOARD_M4_DRV_FAULT_PIN)  ? (1 << 7) : 0);
            status.motor_flags |= (gpio_get(MAIN_BOARD_MD_CTRL_STATUS_PIN) ? (1 << 8) : 0);
            status.motor_flags |= (gpio_get(MAIN_BOARD_MD_DRV_FAULT_PIN)  ? (1 << 9) : 0);

            g_context.powerMonitor->refresh();
            g_context.powerMonitor->accumulateEnergy(PowerMonitor::Rail::V5);
            g_context.powerMonitor->accumulateEnergy(PowerMonitor::Rail::V24);
            status.power_5v_voltage  = g_context.powerMonitor->getVoltage(PowerMonitor::Rail::V5);
            status.power_5v_current  = g_context.powerMonitor->getCurrent(PowerMonitor::Rail::V5);

            status.power_24v_voltage = g_context.powerMonitor->getVoltage(PowerMonitor::Rail::V24);
            status.power_24v_current = g_context.powerMonitor->getCurrent(PowerMonitor::Rail::V24);

            status.power_5v_energy  = g_context.powerMonitor->getTotalEnergy(PowerMonitor::Rail::V5);
            status.power_24v_energy = g_context.powerMonitor->getTotalEnergy(PowerMonitor::Rail::V24);

            g_context.faultMicro =
                (status.mikona_flags & (1 << 4)) ||
                (status.motor_flags & (1 << 1)) ||
                (status.motor_flags & (1 << 3)) ||
                (status.motor_flags & (1 << 5)) ||
                (status.motor_flags & (1 << 7)) ||
                (status.motor_flags & (1 << 9));
            g_context.ioex->setLedFault(g_context.faultMainBoard || g_context.faultMicro);

            g_context.protocol->fill_tx_buffer(status);
        }

        {
            g_context.ioex->setLedIr(g_context.ballDetector->ball_detected());
            g_context.ioex->setLedFault(g_context.faultMainBoard || g_context.faultMicro || g_context.ioex->getButton());

            if (g_context.mikona->getStatus().done)
                g_context.ioex->setLedMikona(Ioex::LedMikona::Done);
            else if (g_context.mikona->getStatus().charge)
                g_context.ioex->setLedMikona(Ioex::LedMikona::Charging);
            else
                g_context.ioex->setLedMikona(Ioex::LedMikona::None);

        }

        g_context.ioex->write();
    }
}

void core1_entry()
{
    while(true)
    {
        g_context.protocol->transceive_blocking();
    }
}

int main()
{
    stdio_init_all();

    printf("hello from rp2040, and hippo :D\n");

    // Initialize I2C 0
    i2c_init(i2c0, 400 * 1000);
    gpio_set_function(MAIN_BOARD_I2C_0_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(MAIN_BOARD_I2C_0_SCL_PIN, GPIO_FUNC_I2C);

    // Initialize I2C 1
    i2c_init(i2c1, 400 * 1000);
    gpio_set_function(MAIN_BOARD_I2C_1_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(MAIN_BOARD_I2C_1_SCL_PIN, GPIO_FUNC_I2C);

    gpio_init(MAIN_BOARD_BUZZER_PIN);
    gpio_set_dir(MAIN_BOARD_BUZZER_PIN, GPIO_OUT);
    gpio_put(MAIN_BOARD_BUZZER_PIN, 0);

    g_context.ioex = std::make_unique<Ioex>(i2c0);
    g_context.ioex->init();

    // --- IOEX debug ---
    while (true)
    {
        auto& ioex = *g_context.ioex;

        // LED sweep
        const auto led_delay_ms = 50;
        ioex.setLedFault(true);   ioex.write(); sleep_ms(led_delay_ms);
        ioex.setLedFault(false);  ioex.write(); sleep_ms(led_delay_ms);
        ioex.setLedIr(true);      ioex.write(); sleep_ms(led_delay_ms);
        ioex.setLedIr(false);     ioex.write(); sleep_ms(led_delay_ms);
        ioex.setLedMikona(Ioex::LedMikona::Charging); ioex.write(); sleep_ms(led_delay_ms);
        ioex.setLedMikona(Ioex::LedMikona::Done);     ioex.write(); sleep_ms(led_delay_ms);
        ioex.setLedMikona(Ioex::LedMikona::None);     ioex.write(); sleep_ms(led_delay_ms);
        ioex.setLedWifi(Ioex::LedWifi::Connected); ioex.write(); sleep_ms(led_delay_ms);
        ioex.setLedWifi(Ioex::LedWifi::Activity);  ioex.write(); sleep_ms(led_delay_ms);
        ioex.setLedWifi(Ioex::LedWifi::None);      ioex.write(); sleep_ms(led_delay_ms);
        ioex.setLedSwitch(Ioex::LedSwitch::Warning); ioex.write(); sleep_ms(led_delay_ms);
        ioex.setLedSwitch(Ioex::LedSwitch::Normal);  ioex.write(); sleep_ms(led_delay_ms);

        // Quick beeps
        for (int i = 0; i < 2; i++)
        {
            //gpio_put(MAIN_BOARD_BUZZER_PIN, 1); sleep_ms(30);
            //gpio_put(MAIN_BOARD_BUZZER_PIN, 0); sleep_ms(30);
        }

        // Print inputs
        ioex.read();
        printf("[IOEX] ID=%d\n", ioex.getId());
        printf("[IOEX] DIP1=%d DIP2=%d DIP3=%d DIP4=%d\n",
            ioex.getDip(1), ioex.getDip(2), ioex.getDip(3), ioex.getDip(4));
        printf("[IOEX] Button=%d\n", ioex.getButton());
    }
    // --- end IOEX debug ---

    g_context.mikona = std::make_unique<Mikona>(i2c0);
    g_context.mikona->init();

    g_context.powerMonitor = std::make_unique<PowerMonitor>(i2c0);
    g_context.powerMonitor->init();

    // TODO: remove debug
    sleep_ms(250);
    g_context.powerMonitor->refresh();

    const float v24_V = g_context.powerMonitor->getVoltage(PowerMonitor::Rail::V24);
    const float v24_I = g_context.powerMonitor->getCurrent(PowerMonitor::Rail::V24);
    printf("  [V24] V=%.3fV  I=%.4fA  P=%.3fW\n", v24_V, v24_I, v24_V * v24_I);

    const float v5_V = g_context.powerMonitor->getVoltage(PowerMonitor::Rail::V5);
    const float v5_I = g_context.powerMonitor->getCurrent(PowerMonitor::Rail::V5);
    printf("  [V5]  V=%.3fV  I=%.4fA  P=%.3fW\n", v5_V, v5_I, v5_V * v5_I);

    const float elapsed = g_context.powerMonitor->getElapsedTime();
    printf("  elapsed=%.2fs\n", elapsed);

    printf("  [V24] E=%.3fmWh\n", g_context.powerMonitor->getEnergy(PowerMonitor::Rail::V24));
    printf("  [V5]  E=%.3fmWh\n", g_context.powerMonitor->getEnergy(PowerMonitor::Rail::V5));
    printf("---\n");

    g_context.ballDetector = std::make_unique<BallDetector>();
    g_context.ballDetector->init();

    g_context.protocol = std::make_unique<Protocol>();
    g_context.protocol->init();

    multicore_launch_core1(core1_entry);



    core0_entry();
}
