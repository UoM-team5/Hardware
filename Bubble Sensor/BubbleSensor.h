#ifndef BubbleSensor_h
#define BubbleSensor_h

#include <Arduino.h>

class BubbleSensor 
{

  private: 
  int Input;
  int Output;
  float average;

  public:
  BubbleSensor(int in, int out) {Input = in; Output = out;};

  void setupBS() {

    Serial.begin(9600);
    pinMode(Output, OUTPUT);

  }

  float GetValue(){
    digitalWrite(Output,HIGH);
    float sensorValue = analogRead(Input);
    float total = 0;
    for (int i=0; i<20; i++) {
      total = total + analogRead(Input);
    } 
    average = total/20;
    return average;
  };

  int Status(){
    if (average < 2) {
      Serial.println("Tube present, no liquid");
      return 1;
    }
    else if (average > 20) {
      Serial.println("Tube and liquid present");
      return 2;
    }
    else if (average > 8 && average < 20){
      Serial.println("No tube present");
      return 3;
    }
   delay(500);
   return 0;
  };
};
  #endif