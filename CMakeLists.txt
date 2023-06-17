cmake_minimum_required(VERSION 3.13)

# initialize pico-sdk from submodule
# note: this must happen before project()
include(3rdparty/pico-sdk/pico_sdk_init.cmake)

project(micro-firmware C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_BOARD_HEADER_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
set(PICO_BOARD main-board)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_executable(micro-firmware
  main.cpp
)

pico_enable_stdio_usb(micro-firmware 0)
pico_enable_stdio_uart(micro-firmware 1)

pico_add_extra_outputs(micro-firmware)

target_link_libraries(micro-firmware pico_stdlib hardware_spi)
