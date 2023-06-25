#include <stdio.h>
#include <string.h>

#include <pico/stdlib.h>
#include <hardware/spi.h>

#include <pb_encode.h>
#include <pb_decode.h>
#include "immortals/micro.pb.h"

#include "3rdparty/PAC194x_5x/PAC194x_5x.h"

#include "ball-detector.h"
#include "mikona.h"
#include "ioex.h"

#define SPI_FREQ (4 * 1000 * 1000)

#define BUFFER_LEN 128

uint8_t tx_buffer[BUFFER_LEN] = {}, rx_buffer[BUFFER_LEN] = {};

static_assert(Immortals_Protos_MicroCommand_size < BUFFER_LEN, "Buffer too small");
static_assert(Immortals_Protos_MicroStatus_size < BUFFER_LEN, "Buffer too small");

bool fill_tx_buffer(const Immortals_Protos_MicroStatus& message, uint8_t* buffer, size_t buffer_len)
{
    pb_ostream_t stream = pb_ostream_from_buffer(buffer, buffer_len);
    bool status = pb_encode_ex(&stream, Immortals_Protos_MicroStatus_fields, &message, PB_ENCODE_DELIMITED);
    
    if (!status)
    {
        printf("Encoding failed: %s\n", PB_GET_ERROR(&stream));
        return false;
    }

    return true;
}

bool consume_rx_buffer(Immortals_Protos_MicroCommand* const message, const uint8_t* buffer, size_t buffer_len)
{
    pb_istream_t stream = pb_istream_from_buffer(buffer, buffer_len);
    bool status = pb_decode_ex(&stream, Immortals_Protos_MicroCommand_fields, message, PB_DECODE_DELIMITED);
    
    if (!status)
    {
        printf("Decoding failed: %s\n", PB_GET_ERROR(&stream));
        return false;
    }

    return true;
}


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

    test_ir();

    init_i2c0();

    Ioex ioex{};
    ioex.init(i2c0);

    test_mikona();

    test_pac1954();

    while (true)
    {
        ioex.setLedSwitch(ioex.getButton() ? Ioex::LedSwitch::Warning : Ioex::LedSwitch::Normal);
        printf("id: %d\n", ioex.getId());
        sleep_ms(100);
    }

    // init io
    gpio_init(MAIN_BOARD_LED_PIN);
    gpio_set_dir(MAIN_BOARD_LED_PIN, GPIO_OUT);
    gpio_put(MAIN_BOARD_LED_PIN, 1-gpio_get_out_level(MAIN_BOARD_LED_PIN));
    
    // init spi
    spi_init(spi_default, SPI_FREQ);
    spi_set_slave(spi_default, true);
    spi_set_format(spi_default, 8, SPI_CPOL_1, SPI_CPHA_1, SPI_MSB_FIRST);
    gpio_set_function(MAIN_BOARD_SPI_RX_PIN, GPIO_FUNC_SPI);
    gpio_set_function(MAIN_BOARD_SPI_TX_PIN, GPIO_FUNC_SPI);
    gpio_set_function(MAIN_BOARD_SPI_SCK_PIN, GPIO_FUNC_SPI);
    gpio_set_function(MAIN_BOARD_SPI_CSN_PIN, GPIO_FUNC_SPI);

    Immortals_Protos_MicroStatus status = Immortals_Protos_MicroStatus_init_zero;
    status.ballDetected = true;
    fill_tx_buffer(status, tx_buffer, BUFFER_LEN);

    for (size_t i = 0; ; ++i)
    {
        // Write the output buffer to MISO, and at the same time read from MOSI.
        spi_write_read_blocking(spi_default, tx_buffer, rx_buffer, BUFFER_LEN);

        Immortals_Protos_MicroCommand command = Immortals_Protos_MicroCommand_init_zero;
        const bool success = consume_rx_buffer(&command, rx_buffer, BUFFER_LEN);
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
