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
#include "keychron_common.h"
#include "keymap_user.h"
#include "keymap_user_config.h"
#ifdef RGB_MATRIX_ENABLE
#    include "rgb_matrix_user.h"
#endif

enum user_bootloader_state {
    BOOTLOADER_INACTIVE,
    BOOTLOADER_PRESSED,
    BOOTLOADER_WAIT,
    BOOTLOADER_DO
} bootloader_state;

enum user_keycodes {
    KC_FN_LAYER_TRANSPARENT_KEYS_TOGGLE = QK_USER_0,
    KC_FN_LAYER_COLOR_TOGGLE,
};

#define KC_TGTL KC_FN_LAYER_TRANSPARENT_KEYS_TOGGLE
#define KC_TGCL KC_FN_LAYER_COLOR_TOGGLE

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
#define KC_MVRS C(KC_RGHT)      // move right spacee
#define KC_DESK KC_F11          // show desktop
#define KC_WBAK G(KC_LBRC)      // browser back
#define KC_WFOR G(KC_RBRC)      // browser forward
#define KC_BSPW A(KC_BSPC)      // backspace word
#define KC_FRCQ LAG(KC_ESC)     // force quit

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// template
    // [BASE] = LAYOUT_numpad_6x5(
    //     _______,   _______,  _______,  _______,  _______,
    //     _______,   _______,  _______,  _______,  _______,
    //     _______,   _______,  _______,  _______,  _______,
    //     _______,   _______,  _______,  _______,
    //     _______,   _______,  _______,  _______,  _______,
    //     _______,   _______,            _______),

    [BASE] = LAYOUT_numpad_6x5(     // layer 0 - white
        KC_MUTE,   TO(1),    TO(2),    TO(3),    TO(4),
        KC_ESC,    KC_PEQL,  KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_HOME,   KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
        KC_END,    KC_P4,    KC_P5,    KC_P6,
        KC_LCTL,   KC_P1,    KC_P2,    KC_P3,    LT(2,KC_PENT),
        TT(3),     LT(1,KC_P0),        KC_PDOT),

    [BASE_CALC] = LAYOUT_numpad_6x5(     // layer 1 - orange
        KC_ZACT,   TO(0),    TO(2),    TO(3),    TO(4),
        KC_BSPC,   KC_PEQL,  KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_LPRN,   KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
        KC_RPRN,   KC_P4,    KC_P5,    KC_P6,
        KC_SPC,    KC_P1,    KC_P2,    KC_P3,    LT(2,KC_PENT),
        TT(3),     LT(5,KC_P0),        KC_PDOT),

    [BASE_FN] = LAYOUT_numpad_6x5(     // layer 2 - cyan
        KC_LSCR,   TO(1),    TO(0),    TO(3),    TO(4),
        KC_BSPC,   KC_WBAK,  KC_WFOR,  KC_ZACT,  KC_ZMNS,
        KC_PGUP,   KC_MVLT,  QK_KB_0,  KC_MVRT,  KC_ZPLS,
        KC_PGDN,   KC_MVLS,  KC_UP,    KC_MVRS,
        KC_LCMMD,  KC_LEFT,  KC_DOWN,  KC_RGHT,  MT(MOD_LSFT,KC_PENT),
        _______,   LT(3,KC_SPC),       KC_LOPTN),

    [_FN1] = LAYOUT_numpad_6x5(     // layer 3 - blue
        KC_ZACT,   TO(1),    TO(2),    TO(0),    TO(4),
        KC_LSCR,   G(KC_X),  G(KC_C),  G(KC_V),  KC_PSTT,
        KC_FSTG,   KC_MVLT,  QK_KB_0,  KC_MVRT,  G(KC_Z),
        KC_FRCQ,   KC_MVLS,  KC_UP,    KC_MVRS,
        KC_BSPC,   KC_LEFT,  KC_DOWN,  KC_RGHT,  MT(MOD_LSFT,KC_PENT),
        _______,   KC_SPC,             KC_DESK),

    [_FN2] = LAYOUT_numpad_6x5(     // layer 4 - green
        RGB_TOG,   TO(1),    TO(2),    TO(3),    TO(0),
        _______,   RGB_HUI,  RGB_SAI,  RGB_VAI,  _______,
        KC_TGCL,   RGB_HUD,  RGB_SAD,  RGB_VAD,  _______,
        KC_TGTL,   RGB_MOD,  RGB_SPI,  _______,
        _______,   RGB_RMOD, RGB_SPD,  _______,  _______,
        _______,   RGB_TOG,            _______),

    [_FN3] = LAYOUT_numpad_6x5(     // layer 5 - yellow
        _______,   _______,  _______,  _______,  _______,
        _______,   KC_DLR,   KC_PERC,  KC_CIRC,  KC_UNDS,
        _______,   KC_LPRN,  _______,  KC_RPRN,  KC_AMPR,
        _______,   _______,  _______,  _______,
        _______,   _______,  _______,  _______,  KC_PIPE,
        _______,   _______,            KC_QUES)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [BASE_CALC] = { ENCODER_CCW_CW(KC_ZMNS, KC_ZPLS) },
    [BASE_FN] = { ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
    [_FN1] = { ENCODER_CCW_CW(KC_ZMNS, KC_ZPLS) },
    [_FN2] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [_FN3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif // ENCODER_MAP_ENABLE

// clang-format on

void matrix_init_user(void) {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_init_user();
#endif
}

void keyboard_post_init_user(void) {
    user_config_read_eeprom();
}

void housekeeping_task_user(void) {
    switch(bootloader_state) {
        case BOOTLOADER_DO:
            // bootloader was pressed two frames ago. RGB should now be off,
            // so we can call the bootloader.
            reset_keyboard();
            break;
        case BOOTLOADER_WAIT:
            // bootloader was pressed on previous frame, we wait this frame and
            // set flag to do bootloader at end of next frame. For some reason, my
            // Q2 needed this extra wait frame.
            bootloader_state = BOOTLOADER_DO;
            break;
        case BOOTLOADER_PRESSED:
            // User pressed bootloader keycode and RGB was disabled earlier in this
            // frame. However RGB changes wont take place immediately, so we set a
            // flag here which will be caught at end of the next frame.
            bootloader_state = BOOTLOADER_WAIT;
            break;
        default:
            break;
    }
    housekeeping_task_keychron();
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case BASE:
            // load base settings
            rgb_matrix_enable_noeeprom();
            rgb_matrix_reload_from_eeprom();
            // check disable
            if (!user_config_get_enable_rgb()) {
                rgb_matrix_disable_noeeprom();
            }
            break;
        default:
            break;
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (process_record_keychron(keycode, record)) {
        switch (keycode) {
            case QK_BOOT:
                // We want to turn off LEDs before calling bootloader, so here
                // we call rgb_matrix_disable_noeeprom() and set a flag because
                // the LEDs won't be updated until the next frame.
                if (record->event.pressed) {
                    rgb_matrix_disable_noeeprom();
                    bootloader_state = BOOTLOADER_PRESSED;
                }
                return false;  // Skip all further processing of this key
            case RGB_TOG:
                if (record->event.pressed) {
                    rgb_matrix_toggle_noeeprom();
                    user_config_toggle_enable_rgb();
                }
                return false;  // Skip all further processing of this key
            case KC_FN_LAYER_TRANSPARENT_KEYS_TOGGLE:
                if (record->event.pressed) {
                    user_config_toggle_fn_layer_transparent_keys_off();
                }
                return false;  // Skip all further processing of this key
            case KC_FN_LAYER_COLOR_TOGGLE:
                if (record->event.pressed) {
                    user_config_toggle_fn_layer_color_enable();
                }
                return false;  // Skip all further processing of this key
            default:
                return true;  // Process all other keycodes normally
        }
    }
    return true;
}
