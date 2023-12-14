#include "TappingSystem.h"

TappingSystem::TappingSystem(Scale *scale, HighTorqueServo *cupHolderServo, HighTorqueServo *armHolderServo, Pump *pump) : 
  scale(scale), cupHolderServo(cupHolderServo), armHolderServo(armHolderServo), pump(pump) {}
