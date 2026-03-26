#pragma once

#include <stdint.h>
#include <hardware/pwm.h>
#include <hardware/clocks.h>

class Buzzer
{
public:
    Buzzer(uint pin);

    void init();

    // Set frequency (Hz) and duty cycle (0.0 - 1.0). Pass freq=0 to silence.
    void set(uint32_t freq_hz, float duty);

private:
    const uint m_pin;
    uint m_slice;
    uint m_channel;
};
