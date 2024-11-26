#include "subsystems/lift.hpp"

const int8_t liftPort1=1;
const int8_t liftPort2=2;

MotorGroup lift = MotorGroup({liftPort1,liftPort2});