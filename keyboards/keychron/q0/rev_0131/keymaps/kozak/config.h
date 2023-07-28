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

#define EECONFIG_USER_DATA_SIZE 3  // size of eeprom data, do not change.

// default options applied when eeprom is cleared
#define DEFAULT_FN_LAYER_TRANSPARENT_OFF 1             // default layer transparency
#define DEFAULT_FN_LAYER_SHOW_COLOR      1             // default show layer colors
#define DEFAULT_RGB_ENABLE_BASE          1             // default lighting state - base layer
#define RGB_MATRIX_DEFAULT_HUE           36            // default hue - base layer [warm white]
#define RGB_MATRIX_DEFAULT_SAT           159           // default saturation - base layer
#define RGB_MATRIX_DEFAULT_VAL           127           // default brightness
#define RGB_MATRIX_DEFAULT_SPD           0             // default effect speed
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR // default effect

// RGB setting change granularity
#define RGB_MATRIX_HUE_STEP 8       // units to step when in/decreasing hue
#define RGB_MATRIX_SAT_STEP 8       // units to step when in/decreasing saturation
#define RGB_MATRIX_VAL_STEP 8       // units to step when in/decreasing value (brightness)
#define RGB_MATRIX_SPD_STEP 8       // units to step when in/decreasing speed

// Dynamic Fn Layer RGB indicator options
#define CALC_LAYER_COLOR 0xFE, 0x11, 0x00  // layer 1; RGB orange
#define FN0_LAYER_COLOR 0x01, 0xEE, 0xFE   // layer 2; RGB cyan
#define FN1_LAYER_COLOR 0x11, 0x01, 0xFE   // layer 3; RGB blue
#define FN2_LAYER_COLOR 0x01, 0xFE, 0x11   // layer 4; RGB green
#define FN3_LAYER_COLOR 0xFE, 0xE4, 0x01   // layer 5; RGB yellow

// Override + Disable LED current settings
#undef CKLED2001_CURRENT_TUNE
// #define CKLED2001_CURRENT_TUNE { 0xFF, 0xFF, 0x70, 0xFF, 0xFF, 0x70, 0xFF, 0xFF, 0x70, 0xFF, 0xFF, 0x70 }    // q0
// #define CKLED2001_CURRENT_TUNE { 0xCA, 0xCA, 0x60, 0xCA, 0xCA, 0x60, 0xCA, 0xCA, 0x60, 0xCA, 0xCA, 0x60 }    // q2
// #define CKLED2001_CURRENT_TUNE { 0xD8, 0xD8, 0x60, 0xD8, 0xD8, 0x60, 0xD8, 0xD8, 0x60, 0xD8, 0xD8, 0x60 }    // q60

// Override + Disable RGB Matrix Animation modes
#undef RGB_MATRIX_KEYPRESSES
#undef RGB_MATRIX_FRAMEBUFFER_EFFECTS

// Disable num lock led
#undef NUM_LOCK_LED_INDEX

// Layer count
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

// Faster tap threshold
#define TAPPING_TERM 160
#undef PERMISSIVE_HOLD
#undef PREVENT_STUCK_MODIFIERS

// One-shot timeout
#define ONESHOT_TIMEOUT 500

// Backlight timeout
#define RGB_MATRIX_TIMEOUT 300000  // 5 minutes
