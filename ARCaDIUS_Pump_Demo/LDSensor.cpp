
#include <Arduino.h>
#include "LDSensor.h"


  void LDSensor:: SetUpLDS() {
    Serial.begin(9600);
    pinMode(Input,INPUT);
    }  
 

  int LDSensor:: StatusLDS () {
    Liquid_level = digitalRead(Input); 
    if (Liquid_level == HIGH) {
      Serial.println("Liquid detected");
      return 1;
    }
    else {
      Serial.println("No liquid detected");
      return 0; 
    }
  }
