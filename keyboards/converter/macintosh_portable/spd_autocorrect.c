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
#include "custom_keycodes.h"



////////////////////////////////////////////////////////////////////////////////
// Key overrides for autocorrect SPD layer

const key_override_t comma_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_COMM, 1 << SPD);
const key_override_t period_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_DOT, 1 << SPD);
const key_override_t hyphen_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_MINS, KC_MINS, 1 << SPD);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &comma_override,
    &period_override,
    &hyphen_override,
};



////////////////////////////////////////////////////////////////////////////////
// Autocorrect stack

void keyboard_post_init_ac(void) {
#ifdef AUTOCORRECT_OFF_AT_STARTUP
    // toggle autocorrect off at startup
    if (autocorrect_is_enabled()) {
        autocorrect_toggle();
    }
#endif
}

layer_state_t layer_state_set_ac(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case SPD:
            if (!autocorrect_is_enabled()) {
                autocorrect_enable();
            }
            break;
        default:
            if (autocorrect_is_enabled()) {
                autocorrect_disable();
            }
            break;
    }
    return state;
}

bool is_number(uint16_t keycode) {
    switch (keycode) {
        case KC_P1 ... KC_P0:
        case KC_2 ... KC_9:         // range change to allow ! and ) after alphas
            return true;
        default:
            return false;
    }
}

bool is_alpha (uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
            return true;
        default:
            return false;
    }
}

bool is_prev_alpha = false;

bool process_record_ac(uint16_t keycode, keyrecord_t *record) {
    // speed layer toggle
    if (keycode == KC_TGSP) {
        if (record->event.pressed) {
            layer_move(SPD);
        } else {
            layer_clear();
        }
        return false;
    }
    // ignore suprious number keys in the middle of alphas for speed layer
    if (get_highest_layer(layer_state) == SPD) {
        if (is_number(keycode)) {
            if (is_prev_alpha) {
                return false;
            }
        }
        // update previous keycode is_alpha state
        if (record->event.pressed) {
            if (is_alpha(keycode)) {    // keycode is alpha
                if (!is_prev_alpha) {
                    is_prev_alpha = true;
                }
            } else {                    // keycode is not alpha
                if (is_prev_alpha) {
                    is_prev_alpha = false;
                }
            }
        }
    }
    return true;
}
