
#include <LedControl.h>

constexpr byte DIN = 11, CLK = 13, CS = 10;
LedControl lc(DIN, CLK, CS, 1);

const int ROWS = 2;
int currentRow = 0;
const byte IMAGES[ROWS][8] = { 
  {
    B00000000,
    B01100110,
    B11111111,
    B11111111,
    B11111111,
    B01111110,
    B00111100,
    B00011000
  },
  {
    B00000000,
    B00100100,
    B00100100,
    B00100100,
    B00000000,
    B10000001,
    B01000010,
    B00111100
  }
};

unsigned long lastChange = 0;
const unsigned long DELAY = 2000;

void setup() {

  lc.shutdown(0, false);
  lc.setIntensity(0, 1);
  //lc.clearDisplay(0);
  for (byte row = 0; row < 8; ++row)
    lc.setRow(0, row, IMAGES[0][row]);
}


void loop() {
  if (millis()-lastChange > DELAY){
    currentRow++;
    if (currentRow >= ROWS){
      currentRow = 0;
    }
    lastChange = millis();
    for (byte row = 0; row < 8; ++row)
      lc.setRow(0, row, IMAGES[currentRow][row]);
  }
}