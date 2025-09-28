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

/* Override info.json */
// #undef MANUFACTURER
// #define MANUFACTURER "kozak"
// #undef VENDOR_ID
// #define VENDOR_ID 0x4D4B
// #undef PRODUCT_ID
// #define PRODUCT_ID 0x0ADB

/* ADB port setting */
#define ADB_PORT        PORTD
#define ADB_PIN         PIND
#define ADB_DDR         DDRD
#define ADB_DATA_BIT    0
#define ADB_PSW_BIT     1       // optional

/* ADB handler callback interval (ms) */
#define ADB_INIT_CB_MS  60000   // 1 minute

/* Enable ADB logging to console */
// #define ADB_LOGGING

/* Enable ADB LED indicators */
// #define ADB_LED_INDICATORS

/* Map MCU LED pins */
#define RX_LED B0
#define TX_LED D5

/* Enable LED diagnostic blinking */
#define LED_DIAG_BLINK

/* Disable locking support */
// #undef LOCKING_SUPPORT_ENABLE
// #undef LOCKING_RESYNC_ENABLE

/* Enable locking speed layer toggle */
// #define LOCKING_SPEED_TOGGLE

/* Faster tap threshold */
#define TAPPING_TERM 175
#undef PERMISSIVE_HOLD
#undef PREVENT_STUCK_MODIFIERS

/* Enable per-key tap dance timing */
#define TAPPING_TERM_PER_KEY

/* One-shot timeout */
#define ONESHOT_TIMEOUT 175

/* Disable Autocorrect at startup */
#define AUTOCORRECT_OFF_AT_STARTUP
