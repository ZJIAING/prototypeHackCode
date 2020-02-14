//Include Adafruit NeoPixel library
#include <Adafruit_NeoPixel.h>

//include coordinates library
#include <Coordinates.h>

//Define parameters for NeoPixel object
#define PIXELPIN 7
#define NUMPIXELS 16

//Declare NeoPixel object with above parameters
Adafruit_NeoPixel pixels(NUMPIXELS, PIXELPIN, NEO_RGBW);

//Declare a coordinates object
Coordinates point = Coordinates();

//define a pin name/number for a ANALOG input
#define X_PIN A0
#define Y_PIN A1

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

}


void loop() {
  //read the analog Values
  int xRead = analogRead(X_PIN);
  int yRead = analogRead(Y_PIN);

  //convert them to cartesian coordinates
  int xCo = map(xRead, 0, 1023, -100, 100);
  int yCo = map(yRead, 0, 1023, -100, 100);

  //convert the xCo and yCo to polar coordinates
  point.fromCartesian(xCo, yCo);

  //get the angle in radians
  //there are 2 RADS in a full circle
  //we have 16 leds
  //2 RAD / 16 = 0.125
  //we can figure out which led to light by dividing our angle by 0.125
  float ledAngle;
  if (point.getAngle() != 0) {
    ledAngle = point.getAngle() / 0.125;
  }

  int ledNumber = (int)ledAngle; //cast the ledAngle to int

  //now write the ledNumber to the pixels
  pixels.clear();
  pixels.setPixelColor(ledNumber, 0, 0, 255, 0);
  pixels.show();

  //pause for stability
  delay(10);

//this works but is glitcy at the bottom and top of stick
//need a better algorithm to determine which led to light up
//might work better with conversion to degrees?
//need to do some serial debug

}
