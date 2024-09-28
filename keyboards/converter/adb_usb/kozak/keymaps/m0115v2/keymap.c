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
#include "mcu_leds.c"




////////////////////////////////////////////////////////////////////////////////
// Custom keycodes

enum custom_keycodes {
  KC_APFN = SAFE_RANGE,         // apple fn
  LCTL_FN,                      // left control + apple fn (tap-hold)
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
#define KC_DESK C(KC_DOWN)      // show desktop
#define KC_WBAK G(KC_LBRC)      // browser back
#define KC_WFOR G(KC_RBRC)      // browser forward
#define KC_CMNT G(KC_SLSH)      // comment shortcut
#define KC_NTAB G(KC_T)         // new tab
#define KC_REFR LSG(KC_R)       // refresh
#define ___x___ KC_NO           // null

// M0115v2-specific
#define KC_CALU HYPR(KC_PEQL)   // launch calculator from services menu
#define KC_BTAB S(KC_TAB)       // backtab
#define KC_CTAP LCTL_T(KC_CAPS) // left control / tap caps lock



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
    /* M0115
     * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐             ┌───┐
     * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |F13|F14|F15|             |◀︎  |
     * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘             └───┘
     *
     *
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
     * |`  |1  |2  |3  |4  |5  |6  |7  |8  |9  |0  |-  |=  |Delete | |Ins|Hom|Pg↑| |Clr|=  |/  |*  |
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
     * |Tab  |Q  |W  |E  |R  |T  |Y  |U  |I  |O  |P  |[  |]  |\    | |Del|End|Pg↓| |8  |9  |+  |-  |
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┼───┤
     * |CapsLk|A  |S  |D  |F  |G  |H  |J  |K  |L  |;  |'  |Return  |               |4  |5  |6  |+  |
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
     * |Shift   |Z  |X  |C  |V  |B  |N  |M  |,  |.  |/  |Shift     |     |↑  |     |1  |2  |3  |   |
     * ├─────┬──┴─┬─┴───┼───┴───┴───┴───┴───┴───┴─┬─┴───┼────┬─────┤ ┌───┼───┼───┐ ├───┴───┼───┤Ent|
     * |Ctrl |Opt |   ⌘ |                         | ⌘   |Opt |Ctrl | |←  |↓  |→  | |0      |.  |   |
     * └─────┴────┴─────┴─────────────────────────┴─────┴────┴─────┘ └───┴───┴───┘ └───────┴───┴───┘
     */

