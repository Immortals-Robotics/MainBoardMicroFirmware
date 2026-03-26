#include "buzzer.h"

#include <hardware/gpio.h>

Buzzer::Buzzer(const uint pin)
    : m_pin(pin)
    , m_slice(pwm_gpio_to_slice_num(pin))
    , m_channel(pwm_gpio_to_channel(pin))
{
}

void Buzzer::init()
{
    gpio_set_function(m_pin, GPIO_FUNC_PWM);
    pwm_set_enabled(m_slice, false);
}

void Buzzer::set(const uint32_t freq_hz, const float duty)
{
    if (freq_hz == 0)
    {
        pwm_set_enabled(m_slice, false);
        return;
    }

    // Find the smallest integer clkdiv that keeps wrap within 16 bits
    uint32_t clkdiv = 1;
    uint32_t wrap   = clock_get_hz(clk_sys) / freq_hz - 1;
    while (wrap > 65535) { clkdiv++; wrap = clock_get_hz(clk_sys) / (clkdiv * freq_hz) - 1; }

    pwm_set_clkdiv_int_frac(m_slice, clkdiv, 0);
    pwm_set_wrap(m_slice, wrap);
    pwm_set_chan_level(m_slice, m_channel, (uint32_t)(wrap * duty));
    pwm_set_enabled(m_slice, true);
}
