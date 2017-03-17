#include "Adafruit_HT1632.h"

#define HT_DATA 2
#define HT_WR   3
#define HT_CS   4
#define HT_CS2  5

// use this line for single matrix
Adafruit_HT1632LEDMatrix matrix = Adafruit_HT1632LEDMatrix(HT_DATA, HT_WR, HT_CS);
// use this line for two matrices!
//Adafruit_HT1632LEDMatrix matrix = Adafruit_HT1632LEDMatrix(HT_DATA, HT_WR, HT_CS, HT_CS2);

void drawMatrix(byte tableau[16][24]) {

  matrix.clearScreen();
  uint8_t id_temp = matrix.height() - 1;

  for (uint8_t height=0; height<matrix.height(); height++) {
    for (uint8_t width=0; width<matrix.width(); width++) {
      if (tableau[id_temp][width] == 1) {
        matrix.setPixel(width, height);
      }
    }
    id_temp--;
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
//pour afficher un truc sur l'affichage : 
//byte tableau_affichage[16][24] = "le code sortit du site 'Matrice.html'" (on utilise pas le ledControl. il faut décocher la case. et reverse.)

void loop() {
  //drawMatric(tableau_affichage);
}