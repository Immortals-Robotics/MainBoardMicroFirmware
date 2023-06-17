cmake_minimum_required(VERSION 3.13)

set(PROTOS_DIR "protos")
set(NANOPB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/nanopb")

macro(add_protobuf_generate_command PROTO_DEF PROTO_SRCS PROTO_HDRS)
  set(${PROTO_SRCS})
  set(${PROTO_HDRS})
  
  set(DEF_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${PROTOS_DIR})
  set(GEN_BASE_DIR ${CMAKE_CURRENT_BINARY_DIR}/${PROTOS_DIR})

  foreach(file ${${PROTO_DEF}})
      get_filename_component(FILE_ABS ${file} ABSOLUTE)  # Full path to file
      get_filename_component(FILE_WE  ${file} NAME_WE)   # File name with neither the directory nor the longest extension
      get_filename_component(FILE_DIR ${file} DIRECTORY) # Directory without file name

      file(RELATIVE_PATH FILE_REL     ${DEF_BASE_DIR} ${FILE_ABS})
      file(RELATIVE_PATH FILE_DIR_REL ${DEF_BASE_DIR} ${FILE_DIR})

      set(GEN_DIR "${GEN_BASE_DIR}/${FILE_DIR_REL}")
      set(GEN_FILE_HEADER "${GEN_DIR}/${FILE_WE}.pb.h")
      set(GEN_FILE_SOURCE "${GEN_DIR}/${FILE_WE}.pb.c")

      list(APPEND ${PROTO_SRCS} ${GEN_FILE_SOURCE})
      list(APPEND ${PROTO_HDRS} ${GEN_FILE_HEADER})

      add_custom_command(
        OUTPUT ${GEN_FILE_SOURCE}
               ${GEN_FILE_HEADER}
        COMMAND  ${NANOPB_DIR}/generator-bin/nanopb_generator.exe
        ARGS -I ${DEF_BASE_DIR} --output-dir=${GEN_BASE_DIR} ${FILE_REL} 
        DEPENDS ${FILE_ABS}
        COMMENT "Running nano protocol buffer compiler on ${FILE_REL}"
        VERBATIM )
  endforeach()
endmacro()

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

set(CMAKE_MODULE_PATH ${NANOPB_DIR}/extra)
find_package(Nanopb REQUIRED)
include_directories(${NANOPB_INCLUDE_DIRS})

add_subdirectory(${PROTOS_DIR})
add_protobuf_generate_command(NANO_PROTO_FILES PROTO_SRCS PROTO_HDRS)

add_executable(micro-firmware
  main.cpp
  ${PROTO_SRCS} ${PROTO_HDRS}
  ${NANOPB_DIR}/pb.h
  ${NANOPB_DIR}/pb_common.h
  ${NANOPB_DIR}/pb_common.c
  ${NANOPB_DIR}/pb_decode.h
  ${NANOPB_DIR}/pb_decode.c
  ${NANOPB_DIR}/pb_encode.h
  ${NANOPB_DIR}/pb_encode.c
)

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/${PROTOS_DIR}")
target_include_directories(${PROJECT_NAME} PRIVATE "${NANOPB_DIR}")

pico_enable_stdio_usb(micro-firmware 0)
pico_enable_stdio_uart(micro-firmware 1)

pico_add_extra_outputs(micro-firmware)

target_link_libraries(micro-firmware pico_stdlib hardware_spi)
