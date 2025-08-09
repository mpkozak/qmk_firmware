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
#include "fn_tapdance.c"



////////////////////////////////////////////////////////////////////////////////
// Custom keycodes

// tapdance keycodes
#define ESC_GRV TD(TD_ESC_GRV)
#define CMD_CTL TD(TD_CMD_CTRL)
#define OPT_CTL TD(TD_OPT_CTRL)
#define LCTL_FN TD(TD_LCTL_FN)  // left control + apple fn (tap-hold)



////////////////////////////////////////////////////////////////////////////////
// Layout

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* M0110
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
     * |`  |1  |2  |3  |4  |5  |6  |7  |8  |9  |0  |-  |=  |Backs|
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
     * |Tab  |Q  |W  |E  |R  |T  |Y  |U  |I  |O  |P  |[  |]  |\  |
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
     * |Caps  |A  |S  |D  |F  |G  |H  |J  |K  |L  |;  |'  |Return|
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──────┤
     * |Shift   |Z  |X  |C  |V  |B  |N  |M  |,  |.  |/  |Shift   |
     * └───┬───┬┴───┴┬──┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬───┘
     *     |Opt|⌘    |                             |Enter|Opt|
     *     └───┴─────┴─────────────────────────────┴─────┴───┘
     */

    [BASE] = LAYOUT_m0110(
        ESC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        LCTL_FN, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
                 OPT_CTL, CMD_CTL,                            LT(1,KC_SPC),                                KC_RCMD, KC_ROPT
    ),
    [FN0] = LAYOUT_m0110(
        KC_LSCR, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_INS,  ___x___, KC_UP,   KC_EMOC, KC_REFR, KC_NTAB, ___x___, ___x___, KC_UP,   ___x___, ___x___, KC_VOLD, KC_VOLU, KC_MUTE,
        ___x___, KC_LEFT, KC_DOWN, KC_RGHT, KC_FSTG, ___x___, ___x___, KC_LEFT, KC_DOWN, KC_RGHT, ___x___, KC_MCTL,          KC_PENT,
        ___x___,          KC_ZMNS, KC_ZPLS, KC_ZACT, KC_PSTT, KC_WBAK, KC_WFOR, ___x___, KC_MVLS, KC_MVRS, KC_CMNT,          ___x___,
                 KC_APFN, _______,                            _______,                                     MO(2),   ___x___
    ),
    [FN1] = LAYOUT_m0110(
        ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,
        ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,
        QK_RBT,  ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,          ___x___,
        DB_TOGG,          ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,          ___x___,
                 QK_BOOT, TT(3),                              _______,                                     _______, ___x___
    ),
    [DFLT] = LAYOUT_m0110(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LCAP, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          ___x___,
                 KC_LOPT, KC_LCMD,                            KC_SPC,                                      KC_PENT, ___x___
    )
};



////////////////////////////////////////////////////////////////////////////////
// User hooks

layer_state_t layer_state_set_user(layer_state_t state) {
    state = layer_state_set_mcu(state);
    return state;
}

// void keyboard_post_init_user(void) {
// }

// void housekeeping_task_user(void) {
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_kc(keycode, record)) {
        return false;
    }
    return true;
}
