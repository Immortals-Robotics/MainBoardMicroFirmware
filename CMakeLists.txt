cmake_minimum_required(VERSION 3.13)

set(PI4IOE5V6416_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/PI4IOE5V6416")
set(PAC194X_5X_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/PAC194x_5x")

set(PICO_BOARD_HEADER_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
set(PICO_BOARD main-board)

# initialize pico-sdk from PICO_SDK_PATH
# note: this must happen before project()
include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

project(micro-firmware C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_executable(micro-firmware
  ball-detector.h
  ball-detector.cpp
  ioex.h
  ioex.cpp
  mikona.h
  mikona.cpp
  power_monitor.h
  power_monitor.cpp
  protocol.h
  protocol.cpp
  micro_protocol.h

  main.cpp

  ${PAC194X_5X_DIR}/PAC194x_5x.c
  ${PAC194X_5X_DIR}/PAC194x_5x.h
  ${PAC194X_5X_DIR}/PAC194x_5x_definitions.h
  ${PAC194X_5X_DIR}/PAC194x_5x_i2c.h
  ${PAC194X_5X_DIR}/PAC194x_5x_mutex.h
  ${PI4IOE5V6416_DIR}/PI4IOE5V6416.h
)

pico_enable_stdio_usb(micro-firmware 0)
pico_enable_stdio_uart(micro-firmware 1)

pico_add_extra_outputs(micro-firmware)

target_link_libraries(micro-firmware
  pico_stdlib
  pico_multicore
  hardware_spi
  hardware_i2c
  hardware_pwm
  hardware_adc)
