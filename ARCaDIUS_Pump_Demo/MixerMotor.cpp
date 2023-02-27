#include <Arduino.h>
#include "MixerMotor.h"
 
void MixerMotor:: SetUpMotor() {
  pinMode(E,OUTPUT);
  pinMode(MP1,OUTPUT);
  pinMode(MP2,OUTPUT);
}  

void MixerMotor:: StopMotor(){
  digitalWrite(E,LOW); //slow stop
}
 
void MixerMotor:: MotorHigh() {
  analogWrite(E,150); 
  digitalWrite(MP1,HIGH); //one way
  digitalWrite(MP2,LOW);
  Serial.println("The mixer is mixing fast");
}

void MixerMotor:: MotorMedium() {
  analogWrite(E,125); 
  digitalWrite(MP1,HIGH); //one way
  digitalWrite(MP2,LOW);
}

void MixerMotor:: MotorSlow() {
  analogWrite(E,100); 
  digitalWrite(MP1,HIGH); //one way
  digitalWrite(MP2,LOW);
}