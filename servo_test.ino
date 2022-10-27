#include <ESP32Servo.h>

Servo myservo;
int a = 15;

void setup() {
  Serial.begin(115200);
  myservo.attach(14);
  pinMode(22,INPUT_PULLUP);
  
}
void loop() {
  //15 - 45
  bool button = digitalRead(22);
  if (button){
    a = 45;
  }
  else{a = 15;}
  Serial.println(button);
  
  
  delay(100);
  myservo.write(a);
  
}
