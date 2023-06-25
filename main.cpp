#include <stdio.h>
#include <string.h>

#include <pico/stdlib.h>

#include "ball-detector.h"
#include "mikona.h"
#include "ioex.h"
#include "power_monitor.h"
#include "protocol.h"

void init_i2c0()
{
    i2c_init(i2c0, 400 * 1000);

    gpio_set_function(MAIN_BOARD_I2C_0_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(MAIN_BOARD_I2C_0_SCL_PIN, GPIO_FUNC_I2C);
}

int main()
{
    stdio_init_all();

    init_i2c0();

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

    for (size_t i = 0; ; ++i)
    {
        protocol.transceive_blocking();

        Immortals_Protos_MicroCommand command = Immortals_Protos_MicroCommand_init_zero;
        const bool success = protocol.consume_rx_buffer(&command);
        if (success)
        {
            // TODO: execute command
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

            // TODO: fill power monitor status
            status.power_5v.voltage = powerMonitor.getVoltage(PowerMonitor::Rail::V5);
            status.power_5v.current = powerMonitor.getCurrent(PowerMonitor::Rail::V5);
            status.power_5v.power   = powerMonitor.getPower  (PowerMonitor::Rail::V5);

            status.power_24v.voltage = powerMonitor.getVoltage(PowerMonitor::Rail::V24);
            status.power_24v.current = powerMonitor.getCurrent(PowerMonitor::Rail::V24);
            status.power_24v.power   = powerMonitor.getPower  (PowerMonitor::Rail::V24);

            protocol.fill_tx_buffer(status);
        }
    }
}
