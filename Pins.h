/*
 Pins.h
 */

#ifndef Pins_h
#define Pins_h

#include "Arduino.h"


#define DIGITAL 0
#define ANALOG 1


class Pin {
private:
  int _pin, _state;
  bool _mode, _type, _ready;

  static bool pins[20]; // for now this just tracks whether or not a pin has been registered, but it could be a pointer to the pin object maybe?

public:
  Pin();
  Pin(int pin, bool mode = OUTPUT, bool type = DIGITAL);

  bool setup();

  bool set(int state);
  int get(bool update = true);
};

#endif

