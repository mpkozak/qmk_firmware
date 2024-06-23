
#pragma once



/* Define DIP switch pin assignments */
#define DIP_SWITCH_PINS { GP12, GP13, GP14, GP15, GP16 }

/* Compensate for lack of matrix diodes */
#define MATRIX_HAS_GHOST

/* Define MCU LED pin */
#define LED_PIN GP17

/* Enable LED power status */
#define LED_POWER_ON

/* Enable LED diagnostic blinking */
#define LED_DIAG_BLINK

/* Double tap reset button to enter bootloader */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
