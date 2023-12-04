#include "Scale.h"  

// Constructor: Initializes the Scale object with specified pins and calibration factor
Scale::Scale(int doutPin, int sckPin, float factor)
  : doutPin(doutPin), sckPin(sckPin), factor(factor) {
}

// Initialize the scale
void Scale::init() {
  this.hx711.begin(doutPin, sckPin);  // Initialize HX711 with specified pins
  this.hx711.set_scale(factor);       // Set the calibration factor
  reset();                       // Reset the scale to 0
}

// Reset the scale to zero
void Scale::reset() {
  this.hx711.tare();  // Tare the scale to zero
}

// Get the weight measurement after averaging 'numOfReadings' readings
float Scale::getWeight(int numOfReadings) {
  return this.hx711.get_units(numOfReadings);  // Return the weight measurement
}
