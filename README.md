# MainBoardMicroFirmware
Main board firmware running on an RP2040 microcontroller.

## Prerequisites

- CMake 3.13+
- ARM GCC toolchain (`arm-none-eabi-gcc`)
- [Pico SDK](https://github.com/raspberrypi/pico-sdk) installed separately
- `PICO_SDK_PATH` environment variable pointing to the SDK:
  ```bash
  export PICO_SDK_PATH=/path/to/pico-sdk
  ```

## Building

```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
```

The build produces `micro-firmware.uf2` which can be flashed to the RP2040.

## Flashing

Hold the BOOTSEL button on the board while plugging in USB. The RP2040 will appear as a USB mass storage device. Copy the `.uf2` file to it:

```bash
cp micro-firmware.uf2 /media/$USER/RPI-RP2/
```
