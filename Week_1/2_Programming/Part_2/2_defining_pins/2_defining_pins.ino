// 1. fill the uncomplete code below, run it on simulation
// ----------------------------------------------------------------------------------------------------------------

// this code will control a group of LEDs
// before you use the pin to control LEDs, you should define them first
// the pins is labeled as their numbers, 
// naming the pins based on their functionality could make the code easier to read
 
// pin can be defined like this
#define outputPin_1 4
#define outputPin_2 5
#define outputPin_3 6

// but you can assign them as constant variables too
const int outputPin_4= 7;
const int outputPin_5= 8;
const int outputPin_6= 9;
const int outputPin_7= 10;

// for confinient, you could define them as an array too
const int myInputPin[]= {11, 12, 13};

// those are the common and easy ways to define pins.

void setup() {
  ... // initialize serial communication
  
  // let's set the pins to be output with pinMode API
  pinMode(outputPin_1, OUTPUT);
  pinMode(outputPin_2, OUTPUT);
  // try to fill the rest as output pin
  ....
  ...
  ..
  .

  // with array, repetitive task can be done with loop
  // this method is usually  more confinient, but not the best
  for(int i=0; i<(sizeof(myInputPin)/sizeof(int)); i++){
    pinMode(myInputPin[i], INPUT_PULLUP);
  }
}


void loop() {
    // now, try to turn on all LEDs for 1s, and off for 1s, repeatedly. print the state of LEDs("ON"/"OFF")
  

}
