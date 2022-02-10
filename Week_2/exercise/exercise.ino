// terdapat baris kode yang kosong di berkas ini, ditandai dengan "....."
// lengkapi kode tersebut dengan benar
// petunjuk terdapat pada komentar di atas baris kosong tersebut

// kode yang sudah dilengkapi dapat ditest melalui simulasi (sama seperti prosedur Part 1-4 di modul)

#include <LiquidCrystal_I2C.h>  

// definisikan pin analog 1 dengan nama pinInput
const int ... = ... ;

LiquidCrystal_I2C lcd(0x27,16,2);

int inputValue;

void setup() {
  // atur pinInput sebagai input dengan fungsi pinMode
  ....
  // inisiasi komunikasi serial dengan baud rate 9600
  ....
  
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("LDR");
  lcd.setCursor(0, 1);
  lcd.print("Sensor");
  delay(1000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("val: ");
}
void loop() {

  // baca pinInput dengan fungsi analogRead, lalu simpan di variabel inputValue
  ....
  
  lcd.setCursor(6, 0);
  lcd.print("     ");
  lcd.setCursor(6, 0);
  // tampilkan hasil pembacaan pinInput yang tersimpan
  lcd.print(....);


  /* Buatlah kondisi ketika nilai inputValue kurang dari 150, LCD mencetak "Terang",
     ketika di antara 750 dan 150 mencetak "Redup", dan ketika di atas 750 mencetak "Gelap"
   */ 
  lcd.setCursor(0, 1);
  if(inputValue ... ){
    lcd.print("Terang");
 } else if(inputValue ... ){
   lcd.print( ... );
 } ... ( ... ){
   lcd.print( ... );
 }
}
