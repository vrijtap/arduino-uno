#ifndef TAPPING_SYSTEM_H
#define TAPPING_SYSTEM_H

#include "include/HighTorqueServo.h"
#include "include/Pump.h"
#include "include/Scale.h"

class TappingSystem {
public:
  TappingSystem(Scale *scale, HighTorqueServo *cupHolderServo, HighTorqueServo *armHolderServo, Pump *pump);

private:
  // Scale Object Pointer
  Scale *scale;

  // Servo Object Pointers
  HighTorqueServo *cupHolderServo;
  HighTorqueServo *armHolderServo;

  // Pump Object Pointer
  Pump *pump;
};

#endif // TAPPING_SYSTEM_H
