/* Copyright 2025 @ M. Parker Kozak (https://github.com/mpkozak)
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
#include "mcu_leds.c"



////////////////////////////////////////////////////////////////////////////////
// Custom keycodes

#define SPC_CTL LCTL_T(KC_SPC)        // space + left control
#define KP0_LT1 LT(1, KC_P0)          // keypad 0 + layer 1





////////////////////////////////////////////////////////////////////////////////
// Layout

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* A2S2003
     * ┌───┐   ┌───┬───┬───┐  ┌───┬───┐
     * |Esc|   |7  |8  |9  |  |(  |)  |
     * ├───┤   ├───┼───┼───┤  ├───┼───┤
     * |←  |   |4  |5  |6  |  |−  |÷  |
     * ├───┤   ├───┼───┼───┤  ├───┼───┤
     * |→  |   |1  |2  |3  |  |+  |×  |
     * ├───┤ ┌─┴───┼───┼───┤  ├───┼───┤
     * |Spc| |0    |,  |.  |  |Ret|Prt|
     * └───┘ └─────┴───┴───┘  └───┴───┘
     */

  [BASE] = LAYOUT(
    KC_ESC,   KC_P7,    KC_P8,    KC_P9,    KC_LPRN,  KC_RPRN,
    KC_TAB,   KC_P4,    KC_P5,    KC_P6,    KC_PMNS,  KC_PSLS,
    KC_BTAB,  KC_P1,    KC_P2,    KC_P3,    KC_PPLS,  KC_PAST,
    SPC_CTL,  KP0_LT1,  KC_COMM,  KC_PDOT,  KC_PENT,  MO(2)
  ),
  [FN0] = LAYOUT(
    ___x___,  ___x___,  ___x___,  ___x___,  ___x___,  ___x___,
    KC_BSPC,  ___x___,  KC_UP,    ___x___,  KC_VOLD,  ___x___,
    ___x___,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_VOLU,  ___x___,
    ___x___,  _______,  ___x___,  ___x___,  KC_MUTE,  _______
  ),
  [FN1] = LAYOUT(
    QK_BOOT,  ___x___,  ___x___,  ___x___,  ___x___,  ___x___,
    ___x___,  ___x___,  ___x___,  ___x___,  ___x___,  ___x___,
    ___x___,  ___x___,  ___x___,  ___x___,  ___x___,  ___x___,
    ___x___,  TT(3),    ___x___,  ___x___,  ___x___,  ___x___
  ),
  [DFLT] = LAYOUT(
    KC_ESC,   KC_P7,    KC_P8,    KC_P9,    KC_LPRN,  KC_RPRN,
    KC_LEFT,  KC_P4,    KC_P5,    KC_P6,    KC_PMNS,  KC_PSLS,
    KC_RGHT,  KC_P1,    KC_P2,    KC_P3,    KC_PPLS,  KC_PAST,
    KC_SPC,   KC_P0,    KC_COMM,  KC_PDOT,  KC_PENT,  KC_RCTL
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

void housekeeping_task_user(void) {
    housekeeping_task_fn();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_kc(keycode, record)) {
        return false;
    }
    if (!process_record_fn(keycode, record)) {
        return false;
    }
    return true;
}
