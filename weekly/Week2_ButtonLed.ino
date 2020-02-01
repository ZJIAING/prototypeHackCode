//global varibles
int ledPin = 13;  //ledPin
int delayTime = 1000; //delay time for blinking
int buttonPin = A0;  //buttonPin

void setup(){
  //initialize the serial port for debug and testing
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop(){
  //check the state of the button
  int buttonRead = digitalRead(buttonPin);

  //print the value buttonRead
  Serial.println(buttonRead);

  //print something to the monitor if the button is pushed
  //button is 0 when pushed
  if(buttonRead == 0) {
    Serial.println("Hello World!");
  }
  
  digitalWrite(ledPin, HIGH);
  delay(delayTime);
  digitalWrite(ledPin, LOW);
  delay(delayTime);
}
