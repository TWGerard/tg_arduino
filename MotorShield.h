/*
 MotorShield.h

 by Tyler Gerard

 designed to work with the Arduino Motor Shield R3
 while watching the Family Guy - Simpsons crossover episode

 */

#ifndef MotorShield_h
#define MotorShield_h

#include "Arduino.h"
#include "Pins.h"


#define RIGHT 1
#define LEFT 0
#define FORWARD 1
#define BACKWARD 0


class MotorShield {
private:
	Pin *_pins[6];
	Pin _speed_l, _direction_l, _brake_l, _speed_r, _direction_r, _brake_r;

public:
	MotorShield();

	void setup();

	void forward(int speed);
	void backward(int speed);
	void stop();

	void turn(int speed, int direction);

	void drive(int speed, int direction, int angle);

	void brakesOn();
	void brakesOff();

	void setSpeed(int speed);
	int getSpeed();
};


#endif