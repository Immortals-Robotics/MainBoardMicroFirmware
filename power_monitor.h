#pragma once

#include <hardware/i2c.h>
#include "3rdparty/PAC194x_5x/PAC194x_5x.h"

class PowerMonitor
{
public:
    enum class Rail
    {
        V24,  // CH1: input → 24V rail (power components: motors, actuators, etc.)
        V5,   // CH2: 24V rail → 5V regulator (RPi, micro, logic)
    };

    PowerMonitor(i2c_inst_t* i2c);

    bool init();

    bool isConnected() const { return m_connected; }

    // Call refresh() once before reading any combination of getters.
    // Issues a full REFRESH command: latches all measurement registers and
    // resets the VACC accumulator and ACC_COUNT. This means getElapsedTime()
    // and getEnergy() return values relative to the most recent refresh() call.
    bool refresh();

    // Instantaneous readings (from 8-sample rolling average registers).
    float getVoltage(Rail rail);  // V
    float getCurrent(Rail rail);  // A

    // Time elapsed since the last refresh() call, derived from the hardware
    // accumulator sample count. Assumes 1024 sps (the default sample rate).
    float getElapsedTime();  // seconds

    // Energy accumulated since the last refresh() call.
    // Requires ACCUM_CONFIG in VPOWER mode (the default) — returns 0 otherwise.
    float getEnergy(Rail rail);  // mWh

    // Charge accumulated since the last refresh() call.
    // NOTE: requires ACCUM_CONFIG in VSENSE mode (ACC_CONFIG = 0x1 per channel),
    // which conflicts with VPOWER mode needed for getEnergy.
    // Returns 0 with the default Device_Initialize configuration.
    float getCoulomb(Rail rail);  // mAs

private:
    static constexpr uint8_t kI2cAddress = 0x13;
    static constexpr float   kSampleRate  = 1024.0f;

    i2c_inst_t* const m_i2c;
    PAC194X5X_DEVICE_CONTEXT m_pacDevice;
    bool m_connected = false;
};