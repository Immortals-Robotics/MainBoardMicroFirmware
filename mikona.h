#pragma once

#include <hardware/i2c.h>

class Mikona
{
public:
    struct Status
    {
        bool charge;
        bool discharge;
        bool done;
        bool fault;
    };

    Mikona(i2c_inst_t* i2c);

    bool init();

    bool isConnected() const { return m_connected; }
    uint8_t getDeviceId() const;
    Status getStatus() const;
    float getVoltage() const;

    void setCharge(bool enable);
    void setDischarge(bool enable);
    void clearFault();

    void kickA(uint16_t pulseWidth);
    void kickB(uint16_t pulseWidth);

private:
    enum class Register : uint8_t
    {
        DEV_ID = 0x01,
        STATUS = 0x02,
        V_OUT  = 0x03,
        KICK_A = 0x04,
        KICK_B = 0x05,
    };

    static constexpr uint8_t kAddress = 0x2b;
    static constexpr uint8_t kDevId = 0x54;

    static constexpr float kVoltageConversionFactor = 0.0050857544f;

    int8_t read_bytes(Register reg, uint8_t* data, uint8_t size) const;
    bool write_bytes(Register reg, const uint8_t* data, uint8_t size);

    void updateStatusBit(uint8_t bit, bool value);

    i2c_inst_t* const m_i2c;
    
    bool m_connected = false;
};