    [BASE] = LAYOUT_m0115(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,          TO(1),   TO(2),   TT(3),                                      KC_LSCR,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,         KC_INS,  KC_HOME, KC_PGUP,         KC_ESC,  KC_PEQL, KC_PSLS, KC_PAST,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,         KC_DEL,  KC_END,  KC_PGDN,         KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
        KC_CTAP, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,                                             KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,                  KC_UP,                    KC_P1,   KC_P2,   KC_P3,
        LCTL_FN, KC_LOPT, KC_LCMD,                            LT(1,KC_SPC),                                ___x___, KC_ROPT, KC_RCTL,         KC_LEFT, KC_DOWN, KC_RGHT,         LT(1, KC_P0),     KC_PDOT, LT(1, KC_PENT)
    ),
    [FN0] = LAYOUT_m0115(
        TO(0),            C(KC_1), C(KC_2), C(KC_3), C(KC_4), C(KC_5), C(KC_6), C(KC_7), C(KC_8), KC_F13,  KC_F14,  KC_F15,  KC_F16,          TO(0),   _______, _______,                                    QK_BOOT,
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,          _______, _______, _______,         KC_BSPC, KC_CALU, ___x___, KC_MUTE,
        KC_INS,  ___x___, KC_UP,   KC_EMOC, KC_REFR, KC_NTAB, ___x___, ___x___, KC_UP,   ___x___, ___x___, KC_MVLS, KC_MVRS, KC_DEL,          _______, _______, _______,         ___x___, KC_UP,   ___x___, KC_VOLD,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_FSTG, ___x___, ___x___, KC_LEFT, KC_DOWN, KC_RGHT, ___x___, KC_MCTL,          _______,                                            KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLU,
        _______,          KC_ZMNS, KC_ZPLS, KC_ZACT, KC_PSTT, KC_WBAK, KC_WFOR, ___x___, KC_MVLT, KC_MVRT, KC_CMNT,          _______,                  _______,                  G(KC_1), G(KC_2), G(KC_3),
        KC_APFN, _______, _______,                            _______,                                     _______, _______, _______,         KC_BTAB, _______, KC_TAB,          _______,          KC_TAB,  _______
    ),
    [BASE_SPD] = LAYOUT_m0115(
        TO(0),            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, TO(0),   _______,                                    ___x___,
        KC_ESC,  KC_1,    KC_P2,   KC_P3,   KC_P4,   KC_P5,   KC_P6,   KC_P7,   KC_P8,   KC_9,    KC_0,    KC_MINS, ___x___, KC_BSPC,         _______, _______, _______,         TO(0),   KC_PEQL, KC_PSLS, KC_PAST,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    ___x___, ___x___, KC_BSPC,         _______, _______, _______,         KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,                                             KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        OSM(MOD_LSFT),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUES,          KC_RSFT,                  KC_UP,                    KC_P1,   KC_P2,   KC_P3,
        KC_LCTL, KC_LOPT, KC_LCMD,                            KC_SPC,                                      ___x___, KC_ROPT, KC_RCTL,         KC_LEFT, KC_DOWN, KC_RGHT,         KC_P0,            KC_PDOT, KC_PENT
    ),
    [DEFAULT] = LAYOUT_m0115(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,          KC_PSCR, KC_SCRL, KC_PAUS,                                    KC_F20,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,         KC_INS,  KC_HOME, KC_PGUP,         KC_NUM,  KC_PEQL, KC_PSLS, KC_PAST,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,         KC_DEL,  KC_END,  KC_PGDN,         KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,                                             KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,                  KC_UP,                    KC_P1,   KC_P2,   KC_P3,
        KC_LCTL, KC_LOPT, KC_LCMD,                            KC_SPC,                                      ___x___, KC_ROPT, KC_RCTL,         KC_LEFT, KC_DOWN, KC_RGHT,         KC_P0,            KC_PDOT, KC_PENT
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
    mcu_led_enable();
    switch (get_highest_layer(state)) {
        case BASE_SPD:
            if (!autocorrect_is_enabled()) {
                autocorrect_enable();
            }
            mcu_leds_on();
            break;
        default:
            if (autocorrect_is_enabled()) {
                autocorrect_disable();
            }
            mcu_leds_off();
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

bool process_record_spd(uint16_t keycode, keyrecord_t *record) {
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
// Control/Fn tap+hold stack

bool was_ctrl_tapped = false;
bool is_fn_active = false;
uint16_t fn_timer = 0;

void housekeeping_task_user(void) {
    if (was_ctrl_tapped) {
        if (timer_elapsed(fn_timer) >= TAPPING_TERM * 2) {
            was_ctrl_tapped = false;
        }
    }
}

bool process_record_fn(uint16_t keycode, keyrecord_t *record) {
// left control + tap/hold apple fn key
    if (keycode == LCTL_FN) {
        if (record->event.pressed) {    // keydown
            if (was_ctrl_tapped) {      // control was tapped already
                if (timer_elapsed(fn_timer) < TAPPING_TERM * 2) {       // recently enough
                    was_ctrl_tapped = false;
                    host_consumer_send(0x029D);     // send fn
                    is_fn_active = true;
                    return false;
                } else {                // not recently enough
                    was_ctrl_tapped = false;
                }
            }                           // ctrl was not tapped already
            register_code(KC_LCTL);     // send ctrl
            fn_timer = timer_read();    // start timer
            return false;
        } else {                        // keyup
            if (is_fn_active) {         // fn was active
                host_consumer_send(0);  // clear fn
                is_fn_active = false;
                return false;
            }
            if (timer_elapsed(fn_timer) <= TAPPING_TERM * 2) {   // was tapped
                was_ctrl_tapped = true;
                fn_timer = timer_read();     // restart timer
            }
            unregister_code(KC_LCTL);       // clear ctrl
            return false;
        }
    }
// apple fn key
    if (keycode == KC_APFN) {
        if (record->event.pressed) {
            host_consumer_send(0x029D);
        } else {
            host_consumer_send(0);
        }
        return false;
    }
    return true;
}



////////////////////////////////////////////////////////////////////////////////
// Process Record User

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_fn(keycode, record)) {
        return false;
    }
    if (!process_record_spd(keycode, record)) {
        return false;
    }
    // default layer untoggle
    if (keycode == KC_F20) {                        // power key
        if (record->event.pressed) {                // keydown event
            if (get_mods() == MOD_BIT(KC_LCTL)) {   // while left control active
                layer_clear();
                return false;
            }
        }
        return true;
    }
    return true;
}
