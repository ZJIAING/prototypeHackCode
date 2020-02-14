const int led1Pin = 13;

//these global variables give names to input pins
const int button1Pin = 2;

//this static bool varible will track the state of the LED in the software as TRUE or FALSE
bool led1State = 0;   //bool-either TRUE or WRONG

//tracks the previous button read
int lastButtonRead;

uint32_t debounceTime;

int buttonState = 1;

void setup() {
  Serial.begin(9600);//open serial function
  pinMode(led1Pin, OUTPUT);
  pinMode(button1Pin, INPUT);
}

void loop() {
  //read the button into the local variable (int)button1Read
  int button1Read = digitalRead(button1Pin);
  Serial.println(button1Read);//begin to print something to your serial monitor
  //compare the button pin reading to the pushed state


if (button1Read != lastButtonRead){
  debounceTime = millis(); //mark the current debounceTime
}

uint32_t pressedTime = millis() - debounceTime;

if (pressedTime >= 3){
  if (button1Read != buttonState) {
    //if it is pushed down (low) toggle the ledState
    buttonState = button1Read; //! means the OPPOSITE
    if(buttonState == 0) {
      led1State = !led1State;
    }
  } else {
    //do nothing
  }
} else {
  //do nothing
}

  //set the ledState
  digitalWrite(led1Pin, led1State);

  //save this read for next time
  lastButtonRead = button1Read;//store data

}

//emmalocal varible(bottonRead
