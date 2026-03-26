#include "power_monitor.h"

#include <stdio.h>
#include <pico/stdlib.h>

// PAC1954 constants (unipolar, high-side configuration)
static constexpr float kVbusFSR_V      = 32.0f;    // 32V full-scale for VBUS
static constexpr float kVsenseFSR_mV   = 100.0f;   // 100mV full-scale for VSENSE

// rsense values in micro-Ohms, indexed by channel (0-based)
static constexpr uint32_t kRsense_uOhm[2] = { 1000, 2000 };

static float voltageFromReg(uint16_t reg)
{
    return reg * kVbusFSR_V / 65536.0f;
}

static float currentFromReg(uint16_t reg, uint32_t rsense_uOhm)
{
    // Vsense (mV) = reg * 100mV / 65536
    // I (A)       = Vsense (V) / Rsense (Ω) = Vsense_mV * 1e-3 / (rsense_uOhm * 1e-6)
    //             = Vsense_mV * 1e3 / rsense_uOhm
    const float vsense_mV = reg * kVsenseFSR_mV / 65536.0f;
    return vsense_mV * 1000.0f / rsense_uOhm;
}

static float powerFromReg(uint32_t reg, uint32_t rsense_uOhm)
{
    // VPOWER register is 30-bit (stored left-aligned in 32 bits)
    // P (W) = (reg >> 2) / 2^30 * VbusFSR_V * VsenseFSR_V / Rsense_Ohm
    //       = (reg >> 2) * 32 * 0.1 * 1e6 / rsense_uOhm / 2^30
    const float reg30 = static_cast<float>(reg >> 2);
    return reg30 * 3.2e6f / rsense_uOhm / 1073741824.0f;
}

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
    const PAC194X5X_DEVICE_INIT pacInit =
    {
        .i2cAddress = kI2cAddress,
        .syncMode = true,
        .i2cHandle = m_i2c,
        // NOTE: rsense is in micro-Ohms. Verify against actual shunt resistor values on the board.
        // 1000 uOhm = 1 mOhm, 2000 uOhm = 2 mOhm.
        .rsense = { kRsense_uOhm[0], kRsense_uOhm[1], 0, 0 },
        .VrailToVbusRatio = { 1.0f, 1.0f, 1.0f, 1.0f },
    };

    const uint16_t init_result = PAC194x5x_Device_Initialize(&m_pacDevice, pacInit);

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
            uint16_t vbus_avg = 0, vsense_avg = 0;
            uint32_t vpower_reg = 0;
            PAC194x5x_GetVBUSn_AVG_reg(&m_pacDevice, ch, &vbus_avg);
            PAC194x5x_GetVSENSEn_AVG_reg(&m_pacDevice, ch, &vsense_avg);
            PAC194x5x_GetVPOWERn_reg(&m_pacDevice, ch, &vpower_reg);
            const float V = voltageFromReg(vbus_avg);
            const float I = currentFromReg(vsense_avg, kRsense_uOhm[ch - 1]);
            const float P = powerFromReg(vpower_reg, kRsense_uOhm[ch - 1]);
            printf("  [%s] V=%.3fV  I=%.4fA  P=%.3fW\n", name, V, I, P);
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
    uint16_t reg = 0;
    PAC194x5x_GetVBUSn_reg(&m_pacDevice, channelForRail(rail), &reg);
    return voltageFromReg(reg);
}

float PowerMonitor::getCurrent(const Rail rail)
{
    if (!m_connected) return 0.0f;
    PAC194x5x_RefreshV(&m_pacDevice);
    sleep_ms(1);
    uint16_t reg = 0;
    const uint8_t ch = channelForRail(rail);
    PAC194x5x_GetVSENSEn_reg(&m_pacDevice, ch, &reg);
    return currentFromReg(reg, kRsense_uOhm[ch - 1]);
}

float PowerMonitor::getPower(const Rail rail)
{
    if (!m_connected) return 0.0f;
    PAC194x5x_RefreshV(&m_pacDevice);
    sleep_ms(1);
    const uint8_t ch = channelForRail(rail);
    uint32_t reg = 0;
    PAC194x5x_GetVPOWERn_reg(&m_pacDevice, ch, &reg);
    return powerFromReg(reg, kRsense_uOhm[ch - 1]);
}
