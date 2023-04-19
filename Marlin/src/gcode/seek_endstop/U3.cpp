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
                if(l >170 && l < 200){
                    seek_endstops(X_AXIS, x_rack1, l);
                }
                else if (l >270 && l < 300){
                    seek_endstops(X_AXIS, x_rack2, l);
                }
            }
            break;

        case 1:
            if (parser.seenval(axis_codes[i])) {
                const float l = parser.value_axis_units((AxisEnum)i);
                if(l >100 && l < 130){
                    seek_endstops(Y_AXIS, y_rack1, l);
                }
            }
            break;
        
        default:
            break;
        }
    }
    // 
}