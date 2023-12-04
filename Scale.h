#ifndef SCALE_H
#define SCALE_H

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
