//led variables
const byte ledPin = 13;
//volitile is used when a variable is chaged outside the program scope such as in an interrupt
volatile byte ledState = LOW; 

//button variables
const byte buttonPin = 2;
 volatile int lastDebounceTime;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonISR, LOW);
}

void loop() {
  digitalWrite(ledPin, ledState);
}

void buttonISR() {
  int debounceTime = millis();
  if (debounceTime - lastDebounceTime > 2){
    ledState = !ledState;
  }
  lastDebounceTime = debounceTime;
}
