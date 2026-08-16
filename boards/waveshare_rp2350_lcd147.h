/*
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Pico SDK board definition for Waveshare RP2350-LCD-1.47-A.
 * The onboard LCD and microSD are handled by the application, not here.
 */
#ifndef _BOARDS_WAVESHARE_RP2350_LCD147_H
#define _BOARDS_WAVESHARE_RP2350_LCD147_H

pico_board_cmake_set(PICO_PLATFORM, rp2350)

#define WAVESHARE_RP2350_LCD147
#define PICO_RP2350A 1

#ifndef PICO_DEFAULT_UART
#define PICO_DEFAULT_UART 0
#endif
#ifndef PICO_DEFAULT_UART_TX_PIN
#define PICO_DEFAULT_UART_TX_PIN 0
#endif
#ifndef PICO_DEFAULT_UART_RX_PIN
#define PICO_DEFAULT_UART_RX_PIN 1
#endif

// 16 MB external QSPI NOR flash.
#define PICO_BOOT_STAGE2_CHOOSE_W25Q080 1
#ifndef PICO_FLASH_SPI_CLKDIV
#define PICO_FLASH_SPI_CLKDIV 2
#endif
pico_board_cmake_set_default(PICO_FLASH_SIZE_BYTES, (16 * 1024 * 1024))
#ifndef PICO_FLASH_SIZE_BYTES
#define PICO_FLASH_SIZE_BYTES (16 * 1024 * 1024)
#endif

pico_board_cmake_set_default(PICO_RP2350_A2_SUPPORTED, 1)
#ifndef PICO_RP2350_A2_SUPPORTED
#define PICO_RP2350_A2_SUPPORTED 1
#endif

#endif
