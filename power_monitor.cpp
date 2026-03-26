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

    // Diagnostic loop: accumulate for 250ms per window, then print averaged readings.
    // Uses REFRESH (not REFRESH_V) so the VPOWER accumulator is properly reset each window.
    // V and I come from the 8-sample rolling-average registers for stability.
    printf("  Streaming readings (Ctrl-C to stop)...\n");
    PAC194x5x_Refresh(&m_pacDevice);  // reset accumulators, start first window
    sleep_ms(1);
    for (;;)
    {
        sleep_ms(250);

        // Latch accumulated VPOWER and reset for the next window
        PAC194x5x_Refresh(&m_pacDevice);
        sleep_ms(1);

        for (uint8_t ch = 1; ch <= 2; ch++)
        {
            const char* name = (ch == 1) ? "V24" : "V5";
            float V_mV = 0.0f, I_mA = 0.0f, P_mW = 0.0f;
            PAC194x5x_GetVBUSn_AVG_real(&m_pacDevice, ch, &V_mV);
            PAC194x5x_GetISENSEn_AVG_real(&m_pacDevice, ch, &I_mA);
            PAC194x5x_GetVPOWERn_real(&m_pacDevice, ch, &P_mW);
            printf("  [%s] V=%.3fV  I=%.4fA  P=%.3fW\n", name, V_mV / 1000.0f, I_mA / 1000.0f, P_mW / 1000.0f);
        }
        printf("---\n");
    }

    return true;
}

float PowerMonitor::getVoltage(const Rail rail)
{
    if (!m_connected) return 0.0f;
    PAC194x5x_RefreshV(&m_pacDevice);
    sleep_ms(1);
    float mV = 0.0f;
    PAC194x5x_GetVBUSn_AVG_real(&m_pacDevice, channelForRail(rail), &mV);
    return mV / 1000.0f;
}

float PowerMonitor::getCurrent(const Rail rail)
{
    if (!m_connected) return 0.0f;
    PAC194x5x_RefreshV(&m_pacDevice);
    sleep_ms(1);
    float mA = 0.0f;
    PAC194x5x_GetISENSEn_AVG_real(&m_pacDevice, channelForRail(rail), &mA);
    return mA / 1000.0f;
}

float PowerMonitor::getPower(const Rail rail)
{
    if (!m_connected) return 0.0f;
    PAC194x5x_RefreshV(&m_pacDevice);
    sleep_ms(1);
    float mW = 0.0f;
    PAC194x5x_GetVPOWERn_real(&m_pacDevice, channelForRail(rail), &mW);
    return mW / 1000.0f;
}