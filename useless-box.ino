// Platform libraries.
#include <Arduino.h>  // To add IntelliSense for platform constants.

// Third-party libraries.

// My classes.
#include "speed-servo.h"

#include "config.h"  // To store configuration and secrets.

SpeedServo lidServo;
SpeedServo switchServo;

void setup() {
  initSerial();
  initServos();

  Serial.printf("Application version: %s\n", APP_VERSION);
  Serial.println("Setup completed.");
}

void initSerial() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Initializing serial connection DONE.");
}

void initServos() {
  lidServo.attach(PIN_LID_SERVO);
  lidServo.moveNowTo(LID_START_POSITION);
  switchServo.attach(PIN_SWITCH_SERVO);
  switchServo.moveNowTo(LID_START_POSITION);
}

void loop() {

  for (int pos = LID_START_POSITION; pos <= LID_END_POSITION; pos+=10){
    lidServo.moveNowTo(pos);
    switchServo.moveNowTo(pos);
    delay(10);
  }

  for (int pos = LID_END_POSITION; pos >= LID_START_POSITION; pos-=10){
    lidServo.moveNowTo(pos);
    switchServo.moveNowTo(pos);
    delay(10);
  }

  // Wait 250 ms before next reading (required for the sensor).
  delay(500);
}
