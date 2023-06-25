#pragma once

#include <stdint.h>

#include <pico/critical_section.h>

#include "immortals/micro.pb.h"

class Protocol
{
public:
    Protocol() = default;

    void init();

    bool fill_tx_buffer(const Immortals_Protos_MicroStatus& message);
    bool consume_rx_buffer(Immortals_Protos_MicroCommand* const message);

    bool rx_data_available() const { return m_rx_data_available;}

    bool transceive_blocking();

private:
    static constexpr unsigned int kSpiFreq = 4 * 1000 * 1000;
    static constexpr size_t  kBufferLen = 128;

    static_assert(Immortals_Protos_MicroCommand_size < kBufferLen, "Buffer too small");
    static_assert(Immortals_Protos_MicroStatus_size < kBufferLen, "Buffer too small");

    uint8_t m_tx_buffer[2][kBufferLen] = {};
    uint8_t m_rx_buffer[2][kBufferLen] = {};

    // Support for double buffering
    size_t m_buffer_index = 0;

    bool m_rx_data_available = false;

    critical_section_t m_criticalSection;

    void setLed(bool enable);
    void toggleLed();
};
