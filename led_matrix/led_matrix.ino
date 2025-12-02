
#include <LedControl.h>

constexpr byte DIN = 11, CLK = 13, CS = 10;
LedControl lc(DIN, CLK, CS, 1);


void setup() {

  lc.shutdown(0, false);
  lc.setIntensity(0, 1);
  lc.clearDisplay(0);

  const byte heart[8] = {
    B00000000,
    B01100110,
    B11111111,
    B11111111,
    B11111111,
    B01111110,
    B00111100,
    B00011000
  };
  for (byte row = 0; row < 8; ++row)
    lc.setRow(0, row, heart[row]);
}

void loop() {
}