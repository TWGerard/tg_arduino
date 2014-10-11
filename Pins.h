/*
 Pins.h
 */

#ifndef Pins_h
#define Pins_h

#include "Arduino.h"

const int DIGITAL = 0;
const int ANALOG = 1;


class Pin {
  private:
  int pin_number, mode, type;

  public:
  int state;

  Pin();
  Pin(int pinNumber, int startMode, int startType = DIGITAL);
  void setup();

  boolean set(int newState);
  int get(boolean update = true);
};

class ColorSensor {
  private:
  Pin *pins;

  public:
  int red;
  int green;
  int blue;
  int *state;

  ColorSensor(int pin_number_r, int pin_number_b, int pin_number_g);

  int* get(boolean update = true);
};

class SerialPin {
  private:
  int pin_number;
  float baselineTemp, state;

  public:
  SerialPin(int pin_number);

  void setup();

  float get(boolean update = true);
};

#endif

