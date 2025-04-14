/* Copyright 2024 @ M. Parker Kozak (https://github.com/mpkozak)
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
#define PRODUCT_ID 0x0ADB

/* ADB port setting */
#define ADB_PORT        PORTD
#define ADB_PIN         PIND
#define ADB_DDR         DDRD
#define ADB_DATA_BIT    0
#define ADB_PSW_BIT     1       // optional

/* ADB handler callback interval (ms) */
#define ADB_INIT_CB_MS  60000   // 1 minute

/* Map MCU LED pins */
#define RX_LED B0
#define TX_LED D5

/* Enable LED diagnostic blinking */
#define LED_DIAG_BLINK

/* Enable ADB logging to console */
// #define ADB_LOGGING

/* Faster tap threshold */
#define TAPPING_TERM 175
#undef PERMISSIVE_HOLD
#undef PREVENT_STUCK_MODIFIERS

/* One-shot timeout */
#define ONESHOT_TIMEOUT 175

/* Disable Autocorrect at startup */
#define AUTOCORRECT_OFF_AT_STARTUP





/* MCU onboard leds */
// #define TX_RX_LED_INIT  DDRD |= (1<<5), DDRB |= (1<<0)
// #define TXLED0          PORTD |= (1<<5)
// #define TXLED1          PORTD &= ~(1<<5)
// #define RXLED0          PORTB |= (1<<0)
// #define RXLED1          PORTB &= ~(1<<0)

/* Apple fn override */
// #undef VENDOR_ID
// #undef PRODUCT_ID
// #define VENDOR_ID  0x05AC // Apple
// #define PRODUCT_ID 0x0220 // Aluminum Keyboard (ANSI)
