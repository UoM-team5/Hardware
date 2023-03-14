
#include <ARCaDIUS_Serial.h>
#include <Valve.h>
#include <Shutter.h>
#include <MixerMotor.h>
#include <LDSensor.h>
#include <BubbleSensor.h>
#include <Pump.h>

String DeviceDesc = "This is an example string";
int Device_ID = 1001;
int Sender_ID = 1000;
int Num_of_Pumps = 2;
int Num_of_Valves = 6;
int Num_of_Shutter = 1;
int Num_of_Mixer = 1;
int Num_of_Temp = 0;
int Num_of_Bubble = 0;
int Num_of_LDS = 1;
int ResetPin = 1;

ASerial Device(DeviceDesc, Device_ID, Sender_ID, Num_of_Pumps, Num_of_Valves, Num_of_Shutter, Num_of_Temp, Num_of_Bubble, Num_of_LDS, Num_of_Mixer, ResetPin);
Pump P1(9);
Pump P2(8);
Valve valve1(2, 65, 120);
Valve valve2(3, 65, 120);
Valve valve3(4, 65, 120);
Valve valve4(5, 65, 120);
Valve valve5(6, 65, 120);
Valve valve6(7, 65, 120);
Shutter shutter(A2, 11);
LDSensor liquid(10);
MixerMotor MagMix(12,13,A1);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.setTimeout(1000);
  Serial.println("start");
  Device.Start();
  valve1.setUp();
  valve2.setUp();
  valve3.setUp();
  valve4.setUp();
  valve5.setUp();
  valve6.setUp();
  P1.setUp();
  P2.setUp();
  shutter.Initialise();
  liquid.SetUpLDS();
  MagMix.SetUpMotor();

}

void loop() {
  // put your main code here, to run repeatedly:
//  if (Device.GotCommand()) {
//    //[sID1000 rID1001 PK1 R]
//    switch (Device.GetCommand()) {
//      case WASH:
      int i= 0;
        while (i < 3){   // For now, spec values unknown, so test with this, proper code at the end of the code
         //close shutter, need to find angle of closed state
          shutter.goto_controlled(0);
          // pump in cleaning liquid
          P2.set_vol(40,1);  // Not sure which dir
          MagMix.MotorMedium();  
          delay(5000); // Stir 5 sec, maybe more, need testing
          MagMix.StopMotor();
          //Write valve configuration 
          valve1.set_pos(1);
          valve2.set_pos(1);
          valve3.set_pos(1);
          valve4.set_pos(1);
          valve5.set_pos(1);
          valve6.set_pos(1);
          
          //Pump out cleaning liquid into vessel
          P2.set_vol(40, 0);

          //in case of lefover liquid since input module has servo pump instead of stepper pump.
          while (liquid.StatusLDS()== true){
            P2.set_vol(1, 0);
          }

          ++i;

        }
//  }

}


// water molecular weight = 18 g/mol, or any cleaning agent molecular weight
//Divide liquid volume (grams) by molar mass = moles
//moles x 6.022*10^23 = molecules
/*
desired_vol = 0.90 * 40;  // want 90% of liquid to be water
mol = desired_vol/18;
molecules = mol* 6.022*10^23; 
while(highest_spec_reading<molecules){all the code inside while loop}
*/
//useful links to understand mass spectometry and convertion
//https://chem.libretexts.org/Ancillary_Materials/Reference/Organic_Chemistry_Glossary/Mass-to-Charge_Ratio
//https://www.broadinstitute.org/technology-areas/what-mass-spectrometry
