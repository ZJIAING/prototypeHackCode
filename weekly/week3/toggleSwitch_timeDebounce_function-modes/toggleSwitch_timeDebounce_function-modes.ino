//definitions to give names to different LED MODES
#define LIGHTS_OFF 0
#define FLASH_FIRST 1
#define FLASH_SECOND 2
#define FLIP_FLOP 3
#define FLASH_BOTH 4

//global varibles for output leds//
//led output pins
const int led1Pin = 13;
const int led2Pin = 12;

//the the desired LED MODE
int ledMode = 0;

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
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(button1Pin, INPUT);
}


void loop() {
  //call the buttonDB function to read the button and filter the signal
  buttonDB(button1Pin);

  //toggle the led Modes
  if (ledMode == LIGHTS_OFF) {
    lightsOff();
  } else if (ledMode == FLASH_FIRST) {
    flashFirstLed();
  } else if (ledMode == FLASH_SECOND) {
    flashSecondLed();
  } else if (ledMode == FLIP_FLOP) {
    flipFlopLeds();
  } else if (ledMode == FLASH_BOTH) {
    flashBothLeds();
  }

}

//FUNCTION PROTOTYPES//
void buttonDB(int buttonPin) {
  //read the button into the a local variable
  int button1Read = digitalRead(buttonPin);

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
        //increment the mode of the LED
        ledMode += 1;
        //if the ledmode is higher than 3 send it back to 0
        if (ledMode > 4) {
          ledMode = 0;
        }
      }
    }
  }
  //save the current button read for next time
  button1LastRead = button1Read;
}

void flashBothLeds() {
  digitalWrite(led1Pin, HIGH);
  digitalWrite(led2Pin, HIGH);
  delay(250);
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
  delay(250);
}

void flipFlopLeds() {
  digitalWrite(led1Pin, HIGH);
  digitalWrite(led2Pin, LOW);
  delay(250);
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, HIGH);
  delay(250);
}

void flashFirstLed() {
  digitalWrite(led1Pin, HIGH);
  delay(250);
  digitalWrite(led1Pin, LOW);
  delay(250);
}

void flashSecondLed() {
  digitalWrite(led2Pin, HIGH);
  delay(250);
  digitalWrite(led2Pin, LOW);
  delay(250);
}

void lightsOff() {
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
}
