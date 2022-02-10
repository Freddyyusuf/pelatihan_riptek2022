const int digitalInput= 5;
const int analogInput= A1;

void setup() {
  Serial.begin(9600);
  pinMode(digitalInput, INPUT_PULLUP);
  pinMode(analogInput, INPUT); 
}

void loop() {
  int digitalValue = digitalRead(digitalInput);
  int analogValue = analogRead(analogInput);

  Serial.print("digital: ");
  Serial.print(digitalValue);
  Serial.print("  analog: ");
  Serial.println(analogValue);

  delay(300);

}
