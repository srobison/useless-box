#include <Arduino.h>                    // To add IntelliSense for platform constants.
#include <Wire.h>                       // To read the gesture sensor via I2C.
#include <APDS9930.h>                   // Third-party library with gesture sensor utilities.


#ifndef proximity_sensor_h
#define proximity_sensor_h

class ProximitySensor {
  public:
    void attach(uint8_t sdaPin, uint8_t sclPin, uint16_t rangeThreshold);
    uint16_t getProximity();
    bool isInRange();

  private:
    APDS9930 _sensor;
    uint16_t _lastProximityValue;
    uint16_t _rangeThreshold;
};

#endif /* proximity_sensor_h */
