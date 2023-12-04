// Project Classes
#include "HighTorqueServo.h"
#include "Pump.h"
#include "StateMachine.h"
#include "Pump.h"
#include "Scale.h"

// Standard libraries
#include "Arduino.h"
#include <Wire.h>
#include <stdint.h>

// Create an instance of the HighTorqueServo class for the Cup Holder
const uint8_t CUP_HOLDER_SERVO_PIN = 6; // Pin number connected to the Cup Holder Servo
const uint8_t PUMP_PIN = 7;
const int CUP_HOLDER_MIN_ANGLE = 88;    // Minimum angle for the Cup Holder Servo
const int CUP_HOLDER_MAX_ANGLE = 107;   // Maximum angle for the Cup Holder Servo
const int LOADCELL_DOUT_PIN = 2;  
const int LOADCELL_SCK_PIN = 3;   

// Create an instances of the following classes
HighTorqueServo cupHolderServo(CUP_HOLDER_SERVO_PIN, CUP_HOLDER_MIN_ANGLE, CUP_HOLDER_MAX_ANGLE);
StateMachine stateMachine;
Pump pump(PUMP_PIN);
Scale scale(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

// Function answer requests from the I2C connection
void sendData() {
  if (stateMachine.getState() == SM_IDLE_STATE) {
    Wire.write(200); // TODO: Replace the placeholder data weight data
  } else Wire.write(stateMachine.getState()); // Send the current state
}

// Function to receive state switches from the I2C connection
void receiveData(int byteCount) {
  while (Wire.available()) {
    stateMachine.handleInputEvent(Wire.read());
  }
}

void setup() {
  // Initialize the High Torque Servo component
  Serial.begin(9600);
  cupHolderServo.init(0.0);
  scale.init();

  // Initialize the Pump component
  pump.init();
  cupHolderServo.init(0.0);

  // Configure the I2C connection
  Wire.begin(0x8); // Arduino as a slave, with address 8
  Wire.onRequest(sendData); // Register a callback for outgoing I2C data
  Wire.onReceive(receiveData); // Register a callback for incoming I2C data
}

void loop() {
  // Fetch the current state
  int state = stateMachine.getState();
  Serial.println(scale.getPercentage());
  delay(3000);
  /* DEBUG CODE FOR TESTING THE I2C AND STATE MACHINE INTEGRATION
  if(stateMachine.getState() == SM_TAPPING_STATE)
  {
    //if process has completed turn state to 2 as a flag t the RPi
    stateMachine.handleInputEvent(SM_ONE); // returns to the idle state
  }
  delay(3000);
  */

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
