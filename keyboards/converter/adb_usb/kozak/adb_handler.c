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



/* Change keyboard handler to distinguish right side modifiers */
void keyboard_post_init_kb(void) {
    uint16_t reg3;
    reg3 = adb_host_talk(ADB_ADDR_KEYBOARD, ADB_REG_3);
    adb_host_listen(ADB_ADDR_KEYBOARD, ADB_REG_3, (reg3 >> 8), ADB_HANDLER_AEK_RMOD);
    reg3 = adb_host_talk(ADB_ADDR_KEYBOARD, ADB_REG_3);
}
