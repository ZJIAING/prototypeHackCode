//global varibles for output leds//
//led output pins
const int led1Pin = 13;

//this bool will track the state of the LED in the software as TRUE or FALSE
bool led1State = 0;

//global variables for buttons//
//button pin numbers
const int button1Pin = 2;

//tracks the previous readings of the buttons
int button1LastRead = 1;

void setup() {
  pinMode(led1Pin, OUTPUT);
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
      led1State = !led1State;
    }
  }

  //set the ledState
  digitalWrite(led1Pin, led1State);

  //save the buttonRead for next time around
  button1LastRead = button1Read;
} 
