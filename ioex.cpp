#include "ioex.h"

#include <stdio.h>
#include <pico/stdlib.h>

#define IOEX_DIP_0 PI4IOE5V64XX::Port::P00
#define IOEX_DIP_1 PI4IOE5V64XX::Port::P01
#define IOEX_DIP_2 PI4IOE5V64XX::Port::P02
#define IOEX_DIP_3 PI4IOE5V64XX::Port::P03
#define IOEX_BUTTON PI4IOE5V64XX::Port::P04

#define IOEX_LED_IR              PI4IOE5V64XX::Port::P05
#define IOEX_LED_FAULT           PI4IOE5V64XX::Port::P06
#define IOEX_LED_MIKONA_FULL     PI4IOE5V64XX::Port::P07
#define IOEX_LED_MIKONA_CHARGING PI4IOE5V64XX::Port::P10
#define IOEX_LED_WIFI_CONNECTED  PI4IOE5V64XX::Port::P11
#define IOEX_LED_WIFI_ACTIVITY   PI4IOE5V64XX::Port::P12
#define IOEX_LED_SWITCH          PI4IOE5V64XX::Port::P13

#define IOEX_ID_BIT_2 PI4IOE5V64XX::Port::P14
#define IOEX_ID_BIT_0 PI4IOE5V64XX::Port::P15
#define IOEX_ID_BIT_3 PI4IOE5V64XX::Port::P16
#define IOEX_ID_BIT_1 PI4IOE5V64XX::Port::P17


Ioex::Ioex(i2c_inst_t* const i2c)
    : m_i2c(i2c)
{
}

