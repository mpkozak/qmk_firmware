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

enum user_bootloader_state {
    BOOTLOADER_INACTIVE,
    BOOTLOADER_PRESSED,
    BOOTLOADER_WAIT,
    BOOTLOADER_DO
} bootloader_state;

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
#define KC_WBAK G(KC_LBRC)      // browser back
#define KC_WFOR G(KC_RBRC)      // browser forward
#define KC_BSPW A(KC_BSPC)      // backspace word

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// template
     // _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  // r0
     // _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______,  // r1
     // _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,               _______,  // r2
     // _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______,  // r3
     //              _______,  _______,                                _______,                                _______,  _______),                 // r4

    [BASE] = LAYOUT_ansi_60(        // layer 0 - white
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,        KC_BSPC,
        KC_LCTL,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,               KC_ENT,
        KC_LSFT,         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,             KC_RSFT, MO(2),
                    KC_LOPTN, KC_LCMMD,                               LT(2,KC_SPC),                           KC_RCMMD, KC_ROPTN),

    [BASE_SPD] = LAYOUT_ansi_60(    // layer 1 - orange
        TO(0),     KC_1,    KC_P2,   KC_P3,   KC_P4,   KC_P5,   KC_P6,   KC_P7,   KC_P8,   KC_9,    KC_0,    KC_PMNS, KC_NO,   KC_NO,   KC_BSPC,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,   KC_NO,          KC_BSPW,
        KC_NO,         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,               KC_ENT,
        OSM(MOD_LSFT),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_PDOT, KC_QUES,             KC_RSFT, MO(2),
                    KC_LCTL,  KC_LCMMD,                               LT(2,KC_SPC),                           KC_RCMMD, KC_ROPTN),

    [BASE_FN] = LAYOUT_ansi_60(     // layer 2 - cyan
        KC_LSCR,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  RGB_VAD, RGB_VAI,
        KC_TAB,      KC_MVLT, KC_MVRT, KC_EMOC, KC_NO,   TG(1),   KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,   KC_BRID, KC_BRIU,        TT(4),
        KC_LCTL,       KC_MVLS, KC_MVRS, KC_F11,  KC_FSTG, KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_MVLS, KC_MVRS,               TG(1),
        KC_LSFT,         KC_ZMNS, KC_ZPLS, KC_ZACT, KC_PSTT, KC_WBAK, KC_WFOR, QK_KB_0, KC_VOLD, KC_VOLU, KC_MUTE,             KC_RSFT, _______,
                    KC_LOPTN, KC_LCMMD,                               _______,                                KC_CAPS,  TT(3)),

    [_FN1] = LAYOUT_ansi_60(        // layer 3 - green
        TO(0),     KC_BRID, KC_BRIU, QK_KB_0, QK_KB_1, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,   KC_NO,
        _______,     KC_NO,   KC_NO,   KC_NO,   NK_TOGG, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,          _______,
        _______,       RGB_SAD, RGB_SAI, KC_NO,   KC_NO,   RGB_HUD, RGB_HUI, KC_NO,   RGB_VAD, RGB_VAI, KC_NO,   KC_NO,                 _______,
        _______,         KC_NO,   KC_NO,   RGB_SPD, RGB_SPI, KC_NO,   RGB_RMOD,RGB_MOD, KC_NO,   KC_NO,   KC_NO,               _______, _______,
                    _______,  _______,                                RGB_TOG,                                _______,  _______),

    [_FN2] = LAYOUT_ansi_60(        // layer 4 - blue
        TO(0),     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        _______,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,          _______,
        _______,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                 _______,
        _______,         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,               _______, _______,
                    _______,  _______,                                KC_SPC,                                 _______,  _______)
};

// clang-format on

void keyboard_post_init_user(void) {
    user_config_read_eeprom();
#ifdef AUTOCORRECT_OFF_AT_STARTUP
    // toggle autocorrect off at startup
    if (autocorrect_is_enabled()) {
        autocorrect_toggle();
    }
#endif
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
        case KC_1 ... KC_0:
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
    if (process_record_keychron(keycode, record)) {
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
            default:
                return true;  // Process all other keycodes normally
        }
    }
    return true;
}
