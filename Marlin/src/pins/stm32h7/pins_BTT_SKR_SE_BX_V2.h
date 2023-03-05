/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2022 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#define BOARD_INFO_NAME      "BTT SKR SE BX V2.0"

<<<<<<<< HEAD:Marlin/src/pins/stm32h7/pins_BTT_SKR_SE_BX_V2.h
#define SAFE_POWER_PIN                      PI11
========
struct LowpassFilter {
  uint64_t data_delay = 0;
  uint16_t update(uint16_t value) {
    data_delay += value - (data_delay >> 6);
    return uint16_t(data_delay >> 6);
  }
};
>>>>>>>> 2.1.1:Marlin/src/HAL/LINUX/hardware/Heater.h

#include "pins_BTT_SKR_SE_BX_common.h"
