/*
  Assumes a 10K@25℃ NTC thermistor connected in series 
  with a 10K resistor.
*/
#include <LiquidCrystal_I2C.h>  // LCD I2C library
#include <Servo.h>

#define LED 12

LiquidCrystal_I2C lcd(0x27,16,2);
const float BETA = 3950; // should match the Beta Coefficient of the thermistor
Servo myservo;

int tempRef = 30; // Temperature reference value
int pos = 0;      // Servo rotation degree

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Temperature");
  lcd.setCursor(0, 1);
  lcd.print("Controller");
  delay(2000);
  lcd.clear();

  myservo.attach(10);

  pinMode(LED, OUTPUT);
}

void loop() {
  int analogValue = analogRead(A0);
  float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
    
  lcd.setCursor(1, 0);
  lcd.print("Temp: ");
  lcd.print(celsius);
  lcd.print(" C");

  if (celsius >= tempRef) {
    digitalWrite(LED, HIGH);
    
    // Servo as a fan code start from here:
    for (pos = 0; pos <= 360; pos += 1) {  // Servo rotates 360 degrees
      myservo.write(pos);
      delay(1);
    }
    for (pos = 360; pos >= 0; pos -= 1) {  // Servo rotates to 0 degrees again
      myservo.write(pos);
      delay(1);
    }
    // Until here. You can replace this by just: digitalWrite(fanPin, HIGH);
  
    /* 

    Write your code here

    */
  }

  else if (celsius < tempRef) {
    digitalWrite(LED, LOW);
    
    // Servo as a fan code start from here:
    for (pos = 360; pos >= 0; pos -= 1) {  // Servo rotates to 0 degrees again
        myservo.write(pos);
        break;
      }
    myservo.write(pos=0);
    // Until here. You can replace this by just: digitalWrite(fanPin, LOW);
  
    /* 

    Write your code here

    */
  }

  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.println(" ℃");
  delay(500);
}