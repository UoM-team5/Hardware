#include <Servo.h>

class Valve{
  private:
    int pos0;
    int pos1; 
    bool a;
    int angle_0;
    int angle_1;  
    int pinSer;  // pin number (should be 2 vor the servo)
    Servo myservo;


    
  public:
// Constructor and initial settings
    Valve(int pinServo);



// Setup
  void setUp();



// Set valve position to 1
    void set_pos1(void);


// Set valve position to 0
    void set_pos0(void);



// Toggle valve position
    void toggle_pos(void);
    


// Set the limit position of the servo motor (in degrees)
    void set_angle_lims(int angle0, int angle1);



// Get measurement of the servo motor (in degrees)
    int get_pos_analog(void);


// Get state of valve (0 or 1)
    bool get_pos_digital(void);



// Get measurement of the limit set for the servo motor (in degrees)
    int get_lim(int pos);
};
