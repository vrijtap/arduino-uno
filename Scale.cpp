#include "Scale.h"  

const int NUM_READINGS = 10;    // Amount of readings that will take place.
const float SCALE_FACTOR = -400.628078f;    // Amount of readings that will take place.

// Constructor: Initializes the Scale object with specified pins and calibration factor
Scale::Scale(int doutPin, int sckPin, int max_weight)
  : doutPin(doutPin), sckPin(sckPin), max_weight(max_weight) {
}

// Initialize the scale
void Scale::init() {
  this->hx711.begin(doutPin, sckPin);  // Initialize HX711 with specified pins
  this->hx711.set_scale(SCALE_FACTOR);       // Set the calibration factor

  reset();                       // Reset the scale to 0
}

// Reset the scale to zero
void Scale::reset() {
  this->hx711.tare();  // Tare the scale to zero
}

// Get the weight measurement after averaging 'numOfReadings' readings
float Scale::getWeight() {
  return this->hx711.get_units(NUM_READINGS);  // Return the weight measurement
}

// Get the weight measurement after averaging 'numOfReadings' readings
int Scale::getPercentage() {
  int percentage = this->getWeight() / (this->max_weight / 100);
  return percentage;  // Return the weight measurement
}
