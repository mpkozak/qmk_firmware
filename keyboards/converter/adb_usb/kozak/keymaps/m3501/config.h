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
#undef PRODUCT
#define PRODUCT "M3501"
#undef PRODUCT_ID
#define PRODUCT_ID 0x3501

/* ADB port setting */
#define ADB_PORT        PORTD
#define ADB_PIN         PIND
#define ADB_DDR         DDRD
#define ADB_DATA_BIT    0
#define ADB_PSW_BIT     1       // optional

/* Apple fn override */
// #undef VENDOR_ID
// #undef PRODUCT_ID
// #define VENDOR_ID  0x05AC // Apple
// #define PRODUCT_ID 0x0220 // Aluminum Keyboard (ANSI)


#undef AUTOCORRECT_OFF_AT_STARTUP
