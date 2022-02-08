// Platform libraries.
#include <Arduino.h>  // To add IntelliSense for platform constants.

// Third-party libraries.

// My classes
#include "status-led.h"

#include "config.h"  // To store configuration and secrets.

StatusLed led;



void setup() {
  initSerial();
  initLed();

  Serial.printf("Hello GZ blinky");
  Serial.println("Setup completed.");
}

void initSerial() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Initializing serial connection DONE.");
}

void initLed() {
  led.setPin(LED_BUILTIN);
  led.turnOff();
}

void loop() {
  led.toggle();
  delay(1000);  // wait a second
}
