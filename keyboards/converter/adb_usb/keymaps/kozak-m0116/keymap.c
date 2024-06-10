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
#define ___x___ KC_NO           // nukk

// M0116-specific
// #define KC_CMDG LCMD_T(KC_GRV)          // left command + grave
#define KC_CMDA RCMD_T(KC_BSLS)         // right command + backslash
#define KC_OPTA ROPT_T(KC_LEFT)         // right option + left arrow
#define KC_GRV2 LT(2,KC_GRV)            // backtick/grave + layer 2


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* M0116
     *                     ┌───────┐
     *                     |◀︎      |
     *                     └───────┘
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐ ┌───┬───┬───┬───┐
     * |Esc|1  |2  |3  |4  |5  |6  |7  |8  |9  |0  |-  |=  |Backs| |Clr|=  |/  |*  |
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤ ├───┼───┼───┼───┤
     * |Tab  |Q  |W  |E  |R  |T  |Y  |U  |I  |O  |P  |[  |]  |   | |7  |8  |9  |+  |
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┘   | ├───┼───┼───┼───┤
     * |Ctrl  |A  |S  |D  |F  |G  |H  |J  |K  |L  |;  |'  |Return| |4  |5  |6  |-  |
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──────┤ ├───┼───┼───┼───┤
     * |Shift   |Z  |X  |C  |V  |B  |N  |M  |,  |.  |/  |Shift   | |1  |2  |3  |   |
     * ├───┬───┬┴───┴─┬─┴─┬─┴───┴───┴───┴───┴┬──┴┬──┴┬──┴┬───┬───┘ ├───┴───┼───┤Ent|
     * |Cap|Opt|⌘     |`  |                  |\  |←  |→  |↓  |↑  | |0      |.  |   |
     * └───┴───┴──────┴───┴──────────────────┴───┴───┴───┴───┴───┘ └───────┴───┴───┘
     */

    [BASE] = LAYOUT_m0116_ansi(
                                                     KC_LSCR,
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,         KC_DEL,  KC_PEQL, KC_PSLS, KC_PAST,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                  KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,          KC_P4,   KC_P5,   KC_P6,   KC_PMNS,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,         KC_P1,   KC_P2,   KC_P3,
        KC_GRV2, KC_LOPT, KC_LCMD, MO(2),                     LT(1,KC_SPC),              KC_CMDA, KC_OPTA, KC_RGHT, KC_DOWN, LT(2,KC_UP),     LT(2, KC_P0),     KC_PDOT, LT(2, KC_PENT)
    ),
    [FN0] = LAYOUT_m0116_ansi(
                                                     _______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,          KC_INS,  _______, _______, _______,
        KC_INS,  KC_MVLT, KC_MVRT, KC_EMOC, KC_REFR, KC_NTAB, ___x___, ___x___, KC_UP,   ___x___, ___x___, KC_MVLS, KC_MVRS,                  _______, _______, _______, _______,
        _______, KC_MVLS, KC_MVRS, KC_DESK, KC_FSTG, KC_LPAD, ___x___, KC_LEFT, KC_DOWN, KC_RGHT, ___x___, KC_MCTL,          KC_BSPC,         _______, _______, _______, _______,
        _______,          KC_ZMNS, KC_ZPLS, KC_ZACT, KC_PSTT, KC_WBAK, KC_WFOR, ___x___, KC_MVLT, KC_MVRT, KC_CMNT,          _______,         _______, _______, _______,
        _______, _______, _______, _______,                   _______,                   _______, _______, _______, _______, _______,         _______,          _______, _______
    ),
    [FN1] = LAYOUT_m0116_ansi(
                                                     QK_BOOT,
        ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_MUTE,         QK_BOOT, ___x___, ___x___, KC_MUTE,
        _______, ___x___, KC_UP,   ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,                  ___x___, KC_UP,   ___x___, KC_VOLU,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,          _______,         KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD,
        _______,          KC_DESK, KC_MVLS, KC_MVRS, KC_PSTT, ___x___, ___x___, KC_MCTL, KC_DESK, KC_MVLS, KC_MVRS,          _______,         ___x___, ___x___, ___x___,
        _______, _______, _______, _______,                   _______,                   _______, KC_MVLS, KC_MVRS, KC_DESK, _______,         _______,          ___x___, _______
    )
};



// ---------------------------------------|xxxxxxxxxxxxxxx|-----------------------------------------------------------|-------|-------------------------------|
//                                             KC_EJCT,
// xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxxxxxx|-------|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|
// KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL,     KC_BSPC,        KC_NUM, KC_EQL, KC_PSLS,KC_PAST,
// xxxxxxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|-------|-------|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|
// KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,                KC_P7,  KC_P8,  KC_P9,  KC_PPLS,
// xxxxxxxxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxxxxxxxx|-------|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|
// KC_LCTL,      KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,      KC_ENT,         KC_P4,  KC_P5,  KC_P6,  KC_PMNS,
// xxxxxxxxxxxxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxxxxxxxxxxxx|-------|xxxxxxx|xxxxxxx|xxxxxxx|-------|
// KC_LSFT,          KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,        KC_P1,  KC_P2,  KC_P3,
// xxxxxxx|xxxxxxx|xxxxxxxxxxxxx|xxxxxxx|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|xxxxxxx|-------|xxxxxxx|-------|xxxxxxx|xxxxxxx|
// KC_LCAP,KC_LALT,   KC_LGUI,   KC_GRV,                KC_SPC,                KC_BSLS,KC_LEFT,KC_RGHT,KC_DOWN,KC_UP,          KC_P0,          KC_PDOT,KC_PENT
