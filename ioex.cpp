#include "ioex.h"

#define IOEX_DIP_3 PI4IOE5V64XX::Port::P00
#define IOEX_DIP_2 PI4IOE5V64XX::Port::P01
#define IOEX_DIP_1 PI4IOE5V64XX::Port::P02
#define IOEX_DIP_0 PI4IOE5V64XX::Port::P03
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

void Ioex::init(i2c_inst_t* i2c)
{
    m_ioex = PI4IOE5V6416();
    m_ioex.attach(i2c);

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

    m_ioex.pullUpDownEnable(IOEX_DIP_3   );
    m_ioex.pullUpDownEnable(IOEX_DIP_2   );
    m_ioex.pullUpDownEnable(IOEX_DIP_1   );
    m_ioex.pullUpDownEnable(IOEX_DIP_0   );
    m_ioex.pullUpDownEnable(IOEX_BUTTON  );
    m_ioex.pullUpDownEnable(IOEX_ID_BIT_2);
    m_ioex.pullUpDownEnable(IOEX_ID_BIT_0);
    m_ioex.pullUpDownEnable(IOEX_ID_BIT_3);
    m_ioex.pullUpDownEnable(IOEX_ID_BIT_1);

    m_ioex.pullUpDownSelection(IOEX_DIP_3   , PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    m_ioex.pullUpDownSelection(IOEX_DIP_2   , PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    m_ioex.pullUpDownSelection(IOEX_DIP_1   , PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    m_ioex.pullUpDownSelection(IOEX_DIP_0   , PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    m_ioex.pullUpDownSelection(IOEX_BUTTON  , PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    m_ioex.pullUpDownSelection(IOEX_ID_BIT_2, PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    m_ioex.pullUpDownSelection(IOEX_ID_BIT_0, PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    m_ioex.pullUpDownSelection(IOEX_ID_BIT_3, PI4IOE5V64XX::PullUpDownSelection::PULL_UP);
    m_ioex.pullUpDownSelection(IOEX_ID_BIT_1, PI4IOE5V64XX::PullUpDownSelection::PULL_UP);

    m_ioex.write(IOEX_LED_FAULT          , PI4IOE5V64XX::Level::L);
    m_ioex.write(IOEX_LED_IR             , PI4IOE5V64XX::Level::L);
    m_ioex.write(IOEX_LED_MIKONA_CHARGING, PI4IOE5V64XX::Level::L);
    m_ioex.write(IOEX_LED_MIKONA_FULL    , PI4IOE5V64XX::Level::L);
    m_ioex.write(IOEX_LED_WIFI_ACTIVITY  , PI4IOE5V64XX::Level::L);
    m_ioex.write(IOEX_LED_WIFI_CONNECTED , PI4IOE5V64XX::Level::L);
    m_ioex.write(IOEX_LED_SWITCH         , PI4IOE5V64XX::Level::L);
}

bool Ioex::getButton()
{
    return m_ioex.read(IOEX_BUTTON) == PI4IOE5V64XX::Level::L;
}

bool Ioex::getDip(const uint8_t index)
{
    switch(index)
    {
        case 1: return m_ioex.read(IOEX_DIP_0) == PI4IOE5V64XX::Level::L;
        case 2: return m_ioex.read(IOEX_DIP_1) == PI4IOE5V64XX::Level::L;
        case 3: return m_ioex.read(IOEX_DIP_2) == PI4IOE5V64XX::Level::L;
        case 4: return m_ioex.read(IOEX_DIP_3) == PI4IOE5V64XX::Level::L;
        default: return false;
    }
}

uint8_t Ioex::getId()
{
    return ((m_ioex.read(IOEX_ID_BIT_3) == PI4IOE5V64XX::Level::L) << 3) |
           ((m_ioex.read(IOEX_ID_BIT_2) == PI4IOE5V64XX::Level::L) << 2) |
           ((m_ioex.read(IOEX_ID_BIT_1) == PI4IOE5V64XX::Level::L) << 1) |
           ((m_ioex.read(IOEX_ID_BIT_0) == PI4IOE5V64XX::Level::L) << 0);
}

void Ioex::setLedFault(const bool enable)
{
    m_ioex.write(IOEX_LED_FAULT, enable ? PI4IOE5V64XX::Level::H : PI4IOE5V64XX::Level::L);
}

void Ioex::setLedIr(const bool enable)
{
    m_ioex.write(IOEX_LED_IR, enable ? PI4IOE5V64XX::Level::H : PI4IOE5V64XX::Level::L);
}

void Ioex::setLedMikona(const LedMikona led)
{
    m_ioex.write(IOEX_LED_MIKONA_CHARGING, led == LedMikona::Charging ? PI4IOE5V64XX::Level::H : PI4IOE5V64XX::Level::L);
    m_ioex.write(IOEX_LED_MIKONA_FULL,     led == LedMikona::Done     ? PI4IOE5V64XX::Level::H : PI4IOE5V64XX::Level::L);
}

void Ioex::setLedWifi(const LedWifi led)
{
    m_ioex.write(IOEX_LED_WIFI_CONNECTED, led == LedWifi::Connected ? PI4IOE5V64XX::Level::H : PI4IOE5V64XX::Level::L);
    m_ioex.write(IOEX_LED_WIFI_ACTIVITY,  led == LedWifi::Activity  ? PI4IOE5V64XX::Level::H : PI4IOE5V64XX::Level::L);
}

void Ioex::setLedSwitch(const LedSwitch led)
{
    m_ioex.write(IOEX_LED_SWITCH, led == LedSwitch::Warning ? PI4IOE5V64XX::Level::H : PI4IOE5V64XX::Level::L);
}
