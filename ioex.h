#pragma once

#include <hardware/i2c.h>
#include "3rdparty/PI4IOE5V6416/PI4IOE5V6416.h"

class Ioex
{
public:
    enum class LedMikona
    {
        None,
        Charging,
        Done,
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

    Ioex(i2c_inst_t* i2c);

    void init();

    bool getButton();
    bool getDip(uint8_t index);
    uint8_t getId();

    void setLedFault(bool enable);
    void setLedIr(bool enable);
    void setLedMikona(LedMikona led);
    void setLedWifi(LedWifi led);
    void setLedSwitch(LedSwitch enable);


private:
    i2c_inst_t* const m_i2c;
    PI4IOE5V6416 m_ioex;
};
