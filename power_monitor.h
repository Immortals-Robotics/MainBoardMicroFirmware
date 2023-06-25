#pragma once

#include <hardware/i2c.h>

#include "3rdparty/PAC194x_5x/PAC194x_5x.h"

class PowerMonitor
{
public:
    PowerMonitor() = default;

    bool init(i2c_inst_t* i2c);

private:
    static constexpr uint16_t kI2cAddress = 0x13;

    PAC194X5X_DEVICE_CONTEXT m_pacDevice;
    bool m_connected = false;
};
