#ifndef HX711_SCALE_H
#define HX711_SCALE_H

#include <Arduino.h>
#include "HX711.h"

class HX711_Scale {
  public:
    HX711_Scale(int doutPin, int sckPin, float factor);
    void init();
    void reset();
    float getWeight(int numOfReadings);

  private:
    int doutPin;
    int sckPin;
    float factor;
    HX711 scale;
};

#endif
