const char* APP_VERSION = "0.0.2";

#ifndef LED_BUILTIN
#define LED_BUILTIN D4
#endif

const int PIN_LID_SERVO = D8;     // The GPIO number of the pin where the lid opener servo is connected.
const int PIN_SWITCH_SERVO = D0;  // The GPIO number of the pin where the switch manipulator servo is connected.

const int LID_START_POSITION = 0;
const int LID_END_POSITION = 180;
