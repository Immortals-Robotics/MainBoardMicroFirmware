#include <stdio.h>
#include <string.h>

#include <pico/stdlib.h>
#include <pico/binary_info.h>
#include <hardware/spi.h>

#include <pb_encode.h>
#include <pb_decode.h>
#include "immortals/micro.pb.h"

#include "PI4IOE5V6416.h"

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

#define IOEX_DIP_3 PI4IOE5V64XX::Port::P00
#define IOEX_DIP_2 PI4IOE5V64XX::Port::P01
#define IOEX_DIP_1 PI4IOE5V64XX::Port::P02
#define IOEX_DIP_0 PI4IOE5V64XX::Port::P03
#define IOEX_BUTTON PI4IOE5V64XX::Port::P04

#define IOEX_LED_FAULT           PI4IOE5V64XX::Port::P05
#define IOEX_LED_IR              PI4IOE5V64XX::Port::P06
#define IOEX_LED_MIKONA_CHARGING PI4IOE5V64XX::Port::P07
#define IOEX_LED_MIKONA_FULL     PI4IOE5V64XX::Port::P10
#define IOEX_LED_WIFI_ACTIVITY   PI4IOE5V64XX::Port::P11
#define IOEX_LED_WIFI_CONNECTED  PI4IOE5V64XX::Port::P12
#define IOEX_LED_SWITCH          PI4IOE5V64XX::Port::P13

#define IOEX_ID_BIT_2 PI4IOE5V64XX::Port::P14
#define IOEX_ID_BIT_0 PI4IOE5V64XX::Port::P15
#define IOEX_ID_BIT_3 PI4IOE5V64XX::Port::P16
#define IOEX_ID_BIT_1 PI4IOE5V64XX::Port::P17

PI4IOE5V6416 ioex;

void init_ioex()
{
    ioex = PI4IOE5V6416();
    ioex.attach();
    ioex.polarity(PI4IOE5V64XX::Polarity::ORIGINAL_ALL);

    ioex.direction(IOEX_DIP_3 , PI4IOE5V64XX::Direction::IN);
    ioex.direction(IOEX_DIP_2 , PI4IOE5V64XX::Direction::IN);
    ioex.direction(IOEX_DIP_1 , PI4IOE5V64XX::Direction::IN);
    ioex.direction(IOEX_DIP_0 , PI4IOE5V64XX::Direction::IN);
    ioex.direction(IOEX_BUTTON, PI4IOE5V64XX::Direction::IN);

    ioex.direction(IOEX_LED_FAULT          , PI4IOE5V64XX::Direction::OUT);
    ioex.direction(IOEX_LED_IR             , PI4IOE5V64XX::Direction::OUT);
    ioex.direction(IOEX_LED_MIKONA_CHARGING, PI4IOE5V64XX::Direction::OUT);
    ioex.direction(IOEX_LED_MIKONA_FULL    , PI4IOE5V64XX::Direction::OUT);
    ioex.direction(IOEX_LED_WIFI_ACTIVITY  , PI4IOE5V64XX::Direction::OUT);
    ioex.direction(IOEX_LED_WIFI_CONNECTED , PI4IOE5V64XX::Direction::OUT);
    ioex.direction(IOEX_LED_SWITCH         , PI4IOE5V64XX::Direction::OUT);

    ioex.direction(IOEX_ID_BIT_2, PI4IOE5V64XX::Direction::IN);
    ioex.direction(IOEX_ID_BIT_0, PI4IOE5V64XX::Direction::IN);
    ioex.direction(IOEX_ID_BIT_3, PI4IOE5V64XX::Direction::IN);
    ioex.direction(IOEX_ID_BIT_1, PI4IOE5V64XX::Direction::IN);

    ioex.pullUpDownEnable(IOEX_DIP_3   );
    ioex.pullUpDownEnable(IOEX_DIP_2   );
    ioex.pullUpDownEnable(IOEX_DIP_1   );
    ioex.pullUpDownEnable(IOEX_DIP_0   );
    ioex.pullUpDownEnable(IOEX_BUTTON  );
    ioex.pullUpDownEnable(IOEX_ID_BIT_2);
    ioex.pullUpDownEnable(IOEX_ID_BIT_0);
    ioex.pullUpDownEnable(IOEX_ID_BIT_3);
    ioex.pullUpDownEnable(IOEX_ID_BIT_1);

    ioex.pullUpDownSelection(IOEX_DIP_3   , PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    ioex.pullUpDownSelection(IOEX_DIP_2   , PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    ioex.pullUpDownSelection(IOEX_DIP_1   , PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    ioex.pullUpDownSelection(IOEX_DIP_0   , PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    ioex.pullUpDownSelection(IOEX_BUTTON  , PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    ioex.pullUpDownSelection(IOEX_ID_BIT_2, PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    ioex.pullUpDownSelection(IOEX_ID_BIT_0, PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    ioex.pullUpDownSelection(IOEX_ID_BIT_3, PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    ioex.pullUpDownSelection(IOEX_ID_BIT_1, PI4IOE5V64XX::PullUpDownSelection::PULL_UP);

    ioex.write(IOEX_LED_FAULT          , PI4IOE5V64XX::Level::L);
    ioex.write(IOEX_LED_IR             , PI4IOE5V64XX::Level::L);
    ioex.write(IOEX_LED_MIKONA_CHARGING, PI4IOE5V64XX::Level::L);
    ioex.write(IOEX_LED_MIKONA_FULL    , PI4IOE5V64XX::Level::L);
    ioex.write(IOEX_LED_WIFI_ACTIVITY  , PI4IOE5V64XX::Level::L);
    ioex.write(IOEX_LED_WIFI_CONNECTED , PI4IOE5V64XX::Level::L);
    ioex.write(IOEX_LED_SWITCH         , PI4IOE5V64XX::Level::L);
}

int main()
{
    stdio_init_all();
    
    init_ioex();

    while (true)
    {
        PI4IOE5V64XX::Level::Level button = ioex.read(IOEX_BUTTON);
        ioex.write(IOEX_LED_FAULT         , button);
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
