#include "Arduino.h"
#include "Stepmotor.h"

Stepmotor::Stepmotor(int stepsPerRev, int motorPin1, int motorPin2, int motorPin3, int motorPin4)
{
  // initialize the parametres of stepper motor
  //int motorSpeed = 1200; //variable to set stepper speed
  //int count = 0; //count of steps made
  //int countsperrev = 512; //number of steps per full revolution
  // initialize the maxcount of steps needed to take
  //int maxcount = 0;
  // declare the motor pins as outputs
  pinMode(motorPin1,OUTPUT);
  pinMode(motorPin2,OUTPUT);
  pinMode(motorPin3,OUTPUT);
  pinMode(motorPin4,OUTPUT);
  /////////////////////////////////////////////////////////////////////////
  _countsPerRev = stepsPerRev * 8;
  _motorPin1 = motorPin1;
  _motorPin2 = motorPin2;
  _motorPin3 = motorPin3;
  _motorPin4 = motorPin4;
  /////////////////////////////////////////////////////////////////////////
}

void Stepmotor::setdelay(int motorSpeed)
{
  _motorSpeed = motorSpeed;    //variable to set stepper speed
}

void Stepmotor::anticlockwise(int CountMax)
{
  _CountMax = CountMax;
  for (int stepCount = 0; stepCount < _CountMax; stepCount++)
  {
    //////////////////////////////// phase_1
    digitalWrite( _motorPin1, HIGH);
    digitalWrite( _motorPin2, LOW);
    digitalWrite( _motorPin3, LOW);
    digitalWrite( _motorPin4, HIGH);
    delayMicroseconds(_motorSpeed);
    //////////////////////////////// phase_2
    digitalWrite( _motorPin1, HIGH);
    digitalWrite( _motorPin2, LOW);
    digitalWrite( _motorPin3, LOW);
    digitalWrite( _motorPin4, LOW);
	delayMicroseconds(_motorSpeed);
    //////////////////////////////// phase_3
    digitalWrite( _motorPin1, HIGH);
    digitalWrite( _motorPin2, HIGH);
    digitalWrite( _motorPin3, LOW);
    digitalWrite( _motorPin4, LOW);
	delayMicroseconds(_motorSpeed);
    //////////////////////////////// phase_4
    digitalWrite( _motorPin1, LOW);
    digitalWrite( _motorPin2, HIGH);
    digitalWrite( _motorPin3, LOW);
    digitalWrite( _motorPin4, LOW);
	delayMicroseconds(_motorSpeed);
    //////////////////////////////// phase_5
    digitalWrite( _motorPin1, LOW);
    digitalWrite( _motorPin2, HIGH);
    digitalWrite( _motorPin3, HIGH);
    digitalWrite( _motorPin4, LOW);
	delayMicroseconds(_motorSpeed);
    //////////////////////////////// phase_6
    digitalWrite( _motorPin1, LOW);
    digitalWrite( _motorPin2, LOW);
    digitalWrite( _motorPin3, HIGH);
    digitalWrite( _motorPin4, LOW);
	delayMicroseconds(_motorSpeed);
    //////////////////////////////// phase_7
    digitalWrite( _motorPin1, LOW);
    digitalWrite( _motorPin2, LOW);
    digitalWrite( _motorPin3, HIGH);
    digitalWrite( _motorPin4, HIGH);
	delayMicroseconds(_motorSpeed);
    //////////////////////////////// phase_8
    digitalWrite( _motorPin1, LOW);
    digitalWrite( _motorPin2, LOW);
    digitalWrite( _motorPin3, LOW);
    digitalWrite( _motorPin4, HIGH);
	delayMicroseconds(_motorSpeed);
  }
}

void Stepmotor::clockwise(int CountMax)
{
  _CountMax = CountMax;
  for (int stepCount = 0; stepCount < _CountMax; stepCount++)
  {
    //////////////////////////////// phase_1
    digitalWrite( _motorPin1, LOW);
    digitalWrite( _motorPin2, LOW);
    digitalWrite( _motorPin3, LOW);
    digitalWrite( _motorPin4, HIGH);
	delayMicroseconds(_motorSpeed);
    //////////////////////////////// phase_2
    digitalWrite( _motorPin1, LOW);
    digitalWrite( _motorPin2, LOW);
    digitalWrite( _motorPin3, HIGH);
    digitalWrite( _motorPin4, HIGH);
	delayMicroseconds(_motorSpeed);
    //////////////////////////////// phase_3
    digitalWrite( _motorPin1, LOW);
    digitalWrite( _motorPin2, LOW);
    digitalWrite( _motorPin3, HIGH);
    digitalWrite( _motorPin4, LOW);
	delayMicroseconds(_motorSpeed);
    //////////////////////////////// phase_4
    digitalWrite( _motorPin1, LOW);
    digitalWrite( _motorPin2, HIGH);
    digitalWrite( _motorPin3, HIGH);
    digitalWrite( _motorPin4, LOW);
	delayMicroseconds(_motorSpeed);
    //////////////////////////////// phase_5
    digitalWrite( _motorPin1, LOW);
    digitalWrite( _motorPin2, HIGH);
    digitalWrite( _motorPin3, LOW);
    digitalWrite( _motorPin4, LOW);
	delayMicroseconds(_motorSpeed);
    //////////////////////////////// phase_6
    digitalWrite( _motorPin1, HIGH);
    digitalWrite( _motorPin2, HIGH);
    digitalWrite( _motorPin3, LOW);
    digitalWrite( _motorPin4, LOW);
	delayMicroseconds(_motorSpeed);
    //////////////////////////////// phase_7
    digitalWrite( _motorPin1, HIGH);
    digitalWrite( _motorPin2, LOW);
    digitalWrite( _motorPin3, LOW);
    digitalWrite( _motorPin4, LOW);
	delayMicroseconds(_motorSpeed);
    //////////////////////////////// phase_8
    digitalWrite( _motorPin1, HIGH);
    digitalWrite( _motorPin2, LOW);
    digitalWrite( _motorPin3, LOW);
    digitalWrite( _motorPin4, HIGH);
	delayMicroseconds(_motorSpeed);
  }
}

