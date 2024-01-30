#include QMK_KEYBOARD_H



#define KC_SPUP LT(1,KC_SPC)      // space-fn
#define KC_UPUP LT(1,KC_SPC)      // up-fn
#define KC_NZUP LT(1,KC_P0)       // nzero-fn
#define KC_GCMD LGUI_T(KC_GRV)    // grave-command
#define KC_BCMD RGUI_T(KC_BSLS)   // backslash-command


#define KC_MCTL QK_KB_0
#define KC_LPAD QK_KB_1
#define KC_LSCR C(G(KC_Q))      // lock screen
#define KC_EMOC C(G(KC_SPC))    // character picker
#define KC_FSTG C(G(KC_F))      // fullscreen toggle
#define KC_PSTT S(A(G(KC_V)))   // paste plaintext
#define KC_MVLT LSG(KC_LBRC)    // move left tab
#define KC_MVRT LSG(KC_RBRC)    // move right tab
#define KC_MVLS C(KC_LEFT)      // move left space
#define KC_MVRS C(KC_RGHT)      // move right space
#define KC_DESK KC_F11          // show desktop
#define KC_WBAK G(KC_LBRC)      // browser back
#define KC_WFOR G(KC_RBRC)      // browser forward
#define KC_NTAB G(KC_T)         // new tab
#define KC_REFR LSG(KC_R)       // refresh



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_m0116_ansi(
                                                    KC_LSCR,
        KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL,     KC_BSPC,        KC_NUM, KC_PEQL,KC_PSLS,KC_PAST,
        KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,                KC_P7,  KC_P8,  KC_P9,  KC_PPLS,
        KC_LCTL,      KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,      KC_ENT,         KC_P4,  KC_P5,  KC_P6,  KC_PMNS,
        KC_LSFT,          KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,        KC_P1,  KC_P2,  KC_P3,
        KC_LCAP,KC_LALT,   KC_LGUI,   KC_GCMD,               KC_SPUP,               KC_BCMD,KC_LEFT,KC_RGHT,KC_DOWN,KC_UPUP,        KC_NZUP,        KC_PDOT,KC_PENT
    ),
    [1] = LAYOUT_m0116_ansi(
                                                    QK_BOOT,
        _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,     KC_DEL,         KC_NO,  KC_NO,  KC_NO,  KC_MUTE,
        KC_INS,     KC_MVLT,KC_MVRT,KC_EMOC,KC_REFR,KC_NTAB,KC_NO,  KC_NO,  KC_UP,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                  KC_NO,  KC_UP,  KC_NO,  KC_VOLU,
        _______,      KC_MVLS,KC_MVRS,KC_DESK,KC_FSTG,KC_LPAD,KC_NO,  KC_LEFT,KC_DOWN,KC_RGHT,KC_NO,  KC_NO,        _______,        KC_LEFT,KC_DOWN,KC_RGHT,KC_VOLD,
        _______,          KC_NO,  KC_NO,  KC_NO,  KC_PSTT,KC_WBAK,KC_WFOR,KC_MCTL,KC_DESK,KC_MVLS,KC_MVRS,          _______,        KC_NO,  KC_NO,  KC_NO,
        _______,_______,   _______,   _______,               _______,               _______,KC_MVLS,KC_MVRS,KC_DESK,_______,        _______,        KC_NO,  _______
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
