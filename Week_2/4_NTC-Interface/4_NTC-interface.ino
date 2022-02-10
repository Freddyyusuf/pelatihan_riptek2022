/*
  Assumes a 10K@25℃ NTC thermistor connected in series 
  with a 10K resistor.
*/
#include <LiquidCrystal_I2C.h>  // LCD I2C library

LiquidCrystal_I2C lcd(0x27,16,2);
const float BETA = 3950; // should match the Beta Coefficient of the thermistor

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
}

void loop() {
  int analogValue = analogRead(A0);
  float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
    
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(celsius);
  lcd.print(" C");

  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.println(" ℃");
  delay(1000);
}