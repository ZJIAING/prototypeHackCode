//these global variables give names to output pins
const int led1Pin = 13;

//these global variables give names to input pins
const int button1Pin = 2;

//this static bool varible will track the state of the LED in the software as TRUE or FALSE
bool led1State = 0;

void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(button1Pin, INPUT);
}

void loop() {
  //read the button into the local variable (int)button1Read
  int button1Read = digitalRead(button1Pin);

  //compare the button pin reading to the pushed state
  if (button1Read == 0) {
    //if it is pushed down (low) toggle the ledState
    led1State = !led1State;
  }

  //set the ledState
  digitalWrite(led1Pin, led1State);

}
