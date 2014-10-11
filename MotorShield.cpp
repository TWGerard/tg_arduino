/*
	MotorShield.cpp
*/

#include "MotorShield.h"

MotorShield::MotorShield() {
	_speed_l = Pin(3, OUTPUT, ANALOG);
	_direction_l = Pin(12, OUTPUT, DIGITAL);
	_brake_l = Pin(9, OUTPUT, DIGITAL);

	_speed_r = Pin(11, OUTPUT, ANALOG);
	_direction_r = Pin(13, OUTPUT, DIGITAL);
	_brake_r = Pin(8, OUTPUT, DIGITAL);
}


void MotorShield::setup() {
	_speed_l.setup();
	_direction_l.setup();
	_brake_l.setup();

	_speed_r.setup();
	_direction_r.setup();
	_brake_r.setup();
}

void MotorShield::forward(int speed) {
	_direction_l.set(FORWARD);
	_direction_r.set(FORWARD);
	setSpeed(speed);
	brakesOff();
}

void MotorShield::backward(int speed) {
	_direction_l.set(BACKWARD);
	_direction_r.set(BACKWARD);
	setSpeed(speed);
	brakesOff();
}

void MotorShield::stop() {
	brakesOn();
}

void MotorShield::turn(int speed, int direction) {
	_direction_l.set(direction);
	_direction_r.set(-direction);
	setSpeed(speed);
	brakesOff();
}

void MotorShield::drive(int speed, int direction, int angle) { 

}

void MotorShield::setSpeed(int speed) {
	_speed_l.set(speed);
	_speed_r.set(speed);
}

void MotorShield::brakesOn() {
	_brake_l.set(true);
	_brake_r.set(true);
}

void MotorShield::brakesOff() {
	_brake_l.set(false);
	_brake_r.set(false);
}