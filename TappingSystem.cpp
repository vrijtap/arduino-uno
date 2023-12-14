#include "TappingSystem.h"

TappingSystem::TappingSystem(Scale *scale, HighTorqueServo *cupHolderServo, HighTorqueServo *armHolderServo, Pump *pump) : 
  scale(scale), cupHolderServo(cupHolderServo), armHolderServo(armHolderServo), pump(pump) {
    this->tappingInfo.start = 0;
    this->tappingInfo.amount = 0;
}

TappingSystem::update(void) {
  return false;
}

TappingSystem::pause(void) {
  return;
}
