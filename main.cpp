#include <stdio.h>
#include <string.h>

#include <pico/stdlib.h>

#include "ball-detector.h"
#include "mikona.h"
#include "ioex.h"
#include "power_monitor.h"
#include "protocol.h"

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

    Ioex ioex{};
    ioex.init(i2c0);

    Mikona mikona(i2c0);
    mikona.init();

    PowerMonitor powerMonitor;
    powerMonitor.init(i2c0);

    BallDetector ballDetector;
    ballDetector.init();

    Protocol protocol{};
    protocol.init();

    gpio_init(MAIN_BOARD_BUZZER_PIN);
    gpio_set_dir(MAIN_BOARD_BUZZER_PIN, GPIO_OUT);
    gpio_put(MAIN_BOARD_BUZZER_PIN, 0);

    bool faultMicro = false;
    bool faultMainBoard = false;

    while(true)
    {
        protocol.transceive_blocking();

        Immortals_Protos_MicroCommand command = Immortals_Protos_MicroCommand_init_zero;
        const bool success = protocol.consume_rx_buffer(&command);
        if (success)
        {
            if (command.has_mikona)
            {
                mikona.setCharge(command.mikona.charge);
                mikona.setDischarge(command.mikona.discharge);

                mikona.kickA(command.mikona.kick_a);
                mikona.kickB(command.mikona.kick_b);
            }

            if (command.has_led)
            {
                if (command.led.wifi_acitivity)
                    ioex.setLedWifi(Ioex::LedWifi::Activity);
                else if (command.led.wifi_connected)
                    ioex.setLedWifi(Ioex::LedWifi::Connected);
                else
                    ioex.setLedWifi(Ioex::LedWifi::None);

                faultMainBoard = command.led.fault;
                ioex.setLedFault(faultMainBoard || faultMicro);
            }

            // TODO: improve buzzer
            gpio_put(MAIN_BOARD_BUZZER_PIN, command.buzzer);
        }

        // Fill status
        {
            Immortals_Protos_MicroStatus status = Immortals_Protos_MicroStatus_init_zero;

            status.robot_id = ioex.getId();

            status.dip_switch_1 = ioex.getDip(1);
            status.dip_switch_2 = ioex.getDip(2);
            status.dip_switch_3 = ioex.getDip(3);
            status.dip_switch_4 = ioex.getDip(4);

            status.button = ioex.getButton();

            status.ballDetected = ballDetector.ball_detected();

            const Mikona::Status mikonaStatus = mikona.getStatus();
            status.mikona.connected   = mikona.isConnected();
            status.mikona.charging    = mikonaStatus.charge;
            status.mikona.discharging = mikonaStatus.discharge;
            status.mikona.done        = mikonaStatus.done;
            status.mikona.fault       = mikonaStatus.fault;
            status.mikona.v_out       = mikona.getVoltage();

            status.motor_1.status = gpio_get(MAIN_BOARD_M1_CTRL_STATUS_PIN);
            status.motor_1.fault  = gpio_get(MAIN_BOARD_M1_DRV_FAULT_PIN);

            status.motor_2.status = gpio_get(MAIN_BOARD_M2_CTRL_STATUS_PIN);
            status.motor_2.fault  = gpio_get(MAIN_BOARD_M2_DRV_FAULT_PIN);

            status.motor_3.status = gpio_get(MAIN_BOARD_M3_CTRL_STATUS_PIN);
            status.motor_3.fault  = gpio_get(MAIN_BOARD_M3_DRV_FAULT_PIN);

            status.motor_4.status = gpio_get(MAIN_BOARD_M4_CTRL_STATUS_PIN);
            status.motor_4.fault  = gpio_get(MAIN_BOARD_M4_DRV_FAULT_PIN);

            status.motor_d.status = gpio_get(MAIN_BOARD_MD_CTRL_STATUS_PIN);
            status.motor_d.fault  = gpio_get(MAIN_BOARD_MD_DRV_FAULT_PIN);

            status.power_5v.voltage = powerMonitor.getVoltage(PowerMonitor::Rail::V5);
            status.power_5v.current = powerMonitor.getCurrent(PowerMonitor::Rail::V5);
            status.power_5v.power   = powerMonitor.getPower  (PowerMonitor::Rail::V5);

            status.power_24v.voltage = powerMonitor.getVoltage(PowerMonitor::Rail::V24);
            status.power_24v.current = powerMonitor.getCurrent(PowerMonitor::Rail::V24);
            status.power_24v.power   = powerMonitor.getPower  (PowerMonitor::Rail::V24);

            faultMicro = 
                status.mikona.fault  ||
                status.motor_1.fault ||
                status.motor_2.fault ||
                status.motor_3.fault ||
                status.motor_4.fault ||
                status.motor_d.fault;
            ioex.setLedFault(faultMainBoard || faultMicro);

            protocol.fill_tx_buffer(status);
        }

        {
            ioex.setLedIr(ballDetector.ball_detected());

            if (mikona.getStatus().done)
                ioex.setLedMikona(Ioex::LedMikona::Done);
            else if (mikona.getStatus().charge)
                ioex.setLedMikona(Ioex::LedMikona::Charging);
            else
                ioex.setLedMikona(Ioex::LedMikona::None);
            
        }
    }
}
