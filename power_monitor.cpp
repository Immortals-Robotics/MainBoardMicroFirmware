#include "power_monitor.h"

#include <stdio.h>
#include <pico/stdlib.h>

bool PowerMonitor::init(i2c_inst_t* i2c)
{
    const PAC194X5X_DEVICE_INIT pacInit = 
    {
        .i2cAddress = kI2cAddress,
        .syncMode = false,
        .i2cHandle = i2c,
        .rsense = { 1000, 2000, 0, 0 },
        .VrailToVbusRatio = {  1.0f, 1.0f, 1.0f, 1.0f },
    };

    const uint16_t init_result = PAC194x5x_Device_Initialize(&m_pacDevice, pacInit);

    sleep_ms(1);

    if (init_result == PAC194X5X_SUCCESS)
    {
        //PAC194x5x_Device_Initialize() records in the device context the device ID register values
        printf("Connected to PAC1954 at address 0x%x\n", kI2cAddress);
        printf("Product ID      : 0x%X\n", m_pacDevice.deviceID.product);
        printf("Manufacturer ID : 0x%X\n", m_pacDevice.deviceID.manufacturer);
        printf("Revision ID     : 0x%X\n", m_pacDevice.deviceID.revision);

        m_connected = true;
    }
    else
    {
        printf("Failed to connect to PAC1954 at address 0x%x\n", kI2cAddress);
        m_connected = false;
    }

    return m_connected;
}

// TODO: implement these
float PowerMonitor::getVoltage(const Rail rail)
{
    return 0.0f;
}

float PowerMonitor::getCurrent(const Rail rail)
{
    return 0.0f;
}
float PowerMonitor::getPower(const Rail rail)
{
    return 0.0f;
}
