#include <stdio.h>
#include <string.h>

#include <pico/stdlib.h>
#include <pico/binary_info.h>
#include <hardware/spi.h>
#include <hardware/pwm.h>
#include <hardware/adc.h>

#include <pb_encode.h>
#include <pb_decode.h>
#include "immortals/micro.pb.h"

#include "PI4IOE5V6416.h"

#include "3rdparty/PAC194x_5x/PAC194x_5x.h"

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
    adc_init();
    
    // Make sure GPIO is high-impedance, no pullups etc
    adc_gpio_init(MAIN_BOARD_IR_ADC_PIN);
    // Select ADC input 0 (GPIO26)
    adc_select_input(3);

    gpio_set_function(MAIN_BOARD_IR_PWM_PIN, GPIO_FUNC_PWM);
    const uint slice_num = pwm_gpio_to_slice_num(MAIN_BOARD_IR_PWM_PIN);

    // Get some sensible defaults for the slice configuration. By default, the
    // counter is allowed to wrap over its maximum range (0 to 2**16-1)
    pwm_config config = pwm_get_default_config();
    // Set divider, reduces counter clock to sysclock/this value
    //pwm_config_set_clkdiv(&config, 4.f);
    pwm_config_set_wrap(&config, 1024);
    // Load the configuration into our PWM slice, and set it running.
    pwm_init(slice_num, &config, true);

    pwm_set_gpio_level(MAIN_BOARD_IR_PWM_PIN, 512);

    while (1)
    {
        // 12-bit conversion, assume max value == ADC_VREF == 3.3 V
        const float conversion_factor = 3.3f / (1 << 12);
        const uint16_t result_raw = adc_read();
        const float result = result_raw * conversion_factor;
        const bool ball_detected = result > 3.0f;
        printf("voltage: %f V, Ball: %d\n", result, ball_detected);
        sleep_ms(50);
    }
}

int main()
{
    stdio_init_all();

    test_ir();

    init_i2c0();

    test_pac1954();

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
