# seek_endstops routine

## Prerequisites

### Files and libraries
- [seek_endstop/U3.cpp](../Marlin/src/gcode/seek_endstop/U3.cpp)
- [motion.cpp](../Marlin/src/core/serial.cpp)
- [Serial.cpp](../Marlin/src/core/serial.cpp)

### Variables directly related to seek_endstops
- [boolean](../Marlin/src/module/motion.cpp#L72): seek_endstop_flag
- [integers](../Marlin/src/module/motion.cpp#L1654): target, distance, limit_position, home_fr_mm_s, seek_endstop_axis, seek_limit_name, current_position
- constants: None

## Functions concerned with seek_endstops interface
1. [U3()](../Marlin/src/gcode/seek_endstop/U3.cpp#L11): This function is called when the user/master sends a 'u3' command along with the axis and distance value.
2. [seek_endstops(const AxisEnum axis, uint8_t limit_name, float limit_position)](../Marlin/src/module/motion.cpp#L1654): This functon is used to move the motor towards any particular endstop on its axis.

## seek_endstops code routine
1. As the User/master sends 'u3' command is parsed; **U3()** function is called .
2. A loop is run based on the total number of axes; Corresponding axis values are defined with 0 referencing. 
3. For a particular axis, distance value is checked- if it falls in a certain range - and **seek_endstops()** function is called, by passing exact axis and endstop position.
4. **seek_endstops** function moves the motor in one direction based on the difference of current position and target position. It sets the seek_endstop_axis to the target axis provided as function argument, updates target position and updates the buffer_segment with these values.
5. **planner.synchronize()** runs the motion loop and stops the motor once the target endstop is detected on the axis.
6. current_position is updated based on the limit_position and the internal machine_position_mm is overwritten accordingly.
7. work_offset data is also updated so that the marlin positions are revised.