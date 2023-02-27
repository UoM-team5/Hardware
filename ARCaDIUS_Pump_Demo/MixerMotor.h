#ifndef MixerMotor_h
#define MixerMotor_h


#include <Arduino.h>

class MixerMotor 
{
  private: 
  int MP1;
  int MP2;
  int E;

  public:
  MixerMotor(int motorPin1, int motorPin2, int Enable) {MP1 = motorPin1; MP2 = motorPin2; E = Enable;};

  void SetUpMotor();

  void StopMotor();

  void MotorHigh(); 

  void MotorMedium();

  void MotorSlow(); 

};
#endif

