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
#include "mcu_leds.c"
#include "spd_autocorrect.c"
#include "fn_tapdance.c"



////////////////////////////////////////////////////////////////////////////////
// Custom keycodes

// tapdance keycodes
#define LCTL_FN TD(TD_LCTL_FN)  // left control + apple fn (tap-hold)

#define GRV_CMD LCMD_T(KC_GRV)          // left command + grave
#define BSL_CMD RCMD_T(KC_BSLS)         // right command + backslash
#define LFT_OPT ROPT_T(KC_LEFT)         // right option + left arrow



////////////////////////////////////////////////////////////////////////////////
// Layout

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* M0116
     *                     ┌───────┐
     *                     |◀︎      |
     *                     └───────┘
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐ ┌───┬───┬───┬───┐
     * |Esc|1  |2  |3  |4  |5  |6  |7  |8  |9  |0  |-  |=  |Backs| |Clr|=  |/  |*  |
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤ ├───┼───┼───┼───┤
     * |Tab  |Q  |W  |E  |R  |T  |Y  |U  |I  |O  |P  |[  |]  |   | |7  |8  |9  |+  |
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┘   | ├───┼───┼───┼───┤
     * |Ctrl  |A  |S  |D  |F  |G  |H  |J  |K  |L  |;  |'  |Return| |4  |5  |6  |-  |
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──────┤ ├───┼───┼───┼───┤
     * |Shift   |Z  |X  |C  |V  |B  |N  |M  |,  |.  |/  |Shift   | |1  |2  |3  |   |
     * ├───┬───┬┴───┴─┬─┴─┬─┴───┴───┴───┴───┴┬──┴┬──┴┬──┴┬───┬───┘ ├───┴───┼───┤Ent|
     * |Cap|Opt|⌘     |`  |                  |\  |←  |→  |↓  |↑  | |0      |.  |   |
     * └───┴───┴──────┴───┴──────────────────┴───┴───┴───┴───┴───┘ └───────┴───┴───┘
     */

    [BASE] = LAYOUT_m0116(
                                                     KC_LSCR,
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,         KC_ESC,  KC_PEQL, KC_PSLS, KC_PAST,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                  KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        LCTL_FN, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,          KC_P4,   KC_P5,   KC_P6,   KC_PMNS,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,         KC_P1,   KC_P2,   KC_P3,
        CTL_CAP, KC_LOPT, KC_LCMD, GRV_CMD,                   LT(1,KC_SPC),              BSL_CMD, LFT_OPT, KC_RGHT, KC_DOWN, LT(1,KC_UP),     LT(1, KC_P0),     KC_PDOT, LT(1, KC_PENT)
    ),
    [FN0] = LAYOUT_m0116(
                                                     QK_BOOT,
        TT(3),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,          KC_BSPC, KC_CALU, ___x___, KC_MUTE,
        KC_INS,  ___x___, KC_UP,   KC_EMOC, KC_REFR, TO(2),   ___x___, ___x___, KC_UP,   ___x___, ___x___, KC_MVLT, KC_MVRT,                  KC_BTAB, KC_UP,   KC_TAB,  KC_VOLU,
        KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_FSTG, ___x___, ___x___, KC_LEFT, KC_DOWN, KC_RGHT, ___x___, KC_MCTL,          _______,         KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD,
        _______,          KC_ZMNS, KC_ZPLS, KC_ZACT, KC_PSTT, KC_WBAK, KC_WFOR, ___x___, KC_MCTL, KC_MVLS, KC_MVRS,          _______,         G(KC_1), G(KC_2), G(KC_3),
        KC_APFN, _______, _______, _______,                   _______,                   _______, KC_MVLS, KC_MVRS, KC_DESK, _______,         _______,          KC_TAB,  _______
    ),
    [SPD] = LAYOUT_m0116(
                                                     TO(0),
        TO(0),   KC_1,    KC_P2,   KC_P3,   KC_P4,   KC_P5,   KC_P6,   KC_P7,   KC_P8,   KC_9,    KC_0,    KC_MINS, ___x___, KC_BSPC,         TO(0),   KC_PEQL, KC_PSLS, KC_PAST,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    ___x___, ___x___,                  KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        ___x___, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,          KC_P4,   KC_P5,   KC_P6,   KC_PMNS,
        OSM(MOD_LSFT),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUES,          KC_RSFT,         KC_P1,   KC_P2,   KC_P3,
        KC_LCTL, KC_LOPT, KC_LCMD, ___x___,                   KC_SPC,                    ___x___, KC_LEFT, KC_RGHT, KC_DOWN, KC_UP,           KC_P0,            KC_PDOT, KC_PENT
    ),
    [DFLT] = LAYOUT_m0116(
                                                     KC_F20,
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,         KC_NUM,  KC_PEQL, KC_PSLS, KC_PAST,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                  KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,          KC_P4,   KC_P5,   KC_P6,   KC_PMNS,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,         KC_P1,   KC_P2,   KC_P3,
        KC_CAPS, KC_LOPT, KC_LCMD, KC_GRV,                    KC_SPC,                    KC_BSLS, KC_LEFT, KC_RGHT, KC_DOWN, KC_UP,           KC_P0,            KC_PDOT, KC_PENT
    )
};



////////////////////////////////////////////////////////////////////////////////
// User hooks

layer_state_t layer_state_set_user(layer_state_t state) {
    state = layer_state_set_ac(state);
    state = layer_state_set_mcu(state);
    return state;
}

void keyboard_post_init_user(void) {
    keyboard_post_init_ac();
}

// void housekeeping_task_user(void) {
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_kc(keycode, record)) {
        return false;
    }
    if (!process_record_ac(keycode, record)) {
        return false;
    }
    return true;
}
