#ifndef HX711_SCALE_H
#define HX711_SCALE_H

#include <Arduino.h>
#include "HX711.h"

class Scale {
  public:
    Scale(int doutPin, int sckPin, float factor);
    void init();
    void reset();
    float getWeight(int numOfReadings);

  private:
    int doutPin;
    int sckPin;
    float factor;
    HX711 hx711;
};

#endif
