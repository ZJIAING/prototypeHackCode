//these global variables give names to output pins
const int ledPin = 13;

//these global variables give names to input pins
const int button1Pin = 2;

//this static bool varible will track the state of the LED in the software as TRUE or FALSE
bool ledState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(button1Pin, INPUT);
}

void loop() {
  //read the button into the local variable (int)button1Read
  int button1Read = digitalRead(button1Pin);

  //compare the button pin reading to the pushed state
  if (button1Read == 0) {
    //if it is pushed down (low) toggle the ledState
    ledState = !ledState;
  }

  //set the ledState
  digitalWrite(ledPin, ledState);

}
