#include <Arduino.h>
#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;
const float LOADCELL_FACTOR = -400.6280f;

HX711 scale;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing the scale");

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(LOADCELL_FACTOR);
  scale.tare();               // reset the scale to 0
}

void loop() {
  Serial.print("\t| average:\t");
  Serial.println(scale.get_units(10), 5);   // print the average of 5 readings from the ADC minus tare weight, divided
                                            // by the SCALE parameter set with set_scale

  delay(5000);
}
