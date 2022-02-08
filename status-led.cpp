#include "status-led.h"

void StatusLed::setPin(uint8_t pin) {
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void StatusLed::turnOn() {
   digitalWrite(_pin, LOW);
}

void StatusLed::turnOff() {
   digitalWrite(_pin, HIGH);
}

void StatusLed::toggle() {
  if (digitalRead(_pin)){
    digitalWrite(_pin, LOW);
  } else {
    digitalWrite(_pin, HIGH);
  }
    
}
