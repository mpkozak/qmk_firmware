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
#include "fn_key.c"
#include "spd_autocorrect.c"
#include "mcu_leds.c"



////////////////////////////////////////////////////////////////////////////////
// Custom keycodes

#define KC_CTAP LCTL_T(KC_CAPS) // left control / tap caps lock



////////////////////////////////////////////////////////////////////////////////
// Layout

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* M0115
     * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐             ┌───┐
     * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |F13|F14|F15|             |◀︎  |
     * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘             └───┘
     *
     *
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
     * |`  |1  |2  |3  |4  |5  |6  |7  |8  |9  |0  |-  |=  |Delete | |Ins|Hom|Pg↑| |Clr|=  |/  |*  |
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
     * |Tab  |Q  |W  |E  |R  |T  |Y  |U  |I  |O  |P  |[  |]  |\    | |Del|End|Pg↓| |8  |9  |+  |-  |
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┼───┤
     * |CapsLk|A  |S  |D  |F  |G  |H  |J  |K  |L  |;  |'  |Return  |               |4  |5  |6  |+  |
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
     * |Shift   |Z  |X  |C  |V  |B  |N  |M  |,  |.  |/  |Shift     |     |↑  |     |1  |2  |3  |   |
     * ├─────┬──┴─┬─┴───┼───┴───┴───┴───┴───┴───┴─┬─┴───┼────┬─────┤ ┌───┼───┼───┐ ├───┴───┼───┤Ent|
     * |Ctrl |Opt |   ⌘ |                         | ⌘   |Opt |Ctrl | |←  |↓  |→  | |0      |.  |   |
     * └─────┴────┴─────┴─────────────────────────┴─────┴────┴─────┘ └───┴───┴───┘ └───────┴───┴───┘
     */

    [BASE] = LAYOUT_m0115(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,          TO(1),   TO(2),   TT(3),                                      KC_LSCR,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,         KC_INS,  KC_HOME, KC_PGUP,         KC_ESC,  KC_PEQL, KC_PSLS, KC_PAST,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,         KC_DEL,  KC_END,  KC_PGDN,         KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
        KC_CTAP, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,                                             KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,                  KC_UP,                    KC_P1,   KC_P2,   KC_P3,
        LCTL_FN, KC_LOPT, KC_LCMD,                            LT(1,KC_SPC),                                ___x___, KC_ROPT, KC_RCTL,         KC_LEFT, KC_DOWN, KC_RGHT,         LT(1, KC_P0),     KC_PDOT, LT(1, KC_PENT)
    ),
    [FN0] = LAYOUT_m0115(
        TO(0),            C(KC_1), C(KC_2), C(KC_3), C(KC_4), C(KC_5), C(KC_6), C(KC_7), C(KC_8), KC_F13,  KC_F14,  KC_F15,  KC_F16,          TO(0),   _______, _______,                                    QK_BOOT,
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,          _______, _______, _______,         KC_BSPC, KC_CALU, ___x___, KC_MUTE,
        KC_INS,  ___x___, KC_UP,   KC_EMOC, KC_REFR, KC_NTAB, ___x___, ___x___, KC_UP,   ___x___, ___x___, KC_MVLS, KC_MVRS, KC_DEL,          _______, _______, _______,         ___x___, KC_UP,   ___x___, KC_VOLD,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_FSTG, ___x___, ___x___, KC_LEFT, KC_DOWN, KC_RGHT, ___x___, KC_MCTL,          _______,                                            KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLU,
        _______,          KC_ZMNS, KC_ZPLS, KC_ZACT, KC_PSTT, KC_WBAK, KC_WFOR, ___x___, KC_MVLT, KC_MVRT, KC_CMNT,          _______,                  _______,                  G(KC_1), G(KC_2), G(KC_3),
        KC_APFN, _______, _______,                            _______,                                     _______, _______, _______,         KC_BTAB, _______, KC_TAB,          _______,          KC_TAB,  _______
    ),
    [SPD] = LAYOUT_m0115(
        TO(0),            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, TO(0),   _______,                                    ___x___,
        KC_ESC,  KC_1,    KC_P2,   KC_P3,   KC_P4,   KC_P5,   KC_P6,   KC_P7,   KC_P8,   KC_9,    KC_0,    KC_MINS, ___x___, KC_BSPC,         _______, _______, _______,         TO(0),   KC_PEQL, KC_PSLS, KC_PAST,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    ___x___, ___x___, KC_BSPC,         _______, _______, _______,         KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
        ___x___, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,                                             KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        OSM(MOD_LSFT),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUES,          KC_RSFT,                  KC_UP,                    KC_P1,   KC_P2,   KC_P3,
        KC_LCTL, KC_LOPT, KC_LCMD,                            KC_SPC,                                      ___x___, KC_ROPT, KC_RCTL,         KC_LEFT, KC_DOWN, KC_RGHT,         KC_P0,            KC_PDOT, KC_PENT
    ),
    [DFLT] = LAYOUT_m0115(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,          KC_PSCR, KC_SCRL, KC_PAUS,                                    KC_F20,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,         KC_INS,  KC_HOME, KC_PGUP,         KC_NUM,  KC_PEQL, KC_PSLS, KC_PAST,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,         KC_DEL,  KC_END,  KC_PGDN,         KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,                                             KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,                  KC_UP,                    KC_P1,   KC_P2,   KC_P3,
        KC_LCTL, KC_LOPT, KC_LCMD,                            KC_SPC,                                      ___x___, KC_ROPT, KC_RCTL,         KC_LEFT, KC_DOWN, KC_RGHT,         KC_P0,            KC_PDOT, KC_PENT
    )
};



////////////////////////////////////////////////////////////////////////////////
// User hooks

layer_state_t layer_state_set_user(layer_state_t state) {
    state = layer_state_set_ac(state);
    state = layer_state_set_mcu(state);
    if (get_highest_layer(state) == SPD) {
        if (host_keyboard_led_state().caps_lock) {
            register_code(KC_CAPS);
        }
    }
    return state;
}

void keyboard_post_init_user(void) {
    keyboard_post_init_ac();
}

void housekeeping_task_user(void) {
    housekeeping_task_fn();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_fn(keycode, record)) {
        return false;
    }
    if (!process_record_ac(keycode, record)) {
        return false;
    }
    // default layer untoggle
    if (keycode == KC_F20) {                        // power key
        if (record->event.pressed) {                // keydown event
            if (get_mods() == MOD_BIT(KC_LCTL)) {   // while left control active
                layer_clear();
                return false;
            }
        }
        return true;
    }
    return true;
}
