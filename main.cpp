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

    Immortals_Protos_MicroCommand command;
    Immortals_Protos_MicroStatus  status;

    bool command_received = false;

    bool faultMicro     = false;
    bool faultMainBoard = false;
} g_context;

void command_received_callback()
{
    if (g_context.command.has_mikona)
    {
        g_context.mikona->setCharge(g_context.command.mikona.charge);
        g_context.mikona->setDischarge(g_context.command.mikona.discharge);

        g_context.mikona->kickA(g_context.command.mikona.kick_a);
        g_context.mikona->kickB(g_context.command.mikona.kick_b);
    }

    if (g_context.command.has_led)
    {
        if (g_context.command.led.wifi_acitivity)
            g_context.ioex->setLedWifi(Ioex::LedWifi::Activity);
        else if (g_context.command.led.wifi_connected)
            g_context.ioex->setLedWifi(Ioex::LedWifi::Connected);
        else
            g_context.ioex->setLedWifi(Ioex::LedWifi::None);

        g_context.faultMainBoard = g_context.command.led.fault;
        g_context.ioex->setLedFault(g_context.faultMainBoard || g_context.faultMicro);
    }

    // TODO: improve buzzer
    gpio_put(MAIN_BOARD_BUZZER_PIN, g_context.command.buzzer);
}

void core0_entry()
{
    while(true)
    {
        // Consume command
        if (g_context.command_received)
        {
            g_context.command_received = false;
            command_received_callback();
        }

        // Fill status
        {
            g_context.status = Immortals_Protos_MicroStatus_init_zero;

            g_context.status.robot_id = g_context.ioex->getId();

            g_context.status.dip_switch_1 = g_context.ioex->getDip(1);
            g_context.status.dip_switch_2 = g_context.ioex->getDip(2);
            g_context.status.dip_switch_3 = g_context.ioex->getDip(3);
            g_context.status.dip_switch_4 = g_context.ioex->getDip(4);

            g_context.status.button = g_context.ioex->getButton();

            g_context.status.ballDetected = g_context.ballDetector->ball_detected();

            const Mikona::Status mikonaStatus = g_context.mikona->getStatus();
            g_context.status.mikona.connected   = g_context.mikona->isConnected();
            g_context.status.mikona.charging    = mikonaStatus.charge;
            g_context.status.mikona.discharging = mikonaStatus.discharge;
            g_context.status.mikona.done        = mikonaStatus.done;
            g_context.status.mikona.fault       = mikonaStatus.fault;
            g_context.status.mikona.v_out       = g_context.mikona->getVoltage();

            g_context.status.motor_1.status = gpio_get(MAIN_BOARD_M1_CTRL_STATUS_PIN);
            g_context.status.motor_1.fault  = gpio_get(MAIN_BOARD_M1_DRV_FAULT_PIN);

            g_context.status.motor_2.status = gpio_get(MAIN_BOARD_M2_CTRL_STATUS_PIN);
            g_context.status.motor_2.fault  = gpio_get(MAIN_BOARD_M2_DRV_FAULT_PIN);

            g_context.status.motor_3.status = gpio_get(MAIN_BOARD_M3_CTRL_STATUS_PIN);
            g_context.status.motor_3.fault  = gpio_get(MAIN_BOARD_M3_DRV_FAULT_PIN);

            g_context.status.motor_4.status = gpio_get(MAIN_BOARD_M4_CTRL_STATUS_PIN);
            g_context.status.motor_4.fault  = gpio_get(MAIN_BOARD_M4_DRV_FAULT_PIN);

            g_context.status.motor_d.status = gpio_get(MAIN_BOARD_MD_CTRL_STATUS_PIN);
            g_context.status.motor_d.fault  = gpio_get(MAIN_BOARD_MD_DRV_FAULT_PIN);

            g_context.status.power_5v.voltage = g_context.powerMonitor->getVoltage(PowerMonitor::Rail::V5);
            g_context.status.power_5v.current = g_context.powerMonitor->getCurrent(PowerMonitor::Rail::V5);
            g_context.status.power_5v.power   = g_context.powerMonitor->getPower  (PowerMonitor::Rail::V5);

            g_context.status.power_24v.voltage = g_context.powerMonitor->getVoltage(PowerMonitor::Rail::V24);
            g_context.status.power_24v.current = g_context.powerMonitor->getCurrent(PowerMonitor::Rail::V24);
            g_context.status.power_24v.power   = g_context.powerMonitor->getPower  (PowerMonitor::Rail::V24);

            g_context.faultMicro = 
                g_context.status.mikona.fault  ||
                g_context.status.motor_1.fault ||
                g_context.status.motor_2.fault ||
                g_context.status.motor_3.fault ||
                g_context.status.motor_4.fault ||
                g_context.status.motor_d.fault;
            g_context.ioex->setLedFault(g_context.faultMainBoard || g_context.faultMicro);

            g_context.protocol->fill_tx_buffer(g_context.status);
        }

        {
            g_context.ioex->setLedIr(g_context.ballDetector->ball_detected());
            g_context.ioex->setLedFault(g_context.ioex->getButton());

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

        g_context.command = Immortals_Protos_MicroCommand_init_zero;
        const bool success = g_context.protocol->consume_rx_buffer(&g_context.command);
        if (success)
        {
            // TODO: send interrupt to core 0 to handle this
            g_context.command_received = true;
        }
    }
}

int main()
{
    stdio_init_all();

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
