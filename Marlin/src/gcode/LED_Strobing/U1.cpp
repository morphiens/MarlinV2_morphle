

#include "../gcode.h"
// #include "MarlinConfigPre.h"

uint8_t strobe_sync_pulse; 
void GcodeSuite::U1(){
    strobe_sync_pulse = 20;
    OUT_WRITE(SYNC_PIN,0);  
}



