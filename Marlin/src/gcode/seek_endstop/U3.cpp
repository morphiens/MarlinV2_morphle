#include "../gcode.h"
#include "../../module/motion.h"
#include "../../module/endstops.h"
#include "../../module/stepper.h"
#include "../../module/planner.h"


// #include "MarlinConfigPre.h"

// extern uint8_t strobe_sync_pulse; 
void GcodeSuite::U3(){
    LOOP_LOGICAL_AXES(i) {
       
        switch (i){
          
        case 0:
        
        
            if (parser.seenval(axis_codes[i])) {
                
                const float l = parser.value_axis_units((AxisEnum)i);
                SERIAL_ECHO_F(l,4);
                if(l >35 && l < 41){
                   
                    seek_endstops(X_AXIS, PUSHERX_PIN, l);
                }
                
            }
            break;

        case 1:
            if (parser.seenval(axis_codes[i])) {
                const float l = parser.value_axis_units((AxisEnum)i);
                if(l >0 && l < 8){
                    
                    seek_endstops(Y_AXIS, PUSHERY_PIN, l);
                }
            }
            break;
        
        default:
            break;
        }
    }
    // 
}