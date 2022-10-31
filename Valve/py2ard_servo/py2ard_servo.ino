#include <Servo.h>

Servo myservo;
Servo Pump;

int Speed = 90;
int a = 0;
int servo_angle = 36;

void setup() {
  Serial.begin(115200);
  myservo.attach(2);
  Pump.attach(3);
  Serial.setTimeout(1);
  myservo.write(40);
  Pump.write(Speed);
}

void loop() {
  if (Serial.available() > 0) {
    a = Serial.readStringUntil(',').toInt();
    int mls = Serial.readStringUntil('\n').toInt();

    if (a == 0) {
      servo_angle = 36;
    }
    else if (a == 1) {
      servo_angle = 50;
    }
    myservo.write(servo_angle);
    //float ml = 10.0; // insert amount you want to pump
    if (mls > 0) {
      float mlpersec = (0.0052 * mls) + 0.6678;
      int pumping_time = (mls / mlpersec) * 1000;
      Pump.write(0); //Clockwise maximum speed rotation (0 degrees)
      delay(pumping_time);
      mls = 0;
      Pump.write(90);
    }

    //Serial.println(mlpersec);
  }

  Serial.print(a);
  delay(10);
}
