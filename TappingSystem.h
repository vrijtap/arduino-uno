#ifndef TAPPING_SYSTEM_H
#define TAPPING_SYSTEM_H

#include "include/HighTorqueServo.h"
#include "include/Pump.h"
#include "include/Scale.h"

#include <stdint.h>

// Define a struct to hold tapping information
struct TappingInfo {
  int32_t start;
  int16_t amount;
};

class TappingSystem {
public:
  // Constructor: Initializes the PumpSystem with the components to use
  // scale: Scale object to measure weight
  // cupHolderServo: Servo to tilt the cup
  // armHolderServo: Servo to move the spout
  // pump: Pump to tap the beer
  TappingSystem(Scale *scale, HighTorqueServo *cupHolderServo, HighTorqueServo *armHolderServo, Pump *pump);

  bool update(void);

  void pause(void);

private:
  // Scale Object Pointer
  Scale *scale;

  // Servo Object Pointers
  HighTorqueServo *cupHolderServo;
  HighTorqueServo *armHolderServo;

  // Pump Object Pointer
  Pump *pump;

  // Struct to hold tapping information
  TappingInfo tappingInfo;
};

#endif // TAPPING_SYSTEM_H
