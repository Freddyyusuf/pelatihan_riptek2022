void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Inisiasi komunikasi serial dengan 
                      // dengan kecepatan baud 9600
  println("Hello, world!");
  println("this is executed first and once");
  println("=================================");
}
void loop() {
  // put your main code here, to run repeatedly:
  println("this is executed on and on");
  println("1"); println("2"); println("3");
  delay(700); // menghentikan eksekusi selama 700ms
}
