// deklarasi variabel
bool x = true;
int  a  = -21;
char b = "A";
byte c = 20;
float d = 3.14;
float e = 2.37;
long int f = 1231;
unsigned int g = 31;

//deklarasi array
const int prime[] = {2, 3, 5, 7, 11};
float values[] = {2.8, .9, .002, 12.9};

//mengakses array
int num_one = prime[0];

void setup() {
  values[3] = 9.87; //mengubah nilai elemen array
}

void loop() {
}
