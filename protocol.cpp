#include "protocol.h"

#include <stdio.h>

#include <pico/stdlib.h>
#include <hardware/spi.h>

#include <pb_encode.h>
#include <pb_decode.h>

void Protocol::init()
{
    // Initialize mutex
    critical_section_init(&m_criticalSection);

    // Initialize SPI
    spi_init(spi_default, kSpiFreq);
    spi_set_slave(spi_default, true);
    spi_set_format(spi_default, 8, SPI_CPOL_1, SPI_CPHA_1, SPI_MSB_FIRST);
    gpio_set_function(MAIN_BOARD_SPI_RX_PIN, GPIO_FUNC_SPI);
    gpio_set_function(MAIN_BOARD_SPI_TX_PIN, GPIO_FUNC_SPI);
    gpio_set_function(MAIN_BOARD_SPI_SCK_PIN, GPIO_FUNC_SPI);
    gpio_set_function(MAIN_BOARD_SPI_CSN_PIN, GPIO_FUNC_SPI);

    // Initialize LED
    gpio_init(MAIN_BOARD_LED_PIN);
    gpio_set_dir(MAIN_BOARD_LED_PIN, GPIO_OUT);
    setLed(false);
}

bool Protocol::fill_tx_buffer(const Immortals_Protos_MicroStatus& message)
{
    critical_section_enter_blocking(&m_criticalSection);
    
    pb_ostream_t stream = pb_ostream_from_buffer(m_tx_buffer[1-m_buffer_index], kBufferLen);
    bool status = pb_encode_ex(&stream, Immortals_Protos_MicroStatus_fields, &message, PB_ENCODE_DELIMITED);
    
    critical_section_exit(&m_criticalSection);

    if (!status)
    {
        printf("Encoding failed: %s\n", PB_GET_ERROR(&stream));
        return false;
    }

    return true;
}

bool Protocol::consume_rx_buffer(Immortals_Protos_MicroCommand* const message)
{
    critical_section_enter_blocking(&m_criticalSection);

    if (!rx_data_available())
    {
        critical_section_exit(&m_criticalSection);
        return false;
    }

    pb_istream_t stream = pb_istream_from_buffer(m_rx_buffer[1-m_buffer_index], kBufferLen);
    bool status = pb_decode_ex(&stream, Immortals_Protos_MicroCommand_fields, message, PB_DECODE_DELIMITED);
    m_rx_data_available = false;

    critical_section_exit(&m_criticalSection);

    if (!status)
    {
        printf("Decoding failed: %s\n", PB_GET_ERROR(&stream));
        *message = Immortals_Protos_MicroCommand_init_zero;
        return false;
    }

    return true;
}

bool Protocol::transceive_blocking()
{
    // Write the output buffer to MISO, and at the same time read from MOSI.
    const int length = spi_write_read_blocking(spi_default, m_tx_buffer[m_buffer_index], m_rx_buffer[m_buffer_index], kBufferLen);
    const bool success = length > 0;

    critical_section_enter_blocking(&m_criticalSection);
    m_buffer_index = 1 - m_buffer_index;
    m_rx_data_available = success;
    critical_section_exit(&m_criticalSection);

    if (success)
    {
        toggleLed();
    }

    return success;
}

void Protocol::setLed(bool enable)
{
    gpio_put(MAIN_BOARD_LED_PIN, 1 - enable);
}

void Protocol::toggleLed()
{
    gpio_put(MAIN_BOARD_LED_PIN, 1 - gpio_get_out_level(MAIN_BOARD_LED_PIN));
}
