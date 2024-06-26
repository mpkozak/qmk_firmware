
#include "quantum.h"



////////////////////////////////////////////////////////////////////////////////
// DIP switch keys

const keypos_t PROGMEM dip_keypos[5] = {
    MAKE_KEYPOS(0, 5),
    MAKE_KEYPOS(1, 4),     // (3, 4)
    MAKE_KEYPOS(3, 0),
    MAKE_KEYPOS(0, 1),
    MAKE_KEYPOS(2, 1)
};

bool dip_switch_update_kb(uint8_t index, bool active) {
    keypos_t key = dip_keypos[index];
    keyevent_t event = MAKE_KEYEVENT(key.row, key.col, active);
    action_exec(event);
    return true;
}



////////////////////////////////////////////////////////////////////////////////
// MCU LED

/* Activate MCU led on power-on */
void keyboard_pre_init_kb(void) {
    setPinOutput(LED_PIN);
#ifdef LED_POWER_ON
    writePinHigh(LED_PIN);
#endif
}

/* Runs after each key press, toggles MCU LED off with keydown */
void post_process_record_kb(uint16_t keycode, keyrecord_t *record) {
#ifdef LED_DIAG_BLINK
    if (record->event.pressed) {
        gpio_write_pin_low(LED_PIN);
    } else {
        gpio_write_pin_high(LED_PIN);
    }
#endif
}
