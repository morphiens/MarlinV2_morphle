# endstop_distance routine

## Prerequisites

### Files and libraries
- [endstop_distance/U4.cpp](../Marlin/src/gcode/endstop_distance/U4.cpp)
- [motion.cpp](../Marlin/src/core/serial.cpp)
- [Serial.cpp](../Marlin/src/core/serial.cpp)

### Variables directly related to endstop_distance
- [boolean](../Marlin/src/module/motion.cpp#L72): seek_endstop_flag
- [integers](../Marlin/src/module/motion.cpp#L1656): target, distance, limit_position, home_fr_mm_s, seek_endstop_axis, seek_limit_name, current_position
- constants: 

## Functions concerned with endstop_distance interface
1. [U4()](../Marlin/src/module/motion.cpp#L1654): This function is called when the user/master sends a 'u3' command along with the axis and distance value.
2. [get_endstop_distance(const AxisEnum axis, uint8_t limit_name)](../Marlin/src/module/motion.cpp#L1680): This functon is used to move the motor towards any particular endstop on its axis and measure the distance travelled from home to get the precise position of the other endstop.

## endstop_distance code routine
1. As the User/master sends 'u4' command is parsed; **U4()** function is called .
2. A loop is run based on the total number of axes; Corresponding axis values are defined with 0 referencing. 
3. For a particular axis, distance value is checked- if it falls in a certain range - and **get_endstop_distance()** function is called, by passing axis_name and target endstop.
3. The axis motor is first homed to ensure proper positioning.
4. DEFAULT_AXIS_MAX_LENGTH is obtained based on the default stroke lengths to set it as target distance for the motor; so that upon failed detection, the motors can stop at max stroke.
5. home_fr_mm_s, seek_endstop_axis, seek_limit_name are obtained from function arguments.
5. The buffer_segment function is passed the updated target position and home_fr_mm_s.
6. **planner.synchronize()** runs the motion loop and stops the motor once the target endstop is detected on the axis.
7. Updated real position is printed on the serial console.
8. Then the home routine is run again to reach back to home.