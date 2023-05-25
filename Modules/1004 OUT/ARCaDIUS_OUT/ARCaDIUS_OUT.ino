#include "ARCaDIUS_Serial.h"
#include "Valve.h"
#include "Pump.h"

String DeviceDesc = "Module = Output";
int Device_ID = 1004;
int Sender_ID = 1000;
int Num_of_Pumps = 1;
int Num_of_Valves = 5;
int Num_of_Shutter = 0;
int Num_of_Mixer = 0;
int Num_of_Temp = 0;
int Num_of_Bubble = 0;
int ResetPin = 3;

ASerial Device(DeviceDesc, Device_ID, Sender_ID, Num_of_Pumps, Num_of_Valves, Num_of_Shutter, Num_of_Temp, Num_of_Bubble, Num_of_Mixer, ResetPin);
Valve Valve1(3, 65, 127);
Valve Valve2(5, 65, 127);
Valve Valve3(6, 65, 128);
Valve Valve4(9, 65, 127);
Valve Valve5(10, 66, 130);
Pump P4(11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Device.Start();
  
  Valve1.setUp();
  Valve2.setUp();
  Valve3.setUp();
  Valve4.setUp();
  Valve5.setUp();
  P4.setUp();
}

void loop() {
  if (Device.GotCommand()) {
    switch (Device.GetCommand()) {
      case PUMP: 
        Serial.println("pump number: " + (String)Device.getPump());
        Serial.println("pump volume: " + (String)Device.getPumpMls());
        switch (Device.getPump()) {//[sID1000 rID1004 PK3 P4 m5.00 D1]
          case 4:
            P4.set_vol(Device.getPumpMls(),Device.getPumpDir());
            break;
          default:
            break;
        }
        break;
      case MIXER: // Enter code for mixer here
        Serial.println("The mixer number is: " + (String)Device.getMixer());
        Serial.println("The mixer speed is: " + (String)Device.getMixerSpeed());
        Serial.println("The mixer direction is: " + (String)Device.getMixerDir());
        break;
      case VALVE:
        switch (Device.getValve()) {//test [sID1000 rID1004 PK2 V1 S0]
          case 1:
            Valve1.set_pos(Device.getValveState());
            Serial.println("valve number: " + (String)Device.getValve());
            Serial.println("valve state:  " + (String)Valve1.get_pos_digital());
            Serial.println("valve angle:  " + (String)Valve1.get_pos_analog());
            break;
          case 2:
            Valve2.set_pos(Device.getValveState());
            Serial.println("valve number: " + (String)Device.getValve());
            Serial.println("valve state:  " + (String)Valve2.get_pos_digital());
            Serial.println("valve angle:  " + (String)Valve2.get_pos_analog());
            break;
          case 3:
            Valve3.set_pos(Device.getValveState());
            Serial.println("valve number: " + (String)Device.getValve());
            Serial.println("valve state:  " + (String)Valve3.get_pos_digital());
            Serial.println("valve angle:  " + (String)Valve3.get_pos_analog());
            break;
          case 4:
            Valve4.set_pos(Device.getValveState());
            Serial.println("valve number: " + (String)Device.getValve());
            Serial.println("valve state:  " + (String)Valve4.get_pos_digital());
            Serial.println("valve angle:  " + (String)Valve4.get_pos_analog());
            break;
          case 5:
            Valve5.set_pos(Device.getValveState());
            Serial.println("valve number: " + (String)Device.getValve());
            Serial.println("valve state:  " + (String)Valve5.get_pos_digital());
            Serial.println("valve angle:  " + (String)Valve5.get_pos_analog());
            break;
          default:
            break;
        }
        
        break;
      case SHUTTER: // Enter code for shutter here
        Serial.println("The shutter number is: " + (String)Device.getShutter());
        Serial.println("The shutter position  is: " + (String)Device.getShutterPos());
        break;
      default: // Leave this, its just the default
        break;
    }
    delay(100);
    Device.FinishedCommand();
  }
}
