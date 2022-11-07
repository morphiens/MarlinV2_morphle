# board_identifier routine

## Prerequisites

### Files and libraries
- [U2.cpp](../Marlin/src/gcode/board_identifier/U2.cpp)
- [Configuration.h](../Marlin/Configuration.h)
- [Serial.cpp](../Marlin/src/core/serial.cpp)

### Variables directly related to board_identifier
- boolean: none
- integers: none
- [constants](../Marlin/Configuration.h#L137): CUSTOM_MACHINE_NAME

## Functions concerned with board_identifier
1. [U2()](../Marlin/src/gcode/board_identifier/U2.cpp#L5): This function is called when the user/master sends a 'u2' command usually during the start of the machine.

## board_identifier code routine
1. User/master command is parsed; U2() function is called to print the CUSTOM_MACHINE_NAME to the serial console using the inbuilt SERIAL_ECHOLN() function.