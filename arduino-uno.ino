#include "Arduino.h"
#include <Wire.h>
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
StateMachine sm;

void setup() {
  // Initialize the High Torque Servo component
  cupHolderServo.init(0.0);

  // Initialize the Pump component
  pump.init();
  // TODO: cupHolderServo.init(CUP_HOLDER_SERVO_PIN, 0.0); // unable to run with this line in code currently

  Wire.begin(0x8); // Arduino as a slave, with address 8
  Wire.onReceive(receiveData); // Register a callback for incoming I2C data
  Wire.onRequest(sendData); // Register a callback for outgoing I2C data
  Serial.begin(9600); // Sets baudrate for connection
}

void loop() {
  int state = sm.getState();

  // DEBUG CODE FOR TESTING THE CUP HOLDER SERVO
  if(sm.getState() == SM_TAPPING_STATE)
  {
    //if process has completed turn state to 2 as a flag t the RPi
    sm.handleInputEvent(SM_ONE); // returns to the idle state
  }
  delay(3000);

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

// Function to receive data on arrival
void receiveData(int byteCount) {
  while (Wire.available()) {
    sm.handleInputEvent(Wire.read());
  }
}

// Function to send data back over I2C 
void sendData() {
  if (sm.getState() == SM_IDLE_STATE) {
    Wire.write(200); // temporary data, scale date here
  } else Wire.write(sm.getState()); // Send the current state
}
