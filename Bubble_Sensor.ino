//A variable to hold the level of coolness

void setup() {

  Serial.begin(9600);
  pinMode(6, OUTPUT);
  //pinMode(A0, INPUT);

}

void loop() {

  digitalWrite(6,HIGH);
  float sensorValue = analogRead(A0);
  float total = 0;
  for (int i=0; i<20; i++) {
    total = total + analogRead(A0);
  } 
  float average = total/20;
  //Serial.println(average);
  if (average < 2) {
    Serial.println("Tube present, no liquid");
  
  }
  else if (average > 20) {
    Serial.println("Tube and liquid present");
    
  }
  else if (average > 8 && average < 20){
    Serial.println("No tube present");
    
  }
  delay(500);
  //Serial.println(sensorValue);

}
