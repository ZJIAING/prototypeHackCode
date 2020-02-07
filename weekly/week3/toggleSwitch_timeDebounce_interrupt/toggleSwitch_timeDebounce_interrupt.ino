//led variables
const int led1Pin = 13;

//volitile is used when a variable is chaged outside the program scope such as in an interrupt
volatile int led1State = 0;

//button variables
const int button1Pin = 2;
volatile int lastDebounceTime;

void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(button1Pin, INPUT);
  attachInterrupt(digitalPinToInterrupt(button1Pin), buttonISR, LOW);
}

void loop() {
  digitalWrite(led1Pin, led1State);
}

void buttonISR() {
  int debounceTime = millis();
  if (debounceTime - lastDebounceTime > 2) {
    led1State = !led1State;
  }
  lastDebounceTime = debounceTime;
}
