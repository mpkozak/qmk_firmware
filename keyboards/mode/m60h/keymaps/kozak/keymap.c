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
// #include "keymap_user_config.h"
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
// #define KC_BSPW A(KC_BSPC)      // backspace word
// #define KC_FRCQ LAG(KC_ESC)     // force quit
#define KC_CMNT G(KC_SLSH)      // comment shortcut
#define KC_NTAB G(KC_T)         // new tab
#define KC_REFR LSG(KC_R)       // refresh

// right-side mod arrow cluster
#define KC_RSUP RSFT_T(KC_UP)   // right shift under up arrow
#define KC_RFDN LT(2, KC_DOWN)  // right fn (layer 2) under down arrow
#define KC_RCLF RCMD_T(KC_LEFT) // right command under left arrow
#define KC_RORT ROPT_T(KC_RGHT) // right option under right arrow

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
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSUP, KC_RFDN,
                          KC_LOPT, KC_LCMD,                   LT(1,KC_SPC),                       KC_RCLF, KC_RORT
    ),

    [BASE_FN] = LAYOUT_60_hhkb(    // layer 1 BASE_FN - blue
        TO(0),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  RGB_VAD, RGB_VAI,
        KC_INS,  KC_MVLT, KC_MVRT, KC_EMOC, KC_REFR, KC_NTAB, KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,   KC_MVLS, KC_MVRS, KC_DEL,
        KC_LCTL, KC_MVLS, KC_MVRS, KC_DESK, KC_FSTG, KC_LPAD, KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_MCTL,          KC_ENT,
        KC_LSFT,          KC_ZMNS, KC_ZPLS, KC_ZACT, KC_PSTT, KC_WBAK, KC_WFOR, KC_NO,   KC_MVLT, KC_MVRT, KC_CMNT, KC_RSFT, MO(2),
                          KC_LOPT, KC_LCMD,                   _______,                            KC_RCMD, KC_ROPT
    ),

    [_FN1] = LAYOUT_60_hhkb(       // layer 2 _FN1 - orange [right-side arrows + quick toggles]
        KC_LSCR, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RGB_VAD, RGB_VAI, KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU,
        KC_TAB,  KC_MVLT, KC_MVRT, KC_EMOC, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_UP,   KC_MVLT, KC_MVRT, KC_MUTE,
        _______, KC_MVLS, KC_MVRS, KC_DESK, KC_FSTG, KC_NO,   KC_NO,   KC_NO,   KC_LPAD, KC_LEFT, KC_DOWN, KC_RGHT,          KC_PENT,
        _______,          KC_NO,   KC_NO,   KC_NO,   KC_PSTT, KC_NO,   KC_NO,   KC_MCTL, KC_DESK, KC_MVLS, KC_MVRS, KC_CAPS, _______,
                          _______, _______,                   _______,                            _______, TT(3)
    ),

    [_FN2] = LAYOUT_60_hhkb(       // layer 3 _FN2 - green [mac media keys + rbg settings]
        TO(0),   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,   KC_NO,   KC_NO,   _______, _______,
        _______, QK_BOOT, KC_NO,   KC_NO,   NK_TOGG, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
        _______, RGB_SAD, RGB_SAI, KC_NO,   KC_NO,   RGB_HUD, RGB_HUI, KC_NO,   RGB_VAD, RGB_VAI, KC_NO,   KC_NO,            _______,
        RGB_TOG,          KC_NO,   KC_NO,   RGB_SPD, RGB_SPI, KC_NO,   RGB_RMOD,RGB_MOD, KC_NO,   KC_NO,   KC_NO,   _______, _______,
                          _______, _______,                   _______,                            _______, _______
    )

};

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





// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     return process_record_kozak(keycode, record);
// }





// RGB rgb_scaled_to_val(uint8_t val, uint8_t red, uint8_t green, uint8_t blue) {
//     float value = val;
//     RGB rgb;
//     rgb.r = red * (value / 255);
//     rgb.g = green * (value / 255);
//     rgb.b = blue * (value / 255);
//     return rgb;
// }

// layer_state_t default_layer_state_set_user(layer_state_t state) {
//     HSV hsv = {RGBLIGHT_DEFAULT_HUE, RGBLIGHT_DEFAULT_SAT, RGBLIGHT_DEFAULT_VAL};
//     RGB rgb = hsv_to_rgb(hsv);
//     switch (get_highest_layer(state)) {
//         case BASE:
//             if (rgblight_is_enabled()) {
//                 rgblight_setrgb(rgb.r, rgb.g, rgb.b);
//             }
//             break;
//         default:
//             break;
//     }
//     return state;
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//     uint8_t current_layer = get_highest_layer(layer_state);
//     uint8_t current_val = rgblight_get_val();
//     HSV hsv = {RGBLIGHT_DEFAULT_HUE, RGBLIGHT_DEFAULT_SAT, current_val};
//     RGB rgb = hsv_to_rgb(hsv);
//     switch (current_layer) {
//         case BASE:
//             break;
//         case BASE_FN:
//             rgb = rgb_scaled_to_val(current_val, FN0_LAYER_COLOR);
//             break;
//         case _FN1:
//             rgb = rgb_scaled_to_val(current_val, FN1_LAYER_COLOR);
//             break;
//         case _FN2:
//             rgb = rgb_scaled_to_val(current_val, FN2_LAYER_COLOR);
//             break;
//         default:
//             rgb = hsv_to_rgb(hsv);
//             break;
//     }
//     if (rgblight_is_enabled()) {
//         rgblight_setrgb(rgb.r, rgb.g, rgb.b);
//     }
//     return state;
// }
