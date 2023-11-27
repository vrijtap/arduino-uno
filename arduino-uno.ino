#include "Arduino.h"
#include "HighTorqueServo.h"
#include "StateMachine.h"
#include "Pump.h"


#include <stdint.h>

// Constants for Cup Holder Servo
const uint8_t CUP_HOLDER_SERVO_PIN = 6; // Pin number connected to the Cup Holder Servo
const int CUP_HOLDER_MIN_ANGLE = 88;    // Minimum angle for the Cup Holder Servo
const int CUP_HOLDER_MAX_ANGLE = 107;   // Maximum angle for the Cup Holder Servo

// Create an instance of the HighTorqueServo class for the Cup Holder that initializes at 0.0 percent of the angle range
HighTorqueServo cupHolderServo(CUP_HOLDER_SERVO_PIN, CUP_HOLDER_MIN_ANGLE, CUP_HOLDER_MAX_ANGLE);

// Constants for the Pump
const uint8_t PUMP_PIN = 7;

// Create an instance of the Pump
Pump pump(PUMP_PIN);

void setup() {
  // Initialize the High Torque Servo component
  cupHolderServo.init(0.0);

  // Initialize the Pump component
  pump.init();
}

void loop() {
  /*
    // DEBUG CODE FOR TESTING THE CUP HOLDER SERVO
    cupHolderServo.write(0.0);
    delay(1000);
    cupHolderServo.write(100.0);
    delay(1000);
  */

  /*
    // DEBUG CODE FOR TESTING THE PUMP
    pump.start();
    delay(1000);
    pump.stop();
    delay(1000);
  */
}
