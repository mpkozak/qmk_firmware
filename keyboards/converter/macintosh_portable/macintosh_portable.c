
#include "quantum.h"



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
