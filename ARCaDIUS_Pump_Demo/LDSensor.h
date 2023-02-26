#ifndef LDSensor_h
#define LDSensor_h

#include <Arduino.h>

class LDSensor 
{

  private: 
  int Liquid_level = 0;
  int Input;

  public:
  LDSensor(int in) {Input = in;};

  void SetUpLDS(); 

  int StatusLDS();
};
#endif