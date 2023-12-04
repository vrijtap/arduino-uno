/**
 * @file Scale.cpp
 * A script that will test a predetermined calibration value
 * this script will print a weighed value.
 * 
 * @version 0.1
 * @date 2023-12-04
 * 
 * @copyright Copyright (c) 2023
 */

#include <HX711_ADC.h>
#endif

//pins:
const int HX711_dout = 4;
const int HX711_sck = 5;
const int CALIBRATION_VALUE = 100;

//HX711 constructor:
HX711_ADC LoadCell(HX711_dout, HX711_sck);

void setup() {
  Serial.begin(9600); 
  delay(10);

  LoadCell.begin();
  calibrationValue = CALIBRATION_VALUE;

  unsigned long stabilizingtime = 2000; // preciscion right after power-up can be improved by adding a few seconds of stabilizing time
  LoadCell.start(stabilizingtime, true);

  if (LoadCell.getTareTimeoutFlag()) {
    Serial.println("Timeout, check MCU>HX711 wiring and pin designations");
    while (true);
  }
  else {
    LoadCell.setCalFactor(calibrationValue); // set calibration value (float)
  }
}

void loop() {
  static boolean scaleLoop = false;

  // check for new data/start next conversion:
  if (LoadCell.update()) scaleLoop = true;

  // get smoothed value from the dataset:
  if (scaleLoop) {
      float i = LoadCell.getData();
      serial.println("Weight(g): " + String(int(i)));
      scaleLoop = false;
      delay(500);
  }
}