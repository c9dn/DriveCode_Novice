#include "subsystems/chassis.hpp"


//Assign values to the ports
const int8_t leftFrontPort = 8;
const int8_t leftBackPort = 9;
const int8_t rightFrontPort = 7;
const int8_t rightBackPort = 21;



//Create the motors
Motor leftFrontMotor(leftFrontPort, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor leftBackMotor(leftBackPort, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor rightFrontMotor(rightFrontPort, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor rightBackMotor(rightBackPort, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);

//Create the motor groups
MotorGroup leftMotors({leftFrontMotor, leftBackMotor});
MotorGroup rightMotors({rightFrontMotor, rightBackMotor});

//Create the chassis controller
std::shared_ptr<okapi::ChassisController> chassis = okapi::ChassisControllerBuilder()
    .withMotors(leftMotors, rightMotors)
    .withGains( //initializing integrated PID system
        {0.00068, 0.002, 0}, // Distance controller gains
        {0.006, 0.0018, 0.00016}, // Turn controller gains
        {0.00076, 0.00160, 0.00016}  // Angle controller gains (helps drive straight)
    )

    .withDimensions(AbstractMotor::gearset::blue, {{3.25_in, 9_in}, imev5GreenTPR*(3/5)})
    .build();