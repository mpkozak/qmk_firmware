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

#include QMK_KEYBOARD_H
#include "keychron_common.h"
#include "rgb_matrix_user.h"
#include "keymap_user.h"

// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     uint8_t current_layer = get_highest_layer(layer_state);
//     uint8_t current_val = rgb_matrix_get_val();
//     HSV hsv = {0, 255, current_val};
//     switch(current_layer) {
//         case BASE:
//             hsv.h = RGB_MATRIX_DEFAULT_HUE;
//             hsv.s = RGB_MATRIX_DEFAULT_SAT;
//             break;
//         case BASE_SPD:
//             hsv.h = SPD_LAYER_HUE;
//             break;
//         case BASE_FN:
//             hsv.h = FN0_LAYER_HUE;
//             break;
//         case _FN1:
//             hsv.h = FN1_LAYER_HUE;
//             break;
//         case _FN2:
//             hsv.h = FN2_LAYER_HUE;
//             break;
//         case _FN3:
//             hsv.h = FN3_LAYER_HUE;
//             break;
//         default:
//             break;
//     }
//     hsv.v = current_val;
//     rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, hsv.v);
//     return false;
// }

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t current_layer = get_highest_layer(layer_state);
    uint8_t current_val = rgb_matrix_get_val();
    switch(current_layer) {
        case BASE:
            rgb_matrix_sethsv_noeeprom(RGB_MATRIX_DEFAULT_HUE, RGB_MATRIX_DEFAULT_SAT, current_val);
            break;
        case BASE_SPD:
            rgb_set_at_brightness(current_val, SPD_LAYER_COLOR);
            break;
        case BASE_FN:
            rgb_set_at_brightness(current_val, FN0_LAYER_COLOR);
            break;
        case _FN1:
            rgb_set_at_brightness(current_val, FN1_LAYER_COLOR);
            break;
        case _FN2:
            rgb_set_at_brightness(current_val, FN2_LAYER_COLOR);
            break;
        case _FN3:
            rgb_set_at_brightness(current_val, FN3_LAYER_COLOR);
            break;
        default:
            break;
    }
    return false;
}

// RGB rgb_scaled_to_val(uint8_t val, uint8_t red, uint8_t green, uint8_t blue) {
//     float value = val;
//     RGB rgb;
//     rgb.r = red * (value / 255);
//     rgb.g = green * (value / 255);
//     rgb.b = blue * (value / 255);
//     return rgb;
// }

void rgb_set_at_brightness(uint8_t val, uint8_t red, uint8_t green, uint8_t blue) {
    float value = val;
    int8_t r = red * (value / 255);
    int8_t g = green * (value / 255);
    int8_t b = blue * (value / 255);
    rgb_matrix_set_color_all(r, g, b);
}
