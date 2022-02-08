// Platform libraries.
#include <Arduino.h>  // To add IntelliSense for platform constants.

// Third-party libraries.

// My classes
#include "status-led.h"

#include "config.h"  // To store configuration and secrets.

StatusLed led;

int lastSwitchState = 0;

void setup() {
  initSerial();
  initLed();
  pinMode(PIN_SWITCH, INPUT);

  Serial.printf("Application version: %s\n", APP_VERSION);
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
  int switchState = digitalRead(PIN_SWITCH);

  if (switchState == LOW) {   // when our switch is on, the pin reads 'LOW'/grounded.
    led.turnOn();
  } else {
    led.turnOff();
  }

  delay(50);
}
