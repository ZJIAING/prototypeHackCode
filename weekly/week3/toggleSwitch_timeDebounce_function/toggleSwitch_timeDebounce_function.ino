//global varibles for output leds//
//led output pins
const int ledPin = 13;

//track the state of the LED
bool ledState = 0;

//global variables for buttons and debounce//
//button pin numbers
const int button1Pin = 2;

//tracks the previous readings of the buttons
int button1LastRead = 1;

//tracks the stable button state independent of the buttonRead
int button1State = 1;

//tracks the time when the button state changes
uint32_t button1DebounceTime;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(button1Pin, INPUT);
}


void loop() {
  //call the buttonDB function to read the button and filter the signal
  buttonDB();
  
  //write the ledState
  digitalWrite(ledPin, ledState);

  //save the current button read for next time
  button1LastRead = button1Read;
}

void buttonDB(){
  //read the button into the a local variable
  int button1Read = digitalRead(button1Pin);

  //is the button read different from last read?
  if (button1Read != button1LastRead) {
    //if so set debounceStart to the current time in ms
    button1DebounceTime = millis();
  }

  //calculate how long it has been since the last change
  int button1PressTime = millis() - button1DebounceTime;

  //is presstime is greater than threshold?
  if (button1PressTime >= 2) {
    //if so is the reading different than the last stable button state?
    if (button1Read != button1State) {
      //if so, make the stable state match the reading
      button1State = button1Read;  
      //if the stable state is low after a successful debounce
      if (button1State == 0) {
        //toggle the ledState
        ledState = !ledState;
      }
    }
  }
}
