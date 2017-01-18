#ifndef Stepmotor_h
#define Stepmotor_h

#include "Arduino.h"

class Stepmotor
{
public:
	Stepmotor(int stepsPerRev, int motorPin1, int motorPin2, int motorPin3, int motorPin4);
	void anticlockwise(int CountMax);
	void clockwise(int CountMax);
	void setdelay(int motorSpeed);
private:
	int _countsPerRev;  //_countsPerRev = stepsPerRev * 8
	int _motorSpeed;
	int _motorPin1;
	int _motorPin2;
	int _motorPin3;
	int _motorPin4;
	int _CountMax;
};

#endif
