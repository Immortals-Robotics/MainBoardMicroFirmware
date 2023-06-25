#include <stdio.h>
#include <string.h>

#include <pico/stdlib.h>

#include "3rdparty/PAC194x_5x/PAC194x_5x.h"

#include "ball-detector.h"
#include "mikona.h"
#include "ioex.h"
#include "protocol.h"

void init_i2c0()
{
    i2c_init(i2c0, 400 * 1000);

    gpio_set_function(MAIN_BOARD_I2C_0_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(MAIN_BOARD_I2C_0_SCL_PIN, GPIO_FUNC_I2C);
}

void test_pac1954()
{
    PAC194X5X_DEVICE_CONTEXT pacDevice;
    
    PAC194X5X_DEVICE_INIT pacInit = 
    {
        .i2cAddress = 0x13,
        .syncMode = false,
        .i2cHandle = i2c0,
        .rsense = { 1000, 2000, 1000, 1000 },
        .VrailToVbusRatio = {  1.0f, 1.0f, 1.0f, 1.0f },
    };

    uint16_t init_result = PAC194x5x_Device_Initialize(&pacDevice, pacInit);

    sleep_ms(10);

    if (init_result == PAC194X5X_SUCCESS)
    {
        //PAC194x5x_Device_Initialize() records in the device context the device ID register values
        printf("\nProduct ID      : 0x%X", pacDevice.deviceID.product);
        printf("\nManufacturer ID : 0x%X", pacDevice.deviceID.manufacturer);
        printf("\nRevision ID     : 0x%X", pacDevice.deviceID.revision);

        // TODO: read the measurements
    }
}

void test_ir()
{
    BallDetector ballDetector;
    ballDetector.init();

    while (1)
    {
        printf("Ball detected: %d\n", ballDetector.ball_detected());
        sleep_ms(50);
    }
}

void test_mikona()
{
    Mikona mikona(i2c0);
    mikona.init();

    while(true)
    {
        printf("Mikona status: %d, voltage: %f\n", mikona.getStatus(), mikona.getVoltage());
        sleep_ms(100);
    }
}

int main()
{
    stdio_init_all();

    //test_ir();

    init_i2c0();

    Ioex ioex{};
    ioex.init(i2c0);

    Protocol protocol{};
    protocol.init();

    //test_mikona();

    test_pac1954();

    // init io
    gpio_init(MAIN_BOARD_LED_PIN);
    gpio_set_dir(MAIN_BOARD_LED_PIN, GPIO_OUT);
    gpio_put(MAIN_BOARD_LED_PIN, 1-gpio_get_out_level(MAIN_BOARD_LED_PIN));

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

            // Write to stdio whatever came in on the MOSI line.
            //printf("SPI slave says: read page %d from the MOSI line:\n", i);
            //printbuf(in_buf, BUFFER_LEN);

            gpio_put(MAIN_BOARD_LED_PIN, 1-gpio_get_out_level(MAIN_BOARD_LED_PIN));
        }
    }
}
