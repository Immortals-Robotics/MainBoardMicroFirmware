#include "mikona.h"

#include <stdio.h>
#include <pico/stdlib.h>

#define REG_STATUS_CHARGE_BIT    0
#define REG_STATUS_DISCHARGE_BIT 1
#define REG_STATUS_DONE_BIT      2
#define REG_STATUS_FAULT_BIT     3

static inline bool getBit(const uint8_t byte, const uint8_t bit)
{
    return (byte & (1 << bit)) >> bit;
}

static inline uint8_t setBit(const uint8_t byte, const uint8_t bit, const bool value)
{
    return (~(1 << bit) & byte) | (value << bit);
}

union reg_u16
{
    uint8_t u8[2];
    uint16_t u16;
};

Mikona::Mikona(i2c_inst_t* const i2c)
    : m_i2c(i2c)
{
}

bool Mikona::init()
{
    uint8_t dev_id;
    if (read_bytes(Register::DEV_ID, &dev_id, 1) == 1 && dev_id == kDevId)
    {
        printf("Connected to mikona at address: 0x%x with device id: 0x%x\n", kAddress ,dev_id);
        m_connected = true;
        return true;
    }
    else
    {
        printf("Failed to connect to mikona at address: 0x%x\n", kAddress);
        m_connected = false;
        return false;
    }
}

uint8_t Mikona::getDeviceId() const
{
    uint8_t dev_id;
    read_bytes(Register::DEV_ID, &dev_id, 1);
    return dev_id;
}

Mikona::Status Mikona::getStatus() const
{
    uint8_t status_reg;
    read_bytes(Register::STATUS, &status_reg, 1);

    Status status{};
    status.charge    = getBit(status_reg, REG_STATUS_CHARGE_BIT);
    status.discharge = getBit(status_reg, REG_STATUS_DISCHARGE_BIT);
    status.done      = getBit(status_reg, REG_STATUS_DONE_BIT);
    status.fault     = getBit(status_reg, REG_STATUS_FAULT_BIT);

    return status;
}

float Mikona::getVoltage() const
{
    reg_u16 voltage_reg;
    read_bytes(Register::V_OUT, voltage_reg.u8, 2);

    return voltage_reg.u16 * kVoltageConversionFactor;
}

void Mikona::updateStatusBit(const uint8_t bit, const bool value)
{
    uint8_t status_original;
    read_bytes(Register::STATUS, &status_original, 1);

    const uint8_t status_updated = setBit(status_original, bit, value);
    write_bytes(Register::STATUS, &status_updated, 1);
}

void Mikona::setCharge(const bool enable)
{
    updateStatusBit(REG_STATUS_CHARGE_BIT, enable);
}

void Mikona::setDischarge(bool enable)
{
    updateStatusBit(REG_STATUS_DISCHARGE_BIT, enable);
}

void Mikona::clearFault()
{
    updateStatusBit(REG_STATUS_FAULT_BIT, false);
}

void Mikona::kickA(const uint16_t pulseWidth)
{
    if (pulseWidth == 0)
        return;

    reg_u16 kick_reg;
    kick_reg.u16 = pulseWidth;

    write_bytes(Register::KICK_A, kick_reg.u8, 2);
}

void Mikona::kickB(uint16_t pulseWidth)
{
    if (pulseWidth == 0)
        return;
        
    reg_u16 kick_reg;
    kick_reg.u16 = pulseWidth;

    write_bytes(Register::KICK_B, kick_reg.u8, 2);
}

int8_t Mikona::read_bytes(const Register reg, uint8_t* const data, const uint8_t size) const
{
        i2c_write_blocking(m_i2c, kAddress, (uint8_t*)(&reg), 1, true);
        return i2c_read_blocking(m_i2c, kAddress, data, size, false);
}

bool Mikona::write_bytes(const Register reg, const uint8_t* const data, const uint8_t size)
{
    uint8_t msg[size + 1];

    // Append register address to front of data packet
    msg[0] = (uint8_t)reg;
    for (int i = 0; i < size; i++) {
        msg[i + 1] = data[i];
    }

    // Write data to register(s) over I2C
    int num_bytes_written = i2c_write_blocking(m_i2c, kAddress, msg, (size + 1), false);

    return num_bytes_written > 0;
}
