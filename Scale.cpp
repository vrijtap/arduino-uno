#include "Scale.h"

Scale::Scale(int doutPin, int sckPin, float factor)
  : doutPin(doutPin), sckPin(sckPin), factor(factor) {
}

void Scale::init() {
  scale.init(doutPin, sckPin);
  scale.set_scale(factor);
  reset(); // reset the scale to 0
}

void Scale::reset() {
  scale.tare();
}

float Scale::getWeight(int numOfReadings) {
  return scale.get_units(numOfReadings);
}
