//Include Adafruit NeoPixel library
#include <Adafruit_NeoPixel.h>

//Define parameters for NeoPixel object
#define PIXELPIN 7
#define NUMPIXELS 16

//Declare NeoPixel object with above parameters
Adafruit_NeoPixel pixels(NUMPIXELS, PIXELPIN, NEO_RGBW);

//define a pin name/number for a digital input
#define BUTTON1 2

//keep track of time for debounce
volatile int lastDebounceTime;
//volitile for when a variable can change outside the program scope like in an ISR

//use a global variable to track when an event occurs
volatile bool pixelsMode;
//volitile for when a variable can change outside the program scope like in an ISR

void setup() {
  //initialize the Serial object for serial output
  Serial.begin(9600);
  
  //initialize NeoPixel object (REQUIRED)
  pixels.begin();
  //clear the pixels
  pixels.clear(); 
  //optional - set brightness of the strip (only do this once in SETUP)
  pixels.setBrightness(64); 
  //alway call the .show() function to apply changes to the pixels
  pixels.show();

  //attach an interrupt to BUTTON1 
  
  
}


void loop() {
  while(pixelsMode == 0) {
    
  }
}


//declare an ISR
void button1ISR() {
  int debounceTime = millis();
  if (debounceTime - lastDebounceTime >= 5) {
    pixelsMode += pixelsMode;
    if (pixelsMode > 1) {
      pixelsMode = 0;
    }
  }
  lastDebounceTime = debounceTime;
}
