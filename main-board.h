// Based on https://github.com/raspberrypi/pico-sdk/blob/master/src/boards/include/boards/pico.h
// Pins are from main-board/micro schematics

#ifndef _MAIN_BOARD_H
#define _MAIN_BOARD_H

// --- UART ---
#ifndef MAIN_BOARD_UART
#define MAIN_BOARD_UART 0
#endif
#ifndef MAIN_BOARD_UART_TX_PIN
#define MAIN_BOARD_UART_TX_PIN 0
#endif
#ifndef MAIN_BOARD_UART_RX_PIN
#define MAIN_BOARD_UART_RX_PIN 1
#endif

// --- LED ---
#ifndef MAIN_BOARD_LED_PIN
#define MAIN_BOARD_LED_PIN 25
#endif

// --- BUZZER ---
#ifndef MAIN_BOARD_BUZZER_PIN
#define MAIN_BOARD_BUZZER_PIN 22
#endif

// --- I2C ---
#ifndef MAIN_BOARD_I2C_0
#define MAIN_BOARD_I2C_0 0
#endif
#ifndef MAIN_BOARD_I2C_0_SDA_PIN
#define MAIN_BOARD_I2C_0_SDA_PIN 4
#endif
#ifndef MAIN_BOARD_I2C_0_SCL_PIN
#define MAIN_BOARD_I2C_0_SCL_PIN 5
#endif

#ifndef MAIN_BOARD_I2C_1
#define MAIN_BOARD_I2C_1 1
#endif
#ifndef MAIN_BOARD_I2C_1_SDA_PIN
#define MAIN_BOARD_I2C_1_SDA_PIN 2
#endif
#ifndef MAIN_BOARD_I2C_1_SCL_PIN
#define MAIN_BOARD_I2C_1_SCL_PIN 3
#endif

// --- SPI ---
#ifndef MAIN_BOARD_SPI
#define MAIN_BOARD_SPI 0
#endif
#ifndef MAIN_BOARD_SPI_SCK_PIN
#define MAIN_BOARD_SPI_SCK_PIN 18
#endif
#ifndef MAIN_BOARD_SPI_TX_PIN
#define MAIN_BOARD_SPI_TX_PIN 19
#endif
#ifndef MAIN_BOARD_SPI_RX_PIN
#define MAIN_BOARD_SPI_RX_PIN 16
#endif
#ifndef MAIN_BOARD_SPI_CSN_PIN
#define MAIN_BOARD_SPI_CSN_PIN 17
#endif

// --- IR ---
#ifndef MAIN_BOARD_IR_PWM_PIN
#define MAIN_BOARD_IR_PWM_PIN 28
#endif
#ifndef MAIN_BOARD_IR_ADC_PIN
#define MAIN_BOARD_IR_ADC_PIN 29
#endif

// --- MOTORS ---
#ifndef MAIN_BOARD_M1_CTRL_STATUS_PIN
#define MAIN_BOARD_M1_CTRL_STATUS_PIN 8
#endif
#ifndef MAIN_BOARD_M1_DRV_FAULT_PIN
#define MAIN_BOARD_M1_DRV_FAULT_PIN 9
#endif

#ifndef MAIN_BOARD_M2_CTRL_STATUS_PIN
#define MAIN_BOARD_M2_CTRL_STATUS_PIN 26
#endif
#ifndef MAIN_BOARD_M2_DRV_FAULT_PIN
#define MAIN_BOARD_M2_DRV_FAULT_PIN 27
#endif

#ifndef MAIN_BOARD_M3_CTRL_STATUS_PIN
#define MAIN_BOARD_M3_CTRL_STATUS_PIN 23
#endif
#ifndef MAIN_BOARD_M3_DRV_FAULT_PIN
#define MAIN_BOARD_M3_DRV_FAULT_PIN 24
#endif

#ifndef MAIN_BOARD_M4_CTRL_STATUS_PIN
#define MAIN_BOARD_M4_CTRL_STATUS_PIN 10
#endif
#ifndef MAIN_BOARD_M4_DRV_FAULT_PIN
#define MAIN_BOARD_M4_DRV_FAULT_PIN 11
#endif

#ifndef MAIN_BOARD_MD_CTRL_STATUS_PIN
#define MAIN_BOARD_MD_CTRL_STATUS_PIN 7
#endif
#ifndef MAIN_BOARD_MD_DRV_FAULT_PIN
#define MAIN_BOARD_MD_DRV_FAULT_PIN 6
#endif

// --- INTERRUPTS ---
#ifndef MAIN_BOARD_INT_IO_PIN
#define MAIN_BOARD_INT_IO_PIN 12
#endif

#ifndef MAIN_BOARD_INT_CM_PIN
#define MAIN_BOARD_INT_CM_PIN 20
#endif

// --- FLASH ---
// Taken directly from pico configs as we use the same chip
#define PICO_BOOT_STAGE2_CHOOSE_W25Q080 1

#ifndef PICO_FLASH_SPI_CLKDIV
#define PICO_FLASH_SPI_CLKDIV 2
#endif

#ifndef PICO_FLASH_SIZE_BYTES
#define PICO_FLASH_SIZE_BYTES (2 * 1024 * 1024)
#endif

// --- PICO ---
// Map our configs to pico-sdk

#ifndef PICO_DEFAULT_SPI
#define PICO_DEFAULT_SPI MAIN_BOARD_SPI
#endif

#endif
