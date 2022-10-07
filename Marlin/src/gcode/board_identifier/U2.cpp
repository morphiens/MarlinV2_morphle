#include "../gcode.h"
// #include "MarlinConfigPre.h"

// extern uint8_t strobe_sync_pulse; 
void GcodeSuite::U2(){
    SERIAL_ECHOLN(CUSTOM_MACHINE_NAME);
}
