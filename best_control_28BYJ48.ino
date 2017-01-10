//declare variables for motor pins
int motorPin1 = 8; //Blue - 28BYJ48 pin 1
int motorPin2 = 9; //Pink - 28BYJ48 pin 2
int motorPin3 = 10; //Yellow - 28BYJ48 pin 3
int motorPin4 = 11; //Orange - 28BYJ48 pin 4
             //Red - 28BYJ48 pin 5(VCC)

int motorSpeed = 1200; //variable to set stepper speed
int count = 0; //count of steps made
int countsperrev = 512; //number of steps per full revolution
int lookup[8] = {B01000,B01100,B00100,B00110,B00010,B00011,B00001,B01001};

////////////////////////////////////////////////////////////////
int value = 0;
int maxcount = 0;
int angle = 0;
bool direct = 0;
///////////////////////////////////////////////////////////////
void setup()
{
  //declare the motor pins as outputs
  pinMode(motorPin1,OUTPUT);
  pinMode(motorPin2,OUTPUT);
  pinMode(motorPin3,OUTPUT);
  pinMode(motorPin4,OUTPUT);
  Serial.begin(9600);
}
///////////////////////////////////////////////////////////////
void loop() 
{
  // step one step:
  if (Serial.available())
  {
    char ch = Serial.read();
    if ( ch == '-')      direct = 1;
    if (isDigit(ch))
    {
      value = (value * 10) + (ch - '0');
    }
    else if (ch == 10)
    {
      angle = value;
      Serial.print("Demanned angle: ");
      Serial.print(angle);
      Serial.println(" degrees");
      maxcount = angle * 64 / 45;
      Serial.print("Maxcount= ");
      Serial.println(maxcount);
      value = 0;
      if (direct == 0)
      clockwise(maxcount);
      else if (direct == 1)
      anticlockwise(maxcount);
      direct = 0;
    }
  }
// stepper(maxcount);
// stepCount = 0;
}
/////////////////////////////////////////////////////
/*void loop()
{
  if(count<countsperrev)
   clockwise();
  else if (count ==countsperrev * 2)
   count = 0;
  else
   anticlockwise();
  count++;
}*/
//////////////////////////////////////////////////////////////
//set pins to ULN2003 high in sequence from 1 to 4
//delay "motorSpeed" between each pin setting (to determine speed)
void anticlockwise(int CountMax)
{
  for (int stepCount = 0; stepCount < CountMax; stepCount++)
  {
    for(int i = 0; i < 8; i++)
    {
      setOutput(i);
      delayMicroseconds(motorSpeed);
    }
  }
}
void clockwise(int CountMax)
{
  for (int stepCount = 0; stepCount < CountMax; stepCount++)
  {
    for(int i = 8; i >= 0; i--)
    {
      setOutput(i);
      delayMicroseconds(motorSpeed);
    }
  }
}
void setOutput(int out)
{
  digitalWrite(motorPin1,bitRead(lookup[out],0));
  digitalWrite(motorPin2,bitRead(lookup[out],1));
  digitalWrite(motorPin3,bitRead(lookup[out],2));
  digitalWrite(motorPin4,bitRead(lookup[out],3));
}

