// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

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

// portable-specific
#define KC_CMDG LCMD_T(KC_GRV)          // left command + grave
#define KC_CMDE RCMD_T(KC_PENT)         // right command + enter
#define KC_OPTA ROPT_T(KC_LEFT)         // right option + left arrow
// #define KC_GRV2 LT(2,KC_GRV)            // backtick/grave + layer 2



////////////////////////////////////////////////////////////////////////////////
// Key overrides for BASE_SPD layer

const key_override_t comma_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_COMM, 1 << BASE_SPD);
const key_override_t period_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_DOT, 1 << BASE_SPD);
const key_override_t hyphen_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_MINS, KC_MINS, 1 << BASE_SPD);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &comma_override,
    &period_override,
    &hyphen_override,
    NULL // Null terminate the array of overrides!
};



////////////////////////////////////////////////////////////////////////////////
// Layout

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Macintosh Portable
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐ ┌───┬───┬───┬───┐
     * |Esc|1  |2  |3  |4  |5  |6  |7  |8  |9  |0  |-  |=  |Delet| |Clr|=  |/  |*  |
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤ ├───┼───┼───┼───┤
     * |Tab  |Q  |W  |E  |R  |T  |Y  |U  |I  |O  |P  |[  |]  |\  | |7  |8  |9  |-  |
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤ ├───┼───┼───┼───┤
     * |Ctrl  |A  |S  |D  |F  |G  |H  |J  |K  |L  |;  |'  |Return| |4  |5  |6  |+  |
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──────┤ ├───┼───┼───┼───┤
     * |Shift   |Z  |X  |C  |V  |B  |N  |M  |,  |.  |/  |Shift   | |1  |2  |3  |   |
     * ├───┬───┬┴───┴─┬─┴─┬─┴───┴───┴───┴───┴┬──┴┬──┴┬──┴┬───┬───┘ ├───┴───┼───┤Ent|
     * |Cap|Opt|⌘     |`  |                  |Ent|←  |→  |↓  |↑  | |0      |.  |   |
     * └───┴───┴──────┴───┴──────────────────┴───┴───┴───┴───┴───┘ └───────┴───┴───┘
     */

    [BASE] = LAYOUT_5120_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        KC_LCAP, KC_LOPT, KC_LCMD, KC_CMDG,                   LT(1,KC_SPC),              KC_CMDE, KC_OPTA, KC_RGHT, KC_DOWN, LT(2,KC_UP)
    ),
    [FN0] = LAYOUT_5120_ansi(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_INS,  KC_MVLT, KC_MVRT, KC_EMOC, KC_REFR, KC_NTAB, ___x___, ___x___, KC_UP,   ___x___, ___x___, KC_MVLS, KC_MVRS, KC_BSLS,
        _______, KC_MVLS, KC_MVRS, KC_DESK, KC_FSTG, KC_LPAD, ___x___, KC_LEFT, KC_DOWN, KC_RGHT, ___x___, KC_MCTL,          _______,
        _______,          KC_ZMNS, KC_ZPLS, KC_ZACT, KC_PSTT, KC_WBAK, KC_WFOR, ___x___, KC_MVLT, KC_MVRT, KC_CMNT,          _______,
        _______, _______, _______, _______,                   _______,                   _______, _______, _______, _______, _______
    ),
    [FN1] = LAYOUT_5120_ansi(
        KC_LSCR, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_MUTE,
        _______, ___x___, KC_UP,   ___x___, KC_REFR, KC_NTAB, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,          _______,
        _______,          KC_DESK, KC_MVLS, KC_MVRS, KC_PSTT, ___x___, ___x___, KC_MCTL, KC_DESK, KC_MVLS, KC_MVRS,          _______,
        _______, _______, _______, _______,                   G(KC_SPC),                 _______, KC_MVLS, KC_MVRS, KC_DESK, _______
    ),
    [BASE_SPD] = LAYOUT_5120_ansi(
        KC_ESC,  KC_1,    KC_P2,   KC_P3,   KC_P4,   KC_P5,   KC_P6,   KC_P7,   KC_P8,   KC_9,    KC_0,    KC_MINS, ___x___, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    ___x___, ___x___, KC_BSPC,
        ___x___, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        OSM(MOD_LSFT),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUES,          KC_RSFT,
        _______, KC_LOPT, KC_LCMD, ___x___,                   KC_SPC,                    ___x___, KC_LEFT, KC_RGHT, KC_DOWN, KC_UP
    )
};



////////////////////////////////////////////////////////////////////////////////
// MCU LED

const uint16_t PROGMEM dip_codes[5] = {
    KC_LCAP,
    KC_LSFT,
    KC_LCTL,
    KC_LOPT,
    KC_LCMD
};

bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
        if (active) {
            layer_move(BASE_SPD);
        } else {
            layer_clear();
        }
        return true;
    }
    if (active) {
        register_code(dip_codes[index]);
    } else {
        unregister_code(dip_codes[index]);
    }
    return true;
}



////////////////////////////////////////////////////////////////////////////////
// MCU LED

void keyboard_pre_init_user(void) {
  setPinOutput(LED_PIN);
  writePinHigh(LED_PIN);
}

/* Runs after each key press, check if activity occurred */
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        gpio_write_pin_low(LED_PIN);
    } else {
        gpio_write_pin_high(LED_PIN);
    }
}



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
        // case KC_1 ... KC_0:
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
