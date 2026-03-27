**This repo has been merged into [the main firmware repo](https://github.com/Immortals-Robotics/MainBoardFirmware).**

---

# MainBoardMicroFirmware
Main board firmware running on an RP2040 microcontroller.

## Prerequisites

Install dependencies:

```bash
sudo apt install cmake python3 build-essential gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib openocd tio
```

Clone the [Pico SDK](https://github.com/raspberrypi/pico-sdk) and point `PICO_SDK_PATH` to it:

```bash
git clone https://github.com/raspberrypi/pico-sdk /path/to/pico-sdk
export PICO_SDK_PATH=/path/to/pico-sdk
```

## Building

```bash
cmake --preset debug    # or release
cmake --build --preset debug
```

Build output is placed in `out/`. The main artifact is `out/micro-firmware.elf`.

## Flashing

Flashing is done via SWD using OpenOCD. This also resets the chip immediately after flashing:

```bash
openocd -f interface/raspberrypi-swd.cfg -f target/rp2040.cfg \
  -c 'program out/micro-firmware.elf verify reset exit'
```

## Serial Monitor

```bash
tio -b 115200 /dev/serial0
```

`tio` automatically reconnects when the chip resets or is reflashed.

## Zed Tasks

If using [Zed](https://zed.dev), the following tasks are available via the command palette (`task: spawn`):

| Task | Description |
|---|---|
| `Flash` | Flash via SWD and reset |
| `Reset` | Reset the chip via SWD |
| `Monitor` | Open serial monitor in a dedicated terminal tab |
