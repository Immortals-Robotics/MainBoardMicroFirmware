#include <stdio.h>
#include <string.h>

#include <pico/stdlib.h>
#include <pico/binary_info.h>
#include <hardware/spi.h>

#include <pb_encode.h>
#include <pb_decode.h>
#include "immortals/micro.pb.h"

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

int main()
{
    stdio_init_all();
    
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

    Immortals_Protos_MicroStatus message = Immortals_Protos_MicroStatus_init_zero;
    message.ballDetected = true;

    fill_tx_buffer(message, tx_buffer, BUFFER_LEN);

    for (size_t i = 0; ; ++i)
    {
        // Write the output buffer to MISO, and at the same time read from MOSI.
        spi_write_read_blocking(spi_default, tx_buffer, rx_buffer, BUFFER_LEN);

        Immortals_Protos_MicroCommand message = Immortals_Protos_MicroCommand_init_zero;
        const bool success = consume_rx_buffer(&message, rx_buffer, BUFFER_LEN);
        if (success)
        {
            printf("charge: %d!\n", message.mikona.charge);

            // Write to stdio whatever came in on the MOSI line.
            //printf("SPI slave says: read page %d from the MOSI line:\n", i);
            //printbuf(in_buf, BUFFER_LEN);

            gpio_put(MAIN_BOARD_LED_PIN, 1-gpio_get_out_level(MAIN_BOARD_LED_PIN));
        }
    }
}
