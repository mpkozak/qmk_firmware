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

#include "quantum.h"



////////////////////////////////////////////////////////////////////////////////
// DIP switch keys
/*
Modifier keys are wired to dedicated pins that short to ground when active.
These are wired to dedicated pins on the MCU and interpreted by QMK as DIP
switches. In order to facilitate easier keymap modification, layers, etc., the
relevant modifier keys have been assigned (otherwise unused) matrix positions in
the defined layout macros. When one of these keys is pressed, we intercept the
DIP switch event and dispatch a normal key event with the keycode defined in the
keymap at that matrix position in the current active layer.
**Caveat**
It is impossible to distinguish between the left/right shift keys as they are
wired in parallel. Each shift key has been assigned a unique matrix position and
both are included in the layout macros for the sake of consistency. However,
closure of either shift key will always register the same matrix position. By
default, the left shift keymap assignment(s) are used (any keycodes assigned to
right shift are ignored). This behavior can be swapped by setting the
'DIP_KEYMAP_USE_RIGHT_SHIFT' flag.
*/

const keypos_t PROGMEM dip_keypos[5] = {
    MAKE_KEYPOS(0, 5),      // caps lock
#ifdef DIP_KEYMAP_USE_RIGHT_SHIFT
    MAKE_KEYPOS(3, 4),      // shift (right)
#else
    MAKE_KEYPOS(1, 4),      // shift (left)
#endif
    MAKE_KEYPOS(3, 0),      // control
    MAKE_KEYPOS(0, 1),      // option
    MAKE_KEYPOS(2, 1)       // command
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



////////////////////////////////////////////////////////////////////////////////
// Debug output enable

void keyboard_post_init_kb(void) {
#ifdef DEBUG_ENABLE
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
#endif
}
