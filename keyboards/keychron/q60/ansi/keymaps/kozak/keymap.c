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
// #include "keychron_common.h"
#include "keymap_user.h"
#include "keymap_user_config.h"
#ifdef RGB_MATRIX_ENABLE
#    include "rgb_matrix_user.h"
#endif
#include "custom_keycodes.h"
#include "fn_key.c"
#include "spd_autocorrect.c"



////////////////////////////////////////////////////////////////////////////////
// Bootloader

enum user_bootloader_state {
    BOOTLOADER_INACTIVE,
    BOOTLOADER_PRESSED,
    BOOTLOADER_WAIT,
    BOOTLOADER_DO
} bootloader_state;



////////////////////////////////////////////////////////////////////////////////
// Custom keycodes

#define UP_RSFT RSFT_T(KC_UP)   // right shift under up arrow
#define DOWN_L3 LT(3, KC_DOWN)  // right fn (layer 3) under down arrow
#define LFT_CMD RCMD_T(KC_LEFT) // right command under left arrow
#define RGT_OPT ROPT_T(KC_RGHT) // right option under right arrow



////////////////////////////////////////////////////////////////////////////////
// Layout

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ \ │ ` │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ Bspc│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │ Ctrl │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ Fn│
     * └─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─┴───┘
     *       │Opt│ Cmd │                           │ Cmd │Opt│
     *       └───┴─────┴───────────────────────────┴─────┴───┘
     */

// template
     // _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  // r0
     // _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______,  // r1
     // _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,               _______,  // r2
     // _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______,  // r3
     //              _______,  _______,                                _______,                                _______,  _______),                // r4

    [BASE] = LAYOUT_ansi_60(        // layer 0 BASE - white
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,        KC_BSPC,
        LCTL_FN,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,               KC_ENT,
        KC_LSFT,         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,             UP_RSFT, DOWN_L3,
                    KC_LOPT,  KC_LCMD,                                LT(2,KC_SPC),                           LFT_CMD,  RGT_OPT
    ),

    [SPD] = LAYOUT_ansi_60(         // layer 1 SPD - orange
        TO(0),     KC_1,    KC_P2,   KC_P3,   KC_P4,   KC_P5,   KC_P6,   KC_P7,   KC_P8,   KC_9,    KC_0,    KC_MINS, ___x___, ___x___, KC_BSPC,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    ___x___, ___x___,        KC_BSPC,
        ___x___,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,               KC_ENT,
        OSM(MOD_LSFT),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUES,             KC_RSFT, MO(3),
                    KC_LOPT,  KC_LCMD,                                LT(2,KC_SPC),                           KC_RCMD,  KC_ROPT
    ),

    [FN0] = LAYOUT_ansi_60(         // layer 2 FN0 - blue [space fn]
        KC_LSCR,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  RGB_VAD, RGB_VAI,
        KC_INS,      ___x___, KC_UP,   KC_EMOC, KC_REFR, KC_NTAB, ___x___, ___x___, KC_UP,   ___x___, ___x___, KC_MVLT, KC_MVRT,        KC_DEL,
        KC_LCTL,       KC_LEFT, KC_DOWN, KC_RGHT, KC_FSTG, KC_LPAD, ___x___, KC_LEFT, KC_DOWN, KC_RGHT, ___x___, KC_MCTL,               KC_ENT,
        KC_LSFT,         KC_ZMNS, KC_ZPLS, KC_ZACT, KC_PSTT, KC_WBAK, KC_WFOR, ___x___, KC_MVLT, KC_MVRT, KC_CMNT,             KC_RSFT, MO(3),
                    KC_LOPT,  KC_LCMD,                                _______,                                KC_RCMD,  KC_ROPT
    ),

    [FN1] = LAYOUT_ansi_60(         // layer 3 FN1 - green [quick toggles]
        QK_BOOT,   ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, RGB_VAD, RGB_VAI, KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU,
        KC_TAB,      ___x___, ___x___, ___x___, ___x___, TO(1),   ___x___, ___x___, ___x___, ___x___, ___x___, KC_MVLT, KC_MVRT,        KC_MUTE,
        _______,       ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_LPAD, KC_MCTL, KC_DESK,               KC_PENT,
        KC_CAPS,         ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_DESK, KC_MVLS, KC_MVRS,             KC_CAPS, _______,
                    _______,  _______,                                _______,                                _______, MO(4)
    ),

    [FN2] = LAYOUT_ansi_60(         // layer 4 FN2 - cyan [mac media keys + rbg settings]
        QK_BOOT,   ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_MPRV, KC_MPLY, KC_MNXT, ___x___, ___x___, ___x___, _______, _______,
        _______,     ___x___, ___x___, ___x___, NK_TOGG, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_TGTL, KC_TGCL,        _______,
        _______,       RGB_SAD, RGB_SAI, ___x___, ___x___, RGB_HUD, RGB_HUI, ___x___, RGB_VAD, RGB_VAI, ___x___, ___x___,               _______,
        RGB_TOG,         ___x___, ___x___, RGB_SPD, RGB_SPI, ___x___, RGB_RMOD,RGB_MOD, ___x___, ___x___, ___x___,             _______, _______,
                    _______,  _______,                                _______,                                _______,  _______
    )
};

// clang-format on



////////////////////////////////////////////////////////////////////////////////
// User hooks

void matrix_init_user(void) {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_init_user();
#endif
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
    state = layer_state_set_ac(state);
    return state;
}

void keyboard_post_init_user(void) {
    keyboard_post_init_ac();
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
    housekeeping_task_fn();
    // housekeeping_task_keychron();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_fn(keycode, record)) {
        return false;
    }
    if (!process_record_ac(keycode, record)) {
        return false;
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
    // if (!process_record_keychron(keycode, record)) {
    //     return false;
    // }
    return true;
}
