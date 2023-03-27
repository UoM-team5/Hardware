#include <Arduino.h>
#include <Servo.h>
#define Analog_pin 14
#define Servo_pin 6
#include "Shutter.h"

Shutter shutter(Analog_pin, Servo_pin);

void setup() {
  Serial.begin(9600);
  delay(5000);
  shutter.Initialise();
  
}

void loop() {

  // shutter.moveto(open, 0);
  // delay(2000);
  // shutter.moveto(closed, 0);
  // delay(2000);
  // shutter.moveto(open2, 0);
  // delay(2000);
  // shutter.moveto(closed, 0);
  // delay(2000);

}