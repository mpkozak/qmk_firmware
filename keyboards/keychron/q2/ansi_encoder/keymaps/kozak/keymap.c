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
#include "keymap_user.h"
#include "custom_keycodes.h"
#include "rgb.c"
#include "fn_key.c"
#include "spd_autocorrect.c"



////////////////////////////////////////////////////////////////////////////////
// Custom keycodes

// Tap Dance declarations
enum {
    TD_ESC_GRV,
    TD_PGUP_HOME,
    TD_PGDN_END,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRV),
    [TD_PGUP_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_PGUP, KC_HOME),
    [TD_PGDN_END] = ACTION_TAP_DANCE_DOUBLE(KC_PGDN, KC_END),
};

// Keycode aliases
#define ESC_GRV   TD(TD_ESC_GRV)
#define PGUP_HOME TD(TD_PGUP_HOME)
#define PGDN_END  TD(TD_PGDN_END)

// Set a long-ish tapping term for tap-dance keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return TAPPING_TERM * 2;
        default:
            return TAPPING_TERM;
    }
}



////////////////////////////////////////////////////////////////////////////////
// Layout

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *                                                               ╭───╮
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ │ ↺ │
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │  Bspc │ ╰───╯
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ┌───┐
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \| │ │Hom│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ ├───┤
     * │ Ctrl │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │ │End│
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┘ └───┘
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ ┌───┐
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┘ │ ↑ │
     * │Ctrl│ Opt│ Cmd│                        │Cmd│Opt│ Fn│ ┌───┼───┼───┐
     * └────┴────┴────┴────────────────────────┴───┴───┴───┘ │ ← │ ↓ │ → │
     *                                                       └───┴───┴───┘
     */

    [BASE] = LAYOUT_ansi_67(        // layer 0 BASE - white
        ESC_GRV,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,    KC_BSPC,       KC_MUTE,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,       PGUP_HOME,
        LCTL_FN,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,        KC_ENT,        PGDN_END,
        KC_LSFT,            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,      KC_RSFT,       KC_UP,
        KC_LCTL,   KC_LOPT,   KC_LCMD,                          LT(2,KC_SPC),                     KC_RCMD,  KC_ROPT,  MO(3),     KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [SPD] = LAYOUT_ansi_67(         // layer 1 SPD - orange
        TO(0),        KC_1,    KC_P2,   KC_P3,   KC_P4,   KC_P5,   KC_P6,   KC_P7,   KC_P8,   KC_9,    KC_0,    KC_MINS, ___x___,   KC_BSPC,       KC_MUTE,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    ___x___, ___x___, KC_BSPC,       _______,
        ___x___,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,        KC_ENT,        _______,
        OSM(MOD_LSFT),      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUES,      KC_RSFT,       KC_UP,
        KC_LCTL,   KC_LOPT,   KC_LCMD,                          KC_SPC,                           ___x___,  ___x___,  MO(3),     KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [FN0] = LAYOUT_ansi_67(         // layer 2 FN0 - blue [space fn]
        KC_LSCR,      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_BSPC,       KC_ZACT,
        KC_INS,         ___x___, KC_UP,   KC_EMOC, KC_REFR, KC_NTAB, ___x___, ___x___, KC_UP,   ___x___, ___x___, KC_MVLT, KC_MVRT, KC_DEL,        _______,
        KC_LCTL,          KC_LEFT, KC_DOWN, KC_RGHT, KC_FSTG, KC_LPAD, ___x___, KC_LEFT, KC_DOWN, KC_RGHT, ___x___, KC_MCTL,        KC_ENT,        _______,
        KC_LSFT,            KC_ZMNS, KC_ZPLS, KC_ZACT, KC_PSTT, KC_WBAK, KC_WFOR, ___x___, KC_MVLT, KC_MVRT, KC_CMNT,      KC_RSFT,       KC_MCTL,
        KC_APFN,   KC_LOPT,   KC_LCMD,                          _______,                          KC_RCMD,  MO(4),    MO(3),     KC_MVLS, KC_DESK, KC_MVRS
    ),
    [FN1] = LAYOUT_ansi_67(         // layer 3 FN1 - green [quick toggles]
        KC_GRV,       ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, RM_VALD, RM_VALU, KC_BRID, KC_BRIU,   _______,       KC_LSCR,
        KC_TAB,         ___x___, ___x___, ___x___, ___x___, TO(1),   ___x___, ___x___, ___x___, ___x___, ___x___, KC_MVLT, KC_MVRT, KC_GRV,        KC_PGUP,
        _______,          ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_LPAD, KC_MCTL, KC_DESK,        KC_PENT,       KC_PGDN,
        KC_CAPS,            ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_DESK, KC_MVLS, KC_MVRS,      KC_CAPS,       KC_MCTL,
        KC_APFN,   _______,   _______,                          _______,                          KC_RCMD,  MO(4),    _______,   KC_MVLS, KC_DESK, KC_MVRS
    ),
    [FN2] = LAYOUT_ansi_67(         // layer 4 FN2 - cyan [mac media keys + rbg settings]
        QK_BOOT,      QK_RBT,  EE_CLR,  ___x___, ___x___, ___x___, ___x___, KC_MPRV, KC_MPLY, KC_MNXT, ___x___, ___x___, ___x___,   _______,       RM_TOGG,
        _______,        ___x___, ___x___, ___x___, NK_TOGG, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_TGTL, KC_TGCL, _______,       _______,
        _______,          RM_SATD, RM_SATU, ___x___, ___x___, RM_HUED, RM_HUEU, ___x___, RM_VALD, RM_VALU, ___x___, ___x___,        _______,       _______,
        RM_TOGG,            ___x___, ___x___, RM_SPDD, RM_SPDU, ___x___, RM_PREV, RM_NEXT, ___x___, ___x___, ___x___,      _______,       _______,
        _______,   _______,   _______,                          _______,                          _______,  _______,  _______,   _______, _______, _______
    )
};

// clang-format on



////////////////////////////////////////////////////////////////////////////////
// Encoder map

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [SPD]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [FN0]   = { ENCODER_CCW_CW(KC_ZMNS, KC_ZPLS) },
    [FN1]   = { ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
    [FN2]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU) },
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

layer_state_t layer_state_set_user(layer_state_t state) {
    state = layer_state_set_ac(state);
    return state;
}

void keyboard_post_init_user(void) {
    keyboard_post_init_rgb();
    keyboard_post_init_ac();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_fn(keycode, record)) {
        return false;
    }
    if (!process_record_ac(keycode, record)) {
        return false;
    }
    if (!process_record_rgb(keycode, record)) {
        return false;
    }
    return true;
}
