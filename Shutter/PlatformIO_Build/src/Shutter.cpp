#include <Arduino.h>
#include <Servo.h>
#include "Shutter.h"




    Shutter::Shutter(int inputpin, int outputpin) :input_pin(inputpin), output_pin(outputpin) {};

    void Shutter::Initialise() {
        ShutterServo.attach(output_pin);
        ShutterServo.write(90);
        }

    void Shutter::goto_open (double desired){
        //Serial.println("goto_open");
        double Input = desired+26;
        //Serial.println((unsigned int)((0.728*Input)-19.105));
        ShutterServo.write((unsigned int)((0.728*Input)-19.105));
        delay(500);

    };

    double Shutter::get(void){
        float average;
        //Serial.println("ave:");
        average = analogRead(input_pin);
        //Serial.println(average);
        for(int i = 0; i<3; i++){
            
            average += analogRead(input_pin);
            //Serial.println(average);
            delay(5);
        }
        average = average/4.0;
        //Serial.println("Reading:");
        //Serial.println(average);
        //Serial.println(analogRead(input_pin));
        
    return (0.4826*average);
    };

    void Shutter::goto_controlled (double desired){
        float pos = ShutterServo.read();
        double diff=((desired+26)-(0.4826*analogRead(input_pin)));
        double Ki = 0;
        double dt = 100;
        while ((abs(diff))>3.0){
            //Serial.println(diff);
            double changepos= 0.08*diff;  //Kp
            Ki += 0.4*diff*(dt/1000);            //Ki
            pos += (int) changepos + (int) Ki;
            if (pos>180) pos = 180;
            if (pos<0) pos =0;
            ShutterServo.write((uint16_t)pos);
            delay(dt);
            //Serial.println(pos);
            diff=((desired+26)-(this->get()));
        }
    };

    void Shutter::moveto(state pos, bool controller){
        if(controller) {
            this->goto_controlled(pos);
        }else{
            this->goto_open(pos); 
        };
    };
