#include "main.h"


//Setup namespaces
using namespace okapi;
using namespace okapi::literals;

//Setup ports
extern const int8_t leftFront;
extern const int8_t leftBack;
extern const int8_t rightFront;
extern const int8_t rightBack;

/*
extern Motor leftFront;
extern Motor leftBack;
extern Motor rightFront;
extern Motor rightBack;
*/

//Setup Chassis Controller
extern std::shared_ptr<okapi::ChassisController> chassis;
