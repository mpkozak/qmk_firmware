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
#include "keymap_user.h"
#include "custom_keycodes.h"
#include "rgb.c"
#include "fn_key.c"



////////////////////////////////////////////////////////////////////////////////
// Custom keycodes




////////////////////////////////////////////////////////////////////////////////
// Layout

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ╭───╮ ┌───┬───┬───┬───┐
     * │ ↺ │ │F1 │F2 │F3 │Del │
     * ╰───╯ └───┴───┴───┴───┘
     * ┌───┐ ┌───┬───┬───┬───┐
     * │Esc│ │ = │ ÷ │ × │ - │
     * ├───┤ ├───┼───┼───┼───┤
     * │Tab│ │ 7 │ 8 │ 9 │   │
     * ├───┤ ├───┼───┼───┤ + │
     * │Ctl│ │ 4 │ 5 │ 6 │   │
     * ├───┤ ├───┼───┼───┼───┤
     * │Sft│ │ 1 │ 2 │ 3 │   │
     * ├───┤ ├───┴───┼───┤Ent│
     * │Fn │ │   0   │ . │   │
     * └───┘ └───────┴───┴───┘
     */

    [BASE] = LAYOUT_numpad_6x5(        // layer 0 BASE - white
        KC_MUTE,   TO(2),    TO(3),    TO(4),    KC_BSPC,
        KC_ESC,    KC_PEQL,  KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,    KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
        KC_LCTL,   KC_P4,    KC_P5,    KC_P6,
        KC_LSFT,   KC_P1,    KC_P2,    KC_P3,    LT(3,KC_PENT),
        MO(1),     LT(2,KC_P0),        KC_PDOT
    ),
    [FN0] = LAYOUT_numpad_6x5(         // layer 1 FN0 - blue
        KC_ZACT,   _______,  _______,  _______,  _______,
        _______,   KC_CALU,  ___x___,  ___x___,  A(KC_PMNS),
        KC_BTAB,   ___x___,  KC_UP,    ___x___,  ___x___,
        _______,   KC_LEFT,  KC_DOWN,  KC_RGHT,
        _______,   KC_MVLS,  KC_DESK,  KC_MVRS,  _______,
        _______,   _______,            ___x___
    ),
    [FN1] = LAYOUT_numpad_6x5(         // layer 2 FN1 - orange
        ___x___,   TO(0),    _______,  _______,  _______,
        KC_LSCR,   KC_CALU,  ___x___,  ___x___,  A(KC_PMNS),
        _______,   ___x___,  KC_UP,    ___x___,  ___x___,
        _______,   KC_LEFT,  KC_DOWN,  KC_RGHT,
        _______,   G(KC_1),  G(KC_2),  G(KC_3),  _______,
        _______,   _______,            KC_R
    ),
    [FN2] = LAYOUT_numpad_6x5(         // layer 3 FN2 - green
        RM_TOGG,   _______,  TO(0),    _______,  QK_BOOT,
        _______,   ___x___,  ___x___,  ___x___,  ___x___,
        KC_TGTL,   KC_LPRN,  ___x___,  KC_RPRN,  ___x___,
        KC_TGCL,   KC_D,     KC_E,     KC_F,
        _______,   KC_A,     KC_B,     KC_C,     _______,
        _______,   _______,            KC_COLN
    ),
    [FN3] = LAYOUT_numpad_6x5(         // layer 4 FN3 - yellow
        ___x___,   _______,  _______,  TO(0),    EE_CLR,
        QK_RBT,    ___x___,  ___x___,  ___x___,  ___x___,
        ___x___,   ___x___,  ___x___,  ___x___,  ___x___,
        ___x___,   ___x___,  ___x___,  ___x___,
        ___x___,   ___x___,  ___x___,  ___x___,  ___x___,
        ___x___,   ___x___,            ___x___
    )
};

// clang-format on



////////////////////////////////////////////////////////////////////////////////
// Encoder map

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][1][2] = {
    [BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [FN0] = { ENCODER_CCW_CW(KC_ZMNS, KC_ZPLS) },
    [FN1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [FN2] = { ENCODER_CCW_CW(RM_VALD, RM_VALU) },
    [FN3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif



////////////////////////////////////////////////////////////////////////////////
// User hooks

void matrix_init_user(void) {
    matrix_init_rgb();
}

void housekeeping_task_user(void) {
    housekeeping_task_fn();
    housekeeping_task_rgb();
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    state = default_layer_state_set_rgb(state);
    return state;
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return state;
// }

void keyboard_post_init_user(void) {
    keyboard_post_init_rgb();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_fn(keycode, record)) {
        return false;
    }
    if (!process_record_rgb(keycode, record)) {
        return false;
    }
    return true;
}
