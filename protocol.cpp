#include "protocol.h"

#include <stdio.h>

#include <pico/stdlib.h>
#include <hardware/spi.h>

#include <pb_encode.h>
#include <pb_decode.h>

void Protocol::init()
{
    spi_init(spi_default, kSpiFreq);
    spi_set_slave(spi_default, true);
    spi_set_format(spi_default, 8, SPI_CPOL_1, SPI_CPHA_1, SPI_MSB_FIRST);
    gpio_set_function(MAIN_BOARD_SPI_RX_PIN, GPIO_FUNC_SPI);
    gpio_set_function(MAIN_BOARD_SPI_TX_PIN, GPIO_FUNC_SPI);
    gpio_set_function(MAIN_BOARD_SPI_SCK_PIN, GPIO_FUNC_SPI);
    gpio_set_function(MAIN_BOARD_SPI_CSN_PIN, GPIO_FUNC_SPI);
}

bool Protocol::fill_tx_buffer(const Immortals_Protos_MicroStatus& message)
{
    pb_ostream_t stream = pb_ostream_from_buffer(m_tx_buffer, kBufferLen);
    bool status = pb_encode_ex(&stream, Immortals_Protos_MicroStatus_fields, &message, PB_ENCODE_DELIMITED);
    
    if (!status)
    {
        printf("Encoding failed: %s\n", PB_GET_ERROR(&stream));
        return false;
    }

    return true;
}

bool Protocol::consume_rx_buffer(Immortals_Protos_MicroCommand* const message)
{
    pb_istream_t stream = pb_istream_from_buffer(m_rx_buffer, kBufferLen);
    bool status = pb_decode_ex(&stream, Immortals_Protos_MicroCommand_fields, message, PB_DECODE_DELIMITED);
    
    if (!status)
    {
        printf("Decoding failed: %s\n", PB_GET_ERROR(&stream));
        return false;
    }

    return true;
}

bool Protocol::transceive_blocking()
{
    // Write the output buffer to MISO, and at the same time read from MOSI.
    const int length = spi_write_read_blocking(spi_default, m_tx_buffer, m_rx_buffer, kBufferLen);
    return length > 0;
}
