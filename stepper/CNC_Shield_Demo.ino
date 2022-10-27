
// CNC Shield Stepper  Control Demo
// Superb Tech
// www.youtube.com/superbtech

const int StepX = 2;
const int DirX = 5;


void setup() {
  pinMode(StepX,OUTPUT);
  pinMode(DirX,OUTPUT);
  digitalWrite(DirX, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise
 
  for(int x = 0; x<1707; x++) { // loop for 800 steps, 400*0.9 = 1 rotation; 1707 = 1 ml
  digitalWrite(StepX,HIGH);
  delayMicroseconds(1000);
  digitalWrite(StepX,LOW); 
  delayMicroseconds(1000);
 }

}

void loop() {
}
