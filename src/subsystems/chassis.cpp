#include "subsystems/chassis.hpp"


//Assign values to the ports
const int8_t leftFrontPort = 0;
const int8_t leftBackPort = 0;
const int8_t rightFrontPort = -0;
const int8_t rightBackPort = -0;



//Create the motors
Motor leftFrontMotor(leftFrontPort, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor leftBackMotor(leftBackPort, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor rightFrontMotor(rightFrontPort, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor rightBackMotor(rightBackPort, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);

//Create the motor groups
MotorGroup leftMotors({leftFrontMotor, leftBackMotor});
MotorGroup rightMotors({rightFrontMotor, rightBackMotor});

//Create the chassis controller
std::shared_ptr<okapi::ChassisController> chassis = okapi::ChassisControllerBuilder()
    .withMotors(leftMotors, rightMotors)
    .withDimensions(AbstractMotor::gearset::blue, {{3.25_in, 9_in}, imev5GreenTPR*(3/5)})
    .build();