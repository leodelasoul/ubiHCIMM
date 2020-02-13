#include <SPI.h>
#include "LedMatrix.h"
#include <WiFi.h>


#define NUMBER_OF_DEVICES 8 //number of led matrix connect in series
#define CS_PIN 15
#define CLK_PIN 14
#define MISO_PIN 2 //we do not use this pin just fill to match constructor
#define MOSI_PIN 12



LedMatrix ledMatrix = LedMatrix(NUMBER_OF_DEVICES, CLK_PIN, MISO_PIN, MOSI_PIN, CS_PIN);
  
void setup() {
  ledMatrix.init();
  ledMatrix.setText("Das ist ein Satz, yeay!");
  
  ledMatrix.setIntensity(10);
  
}

void loop() {
  ledMatrix.clear();
  ledMatrix.scrollTextLeft();
  ledMatrix.drawText();
  ledMatrix.commit();
}