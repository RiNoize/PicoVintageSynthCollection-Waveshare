// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2026 Michi71

// project_config.h - Waveshare RP2350-LCD-1.47-A hardware map for this fork.
#ifndef __PROJECT_CONFIG_H__
#define __PROJECT_CONFIG_H__

// Fix 01 is deliberately headless. The onboard LCD will be added next.
#define PICOFACE_HEADLESS 1

// DIN MIDI on uart1. GP5 receives the H11L1 MIDI-IN output.
#define PIN_MIDI_RX 5
#define PIN_MIDI_TX 4

// I2S -> PCM5102
#define PIN_I2S_DOUT  26
#define PIN_I2S_BCK   27
#define PIN_I2S_WS    28

// Kept only so the existing u8g2 callbacks compile. In headless mode the
// callback does not initialise I2C, therefore GP2/GP3 remain encoder pins.
#define PIN_OLED_SDA  2
#define PIN_OLED_SCL  3

// Analogue potentiometer
#define PIN_POT_1     29

// Encoder 1 - Selector
#define PIN_SEL_CLK   6
#define PIN_SEL_DT    7
#define PIN_SEL_SW    8

// Encoder 2 - Param A
#define PIN_PA_CLK    2
#define PIN_PA_DT     3
#define PIN_PA_SW     0

// Encoder 3 - Param B
#define PIN_PB_CLK    9
#define PIN_PB_DT     25
#define PIN_PB_SW     1

// Board-internal GPIOs intentionally left untouched:
// GP10..15 = microSD, GP16..21 = LCD, GP22 = onboard RGB LED.

// QMI M0_TIMING values. Bit layout (see hardware/regs/qmi.h):
//   CLKDIV  [7:0]   flash clock = clk_sys / CLKDIV
//   RXDELAY [10:8]  read data sample point, in clk_sys cycles
// The upper bits (COOLDOWN=1, PAGEBREAK=2, MIN_DESELECT=7) are identical in
// all three values below; only CLKDIV and RXDELAY differ.
// Set BEFORE the clk_sys change, and left in place if the change fails.
// CLKDIV=8, RXDELAY=2 -- deliberately slack during the clock switch.
#define PICOFACE_QMI_M0_TIMING_SAFE 0x60007208u

// Waveshare bring-up: 444 MHz / CLKDIV=4 = 111 MHz flash.
// This is deliberately more conservative than the upstream reference board's
// 148 MHz flash clock. Once the board is proven stable, CLKDIV=3 can be tested.
#define PICOFACE_QMI_M0_TIMING_OC 0x60007304u

// 480 MHz target used by PicoFaceRD: CLKDIV=4, RXDELAY=3 -> 120 MHz flash.
#define PICOFACE_QMI_M0_TIMING_RD 0x60007304u

#endif // __PROJECT_CONFIG_H__
