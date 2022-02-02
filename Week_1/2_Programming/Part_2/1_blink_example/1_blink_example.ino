// this is an example of LED animation
// to run this code on wokwi.com:
// 1. open wokwi.com, choose new Arduino Uno Project
// 2. copy and paste this code in sketch.ino file\
// 3. copy and paste the diagram.json as well
// 4. hit the play button to start the simulation

void setup() {
  // in this code, we will try to print the state of LEDs
  // we couldn't use printf() directly like in conventional C
  // we should open the communication between the arduino and computer/console
  // it can be done by calling Serial module
  Serial.begin(9600); // initialize serial communication
  
  for(int i=4; i<12; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  // use "println" to print new line after string, and "print" to print without new line
  Serial.println("LEDs are moving from right to left");
  for(int i=4; i<12; i++){
    digitalWrite(i, HIGH);
    delay(200);
    digitalWrite(i, LOW);
    delay(200);
  }
 
  Serial.println("LEDs are moving from left to right");
   for(int i=11; i>3; i--){
    digitalWrite(i, HIGH);
    delay(200);
    digitalWrite(i, LOW);
    delay(200);
  }
}
