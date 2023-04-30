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

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t current_layer = get_highest_layer(layer_state);
    uint8_t current_val = rgb_matrix_get_val();
    HSV hsv = {RGB_MATRIX_DEFAULT_HUE, RGB_MATRIX_DEFAULT_SAT, current_val};
    RGB rgb = hsv_to_rgb(hsv);
    switch(current_layer) {
        case BASE:
            break;
        case BASE_SPD:
            rgb = rgb_scaled_to_val(current_val, SPD_LAYER_COLOR);
            break;
        case BASE_FN:
            rgb = rgb_scaled_to_val(current_val, FN0_LAYER_COLOR);
            break;
        case _FN1:
            rgb = rgb_scaled_to_val(current_val, FN1_LAYER_COLOR);
            break;
        case _FN2:
            rgb = rgb_scaled_to_val(current_val, FN2_LAYER_COLOR);
            break;
        case _FN3:
            rgb = rgb_scaled_to_val(current_val, FN3_LAYER_COLOR);
            break;
        default:
            break;
    }
    rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
    return false;
}

RGB rgb_scaled_to_val(uint8_t val, uint8_t red, uint8_t green, uint8_t blue) {
    float value = val;
    RGB rgb;
    rgb.r = red * (value / 255);
    rgb.g = green * (value / 255);
    rgb.b = blue * (value / 255);
    return rgb;
}