void Ioex::init()
{
    m_ioex = PI4IOE5V6416();

    if (m_ioex.attach(m_i2c))
    {
        printf("Connected to IOEX at address: 0x%x\n", m_ioex.getAddress());
    }
    else
    {
        printf("Failed to connect to IOEX at address: 0x%x\n", m_ioex.getAddress());
    }

    m_ioex.polarity(PI4IOE5V64XX::Polarity::ORIGINAL_ALL);

    m_ioex.direction(IOEX_DIP_3 , PI4IOE5V64XX::Direction::IN);
    m_ioex.direction(IOEX_DIP_2 , PI4IOE5V64XX::Direction::IN);
    m_ioex.direction(IOEX_DIP_1 , PI4IOE5V64XX::Direction::IN);
    m_ioex.direction(IOEX_DIP_0 , PI4IOE5V64XX::Direction::IN);
    m_ioex.direction(IOEX_BUTTON, PI4IOE5V64XX::Direction::IN);

    m_ioex.direction(IOEX_LED_FAULT          , PI4IOE5V64XX::Direction::OUT);
    m_ioex.direction(IOEX_LED_IR             , PI4IOE5V64XX::Direction::OUT);
    m_ioex.direction(IOEX_LED_MIKONA_CHARGING, PI4IOE5V64XX::Direction::OUT);
    m_ioex.direction(IOEX_LED_MIKONA_FULL    , PI4IOE5V64XX::Direction::OUT);
    m_ioex.direction(IOEX_LED_WIFI_ACTIVITY  , PI4IOE5V64XX::Direction::OUT);
    m_ioex.direction(IOEX_LED_WIFI_CONNECTED , PI4IOE5V64XX::Direction::OUT);
    m_ioex.direction(IOEX_LED_SWITCH         , PI4IOE5V64XX::Direction::OUT);

    m_ioex.direction(IOEX_ID_BIT_2, PI4IOE5V64XX::Direction::IN);
    m_ioex.direction(IOEX_ID_BIT_0, PI4IOE5V64XX::Direction::IN);
    m_ioex.direction(IOEX_ID_BIT_3, PI4IOE5V64XX::Direction::IN);
    m_ioex.direction(IOEX_ID_BIT_1, PI4IOE5V64XX::Direction::IN);

    m_ioex.pullUpDownEnable(IOEX_DIP_3   , PI4IOE5V64XX::PullUpDownEnable::ENABLE);
    m_ioex.pullUpDownEnable(IOEX_DIP_2   , PI4IOE5V64XX::PullUpDownEnable::ENABLE);
    m_ioex.pullUpDownEnable(IOEX_DIP_1   , PI4IOE5V64XX::PullUpDownEnable::ENABLE);
    m_ioex.pullUpDownEnable(IOEX_DIP_0   , PI4IOE5V64XX::PullUpDownEnable::ENABLE);
    m_ioex.pullUpDownEnable(IOEX_BUTTON  , PI4IOE5V64XX::PullUpDownEnable::ENABLE);
    m_ioex.pullUpDownEnable(IOEX_ID_BIT_2, PI4IOE5V64XX::PullUpDownEnable::ENABLE);
    m_ioex.pullUpDownEnable(IOEX_ID_BIT_0, PI4IOE5V64XX::PullUpDownEnable::ENABLE);
    m_ioex.pullUpDownEnable(IOEX_ID_BIT_3, PI4IOE5V64XX::PullUpDownEnable::ENABLE);
    m_ioex.pullUpDownEnable(IOEX_ID_BIT_1, PI4IOE5V64XX::PullUpDownEnable::ENABLE);

    m_ioex.pullUpDownSelection(IOEX_DIP_3   , PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    m_ioex.pullUpDownSelection(IOEX_DIP_2   , PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    m_ioex.pullUpDownSelection(IOEX_DIP_1   , PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    m_ioex.pullUpDownSelection(IOEX_DIP_0   , PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    m_ioex.pullUpDownSelection(IOEX_BUTTON  , PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    m_ioex.pullUpDownSelection(IOEX_ID_BIT_2, PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    m_ioex.pullUpDownSelection(IOEX_ID_BIT_0, PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    m_ioex.pullUpDownSelection(IOEX_ID_BIT_3, PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    m_ioex.pullUpDownSelection(IOEX_ID_BIT_1, PI4IOE5V64XX::PullUpDownSelection::PULL_UP);

    m_outputs = 0;
    m_ioex.write(m_outputs);
}

void Ioex::read()
{
    m_inputs = m_ioex.read();
}

void Ioex::write()
{
    m_ioex.write(m_outputs);
}

bool Ioex::getButton()
{
    return !get_bit(IOEX_BUTTON);
}

bool Ioex::getDip(const uint8_t index)
{
    switch(index)
    {
        case 1: return !get_bit(IOEX_DIP_0);
        case 2: return !get_bit(IOEX_DIP_1);
        case 3: return !get_bit(IOEX_DIP_2);
        case 4: return !get_bit(IOEX_DIP_3);
        default: return false;
    }
}

uint8_t Ioex::getId()
{
    return (!get_bit(IOEX_ID_BIT_3) << 3) |
           (!get_bit(IOEX_ID_BIT_2) << 2) |
           (!get_bit(IOEX_ID_BIT_1) << 1) |
           (!get_bit(IOEX_ID_BIT_0) << 0);
}

void Ioex::setLedFault(const bool enable)
{
    set_bit(IOEX_LED_FAULT, enable);
}

void Ioex::setLedIr(const bool enable)
{
    set_bit(IOEX_LED_IR, enable);
}

void Ioex::setLedMikona(const LedMikona led)
{
    set_bit(IOEX_LED_MIKONA_CHARGING, led == LedMikona::Charging);
    set_bit(IOEX_LED_MIKONA_FULL,     led == LedMikona::Done);
}

void Ioex::setLedWifi(const LedWifi led)
{
    set_bit(IOEX_LED_WIFI_CONNECTED, led == LedWifi::Connected);
    set_bit(IOEX_LED_WIFI_ACTIVITY,  led == LedWifi::Activity);
}

void Ioex::setLedSwitch(const LedSwitch led)
{
    set_bit(IOEX_LED_SWITCH, led == LedSwitch::Warning);
}
