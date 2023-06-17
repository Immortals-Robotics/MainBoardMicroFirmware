#include <stdio.h>
#include <string.h>

#include <pico/stdlib.h>
#include <pico/binary_info.h>
#include <hardware/spi.h>

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

    for (size_t i = 0; i < BUF_LEN; ++i)
    {
        tx_buf[i] = ~i;
    }

    for (size_t i = 0; ; ++i)
    {
        // Write the output buffer to MISO, and at the same time read from MOSI.
        spi_write_read_blocking(spi_default, tx_buf, rx_buf, BUF_LEN);

        // Write to stdio whatever came in on the MOSI line.
        //printf("SPI slave says: read page %d from the MOSI line:\n", i);
        //printbuf(in_buf, BUF_LEN);

        gpio_put(MAIN_BOARD_LED_PIN, 1-gpio_get_out_level(MAIN_BOARD_LED_PIN));
    }
}
