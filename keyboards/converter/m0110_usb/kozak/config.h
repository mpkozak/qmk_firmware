/* Copyright 2023 @ M. Parker Kozak (https://github.com/mpkozak)
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

/* matrix size */
#define MATRIX_ROWS 14
#define MATRIX_COLS 8

/* Port setting */
#define M0110_CLOCK_PORT        PORTD
#define M0110_CLOCK_PIN         PIND
#define M0110_CLOCK_DDR         DDRD
#define M0110_CLOCK_BIT         1
#define M0110_DATA_PORT         PORTD
#define M0110_DATA_PIN          PIND
#define M0110_DATA_DDR          DDRD
#define M0110_DATA_BIT          0

/* Map MCU LED pins */
#define RX_LED B0
#define TX_LED D5

/* Enable LED power status */
#define LED_POWER_ON

/* Enable LED diagnostic blinking */
#define LED_DIAG_BLINK

/* Enable debug output */
// #define DEBUG_ENABLE

/* Enable locking speed layer toggle */
// #define LOCKING_SPEED_TOGGLE

/* Faster tap threshold */
// #define STRICT_LAYER_RELEASE    // breaks autocorrect(?)
