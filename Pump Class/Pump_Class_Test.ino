int flag=1;
Pump mypump(12,0);
Pump StepPump(5,2,8,1);

void setup(){
  Serial.begin(115200);
  mypump.setUp();
  StepPump.setUp();
}

void loop(){
  if(flag==1){
    StepPump.set_vol(2.5,1);
    mypump.set_vol(2.5,1);
    flag++;
  }   
}
