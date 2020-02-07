//led variables
const int ledPin1 = 13;
const int ledPin2 = 12;
//volitile is used when a variable is chaged outside the program scope such as in an interrupt
volatile byte ledState = LOW; 

//button variables
const byte buttonPin = 2;
 volatile int lastDebounceTime;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin, INPUT);
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
