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
#include "adb.h"
#include "keymap_user.h"



////////////////////////////////////////////////////////////////////////////////
// ADB protocol interface + initialization

/* Change keyboard handler to distinguish right side modifiers */
void adb_init(void) {
    uint16_t reg3 = adb_host_talk(ADB_ADDR_KEYBOARD, ADB_REG_3);
    uint8_t handler = (reg3 & 0xFF);
    if (handler == ADB_HANDLER_AEK) {
        adb_host_listen(ADB_ADDR_KEYBOARD, ADB_REG_3, (reg3 >> 8), ADB_HANDLER_AEK_RMOD);
        reg3 = adb_host_talk(ADB_ADDR_KEYBOARD, ADB_REG_3);
    }
}

/* Callback to reinvoke initialization handler */
uint32_t adb_init_cb(uint32_t trigger_time, void *cb_arg) {
    adb_init();
    return ADB_INIT_CB_MS;
}

/* Initial invocation */
void keyboard_post_init_kb(void) {
    adb_init();
    defer_exec(ADB_INIT_CB_MS, adb_init_cb, NULL);
}

// /* Callback registration */
// deferred_token adb_init_token = defer_exec(60000, adb_init_cb, NULL);



////////////////////////////////////////////////////////////////////////////////
// ADB diagnostic logging

#ifdef ADB_LOGGING
void adb_status(void) {
    // uint16_t reg0 = adb_host_talk(ADB_ADDR_KEYBOARD, ADB_REG_0);
    // uint16_t reg1 = adb_host_talk(ADB_ADDR_KEYBOARD, ADB_REG_1);
    uint16_t reg2 = adb_host_talk(ADB_ADDR_KEYBOARD, ADB_REG_2);
    int keys = (reg2 & 0x7FC0) >> 6;                    // bits 6-14
    int leds = (reg2 & 0x7);                            // bits 0-2
    uint16_t reg3 = adb_host_talk(ADB_ADDR_KEYBOARD, ADB_REG_3);
    int service_request = (reg3 & 0x2000) >> 13;        // bit  13
    int device_address = (reg3 & 0xF00) >> 8;           // bits 8-11
    uint8_t device_handler_id = (reg3 & 0xFF);          // bits 0-7
    print("__ADB-status__"); print("\n");
    // xprintf("         adb_reg2: %b \n", reg2);
    // xprintf("         adb_reg3: %b \n", reg3);
    xprintf("        reg2_keys: %09b \n", keys);
    xprintf("        reg2_leds: %03b \n", leds);
    xprintf("  service_request: %u \n", service_request);
    xprintf("   device_address: %u \n", device_address);
    xprintf("device_handler_id: 0x%02X \n", device_handler_id);
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (get_highest_layer(layer_state) == DFLT) {
        adb_status();
    }
    return true;
}
#endif
