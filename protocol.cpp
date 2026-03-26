#include "protocol.h"

#include <string.h>

#include <pico/stdlib.h>
#include <hardware/spi.h>

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

bool Protocol::fill_tx_buffer(const MicroStatus& message)
{
    critical_section_enter_blocking(&m_criticalSection);

    if (!m_tx_buffer_ready)
    {
        // First fill: pre-populate the active buffer too so the first
        // transceive doesn't send zeros.
        memset(m_tx_buffer[m_buffer_index], 0, kBufferLen);
        memcpy(m_tx_buffer[m_buffer_index], &message, sizeof(MicroStatus));
        m_tx_buffer_ready = true;
    }

    memset(m_tx_buffer[1-m_buffer_index], 0, kBufferLen);
    memcpy(m_tx_buffer[1-m_buffer_index], &message, sizeof(MicroStatus));

    critical_section_exit(&m_criticalSection);

    return true;
}

bool Protocol::consume_rx_buffer(MicroCommand* const message)
{
    critical_section_enter_blocking(&m_criticalSection);

    if (!rx_data_available())
    {
        critical_section_exit(&m_criticalSection);
        return false;
    }

    memcpy(message, m_rx_buffer[1-m_buffer_index], sizeof(MicroCommand));
    m_rx_data_available = false;

    critical_section_exit(&m_criticalSection);

    return true;
}

bool Protocol::transceive_blocking()
{
    // Wait until fill_tx_buffer has been called at least once.
    while (!m_tx_buffer_ready)
        tight_loop_contents();

    // Drain any stale bytes left in the RX FIFO from a previous missed transfer.
    while (spi_is_readable(spi_default))
        (void) spi_get_hw(spi_default)->dr;

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
