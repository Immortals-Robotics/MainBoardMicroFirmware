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

    void read();   // fetch all pin states from the chip into m_inputs
    void write();  // flush m_outputs to the chip

    // call read() first
    bool getButton();
    bool getDip(uint8_t index);
    uint8_t getId();

    // call write() after
    void setLedFault(bool enable);
    void setLedIr(bool enable);
    void setLedMikona(LedMikona led);
    void setLedWifi(LedWifi led);
    void setLedSwitch(LedSwitch led);


private:
    i2c_inst_t* const m_i2c;
    PI4IOE5V6416 m_ioex;
    uint16_t m_inputs  = 0;
    uint16_t m_outputs = 0;

    inline bool get_bit(int bit) const { return m_inputs  &  (1 << bit); }
    inline void set_bit(int bit, bool high) { if (high) m_outputs |= (1 << bit); else m_outputs &= ~(1 << bit); }
};
