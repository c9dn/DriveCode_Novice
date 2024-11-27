#include "subsystems/lift.hpp"


//Assign values to the lift ports
const int8_t liftPort1=1;
const int8_t liftPort2=2;


//Create the lift MotorGroup
MotorGroup lift = MotorGroup({liftPort1,liftPort2});