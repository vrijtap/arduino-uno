#include "Scale.h"

Scale::Scale(int doutPin, int sckPin, float factor)
  : doutPin(doutPin), sckPin(sckPin), factor(factor) {
}

void Scale::init() {
  hx711.begin(doutPin, sckPin);
  hx711.set_scale(factor);
  reset(); // reset the scale to 0
}

void Scale::reset() {
  hx711.tare();
}

float Scale::getWeight(int numOfReadings) {
  return hx711.get_units(numOfReadings);
}
