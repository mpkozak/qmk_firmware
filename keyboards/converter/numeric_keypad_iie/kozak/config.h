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

/* Override keyboard.json */
// #undef MANUFACTURER
// #define MANUFACTURER "kozak"
// #undef VENDOR_ID
// #define VENDOR_ID 0x4D4B
// #undef PRODUCT_ID
// #define PRODUCT_ID 0x2003
// #undef MATRIX_ROW_PINS
// #define MATRIX_ROW_PINS { B1, B6, B2, B3 }
// #undef MATRIX_COL_PINS
// #define MATRIX_COL_PINS { B5, D4, D7, E6, B4, C6 }
// #undef DIODE_DIRECTION
// #define DIODE_DIRECTION COL2ROW

/* Compensate for lack of matrix diodes */
#define MATRIX_HAS_GHOST

/* Map MCU LED pins */
#define RX_LED B0
#define TX_LED D5

/* Enable LED diagnostic blinking */
#define LED_DIAG_BLINK

/* Faster tap threshold */
#define TAPPING_TERM 175
#undef PERMISSIVE_HOLD
#undef PREVENT_STUCK_MODIFIERS

/* One-shot timeout */
#define ONESHOT_TIMEOUT 175
