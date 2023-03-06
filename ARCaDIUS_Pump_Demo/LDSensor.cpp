
#include <Arduino.h>
#include "LDSensor.h"


  void LDSensor:: SetUpLDS() {
    Serial.begin(9600);
    pinMode(Input,INPUT);
    }  
 

  bool LDSensor:: StatusLDS () {
    Liquid_level = digitalRead(Input); 
    if (Liquid_level == HIGH) {
      Serial.println("Liquid detected");
      return true;
    }
    else {
      Serial.println("No liquid detected");
      return false; 
    }
  }
