#pragma once

#include <hardware/i2c.h>
#include "PI4IOE5V6416.h"

class Ioex
{
public:
    enum class LedMikona
    {
        None,
        Charging,
        Full,
    };

    enum class LedWifi
    {
        None,
        Connected,
        Activity,
    };

    enum class LedSwitch
    {
        Normal,
        Warning,
    };

    Ioex() = default;

    void init(i2c_inst_t* i2c);

    bool getButton();
    bool getDip(uint8_t index);
    uint8_t getId();

    void setLedFault(bool enable);
    void setLedIr(bool enable);
    void setLedMikona(LedMikona led);
    void setLedWifi(LedWifi led);
    void setLedSwitch(LedSwitch enable);


private:
    PI4IOE5V6416 m_ioex;
};
