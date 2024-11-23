#include "subsystems/chassis.hpp";

Motor leftFront(leftFront, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor leftBack(leftBack, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor rightFront(rightFront, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor rightBack(rightBack, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);

MotorGroup leftMotors({leftFront, leftBack});
MotorGroup rightMotors({rightFront, rightBack});

std::shared_ptr<ChassisController> chassis = ChassisControllerBuilder()
    .withMotors(leftMotors, rightMotors)
    .withDimensions(AbstractMotor::gearset::blue, {{3.25_in, 9_in}, imev5GreenTPR*(3/5)})
    .withOdometry()
    .buildOdometry();


std::shared_ptr<okapi::ChassisController> chassis = okapi::ChassisControllerBuilder()
    .withMotors(leftMotors, rightMotors)
    .withDimensions(AbstractMotor::gearset::blue, {{3.25_in, 9_in}, imev5GreenTPR*(3/5)})
    .build();