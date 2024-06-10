/*
Copyright 2011,2012,2015 Jun Wako <wakojun@gmail.com>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

--------------

Ported to QMK by Techsock <info@techsock.com>
*/

#include QMK_KEYBOARD_H
#include "keymap_user.h"

#define KC_LSCR C(G(KC_Q))      // lock screen
#define KC_EMOC C(G(KC_SPC))    // character picker
#define KC_FSTG C(G(KC_F))      // fullscreen toggle
#define KC_PSTT S(A(G(KC_V)))   // paste plaintext
#define KC_ZMNS G(KC_MINS)      // zoom out
#define KC_ZPLS G(KC_EQL)       // zoom in
#define KC_ZACT G(KC_0)         // zoom actual
#define KC_MVLT LSG(KC_LBRC)    // move left tab
#define KC_MVRT LSG(KC_RBRC)    // move right tab
#define KC_MVLS C(KC_LEFT)      // move left space
#define KC_MVRS C(KC_RGHT)      // move right space
#define KC_DESK KC_F11          // show desktop
#define KC_WBAK G(KC_LBRC)      // browser back
#define KC_WFOR G(KC_RBRC)      // browser forward
#define KC_CMNT G(KC_SLSH)      // comment shortcut
#define KC_NTAB G(KC_T)         // new tab
#define KC_REFR LSG(KC_R)       // refresh
#define ___x___ KC_NO           // null

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
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                 KC_LOPT, KC_LCMD,                            LT(1,KC_SPC),                                KC_RCMD, KC_ROPT
    ),
    [FN0] = LAYOUT_m0110(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_INS,  KC_MVLT, KC_MVRT, KC_EMOC, KC_REFR, KC_NTAB, ___x___, ___x___, KC_UP,   ___x___, ___x___, KC_MVLS, KC_MVRS, KC_BSLS,
        DB_TOGG, KC_MVLS, KC_MVRS, KC_DESK, KC_FSTG, KC_LPAD, ___x___, KC_LEFT, KC_DOWN, KC_RGHT, ___x___, KC_MCTL,          QK_RBT,
        _______,          KC_ZMNS, KC_ZPLS, KC_ZACT, KC_PSTT, KC_WBAK, KC_WFOR, ___x___, KC_MVLT, KC_MVRT, KC_CMNT, _______,
                 _______, _______,                            _______,                                     MO(2),   _______
    ),
    [FN1] = LAYOUT_m0110(
        KC_LSCR, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_MUTE,
        KC_INS,  KC_MVLT, KC_MVRT, KC_EMOC, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_UP,   KC_MVLT, KC_MVRT, _______,
        _______, KC_MVLS, KC_MVRS, KC_DESK, KC_FSTG, ___x___, ___x___, ___x___, KC_LPAD, KC_LEFT, KC_DOWN, KC_RGHT,          _______,
        _______,          ___x___, ___x___, ___x___, KC_PSTT, ___x___, ___x___, KC_MCTL, KC_DESK, KC_MVLS, KC_MVRS, _______,
                 _______, QK_BOOT,                            _______,                                     _______, _______
    )
};
