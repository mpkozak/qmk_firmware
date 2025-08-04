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

// default options applied when eeprom is cleared
#define DEFAULT_FN_LAYER_TRANSPARENT_OFF 1             // default layer transparency
#define DEFAULT_FN_LAYER_SHOW_COLOR      1             // default show layer colors
#define DEFAULT_RGB_ENABLE_BASE          1             // default lighting state - base layer
#define RGB_MATRIX_DEFAULT_HUE           36            // default hue - base layer [warm white]
#define RGB_MATRIX_DEFAULT_SAT           159           // default saturation - base layer
#define RGB_MATRIX_DEFAULT_VAL           63            // default brightness
#define RGB_MATRIX_DEFAULT_SPD           0             // default effect speed
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR // default effect

// RGB setting change granularity
#define RGB_MATRIX_HUE_STEP 8       // units to step when in/decreasing hue
#define RGB_MATRIX_SAT_STEP 8       // units to step when in/decreasing saturation
#define RGB_MATRIX_VAL_STEP 8       // units to step when in/decreasing value (brightness)
#define RGB_MATRIX_SPD_STEP 8       // units to step when in/decreasing speed

// Dynamic Fn Layer RGB indicator options
#define SPD_LAYER_COLOR 0xFE, 0x11, 0x00   // layer 1; RGB orange
#define FN0_LAYER_COLOR 0x11, 0x01, 0xFE   // layer 2; RGB blue
#define FN1_LAYER_COLOR 0x01, 0xFE, 0x11   // layer 3; RGB green
#define FN2_LAYER_COLOR 0x01, 0xEE, 0xFE   // layer 4; RGB cyan

// Override + Disable LED current settings
#undef CKLED2001_CURRENT_TUNE
#undef SNLED27351_CURRENT_TUNE
// #define CKLED2001_CURRENT_TUNE { 0xFF, 0xFF, 0x70, 0xFF, 0xFF, 0x70, 0xFF, 0xFF, 0x70, 0xFF, 0xFF, 0x70 }    // q0
// #define CKLED2001_CURRENT_TUNE { 0xCA, 0xCA, 0x60, 0xCA, 0xCA, 0x60, 0xCA, 0xCA, 0x60, 0xCA, 0xCA, 0x60 }    // q2
// #define CKLED2001_CURRENT_TUNE { 0xD8, 0xD8, 0x60, 0xD8, 0xD8, 0x60, 0xD8, 0xD8, 0x60, 0xD8, 0xD8, 0x60 }    // q60

// Override + Disable RGB Matrix Animation modes
#undef ENABLE_RGB_MATRIX_BREATHING
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#undef ENABLE_RGB_MATRIX_CYCLE_ALL
#undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#undef ENABLE_RGB_MATRIX_DUAL_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#undef ENABLE_RGB_MATRIX_PIXEL_RAIN
#undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#undef ENABLE_RGB_MATRIX_SPLASH
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH
#undef RGB_MATRIX_KEYPRESSES
#undef RGB_MATRIX_FRAMEBUFFER_EFFECTS

// Disable DIP switch
#undef DIP_SWITCH_ENABLE

// Override Layer count
#undef DYNAMIC_KEYMAP_LAYER_COUNT
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

// Faster tap threshold
#define TAPPING_TERM 160
#undef PERMISSIVE_HOLD
#undef PREVENT_STUCK_MODIFIERS

// One-shot timeout
#define ONESHOT_TIMEOUT 500

// Disable Autocorrect at startup
#define AUTOCORRECT_OFF_AT_STARTUP

// Backlight timeout
#define RGB_MATRIX_TIMEOUT 150000  // 2.5 minutes
