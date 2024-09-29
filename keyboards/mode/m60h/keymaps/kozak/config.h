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

// Set default RGB Light mode
#undef RGBLIGHT_DEFAULT_MODE
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT

// config layer lights
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_RETAIN_VAL

// default options applied when eeprom is cleared
#define RGBLIGHT_DEFAULT_HUE           36            // default hue - base layer [warm white]
#define RGBLIGHT_DEFAULT_SAT           159           // default saturation - base layer
#define RGBLIGHT_DEFAULT_VAL           47            // default brightness
#define RGBLIGHT_DEFAULT_SPD           0             // default effect speed
#define RGBLIGHT_DEFAULT_ON            true

// RGB setting change granularity
#define RGBLIGHT_HUE_STEP 8       // units to step when in/decreasing hue
#define RGBLIGHT_SAT_STEP 8       // units to step when in/decreasing saturation
#define RGBLIGHT_VAL_STEP 8       // units to step when in/decreasing value (brightness)

// // Dynamic Fn Layer RGB indicator options
// #define SPD_LAYER_COLOR 0xFE, 0x11, 0x00   // layer 1; RGB orange
// #define FN0_LAYER_COLOR 0x11, 0x01, 0xFE   // layer 2; RGB blue
// #define FN1_LAYER_COLOR 0x01, 0xFE, 0x11   // layer 3; RGB green

// Dynamic Fn Layer RGB indicator options
#define BASE_LAYER_HSV 36,  159, 47    // layer 0; HSV white
#define SPD_LAYER_HSV  3,   252, 47    // layer 1; HSV orange
#define FN0_LAYER_HSV  173, 252, 47    // layer 2; HSV blue
#define FN1_LAYER_HSV  88,  252, 47    // layer 3; HSV green

// Override + Disable RGB Light Animation modes
#undef RGBLIGHT_ANIMATIONS
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_BREATHING
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_TWINKLE

// Override Layer count
#undef DYNAMIC_KEYMAP_LAYER_COUNT
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

// // Override Macro count
// #undef DYNAMIC_KEYMAP_MACRO_COUNT
// #define DYNAMIC_KEYMAP_MACRO_COUNT 0

// Faster tap threshold
#define TAPPING_TERM 160
#undef PERMISSIVE_HOLD
#undef PREVENT_STUCK_MODIFIERS

// One-shot timeout
#define ONESHOT_TIMEOUT 500

// Disable Autocorrect at startup
#define AUTOCORRECT_OFF_AT_STARTUP

// RBG Light Sleep
#define RGBLIGHT_SLEEP              // enable rgblight_suspend() and rgblight_wakeup() in keymap.c
#define RGBLIGHT_TIMEOUT 150000     // 2.5 minutes
