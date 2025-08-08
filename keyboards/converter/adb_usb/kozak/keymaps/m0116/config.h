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

#pragma once

/* Override info.json */
#undef PRODUCT
#define PRODUCT "M0116"
#undef PRODUCT_ID
#define PRODUCT_ID 0x0116

/* ADB port setting */
#undef ADB_PSW_BIT          // disabled

/* Enable ADB logging to console */
#define ADB_LOGGING

/* Disable locking support */
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

/* Enable locking speed layer toggle */
#define LOCKING_SPEED_TOGGLE
