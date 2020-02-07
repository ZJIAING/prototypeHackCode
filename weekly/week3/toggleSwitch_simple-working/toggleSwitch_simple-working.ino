//global varibles for output leds//
//led output pins
const int ledPin = 13;

//this bool will track the state of the LED in the software as TRUE or FALSE
bool ledState = 0;

//global variables for buttons//
//button pin numbers
const int button1Pin = 2;

//tracks the previous readings of the buttons
int button1LastRead = 1;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(button1Pin, INPUT);
}

void loop() {
  //read the button into the local variable (int)buttonState
  int button1Read = digitalRead(button1Pin);

  //is the button read different from last read?
  if (button1Read != button1LastRead) {
    //if so, check to see if it is LOW
    if (button1Read == 0) {
      //if so, toggle the ledState
      ledState = !ledState;
    }
  }

  //set the ledState
  digitalWrite(ledPin, ledState);

  //save the buttonRead for next time around
  button1LastRead = button1Read;
} 
