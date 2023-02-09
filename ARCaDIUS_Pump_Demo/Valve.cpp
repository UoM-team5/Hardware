#include "Valve.h"
#include "Servo.h"

// Setup
void Valve::setUp() {
  Serial.println(myservo.attach(pinSer));
  myservo.write(1700);
}

// Set Valve position to 1
void Valve::set_pos1(void) {
  a = angle_1;
  myservo.write(angle_1);
} // End function

// Set Valve position to 0
void Valve::set_pos0(void) {
  a = angle_0;
  myservo.write(angle_0);
} // End function

// Toggle Valve position
void Valve::toggle_pos(void) {
  if (get_pos_digital() == 1) {
    set_pos0();
  } // End if
  else {
    set_pos1();
  } // End else
} // End funtion

// Set the limit position of the servo motor (in degrees)
void Valve::set_angle_lims(int angle0, int angle1) {
  angle_0 = angle0;
  angle_1 = angle1;
} // End function

// Get measurement of the servo motor (in degrees)
int Valve::get_pos_analog(void) {
  return myservo.read();
}

// Get state of Valve (0 or 1)
bool Valve::get_pos_digital(void) {
  if (a == 1) {
    return 1;
  } // End if
  else {
    return 0;
  } // End else
} // End function

// Get measurement of the limit set for the servo motor (in degrees)
int Valve::get_lim(int pos) {
  if (pos == 0) {
    return angle_0;
  }
  if (pos == 1) {
    return angle_1;
  }
} // End function
