// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H



#define ___x___ KC_NO           // null

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

    [0] = LAYOUT_5120_numpad(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,         KC_DEL,  KC_PEQL, KC_PSLS, KC_PAST,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,         KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,          KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,         KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCAP, KC_LOPT, KC_LCMD, KC_GRV,                    KC_SPC,                    KC_PENT, KC_LEFT, KC_RGHT, KC_DOWN, KC_UP,           KC_P0,            KC_PDOT
    )

    // [0] = LAYOUT_5120_ansi(
    //     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    //     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    //     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    //     KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
    //     KC_LCAP, KC_LOPT, KC_LCMD, KC_GRV,                    KC_SPC,                    KC_PENT, KC_LEFT, KC_RGHT, KC_DOWN, KC_UP
    // )
};



const uint16_t PROGMEM dip_codes[5] = {
    KC_LCAP,
    KC_LSFT,
    KC_LCTL,
    KC_LOPT,
    KC_LCMD
};

bool dip_switch_update_user(uint8_t index, bool active) {
    if (active) {
        register_code(dip_codes[index]);
    } else {
        unregister_code(dip_codes[index]);
    }
    return true;
}



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





// // Does not work

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
