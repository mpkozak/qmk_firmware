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

#define EECONFIG_USER_DATA_SIZE 15  // size of eeprom data, do not change.

// default options applied when eeprom is cleared
#define DEFAULT_FN_LAYER_TRANSPARENT_OFF 0             // default layer transparency
#define DEFAULT_FN_LAYER_SHOW_COLOR      1             // default show layer colors
#define DEFAULT_RGB_ENABLE_BASE          1             // default lighting state - base layer
#define RGB_MATRIX_DEFAULT_HUE           36            // default hue - base layer [warm white]
#define RGB_MATRIX_DEFAULT_SAT           159           // default saturation - base layer
#define RGB_MATRIX_DEFAULT_VAL           255           // default brightness
#define RGB_MATRIX_DEFAULT_SPD           0             // default effect speed
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR // default effect

// RGB setting change granularity
#define RGBLIGHT_HUE_STEP 8       // units to step when in/decreasing hue
#define RGBLIGHT_SAT_STEP 8       // units to step when in/decreasing saturation
#define RGBLIGHT_VAL_STEP 16      // units to step when in/decreasing value (brightness)

// Dynamic Fn Layer RGB indicator options
#define SPD_LAYER_COLOR 0xFE, 0x23, 0x00   // layer 1; RGB orange
// #define FN0_LAYER_COLOR 0xFF, 0x00, 0xFF   // layer 2; RGB magenta
#define FN0_LAYER_COLOR 0x00, 0xFF, 0xFF   // layer 2; RGB cyan
#define FN1_LAYER_COLOR 0x00, 0x00, 0xFF   // layer 3; RGB blue
#define FN2_LAYER_COLOR 0x00, 0xFF, 0x00   // layer 4; RGB green
#define FN3_LAYER_COLOR 0xFF, 0x00, 0x00   // layer 5; RGB red

// Override + Disable LED current settings
#undef CKLED2001_CURRENT_TUNE
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

// Faster tap threshold
#define TAPPING_TERM 160
#define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD
#undef PREVENT_STUCK_MODIFIERS

// Autocorrect is on at start up. If you want Autocorrect to be off at startup,
// un-comment the following line
#define AUTOCORRECT_OFF_AT_STARTUP
