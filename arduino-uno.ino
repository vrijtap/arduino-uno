#include "Arduino.h"
#include "HighTorqueServo.h"
#include "StateMachine.h"

#include <stdint.h>

// Constants for Cup Holder Servo
const uint8_t CUP_HOLDER_SERVO_PIN = 6; // Pin number connected to the Cup Holder Servo
const int CUP_HOLDER_MIN_ANGLE = 88;    // Minimum angle for the Cup Holder Servo
const int CUP_HOLDER_MAX_ANGLE = 107;   // Maximum angle for the Cup Holder Servo

// Create an instance of the HighTorqueServo class for the Cup Holder that initializes at 0.0 percent of the angle range
HighTorqueServo cupHolderServo(CUP_HOLDER_MIN_ANGLE, CUP_HOLDER_MAX_ANGLE);

void setup() {
  // Initialize the High Torque Servo component
  cupHolderServo.init(CUP_HOLDER_SERVO_PIN, 0.0);
}

void loop() {
  /*
    // DEBUG CODE FOR TESTING THE CUP HOLDER SERVO
    cupHolderServo.write(0.0);
    delay(1000);
    cupHolderServo.write(100.0);
    delay(1000);
  */
}
