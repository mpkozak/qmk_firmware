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

#define EECONFIG_USER_DATA_SIZE 12  // size of eeprom data, do not change.

// default options applied when eeprom is cleared
#define DEFAULT_FN_LAYER_TRANSPARENT_OFF 0             // 1 = enable, 0 = disable
#define DEFAULT_FN_LAYER_SHOW_COLOR      1             // 1 = enable, 0 = disable
#define DEFAULT_RGB_ENABLE_BASE          1             // 1 = enable, 0 = disable
#define RGB_MATRIX_DEFAULT_HUE           36            // HSV warm white (Base layer)
#define RGB_MATRIX_DEFAULT_SAT           159           // HSV warm white (Base layer)
#define RGB_MATRIX_DEFAULT_VAL           255           // HSV warm white (Base layer)
#define RGB_MATRIX_DEFAULT_SPD           0             // Effect speed (Base layer)
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR // (Base layer)

// RGB setting change granularity
#define RGBLIGHT_HUE_STEP 8       // units to step when in/decreasing hue
#define RGBLIGHT_SAT_STEP 8       // units to step when in/decreasing saturation
#define RGBLIGHT_VAL_STEP 16      // units to step when in/decreasing value (brightness)

// Faster tap threshold
#define TAPPING_TERM 160
#define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD
#undef PREVENT_STUCK_MODIFIERS

// Autocorrect is on at start up. If you want Autocorrect to be off at startup,
// un-comment the following line
#define AUTOCORRECT_OFF_AT_STARTUP

// Dynamic Fn Layer RGB indicator options
#define SPD_LAYER_COLOR 0xFE, 0x23, 0x00   // layer 1; RGB orange
#define FN1_LAYER_COLOR 0x00, 0x00, 0xFF   // layer 2; RGB blue
#define FN2_LAYER_COLOR 0x00, 0xFF, 0x00   // layer 3; RGB green
#define FN3_LAYER_COLOR 0xFF, 0x00, 0x00   // layer 4; RGB red



// LED current settings
#undef CKLED2001_CURRENT_TUNE
// #define CKLED2001_CURRENT_TUNE { 0xFF, 0xFF, 0x70, 0xFF, 0xFF, 0x70, 0xFF, 0xFF, 0x70, 0xFF, 0xFF, 0x70 }    // q0
// #define CKLED2001_CURRENT_TUNE { 0xCA, 0xCA, 0x60, 0xCA, 0xCA, 0x60, 0xCA, 0xCA, 0x60, 0xCA, 0xCA, 0x60 }    // q2
// #define CKLED2001_CURRENT_TUNE { 0xD8, 0xD8, 0x60, 0xD8, 0xD8, 0x60, 0xD8, 0xD8, 0x60, 0xD8, 0xD8, 0x60 }    // q60
