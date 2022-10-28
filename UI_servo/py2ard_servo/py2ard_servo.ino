#include <Servo.h>

Servo myservo;


int a = 0;
int servo_angle=36;
void setup() {
 Serial.begin(115200);
 myservo.attach(2);
 Serial.setTimeout(1);
 myservo.write(40);
}
void loop() {
 while (!Serial.available());
 a = Serial.readString().toInt();
 
 if(a==0){servo_angle=36;}
 else if(a==1){servo_angle=50;}
 
 myservo.write(servo_angle);
 
 Serial.print(a);
 delay(100);
}
