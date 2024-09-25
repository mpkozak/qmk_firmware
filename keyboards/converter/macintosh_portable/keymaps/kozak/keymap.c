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



////////////////////////////////////////////////////////////////////////////////
// Custom keycodes

enum custom_keycodes {
  KC_TGSP = SAFE_RANGE          // locking speed toggle
};

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

// portable-specific
// #define KC_CMDG LCMD_T(KC_GRV)          // left command + grave
// #define KC_CMDE RCMD_T(KC_PENT)         // right command + enter
#define KC_CMDG RCMD_T(KC_GRV)          // right command + grave
#define KC_OPTA ROPT_T(KC_LEFT)         // right option + left arrow



////////////////////////////////////////////////////////////////////////////////
// Key overrides for autocorrect BASE_SPD layer

const key_override_t comma_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_COMM, 1 << BASE_SPD);
const key_override_t period_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_DOT, 1 << BASE_SPD);
const key_override_t hyphen_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_MINS, KC_MINS, 1 << BASE_SPD);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &comma_override,
    &period_override,
    &hyphen_override,
};



////////////////////////////////////////////////////////////////////////////////
// Layout

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Macintosh Portable
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
     * |Esc|1  |2  |3  |4  |5  |6  |7  |8  |9  |0  |-  |=  |Delet|
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
     * |Tab  |Q  |W  |E  |R  |T  |Y  |U  |I  |O  |P  |[  |]  |\  |
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
     * |Ctrl  |A  |S  |D  |F  |G  |H  |J  |K  |L  |;  |'  |Return|
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──────┤
     * |Shift   |Z  |X  |C  |V  |B  |N  |M  |,  |.  |/  |Shift   |
     * ├───┬───┬┴───┴─┬─┴─┬─┴───┴───┴───┴───┴┬──┴┬──┴┬──┴┬───┬───┘
     * |Cap|Opt|⌘     |`  |                  |Ent|←  |→  |↓  |↑  |
     * └───┴───┴──────┴───┴──────────────────┴───┴───┴───┴───┴───┘
     */

    [BASE] = LAYOUT_5120_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        KC_TGSP, KC_LOPT, KC_LCMD, ___x___,                   LT(1,KC_SPC),              KC_CMDG, KC_OPTA, KC_RGHT, KC_DOWN, LT(2,KC_UP)
    ),
    [FN0] = LAYOUT_5120_ansi(
        KC_LSCR, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_INS,  KC_MVLT, KC_MVRT, KC_EMOC, KC_REFR, KC_NTAB, ___x___, ___x___, KC_UP,   ___x___, ___x___, KC_MVLS, KC_MVRS, KC_BSLS,
        _______, KC_MVLS, KC_MVRS, KC_DESK, KC_FSTG, KC_LPAD, ___x___, KC_LEFT, KC_DOWN, KC_RGHT, ___x___, KC_MCTL,          _______,
        _______,          KC_ZMNS, KC_ZPLS, KC_ZACT, KC_PSTT, KC_WBAK, KC_WFOR, ___x___, KC_MVLT, KC_MVRT, KC_CMNT,          _______,
        _______, _______, _______, ___x___,                   _______,                   _______, _______, _______, _______, _______
    ),
    [FN1] = LAYOUT_5120_ansi(
        QK_BOOT, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_MUTE,
        _______, ___x___, KC_UP,   ___x___, KC_REFR, KC_NTAB, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,          _______,
        _______,          KC_DESK, KC_MVLS, KC_MVRS, KC_PSTT, ___x___, ___x___, KC_MCTL, KC_DESK, KC_MVLS, KC_MVRS,          _______,
        _______, _______, _______, ___x___,                   G(KC_SPC),                 _______, KC_MVLS, KC_MVRS, KC_DESK, _______
    ),
    [BASE_SPD] = LAYOUT_5120_ansi(
        KC_ESC,  KC_1,    KC_P2,   KC_P3,   KC_P4,   KC_P5,   KC_P6,   KC_P7,   KC_P8,   KC_9,    KC_0,    KC_MINS, ___x___, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    ___x___, ___x___, KC_BSPC,
        ___x___, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        OSM(MOD_LSFT),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUES,          KC_RSFT,
        _______, KC_LOPT, KC_LCMD, ___x___,                   KC_SPC,                    ___x___, ___x___, ___x___, KC_DOWN, KC_UP
    )
};



////////////////////////////////////////////////////////////////////////////////
// Autocorrect stack

void keyboard_post_init_user(void) {
#ifdef AUTOCORRECT_OFF_AT_STARTUP
    // toggle autocorrect off at startup
    if (autocorrect_is_enabled()) {
        autocorrect_toggle();
    }
#endif
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case BASE_SPD:
            if (!autocorrect_is_enabled()) {
                autocorrect_enable();
            }
#ifdef LED_LAYER_STATUS
            gpio_write_pin_high(LED_PIN);
#endif
            break;
        default:
            if (autocorrect_is_enabled()) {
                autocorrect_disable();
            }
#ifdef LED_LAYER_STATUS
            gpio_write_pin_low(LED_PIN);
#endif
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // speed layer toggle
    if (keycode == KC_TGSP) {
        if (record->event.pressed) {
            layer_move(BASE_SPD);
        } else {
            layer_clear();
        }
        return false;
    }
    // ignore suprious number keys in the middle of alphas for speed layer
    if (get_highest_layer(layer_state) == BASE_SPD) {
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







////////////////////////////////////////////////////////////////////////////////
// [removed] DIP switch keys -- WORKS

// const uint8_t PROGMEM dip_matrix[][2] = {
//     {0, 5},
//     {1, 4},     // {3, 4}
//     {3, 0},
//     {0, 1},
//     {2, 1}
// };

// uint16_t get_dip_keycode(uint8_t layer, uint8_t row, uint8_t col) {
//     uint16_t keycode = keycode_at_keymap_location(layer, row, col);
//     if (keycode == KC_TRNS) {
//         return get_dip_keycode(layer - 1, row, col);
//     }
//     return keycode;
// }

// bool dip_switch_update_user(uint8_t index, bool active) {
//     uint8_t layer = get_highest_layer(layer_state);
//     uint8_t row = dip_matrix[index][0];
//     uint8_t col = dip_matrix[index][1];
//     uint16_t keycode = get_dip_keycode(layer, row, col);
//     uprintf("kc: 0x%04X, layer: %2u, col: %2u, row: %2u", keycode, layer, col, row); print("\n");

// // use Locking Caps Lock keyswitch to toggle BASE_SPD layer on/off
//     if (index == 0) {
//         if (active) {
//             layer_move(BASE_SPD);
// #ifdef LED_LAYER_STATUS
//             gpio_write_pin_high(LED_PIN);
// #endif
//         } else {
//             layer_clear();
// #ifdef LED_LAYER_STATUS
//             gpio_write_pin_low(LED_PIN);
// #endif
//         }
//         return true;
//     }

// // handle oneshot keycodes
//     if (IS_QK_ONE_SHOT_MOD(keycode)) {
//         print("IS ONESHOT\n");
//         if (active) {
//             set_oneshot_mods(QK_ONE_SHOT_MOD_GET_MODS(keycode));
//         } else {
//             // clear_oneshot_mods();
//         }
//         return true;
//     }

// // otherwise handle keycode normally
//     if (active) {
//         register_code(keycode);
//     } else {
//         unregister_code(keycode);
//     }

//     return true;
// }







////////////////////////////////////////////////////////////////////////////////
// Does not work

// #ifdef DIP_SWITCH_MAP_ENABLE

// const uint16_t PROGMEM dip_switch_map[NUM_DIP_SWITCHES][NUM_DIP_STATES] = {
//     DIP_SWITCH_OFF_ON(KC_LCAP, KC_LCAP),
//     DIP_SWITCH_OFF_ON(KC_LSFT, KC_LSFT),
//     DIP_SWITCH_OFF_ON(KC_LCTL, KC_LCTL),
//     DIP_SWITCH_OFF_ON(KC_LOPT, KC_LOPT),
//     DIP_SWITCH_OFF_ON(KC_LCMD, KC_LCMD)
// };

// bool dip_switch_update_user(uint8_t index, bool active) {
//     if (active) {
//         register_code(dip_switch_map[index][1]);
//     } else {
//         unregister_code(dip_switch_map[index][0]);
//     }
//     return false;
// }

// #endif
