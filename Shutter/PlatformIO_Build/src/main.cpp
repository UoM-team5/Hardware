#include <Arduino.h>
#include <Servo.h>
#define Analog_pin 14
#define Servo_pin 5
#include "Shutter.h"

Shutter shutter(Analog_pin, Servo_pin);

void setup() {
  Serial.begin(9600);
  delay(1000);
  shutter.Initialise();
  delay(5000);
}

int start;
int time;
int iterations= 0;

void loop() {
  iterations++;
  Serial.println(iterations);
  Serial.println("Opening");
  start = millis();
  shutter.moveto(open, 1);
  time = millis() - start;
  Serial.println(time);
  Serial.println(shutter.get());
  delay(2000);

  Serial.println("Closing");
  start = millis();
  shutter.moveto(closed, 1);
  time = millis() - start;
  delay(2000);
  Serial.println(time);
  Serial.println(shutter.get());
  // shutter.moveto(open2, 0);
  // delay(2000);
  // shutter.moveto(closed, 0);
  // delay(2000);

}