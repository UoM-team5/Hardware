/***************************************************
This sample code shows 3 states: clockwise maximum speed rotation; stop;
counterclockwise maximum speed rotation

0 -> clockwise maximum speed rotation
90 -> stop
180 -> counterclockwise maximum speed rotation
****************************************************/
#include <Servo.h>
#define PUMPPIN 8 //peristaltic pump control pin, connect to arduino digital pin 8


Servo myservo;

float ml = 6.0; // insert amount you want to pump
float mlpersec = (0.0038*ml) + 0.5967;
int pumping_time = (ml/mlpersec)*1000;
int flag = 0;
8// int pumping_time = 12500;

void setup()
{
 myservo.attach(PUMPPIN);
 Serial.begin(9600);
}

void loop()
{
  if (flag == 0)
  {
    myservo.write(0); //Clockwise maximum speed rotation (0 degrees)
    delay(pumping_time);
    flag = 1;
   }else
   {
    myservo.write(90); //Stop
    
   }
   //Serial.println(mlpersec);
   //delay(1);
}
