#include "ball-detector.h"

#include <stdio.h>
#include <pico/stdlib.h>

#include <hardware/pwm.h>
#include <hardware/adc.h>
#include "ball-detector.h"

void BallDetector::init()
{
    // Initialize ADC
    {
        adc_init();
        
        // Make sure GPIO is high-impedance, no pullups etc
        adc_gpio_init(MAIN_BOARD_IR_ADC_PIN);
        // Select ADC input (GPIO26 is input 0)
        adc_select_input(MAIN_BOARD_IR_ADC_PIN - 26);
    }

    // Initialize PWM
    {
        gpio_set_function(MAIN_BOARD_IR_PWM_PIN, GPIO_FUNC_PWM);
        const uint slice_num = pwm_gpio_to_slice_num(MAIN_BOARD_IR_PWM_PIN);

        // counter is allowed to wrap over its maximum range (0 to 2**16-1)
        pwm_config config = pwm_get_default_config();
        // reduce range to 0..1024 (2**10)
        pwm_config_set_wrap(&config, kPwmWrap);
        // Load the configuration into our PWM slice, and set it running.
        pwm_init(slice_num, &config, true);

        // Set the PWM duty cycle to 50%
        pwm_set_gpio_level(MAIN_BOARD_IR_PWM_PIN, kPwmWrap / 2);
    }
}

bool BallDetector::ball_detected() const
{
    // 12-bit conversion, assume max value == ADC_VREF == 3.3 V
    const float conversion_factor = kVAdcRef / (1 << 12);
    const uint16_t result_raw = adc_read();
    const float result = result_raw * conversion_factor;
    return result > kBallDetectionVoltageThreshold;
}
