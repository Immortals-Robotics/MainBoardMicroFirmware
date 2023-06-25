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

    Immortals_Protos_MicroStatus status = Immortals_Protos_MicroStatus_init_zero;
    status.ballDetected = true;
    protocol.fill_tx_buffer(status);

    for (size_t i = 0; ; ++i)
    {
        protocol.transceive_blocking();

        Immortals_Protos_MicroCommand command = Immortals_Protos_MicroCommand_init_zero;
        const bool success = protocol.consume_rx_buffer(&command);
        if (success)
        {
            printf("charge: %d!\n", command.mikona.charge);
        }

        printf("Ball detected: %d\n", ballDetector.ball_detected());

        printf("Mikona status: %d, voltage: %f\n", mikona.getStatus(), mikona.getVoltage());
    }
}
