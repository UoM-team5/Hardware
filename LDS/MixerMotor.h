#ifndef MixerMotor_h
#define MixerMotor_h


#include <Arduino.h>

class MixerMotor 
{
  private: 
  int motorPin1 = 3;
  int motorPin2 = 4;
  int Enable = 5;

  public:
  MixerMotor() {};


  void SetUpLDS() {
    pinMode(Enable,OUTPUT);
    pinMode(motorPin1,OUTPUT);
    pinMode(motorPin2,OUTPUT);
  }  

  void StopMotor(){
    digitalWrite(Enable,LOW); //slow stop
  }
 
  void MotorHigh() {
    analogWrite(Enable,255); 
    digitalWrite(motorPin1,HIGH); //one way
    digitalWrite(motorPin2,LOW);
  }

  void MotorMedium() {
    analogWrite(Enable,180); 
    digitalWrite(motorPin1,HIGH); //one way
    digitalWrite(motorPin2,LOW);
  }

  void MotorSlow() {
    analogWrite(Enable,100); 
    digitalWrite(motorPin1,HIGH); //one way
    digitalWrite(motorPin2,LOW);
  }

};
#endif