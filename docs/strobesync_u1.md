# Strobesync routine

## Prerequisites

### Files and libraries
- [U1.cpp](../Marlin/src/gcode/LED_Strobing/U1.cpp)
- [HAL.cpp](../Marlin/src/HAL/STM32/HAL.cpp)
- stm32h7xx_hal_gpio.h

### Variables directly related to strobesync
- boolean: none
- integers: strobe_sync_pulse

## Functions concerned with Strobesync interface
1. [U1()](../Marlin/src/gcode/LED_Strobing/U1.cpp#L7): This function is called when the user/master sends a 'u1' command, usually combined with a motion command.
2. [reset_U1()](../Marlin/src/gcode/LED_Strobing/U1.cpp#L12): This function is called by the systick timer loop to decrement strobe_sync_pulse counter each time until it sets to 0.
3. [MarlinHAL::init()](../Marlin/src/HAL/STM32/HAL.cpp#L68): This init function consists the steps to set sync pin gpio to output and and set it to LOW.


## Strobesync code routine
1. SYNC_PIN in initialised as output pin and set to LOW in init().
2. User/master command is parsed; U1() function is called to reset the strobe_sync_pulse counter to 20 and SYNC_PIN is set to HIGH.
3. systick timer calls reset_U1() function every ms and thereby decrements the counter in each iteration.
4. When strobe_sync_pulse reaches 0, the SYNC_PIN is set to LOW.