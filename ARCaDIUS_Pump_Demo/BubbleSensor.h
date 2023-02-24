#ifndef BubbleSensor_h
#define BubbleSensor_h

#include <Arduino.h>

class BubbleSensor 
{

  private: 
  int Input;
  int Output;

  public:
  float average;
  BubbleSensor(int in, int out) {Input = in; Output = out;};

  void setupBS();

  int Status();
};
  #endif