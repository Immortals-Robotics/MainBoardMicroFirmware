#include "buzzer.h"

#include <hardware/gpio.h>
#include <pico/stdlib.h>
#include <initializer_list>

Buzzer::Buzzer(const uint pin)
    : m_pin(pin)
    , m_slice(pwm_gpio_to_slice_num(pin))
    , m_channel(pwm_gpio_to_channel(pin))
{
}

void Buzzer::init()
{
    gpio_set_function(m_pin, GPIO_FUNC_PWM);
    // Start with an arbitrary wrap and level=0 so the pin is driven low from the start
    pwm_set_wrap(m_slice, 999);
    pwm_set_chan_level(m_slice, m_channel, 0);
    pwm_set_enabled(m_slice, true);
}

void Buzzer::stop()
{
    pwm_set_chan_level(m_slice, m_channel, 0);
}

void Buzzer::set(const uint32_t freq_hz, const float duty)
{
    if (freq_hz == 0)
    {
        stop();
        return;
    }

    // Find the smallest integer clkdiv that keeps wrap within 16 bits
    uint32_t clkdiv = 1;
    uint32_t wrap   = clock_get_hz(clk_sys) / freq_hz - 1;
    while (wrap > 65535) { clkdiv++; wrap = clock_get_hz(clk_sys) / (clkdiv * freq_hz) - 1; }

    pwm_set_clkdiv_int_frac(m_slice, clkdiv, 0);
    pwm_set_wrap(m_slice, wrap);
    pwm_set_chan_level(m_slice, m_channel, (uint32_t)(wrap * duty));
}

void Buzzer::play(const Sequence sequence)
{
    switch (sequence)
    {
        case Sequence::BootJingle:
            play({
                { 523, 0.25f, 100 },  // C5
                { 659, 0.25f, 100 },  // E5
                { 784, 0.25f, 100 },  // G5
                {   0, 0.0f,   60 },
                {1047, 0.25f, 350 },  // C6
            });
            break;

        case Sequence::TripleAlert:
            play({
                {2500, 0.25f,  80 },
                {   0, 0.0f,   60 },
                {2500, 0.25f,  80 },
                {   0, 0.0f,   60 },
                {2500, 0.25f,  80 },
            });
            break;

        case Sequence::Chirp:
            play({
                {3000, 0.25f,  50 },
                {1500, 0.25f,  50 },
                {3500, 0.25f,  40 },
                {2000, 0.25f,  60 },
                {4000, 0.25f,  30 },
                {1800, 0.25f,  80 },
                {2800, 0.25f, 120 },
            });
            break;

        case Sequence::SadTrombone:
            play({
                { 587, 0.25f, 180 },  // D5
                { 554, 0.25f, 180 },  // C#5
                { 494, 0.25f, 180 },  // B4
                { 440, 0.25f, 500 },  // A4
            });
            break;

        case Sequence::MarioCoin:
            play({
                {  988, 0.25f,  50 },  // B5
                { 1319, 0.25f, 200 },  // E6
            });
            break;

        case Sequence::Mario1Up:
            play({
                { 1319, 0.25f, 125 },  // E6
                { 1568, 0.25f, 125 },  // G6
                { 2637, 0.25f, 125 },  // E7
                { 2093, 0.25f, 125 },  // C7
                { 2349, 0.25f, 125 },  // D7
                { 3136, 0.25f, 175 },  // G7
            });
            break;

        case Sequence::ZeldaItemGet:
            play({
                {  392, 0.25f,  75 },  // G4
                {  523, 0.25f,  75 },  // C5
                {  659, 0.25f,  75 },  // E5
                {  784, 0.25f,  75 },  // G5
                {  988, 0.25f,  75 },  // B5
                { 1047, 0.25f,  75 },  // C6
                {  988, 0.25f,  75 },  // B5
                { 1047, 0.25f, 350 },  // C6
            });
            break;

        case Sequence::Tetris:
            play({
                {  659, 0.25f, 150 },  // E5
                {  494, 0.25f,  75 },  // B4
                {  523, 0.25f,  75 },  // C5
                {  587, 0.25f, 150 },  // D5
                {  523, 0.25f,  75 },  // C5
                {  494, 0.25f,  75 },  // B4
                {  440, 0.25f, 150 },  // A4
                {  440, 0.25f,  75 },  // A4
                {  523, 0.25f,  75 },  // C5
                {  659, 0.25f, 150 },  // E5
                {  587, 0.25f,  75 },  // D5
                {  523, 0.25f,  75 },  // C5
                {  494, 0.25f, 225 },  // B4
            });
            break;

        case Sequence::PacManDeath:
            play({
                {  494, 0.25f,  80 },  // B4
                {  440, 0.25f,  80 },  // A4
                {  415, 0.25f,  80 },  // Ab4
                {  392, 0.25f,  80 },  // G4
                {  370, 0.25f,  80 },  // Gb4
                {  349, 0.25f,  80 },  // F4
                {  330, 0.25f,  80 },  // E4
                {  311, 0.25f,  80 },  // Eb4
                {  294, 0.25f,  80 },  // D4
                {  277, 0.25f,  80 },  // Db4
                {  262, 0.25f,  80 },  // C4
                {  247, 0.25f, 160 },  // B3
            });
            break;
    }
}

void Buzzer::play(std::initializer_list<BuzzerNote> notes)
{
    for (const auto& note : notes)
    {
        set(note.freq_hz, note.duty);
        sleep_ms(note.duration_ms);
    }
    stop();
}
