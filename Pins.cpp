/*
 Pins.cpp
 */

#include "Pins.h"

// Add static references to each physical pin on the Arduino
// These will be used to make sure each pin is only used once

bool Pin::pins[20] = { false };

Pin::Pin() {
  _pin = -1;
  _mode = OUTPUT;
  _type = DIGITAL;
  _state = 0;
  _ready = false;
}
Pin::Pin(int pin, bool mode, bool type) {
  _pin = pin;
  _mode = mode;
  _type = type;
  _state = 0;
  _ready = false;
}

bool Pin::setup() {
  // Make sure pin has been set
  if (_pin == -1) {
    // throw error
    return false;
  }

  // Add error catching for what each specific pin can actually do

  // Pins 0 & 1 are unusable?
  // Pins 0-13 can be DIGITAL INPUT/OUTPUT
  // Pins 14-19 are INPUT only (including ANALOG)
  // Only Pins 3, 5, 6, & 9-11 can be ANALOG OUTPUT

  if (Pin::pins[_pin]) {
    // pin is already set. throw error
    return false;
  }

  if (_type == ANALOG) {
    // Make sure Serial is started with Serial.begin(9600);
    Serial.begin(9600);
  }

  pinMode(_pin, _mode);
  Pin::pins[_pin] = true;
  _ready = true;
  return true;
}

bool Pin::set(int state) {
  if (!_ready) {
    // throw error
    return false;
  }

  if (_mode == OUTPUT) {
    if (_type == DIGITAL) {
      _state = (bool)state;
      digitalWrite(_pin, _state);
      return true;
    } else {
      _state = constrain(state, 0, 255);
      analogWrite(_pin, _state);
      return true;
    }
  } else {
    // Can't set an output!
    // throw a warning
    return false;
  }
}

int Pin::get(bool update) {
  if (!_ready) {
    // throw error
    return _state;
  }

  if (_mode == INPUT && update) {
    if (_type == DIGITAL) {
      _state = digitalRead(_pin);
    } else {
      _state = analogRead(_pin);
    }
  }

  return _state; // returns 0 if called on OUTPUT
}


bool Pin::tone(unsigned int pitch) {
  ::tone(_pin, pitch);
  return true;
}

bool Pin::tone(unsigned int pitch, unsigned long duration) {
  ::tone(_pin, pitch, duration);
  return true;
}

bool Pin::noTone() {
  ::noTone(_pin);
  return true;
}
