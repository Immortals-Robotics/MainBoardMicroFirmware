#pragma once

#include <stdint.h>
#include <initializer_list>
#include <hardware/pwm.h>
#include <hardware/clocks.h>

struct BuzzerNote
{
    uint32_t freq_hz;     // 0 = silence
    float    duty;
    uint32_t duration_ms;
};

class Buzzer
{
public:
    enum class Sequence
    {
        BootJingle,
        TripleAlert,
        Chirp,
        SadTrombone,
        MarioCoin,
        Mario1Up,
        ZeldaItemGet,
        Tetris,
        PacManDeath,
    };

    Buzzer(uint pin);

    void init();

    void stop();

    // Set frequency (Hz) and duty cycle (0.0 - 1.0). Pass freq=0 to silence.
    void set(uint32_t freq_hz, float duty);

    // Play a sequence of notes blocking until done.
    void play(std::initializer_list<BuzzerNote> notes);
    void play(Sequence sequence);

private:
    const uint m_pin;
    uint m_slice;
    uint m_channel;
};
