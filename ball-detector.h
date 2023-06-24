#pragma once

#include <stdint.h>

class BallDetector
{
public:
    BallDetector() = default;

    void init();

    bool ball_detected() const;

private:
    // ADC parameters
    static constexpr float kBallDetectionVoltageThreshold = 3.0f;
    static constexpr float kVAdcRef = 3.3f;

    // PWM parameters
    static constexpr uint16_t kPwmWrap = 1024;
};
