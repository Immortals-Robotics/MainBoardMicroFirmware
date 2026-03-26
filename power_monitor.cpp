#include "power_monitor.h"

#include <stdio.h>
#include <pico/stdlib.h>

// rsense values in micro-Ohms, indexed by channel (0-based)
// NOTE: Verify against actual shunt resistor values on the board.
// 1000 uOhm = 1 mOhm, 2000 uOhm = 2 mOhm.
static constexpr uint32_t kRsense_uOhm[2] = { 1000, 2000 };

PowerMonitor::PowerMonitor(i2c_inst_t* const i2c)
    : m_i2c(i2c)
{
}

static uint8_t channelForRail(PowerMonitor::Rail rail)
{
    switch (rail)
    {
        case PowerMonitor::Rail::V24: return 1;
        case PowerMonitor::Rail::V5:  return 2;
        default:                      return 1;
    }
}

bool PowerMonitor::init()
{
    const uint8_t busID = (m_i2c == i2c0) ? 0 : 1;

    const PAC194X5X_i2cParams i2cParams = { kI2cAddress, busID };

    uint32_t rsense[PAC194X5X_MAX_CH_COUNT] = { kRsense_uOhm[0], kRsense_uOhm[1], 0, 0 };
    float VrailToVbusRatio[PAC194X5X_MAX_CH_COUNT] = { 1.0f, 1.0f, 1.0f, 1.0f };

    const uint16_t init_result = PAC194x5x_Device_Initialize(i2cParams, &m_pacDevice, VrailToVbusRatio, rsense);

    sleep_ms(1);

    if (init_result != PAC194X5X_SUCCESS)
    {
        printf("Failed to connect to PAC1954 at address 0x%x (err=%d)\n", kI2cAddress, init_result);
        m_connected = false;
        return false;
    }

    printf("Connected to PAC1954 at address 0x%x\n", kI2cAddress);
    printf("  Product ID      : 0x%X\n", m_pacDevice.deviceID.product);
    printf("  Manufacturer ID : 0x%X\n", m_pacDevice.deviceID.manufacturer);
    printf("  Revision ID     : 0x%X\n", m_pacDevice.deviceID.revision);

    PAC194X5X_CTRL_REGISTER ctrl_reg;
    if (PAC194x5x_GetCtrl_reg(&m_pacDevice, 1, &ctrl_reg) == PAC194X5X_SUCCESS)
    {
        printf("  CTRL: sample_mode=%d gpio_alert2=%d slow_alert1=%d ch1_off=%d ch2_off=%d\n",
               ctrl_reg.SAMPLE_MODE, ctrl_reg.GPIO_ALERT2, ctrl_reg.SLOW_ALERT1,
               ctrl_reg.CH1_OFF, ctrl_reg.CH2_OFF);
    }

    m_connected = true;

    return true;
}

bool PowerMonitor::refresh()
{
    if (!m_connected) return false;
    PAC194x5x_Refresh(&m_pacDevice);
    sleep_ms(1);
    return true;
}

float PowerMonitor::getVoltage(const Rail rail)
{
    if (!m_connected) return 0.0f;
    float mV = 0.0f;
    PAC194x5x_GetVBUSn_AVG_real(&m_pacDevice, channelForRail(rail), &mV);
    return mV / 1000.0f;
}

float PowerMonitor::getCurrent(const Rail rail)
{
    if (!m_connected) return 0.0f;
    float mA = 0.0f;
    PAC194x5x_GetISENSEn_AVG_real(&m_pacDevice, channelForRail(rail), &mA);
    return mA / 1000.0f;
}

float PowerMonitor::getElapsedTime()
{
    if (!m_connected) return 0.0f;
    uint32_t accCount = 0;
    PAC194x5x_GetAccumulatorCount(&m_pacDevice, &accCount);
    return static_cast<float>(accCount) / kSampleRate;
}

float PowerMonitor::getEnergy(const Rail rail)
{
    if (!m_connected) return 0.0f;
    float mWh = 0.0f;
    PAC194x5x_GetEnergy(&m_pacDevice, channelForRail(rail), &mWh);
    return mWh;
}

float PowerMonitor::getCoulomb(const Rail rail)
{
    if (!m_connected) return 0.0f;
    float mAs = 0.0f;
    PAC194x5x_GetCoulomb(&m_pacDevice, channelForRail(rail), &mAs);
    return mAs;
}


