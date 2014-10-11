/*
 Pins.cpp
 */

#include "Pins.h"


  Pin::Pin() {
    pin_number = -1;
    mode = INPUT;
    type = DIGITAL;
  }
  Pin::Pin(int pinNumber, int startMode, int startType) {
    pin_number = pinNumber;
    mode = startMode;
    type = startType;
  }

  void Pin::setup() {
    if (type == DIGITAL) {
      pinMode(pin_number, mode);
    }
  }

  boolean Pin::set(int newState) {
    if (mode == OUTPUT) {
      state = newState;
      if (type == DIGITAL) {
        digitalWrite(pin_number, state);
      } 
      else {
        analogWrite(pin_number, state);
      }
      return true;
    } 
    else {
      // Can't set an output!
      return false;
    }
  }

  int Pin::get(boolean update) {
    if (mode == INPUT && update) {
      if (type == DIGITAL) {
        state = digitalRead(pin_number);
      } 
      else {
        state = analogRead(pin_number);
      }
    }
    return state;
  }



  ColorSensor::ColorSensor(int pin_number_r, int pin_number_b, int pin_number_g) {
    pins = new Pin[3];
    Pin *newPinR = new Pin(pin_number_r, INPUT, ANALOG);
    pins[0] = *newPinR;
    Pin *newPinG = new Pin(pin_number_g, INPUT, ANALOG);
    pins[1] = *newPinG;
    Pin *newPinB = new Pin(pin_number_b, INPUT, ANALOG);
    pins[2] = *newPinB;
    
    state = new int[3];
  }

  int* ColorSensor::get(boolean update) {
    if (update) {
      state[0] = red = pins[0].get();
      delay(5);
      state[1] = green = pins[1].get();
      delay(5);
      state[2] = blue = pins[2].get();
    }
    return state;
  }




  SerialPin::SerialPin(int pin_number) : pin_number(pin_number) {}

  void SerialPin::setup() {
    Serial.begin(9600);
  }

  float SerialPin::get(boolean update) {
    if (update) {
      float rval = analogRead(pin_number);
      rval = (rval/1024.0) * 5.0; // to Volts
      rval = (rval - .5) * 100; // to Celcius
      state = rval;
    }
    return state;
  }
  
