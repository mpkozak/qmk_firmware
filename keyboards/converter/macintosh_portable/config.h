/* Copyright 2025 @ M. Parker Kozak (https://github.com/mpkozak)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* Double tap reset button to enter bootloader */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

/* Map MCU LED pins */
#define LED_PIN GP17

/* Enable LED power status */
#define LED_POWER_ON

/* Enable LED diagnostic blinking */
#define LED_DIAG_BLINK

/* Enable LED layer status */
// #define LED_LAYER_STATUS

/* Enable debug output */
// #define DEBUG_ENABLE

/* Specify which shift key mapping to use */
// #define DIP_KEYMAP_USE_RIGHT_SHIFT

/* Disable locking support */
// #undef LOCKING_SUPPORT_ENABLE
// #undef LOCKING_RESYNC_ENABLE

/* Enable locking speed layer toggle */
// #define LOCKING_SPEED_TOGGLE

/* Faster tap threshold */
// #define STRICT_LAYER_RELEASE    // breaks autocorrect(?)

/* Disable Autocorrect at startup */
#define AUTOCORRECT_OFF_AT_STARTUP
