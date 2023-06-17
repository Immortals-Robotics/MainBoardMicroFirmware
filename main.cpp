#include <stdio.h>
#include <string.h>

#include <pico/stdlib.h>
#include <pico/binary_info.h>
#include <hardware/spi.h>

#include <pb_encode.h>
#include <pb_decode.h>
#include "immortals/micro.pb.h"

#define BUF_LEN 256
uint8_t tx_buf[BUF_LEN] = {}, rx_buf[BUF_LEN] = {};
size_t tx_buf_idx = 0, rx_buf_idx = 0;

int main() 
{
    stdio_init_all();
    
    gpio_init(MAIN_BOARD_LED_PIN);
    gpio_set_dir(MAIN_BOARD_LED_PIN, GPIO_OUT);
    gpio_put(MAIN_BOARD_LED_PIN, 1-gpio_get_out_level(MAIN_BOARD_LED_PIN));
    
    spi_init(spi_default, 4 * 1000 * 1000);
    spi_set_slave(spi_default, true);
    spi_set_format(spi_default, 8, SPI_CPOL_1, SPI_CPHA_1, SPI_MSB_FIRST);
    gpio_set_function(MAIN_BOARD_SPI_RX_PIN, GPIO_FUNC_SPI);
    gpio_set_function(MAIN_BOARD_SPI_TX_PIN, GPIO_FUNC_SPI);
    gpio_set_function(MAIN_BOARD_SPI_SCK_PIN, GPIO_FUNC_SPI);
    gpio_set_function(MAIN_BOARD_SPI_CSN_PIN, GPIO_FUNC_SPI);

    Immortals_Protos_MicroStatus message = Immortals_Protos_MicroStatus_init_zero;
        
        pb_ostream_t stream = pb_ostream_from_buffer(tx_buf, sizeof(BUF_LEN));

        // TODO:        
        message.ballDetected = true;
        
        bool status = pb_encode_ex(&stream, Immortals_Protos_MicroStatus_fields, &message, PB_ENCODE_DELIMITED);
        size_t message_length = stream.bytes_written;
        
        if (!status)
        {
            printf("Encoding failed: %s\n", PB_GET_ERROR(&stream));
            return 1;
        }

    for (size_t i = 0; ; ++i)
    {
        // Write the output buffer to MISO, and at the same time read from MOSI.
        spi_write_read_blocking(spi_default, tx_buf, rx_buf, BUF_LEN);

        Immortals_Protos_MicroCommand message = Immortals_Protos_MicroCommand_init_zero;
        pb_istream_t stream = pb_istream_from_buffer(rx_buf, BUF_LEN);
        status = pb_decode_ex(&stream, Immortals_Protos_MicroCommand_fields, &message, PB_DECODE_DELIMITED);
        
        if (!status)
        {
            printf("Decoding failed: %s\n", PB_GET_ERROR(&stream));
        }
        else
        {
            printf("kick: %d!\n", message.kick);

            // Write to stdio whatever came in on the MOSI line.
            //printf("SPI slave says: read page %d from the MOSI line:\n", i);
            //printbuf(in_buf, BUF_LEN);

            gpio_put(MAIN_BOARD_LED_PIN, 1-gpio_get_out_level(MAIN_BOARD_LED_PIN));
        }
    }
}
