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

            status.power_5v_voltage = g_context.powerMonitor->getVoltage(PowerMonitor::Rail::V5);
            status.power_5v_current = g_context.powerMonitor->getCurrent(PowerMonitor::Rail::V5);
            status.power_5v_power   = g_context.powerMonitor->getPower  (PowerMonitor::Rail::V5);

            status.power_24v_voltage = g_context.powerMonitor->getVoltage(PowerMonitor::Rail::V24);
            status.power_24v_current = g_context.powerMonitor->getCurrent(PowerMonitor::Rail::V24);
            status.power_24v_power   = g_context.powerMonitor->getPower  (PowerMonitor::Rail::V24);

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

    g_context.ioex = std::make_unique<Ioex>(i2c0);
    g_context.ioex->init();

    g_context.mikona = std::make_unique<Mikona>(i2c0);
    g_context.mikona->init();

    g_context.powerMonitor = std::make_unique<PowerMonitor>(i2c0);
    g_context.powerMonitor->init();

    g_context.ballDetector = std::make_unique<BallDetector>();
    g_context.ballDetector->init();

    g_context.protocol = std::make_unique<Protocol>();
    g_context.protocol->init();

    gpio_init(MAIN_BOARD_BUZZER_PIN);
    gpio_set_dir(MAIN_BOARD_BUZZER_PIN, GPIO_OUT);
    gpio_put(MAIN_BOARD_BUZZER_PIN, 0);

    multicore_launch_core1(core1_entry);
    core0_entry();
}
