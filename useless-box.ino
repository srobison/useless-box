// Platform libraries.
#include <Arduino.h>  // To add IntelliSense for platform constants.

// Third-party libraries.

// My classes
#include "proximity-sensor.h"

#include "config.h"  // To store configuration and secrets.

ProximitySensor sensor;


void setup() {
  initSerial();
  initSensor();

  Serial.printf("Hello GZ!\n");
  Serial.println("Setup completed.");
  delay(2000);
}

void initSerial() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Initializing serial connection DONE.");
}

void initSensor() {
  sensor.attach(PIN_SENSOR_SDA, PIN_SENSOR_SCL, SENSOR_TRIGGER_THRESHOLD);
}

void loop() {
  sensor.getProximity(); // retrieve and print APDS9930 raw value

  // Wait 250 ms before next reading (required for the sensor).
  delay(250);
}
