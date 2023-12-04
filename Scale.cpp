#include "Scale.h"

HX711_Scale::HX711_Scale(int doutPin, int sckPin, float factor)
  : doutPin(doutPin), sckPin(sckPin), factor(factor) {
}

void HX711_Scale::init() {
  scale.init(doutPin, sckPin);
  scale.set_scale(factor);
  reset(); // reset the scale to 0
}

void HX711_Scale::reset() {
  scale.tare();
}

float HX711_Scale::getWeight(int numOfReadings) {
  return scale.get_units(numOfReadings);
}
