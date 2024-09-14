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



/* Callback interval (ms) */
#define INIT_CB_MS  60000   // 1 minute



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
    return INIT_CB_MS;
}

/* Initial invocation */
void keyboard_post_init_kb(void) {
    adb_init();
    defer_exec(INIT_CB_MS, adb_init_cb, NULL);
}







// /* Callback registration */
// deferred_token adb_init_token = defer_exec(60000, adb_init_cb, NULL);
