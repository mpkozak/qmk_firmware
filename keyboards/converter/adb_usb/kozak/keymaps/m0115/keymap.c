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

// M0116-specific
// #define KC_CMDG LCMD_T(KC_GRV)          // left command + grave
// #define KC_CMDA RCMD_T(KC_BSLS)         // right command + backslash
// #define KC_OPTA ROPT_T(KC_LEFT)         // right option + left arrow
// #define KC_GRV2 LT(2,KC_GRV)            // backtick/grave + layer 2


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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* M0115
     * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐             ┌───┐
     * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |F13|F14|F15|             | ◀︎ |
     * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘             └───┘
     *
     *
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
     * |Esc|1  |2  |3  |4  |5  |6  |7  |8  |9  |0  |-  |=  |Delete | |Ins|Hom|PUp| |Clr|=  |/  |*  |
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
     * |Tab  |Q  |W  |E  |R  |T  |Y  |U  |I  |O  |P  |[  |]  |\    | |Del|End|PDn  |8  |9  |+  |-  |
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┼───┤
     * |CapsLk|A  |S  |D  |F  |G  |H  |J  |K  |L  |;  |'  |Return  |               |4  |5  |6  |+  |
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
     * |Shift   |Z  |X  |C  |V  |B  |N  |M  |,  |.  |/  |Shift     |     |↑  |     |1  |2  |3  |   |
     * ├─────┬──┴┬──┴───┼───┴───┴───┴───┴───┴───┴─┬─┴───┼───┬──────┤ ┌───┼───┼───┐ ├───┴───┼───┤Ent|
     * |Ctrl |Opt|⌘     |                         |⌘    |Opt|Ctrl  | |←  |↓  |→  | |0      |.  |   |
     * └─────┴───┴──────┴─────────────────────────┴─────┴───┴──────┘ └───┴───┴───┘ └───────┴───┴───┘
     */
    [BASE] = LAYOUT_m0115(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                   KC_PSCR, KC_SCRL, KC_PAUS,                                    QK_BOOT,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,         KC_INS,  KC_HOME, KC_PGUP,         KC_NUM,  KC_PEQL, KC_PSLS, KC_PAST,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,         KC_DEL,  KC_END,  KC_PGDN,         KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
        KC_LCAP, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,                                             KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,                  KC_UP,                    KC_P1,   KC_P2,   KC_P3,
        KC_LCTL, KC_LOPT, KC_LCMD,                            KC_SPC,                                      ___x___, KC_ROPT, KC_RCTL,         KC_LEFT, KC_DOWN, KC_RGHT,         KC_P0,            KC_PDOT, KC_PENT
    ),
    [FN0] = LAYOUT_m0115(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______,                                    _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,                                            _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,                  _______,                  _______, _______, _______,
        _______, _______, _______,                            _______,                                     _______, _______, _______,         _______, _______, _______,         _______,          _______, _______
    ),
    [FN1] = LAYOUT_m0115(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______,                                    _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,                                            _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,                  _______,                  _______, _______, _______,
        _______, _______, _______,                            _______,                                     _______, _______, _______,         _______, _______, _______,         _______,          _______, _______
    ),
    [BASE_SPD] = LAYOUT_m0115(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______,                                    _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,                                            _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,                  _______,                  _______, _______, _______,
        _______, _______, _______,                            _______,                                     _______, _______, _______,         _______, _______, _______,         _______,          _______, _______
    ),
};



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
