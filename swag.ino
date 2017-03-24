#include "Adafruit_HT1632.h"

#define HT_DATA 2
#define HT_WR   3
#define HT_CS   4

// use this line for single matrix
Adafruit_HT1632LEDMatrix matrix = Adafruit_HT1632LEDMatrix(HT_DATA, HT_WR, HT_CS);

void drawMatrix(long tableau[16]) {
  long val;

  matrix.clearScreen();
  for (uint8_t height=0; height<matrix.height(); height++) {
    for (uint8_t width=0;width<matrix.width();width++) {
      val=tableau[height] >> ((matrix.width() - 1) - width);
      val=val & 0x01;
      if (val == 1) {
        matrix.setPixel(width, 15 - height);
      }
    }
  }
  matrix.writeScreen();
}

void setup() {
  Serial.begin(9600);
  matrix.begin(ADA_HT1632_COMMON_16NMOS);
  matrix.fillScreen();
  delay(500);
  matrix.clearScreen(); 
}

long test[16] = {
  0b000000000000000000000000,
  0b000000000000000000000000,
  0b000001100000000000110000,
  0b000010010000000001001000,
  0b000010010000000001001000,
  0b000001100000000000110000,
  0b000000000000000000000000,
  0b000001000000000000010000,
  0b000000111111111111100000,
  0b000000000000000000000000,
  0b000000000000000000000000,
  0b000000000000000000000000,
  0b000000000000000000000000,
  0b000000000000000000000000,
  0b000000000000000000000000,
  0b000000000000000000000000,
};

//pour afficher un truc sur l'affichage : 
//byte tableau_affichage[16][24] = "le code sortit du site 'Matrice.html'" (on utilise pas le ledControl. il faut décocher la case. et reverse.)

void loop() {
  drawMatrix(test);
  delay(212121231231);
}