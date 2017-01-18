#include <Stepmotor.h>    // Include the lib for 28BYJ-48 written by Kai.

int stepsperrev = 64;      // 64 steps per full revolution, which means 512 counts(phases) per full revolution.
int _motorPin1 = 10;
int _motorPin2 = 11;
int _motorPin3 = 12;
int _motorPin4 = 13;
int motorSpeed = 1200;      // This variable actually defines the delay among every two counts, here we set 1200 microseconds.

Stepmotor stepmotor(stepsperrev, _motorPin1, _motorPin2, _motorPin3, _motorPin4 );

void setup()
{
  stepmotor.setdelay(motorSpeed);     // Set speed for motor.
  Serial.begin(9600);
}

void loop()
{
  while (Serial.available() > 0)                      //Read the input from serial port.It should be the number of degrees we want motor to rotate.
  {                                                  
    int maxcount = Serial.parseInt();
    if (Serial.read() == '\n')
    {
      Serial.print("Demanned angle: ");
      Serial.print(maxcount);
      Serial.println(" degrees");
      maxcount = maxcount * 64 / 45;  // 64/45 = 512/360. 
      Serial.print("Maxcount= ");    // But there pharpse some issue with stack,so can't write like that
      Serial.println(maxcount);
      if ( maxcount >= 0 )
      stepmotor.clockwise(maxcount);              // Rotate the motor clockwise
      else if ( maxcount < 0 )
      stepmotor.anticlockwise(abs(maxcount));    // Rotate the motor counterclockwise
    }
  }
}




