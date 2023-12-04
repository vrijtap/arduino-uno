#ifndef SCALE_H  
#define SCALE_H

#include <Arduino.h>  
#include "HX711.h"    

class Scale {
  public:
    // Constructor: Initializes the Scale object with specified pins and calibration factor
    Scale(int doutPin, int sckPin, float factor);

    // Initialize the scale
    void init();

    // Reset the scale to zero
    void reset();

    // Get the weight measurement after averaging 'numOfReadings' readings
    float getWeight(int numOfReadings);

  private:
    int doutPin;    // Pin connected to the DOUT (data output) of the HX711
    int sckPin;     // Pin connected to the SCK (serial clock) of the HX711
    float factor;   // Calibration factor used to convert raw readings to weight units
    HX711 hx711;    // Instance of the HX711 library for interfacing with the load cell
};

#endif //SCALE_H
