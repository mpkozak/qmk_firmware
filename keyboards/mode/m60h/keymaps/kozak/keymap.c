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
#define KC_DESK C(KC_DOWN)      // show desktop
#define KC_WBAK G(KC_LBRC)      // browser back
#define KC_WFOR G(KC_RBRC)      // browser forward
#define KC_CMNT G(KC_SLSH)      // comment shortcut
#define KC_NTAB G(KC_T)         // new tab
#define KC_REFR LSG(KC_R)       // refresh
#define ___x___ KC_NO           // null

// right-side mod arrow cluster
#define KC_SHUP RSFT_T(KC_UP)   // right shift under up arrow
#define KC_FNRT LT(2, KC_RGHT)  // right fn (layer 2) under right arrow
#define KC_CMLF RCMD_T(KC_LEFT) // right command under left arrow
#define KC_OPDN ROPT_T(KC_DOWN) // right option under down arrow



////////////////////////////////////////////////////////////////////////////////
// Layout

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

    [BASE] = LAYOUT_60_hhkb(       // layer 0 BASE - white
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SHUP, KC_FNRT,
                          KC_LOPT, KC_LCMD,                   LT(1,KC_SPC),                       KC_CMLF, KC_OPDN
    ),

    [BASE_FN] = LAYOUT_60_hhkb(    // layer 1 BASE_FN - blue [space fn]
        KC_LSCR, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  RGB_VAD, RGB_VAI,
        KC_INS,  KC_MVLT, KC_MVRT, KC_EMOC, KC_REFR, KC_NTAB, ___x___, ___x___, KC_UP,   ___x___, ___x___, KC_MVLS, KC_MVRS, KC_DEL,
        _______, KC_MVLS, KC_MVRS, KC_DESK, KC_FSTG, KC_LPAD, ___x___, KC_LEFT, KC_DOWN, KC_RGHT, ___x___, KC_MCTL,          KC_ENT,
        _______,          KC_ZMNS, KC_ZPLS, KC_ZACT, KC_PSTT, KC_WBAK, KC_WFOR, ___x___, KC_MVLT, KC_MVRT, KC_CMNT, KC_RSFT, MO(2),
                          _______, _______,                   _______,                            KC_RCMD, KC_ROPT
    ),

    [_FN1] = LAYOUT_60_hhkb(       // layer 2 _FN1 - orange [right-side arrows + quick toggles]
        KC_LSCR, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, RGB_VAD, RGB_VAI, KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU,
        KC_TAB,  KC_MVLT, KC_MVRT, KC_EMOC, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_UP,   KC_MVLT, KC_MVRT, KC_MUTE,
        _______, KC_MVLS, KC_MVRS, KC_DESK, KC_FSTG, ___x___, ___x___, ___x___, KC_LPAD, KC_LEFT, KC_DOWN, KC_RGHT,          KC_PENT,
        _______,          ___x___, ___x___, ___x___, KC_PSTT, ___x___, ___x___, KC_MCTL, KC_DESK, KC_MVLS, KC_MVRS, KC_CAPS, _______,
                          _______, _______,                   _______,                            _______, MO(3)
    ),

    [_FN2] = LAYOUT_60_hhkb(       // layer 3 _FN2 - green [mac media keys + rbg settings]
        QK_BOOT, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_MPRV, KC_MPLY, KC_MNXT, ___x___, ___x___, ___x___, _______, _______,
        _______, ___x___, ___x___, ___x___, NK_TOGG, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, _______,
        _______, RGB_SAD, RGB_SAI, ___x___, ___x___, RGB_HUD, RGB_HUI, ___x___, RGB_VAD, RGB_VAI, ___x___, ___x___,          _______,
        RGB_TOG,          ___x___, ___x___, RGB_SPD, RGB_SPI, ___x___, RGB_RMOD,RGB_MOD, ___x___, ___x___, ___x___, _______, _______,
                          _______, _______,                   _______,                            _______, _______
    )
};



////////////////////////////////////////////////////////////////////////////////
// RGB layers

const rgblight_segment_t PROGMEM rbg_layer_base[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, BASE_LAYER_HSV}
);

const rgblight_segment_t PROGMEM rbg_layer_base_fn[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, FN0_LAYER_HSV}
);

const rgblight_segment_t PROGMEM rbg_layer_fn1[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, FN1_LAYER_HSV}
);

const rgblight_segment_t PROGMEM rbg_layer_fn2[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, FN2_LAYER_HSV}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rbg_layer_base,
    rbg_layer_base_fn,
    rbg_layer_fn1,
    rbg_layer_fn2
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, BASE));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, BASE));
    rgblight_set_layer_state(1, layer_state_cmp(state, BASE_FN));
    rgblight_set_layer_state(2, layer_state_cmp(state, _FN1));
    rgblight_set_layer_state(3, layer_state_cmp(state, _FN2));
    return state;
}



////////////////////////////////////////////////////////////////////////////////
// RGB timeout

// https://github.com/qmk/qmk_firmware/blob/master/docs/custom_quantum_functions.md#keyboard-housekeeping

static uint32_t key_timer;           // timer for last keyboard activity, use 32bit value and function to make longer idle time possible
static void refresh_rgb(void);       // refreshes the activity timer and RGB, invoke whenever any activity happens
static void check_rgb_timeout(void); // checks if enough time has passed for RGB to timeout
bool is_rgb_timeout = false;         // store if RGB has timed out or not in a boolean

void refresh_rgb(void) {
    key_timer = timer_read32();     // store time of last refresh
    if (is_rgb_timeout) {
        is_rgb_timeout = false;
        rgblight_wakeup();
    }
}

void check_rgb_timeout(void) {
    if (!is_rgb_timeout && timer_elapsed32(key_timer) > RGBLIGHT_TIMEOUT) {     // check if RGB has already timeout and if enough time has passed
        rgblight_suspend();
        is_rgb_timeout = true;
    }
}

/* Then, call the above functions from QMK's built in post processing functions like so */
/* Runs at the end of each scan loop, check if RGB timeout has occured or not */
void housekeeping_task_user(void) {
    #ifdef RGBLIGHT_TIMEOUT
        check_rgb_timeout();
    #endif
}

/* Runs after each key press, check if activity occurred */
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef RGBLIGHT_TIMEOUT
        if (record->event.pressed) {
            refresh_rgb();
        }
    #endif
}
