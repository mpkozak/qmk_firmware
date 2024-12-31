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

/* Override info.json */
#undef MANUFACTURER
#define MANUFACTURER "kozak"
#undef VENDOR_ID
#define VENDOR_ID 0x4D4B
#undef PRODUCT_ID
#define PRODUCT_ID 0x0110

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

/* Enable LED diagnostic blinking */
#define LED_DIAG_BLINK

/* Faster tap threshold */
#define TAPPING_TERM 175
#undef PERMISSIVE_HOLD
#undef PREVENT_STUCK_MODIFIERS

/* One-shot timeout */
#define ONESHOT_TIMEOUT 175

/* Disable Autocorrect at startup */
#define AUTOCORRECT_OFF_AT_STARTUP
