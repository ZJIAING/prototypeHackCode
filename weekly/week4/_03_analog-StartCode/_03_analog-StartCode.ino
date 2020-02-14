//Include Adafruit NeoPixel library
#include <Adafruit_NeoPixel.h>

//Define parameters for NeoPixel object
#define PIXELPIN 7
#define NUMPIXELS 16

//Declare NeoPixel object with above parameters
Adafruit_NeoPixel pixels(NUMPIXELS, PIXELPIN, NEO_RGBW);

//define a pin name/number for a ANALOG input
#define ANALOG1 A0

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
  
}
