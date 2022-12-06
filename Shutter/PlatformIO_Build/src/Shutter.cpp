#include <Arduino.h>
#include <Servo.h>
#include "Shutter.h"




    Shutter::Shutter(int inputpin, int outputpin) :input_pin(inputpin), output_pin(outputpin) {};

    void Shutter::Initialise() {
        ShutterServo.attach(output_pin);
        ShutterServo.write(90);
        }

    void Shutter::goto_open (double desired){
        Serial.println("goto_open");
        double Input = desired+26;
        Serial.println((unsigned int)((0.728*Input)-19.105));
        ShutterServo.write((unsigned int)((0.728*Input)-19.105));
        delay(500);
    };

    double Shutter::get(void){
    return ((0.4826*analogRead(input_pin)-26));
    };

    void Shutter::goto_controlled (double desired){
        uint16_t pos = ShutterServo.read();
        double diff=((desired+26)-(0.4826*analogRead(input_pin)));
        double Ki = 0;
        while ((abs(diff))>3){
            // Serial.println(diff);
            double changepos= 0.1*diff;  //Kp
            Ki += 0.001*diff;            //Ki
            pos += (int) changepos + (int) Ki;
            if (pos>180) pos = 180;
            if (pos<0) pos =0;
            ShutterServo.write(pos);
            delay(100);
            diff=((desired+26)-(0.4826*analogRead(input_pin)));
        }
    };

    void Shutter::moveto(state pos, bool controller){
        if(controller) {
            this->goto_controlled(pos);
        }else{
            this->goto_open(pos); 
        };
    };
