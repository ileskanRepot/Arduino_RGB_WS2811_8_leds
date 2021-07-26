#include "FastLED.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
//
// RGB Calibration code
//
// Use this sketch to determine what the RGB ordering for your chipset should be.  Steps for setting up to use:

// * Uncomment the line in setup that corresponds to the LED chipset that you are using.  (Note that they
//   all explicitly specify the RGB order as RGB)
// * Define DATA_PIN to the pin that data is connected to.
// * (Optional) if using software SPI for chipsets that are SPI based, define CLOCK_PIN to the clock pin
// * Compile/upload/run the sketch 

// You should see six leds on.  If the RGB ordering is correct, you should see 1 red led, 2 green 
// leds, and 3 blue leds.  If you see different colors, the count of each color tells you what the 
// position for that color in the rgb orering should be.  So, for example, if you see 1 Blue, and 2
// Red, and 3 Green leds then the rgb ordering should be BRG (Blue, Red, Green).  

// You can then test this ordering by setting the RGB ordering in the addLeds line below to the new ordering
// and it should come out correctly, 1 red, 2 green, and 3 blue.
//
//////////////////////////////////////////////////

#define NUM_LEDS 8

// Data pin that led data will be written out over
#define DATA_PIN 13
// Clock pin only needed for SPI based chipsets when not using hardware SPI
//#define CLOCK_PIN 8
#define TIME 200
CRGB leds[NUM_LEDS];

void setup() {
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(200);

      // Uncomment one of the following lines for your leds arrangement.
      FastLED.addLeds<WS2811, DATA_PIN, BRG>(leds, NUM_LEDS);
      FastLED.clear();
}

/*void loop() {
  for (unsigned char b = 16;b<256;b+=16)
  {
    for (unsigned char g = 16;g<256;g+=16)
    {
      for (unsigned char r = 16;r<256;r+=16)
      {
        for (unsigned char i = 0;i < NUM_LEDS; i++)
        {
          leds[i] = CRGB(0,0,0);
          leds[(i+2)%NUM_LEDS] = CRGB(r,g,b);
      
          FastLED.show();
          delay(TIME);
        }
      }
    }
  }
}*/
int r;
int b;
int g;
char a = 0;
void loop() {
  switch(a){
    case 0:
      r = 0;
      b = 255;

      for (g = 0; g < 256; g+=16)
      {
        for (unsigned char i = 0;i < NUM_LEDS; i++)
        {
          leds[i] = CRGB(0,0,0);
          leds[(i+2)%NUM_LEDS] = CRGB(r,g,b);
        
          FastLED.show();
          delay(TIME);
        }
      }
      
    case 1:
      r = 0;
      g = 255;

      for (b = 0; b < 256; b+=16)
      {
        for (unsigned char i = 0;i < NUM_LEDS; i++)
        {
          leds[i] = CRGB(0,0,0);
          leds[(i+2)%NUM_LEDS] = CRGB(r,g,b);
        
          FastLED.show();
          delay(TIME);
        }
      }
      
    case 2:
      r = 255;
      b = 0;

      for (g = 0; g < 256; g+=16)
      {
        for (unsigned char i = 0;i < NUM_LEDS; i++)
        {
          leds[i] = CRGB(0,0,0);
          leds[(i+2)%NUM_LEDS] = CRGB(r,g,b);
        
          FastLED.show();
          delay(TIME);
        }
      }
      
    case 3:
      r = 255;
      g = 0;

      for (b = 0; b < 256; b+=16)
      {
        for (unsigned char i = 0;i < NUM_LEDS; i++)
        {
          leds[i] = CRGB(0,0,0);
          leds[(i+2)%NUM_LEDS] = CRGB(r,g,b);
        
          FastLED.show();
          delay(TIME);
        }
      }
      
    case 4:
      g = 0;
      b = 255;

      for (r = 0; r < 256; r+=16)
      {
        for (unsigned char i = 0;i < NUM_LEDS; i++)
        {
          leds[i] = CRGB(0,0,0);
          leds[(i+2)%NUM_LEDS] = CRGB(r,g,b);
        
          FastLED.show();
          delay(TIME);
        }
      }
      
    default:
      g = 255;
      b = 0;

      for (r = 0; r < 256; r+=16)
      {
        for (unsigned char i = 0;i < NUM_LEDS; i++)
        {
          leds[i] = CRGB(0,0,0);
          leds[(i+2)%NUM_LEDS] = CRGB(r,g,b);
        
          FastLED.show();
          delay(TIME);
        }
      }
      
  }

  a++;
}
