// constants won't change. They're used here to set pin numbers:
// these are the pins for the RAMPS and compatable boards
const int xminPin = 3;       // the number of the X minimum pin
const int yminPin = 14;       // the number of the Y minimum pin
const int zminPin = 18;       // the number of the Z minimum pin
const int xmaxPin = 2;       // the number of the X maximum pin
const int ymaxPin = 15;       // the number of the Y minimum pin
const int zmaxPin = 19;       // the number of the Z minimum pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int xminendstopState = 0; 
int yminendstopState = 0; 
int zminendstopState = 0; 
int xmaxendstopState = 0; 
int ymaxendstopState = 0; 
int zmaxendstopState = 0; 

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the endstop pins as an input with internal pullup:
  pinMode(xminPin, INPUT_PULLUP);
  pinMode(yminPin, INPUT_PULLUP);
  pinMode(zminPin, INPUT_PULLUP);
  pinMode(xmaxPin, INPUT_PULLUP);
  pinMode(ymaxPin, INPUT_PULLUP);
  pinMode(zmaxPin, INPUT_PULLUP);
  // open up serial port
  Serial.begin(9600); 
}

void loop() {
  // read the state of the pushbutton value:
  xminendstopState = digitalRead(xminPin);
  yminendstopState = digitalRead(yminPin);
  zminendstopState = digitalRead(zminPin);
  xmaxendstopState = digitalRead(xmaxPin);
  ymaxendstopState = digitalRead(ymaxPin);
  zmaxendstopState = digitalRead(zmaxPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if ( xminendstopState == LOW || yminendstopState == LOW || zminendstopState == LOW || xmaxendstopState == LOW || ymaxendstopState == LOW || zmaxendstopState == LOW ) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

  //send state to serial port
  Serial.print("X min endstop ==> [");
  Serial.print(xminendstopState, DEC);
  Serial.print("] X max endstop ==> [");
  Serial.print(xmaxendstopState, DEC);
  
  Serial.print("] Y min endstop ==> [");
  Serial.print(yminendstopState, DEC);
  Serial.print("] Y max endstop ==> [");
  Serial.print(ymaxendstopState, DEC);

  Serial.print("] Z min endstop ==> [");
  Serial.print(zminendstopState, DEC);
  Serial.print("] Z max endstop ==> [");
  Serial.print(zmaxendstopState, DEC);

  Serial.println("]");

  delay(300);
}
