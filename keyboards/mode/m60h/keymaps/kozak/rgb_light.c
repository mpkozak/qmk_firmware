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

#include QMK_KEYBOARD_H



////////////////////////////////////////////////////////////////////////////////
// RGB layers

const rgblight_segment_t PROGMEM rbg_layer_base[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, BASE_LAYER_HSV}
);

const rgblight_segment_t PROGMEM rbg_layer_spd[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, SPD_LAYER_HSV}
);

const rgblight_segment_t PROGMEM rgb_layer_fn0[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, FN0_LAYER_HSV}
);

const rgblight_segment_t PROGMEM rbg_layer_fn1[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, FN1_LAYER_HSV}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rbg_layer_base,
    rbg_layer_spd,
    rgb_layer_fn0,
    rbg_layer_fn1
);

void keyboard_post_init_rgb(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
}

layer_state_t default_layer_state_set_rgb(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, BASE));
    return state;
}

layer_state_t layer_state_set_rgb(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, BASE));
    rgblight_set_layer_state(1, layer_state_cmp(state, SPD));
    rgblight_set_layer_state(2, layer_state_cmp(state, FN0));
    rgblight_set_layer_state(3, layer_state_cmp(state, FN1));
    return state;
}
