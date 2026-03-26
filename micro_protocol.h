#pragma once

#include <stdint.h>

#pragma pack(push, 1)

struct MicroCommand
{
    // bit 0: charge
    // bit 1: discharge
    // bit 2: wifi_connected
    // bit 3: wifi_activity
    // bit 4: fault
    // bit 5: buzzer
    uint8_t flags;

    uint32_t kick_a;
    uint32_t kick_b;
};

struct MicroStatus
{
    uint8_t robot_id;

    // bit 0-3: dip_switch 1-4
    // bit 4: button
    // bit 5: ball_detected
    uint8_t flags;

    // bit 0: connected
    // bit 1: charging
    // bit 2: discharging
    // bit 3: done
    // bit 4: fault
    uint8_t mikona_flags;

    float mikona_v_out;

    // bit 0: m1_status, bit 1: m1_fault
    // bit 2: m2_status, bit 3: m2_fault
    // bit 4: m3_status, bit 5: m3_fault
    // bit 6: m4_status, bit 7: m4_fault
    // bit 8: md_status, bit 9: md_fault
    uint16_t motor_flags;

    float power_5v_voltage;
    float power_5v_current;

    float power_24v_voltage;
    float power_24v_current;

    float power_elapsed;
    float power_5v_energy;
    float power_24v_energy;
};

#pragma pack(pop)

static_assert(sizeof(MicroCommand) == 9, "Unexpected MicroCommand size");
static_assert(sizeof(MicroStatus) == 37, "Unexpected MicroStatus size");
