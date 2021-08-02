#include "letters.h"
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

#define NUM_LEDS 56


// Data pin that led data will be written out over
#define DATA_PIN 13
// Clock pin only needed for SPI based chipsets when not using hardware SPI
//#define CLOCK_PIN 8
#define TIME 800
CRGB leds[NUM_LEDS];

void setup() {
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(200);

      // Uncomment one of the following lines for your leds arrangement.
      FastLED.addLeds<WS2811, DATA_PIN, BRG>(leds, NUM_LEDS);
      FastLED.clear();
}

void print_matrix(unsigned char CHAR[8],unsigned char color_1,unsigned char color_2,unsigned char color_3)
{
  int k;
  FastLED.clear();

  for (int j = 0; j < 7;j++)
  {
    for (int i = 0; i < 8; i++)
    {
      unsigned char a = reverse(CHAR[j]);
      k = a >> i;
      if ((k & 1))
        leds[8*j+i] = CRGB(color_1,color_2,color_3);
      //else
      //  leds[8*j+i] = CRGB(0,0,0);
      //delay(0);
    }
  }
  FastLED.show();
}

void print_text(String text,unsigned char color_1,unsigned char color_2,unsigned char color_3,int dela)
{
    text.toUpperCase();
    for (int i = 0; text[i] != '\0';i++)
    {
      switch (text[i])  {
        case 'A':
          print_matrix(A,color_1,color_2,color_3);
          break;

        case 'B':  
          print_matrix(B,color_1,color_2,color_3);        
          break;

        case 'C':  
          print_matrix(C,color_1,color_2,color_3);
          break;

        case 'D':  
          print_matrix(D,color_1,color_2,color_3);
          break;

        case 'E':
          print_matrix(E,color_1,color_2,color_3);
          break;

        case 'F':  
          print_matrix(F,color_1,color_2,color_3);
          break;

        case 'G':
          print_matrix(G,color_1,color_2,color_3);
          break;

        case 'H':
          print_matrix(H,color_1,color_2,color_3);
          break;

        case 'I':
          print_matrix(I,color_1,color_2,color_3);
          break;

        case 'J':
          print_matrix(J,color_1,color_2,color_3);
          break;

        case 'K':
          print_matrix(K,color_1,color_2,color_3);
          break;

        case 'L':
          print_matrix(L,color_1,color_2,color_3);
          break;

        case 'M':
          print_matrix(M,color_1,color_2,color_3);
          break;

        case 'N':
          print_matrix(N,color_1,color_2,color_3);
          break;

        case 'O':
          print_matrix(O,color_1,color_2,color_3);
          break;

        case 'P':
          print_matrix(P,color_1,color_2,color_3);
          break;

        case 'Q':
          print_matrix(Q,color_1,color_2,color_3);
          break;

        case 'R':
          print_matrix(R,color_1,color_2,color_3);
          break;

        case 'S':
          print_matrix(S,color_1,color_2,color_3);
          break;

        case 'T':
          print_matrix(T,color_1,color_2,color_3);
          break;

        case 'U':
          print_matrix(U,color_1,color_2,color_3);
          break;

        case 'V':
          print_matrix(V,color_1,color_2,color_3);
          break;

        case 'W':
          print_matrix(W,color_1,color_2,color_3);
          break;

        case 'X':
          print_matrix(X,color_1,color_2,color_3);
          break;

        case 'Y':
          print_matrix(Y,color_1,color_2,color_3);
          break;

        case 'Z':
          print_matrix(Z,color_1,color_2,color_3);
          break;
        
        default:
          print_matrix(EMP,color_1,color_2,color_3);
      }
      delay(dela);
    }
}

void loop()
{
  unsigned char color_1 = random8();
  unsigned char color_2 = random8();
  unsigned char color_3 = random8();
  print_text("PAIVOLA \n",color_1,color_2,color_3,TIME);
}

unsigned char reverse(unsigned char b) {
   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
   return b;
}
