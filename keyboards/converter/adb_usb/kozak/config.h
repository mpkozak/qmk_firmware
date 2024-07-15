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

/* Override Layer count */
#undef DYNAMIC_KEYMAP_LAYER_COUNT
#define DYNAMIC_KEYMAP_LAYER_COUNT

/* Faster tap threshold */
#define TAPPING_TERM 175
#undef PERMISSIVE_HOLD
#undef PREVENT_STUCK_MODIFIERS

/* One-shot timeout */
#define ONESHOT_TIMEOUT 175

/* Disable Autocorrect at startup */
#define AUTOCORRECT_OFF_AT_STARTUP
