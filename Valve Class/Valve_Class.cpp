#include <Servo.h>

class Valve{
  private:
    int pos0 = 0;
    int pos1 = 1; 
    bool a = 0;
    int angle_0 = 0;
    int angle_1 = 50;  
    int pinSer;  // pin number (should be 2 vor the servo)
    Servo myservo;


    
  public:
// Constructor and initial settings
    Valve(int pinServo):pinSer(pinServo){}



// Setup
  void setUp(){
    myservo.attach(Valve::pinSer);
    myservo.write(0);
  }



// Set valve position to 1
    void set_pos1(void){
      Valve::a = angle_1;
      myservo.write(angle_1);
    } // End function



// Set valve position to 0
    void set_pos0(void){
      Valve::a = Valve::angle_0;
      myservo.write(angle_0);
    } // End function



// Toggle valve position
    void toggle_pos(void){        
      if (get_pos_digital() == 1){
        set_pos0();
      } // End if
      else {
        set_pos1();
      } // End else
    } // End funtion
    


// Set the limit position of the servo motor (in degrees)
    void set_angle_lims(int angle0, int angle1){
        Valve::angle_0 = angle0;
        Valve::angle_1 = angle1;
    } // End function



// Get measurement of the servo motor (in degrees)
    int get_pos_analog(void){
      return myservo.read();
    }



// Get state of valve (0 or 1)
    bool get_pos_digital(void){
      if (a==1){
        return 1;  
      } // End if
      else {
        return 0;
      } // End else
    } // End function



// Get measurement of the limit set for the servo motor (in degrees)
    int get_lim(int pos){
      if (pos == 0){
        return Valve::angle_0;
      }
      if (pos == 1){
        return Valve::angle_1;
      }
    } // End function   
};