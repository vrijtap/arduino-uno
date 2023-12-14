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

// Create the Scale Class
const int MAX_WEIGHT = 925;
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;
Scale scale(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN, MAX_WEIGHT);

// Create the Cup Holder Servo Class
const uint8_t CUP_HOLDER_SERVO_PIN = 6;
const int CUP_HOLDER_MIN_ANGLE = 88;
const int CUP_HOLDER_MAX_ANGLE = 107;
HighTorqueServo cupHolderServo(CUP_HOLDER_SERVO_PIN, CUP_HOLDER_MIN_ANGLE, CUP_HOLDER_MAX_ANGLE);

// Create the Arm Holder Servo Class
const uint8_t ARM_HOLDER_SERVO_PIN = 5;
const int ARM_HOLDER_MIN_ANGLE = 0;
const int ARM_HOLDER_MAX_ANGLE = 60;
HighTorqueServo armHolderServo(ARM_HOLDER_SERVO_PIN, ARM_HOLDER_MIN_ANGLE, ARM_HOLDER_MAX_ANGLE);

// Create the Pump Class
const uint8_t PUMP_PIN = 7;
Pump pump(PUMP_PIN);

// Define the I2C send/receive functions
void sendData(void);
void receiveData(int byteCount);

// Create the State Machine
StateMachine stateMachine;

void setup() {
  // Initialize the Scale
  Serial.begin(115200);
  scale.init();
  scale.reset();

  // Initialize the Cup Holder Servo
  cupHolderServo.init(100.0);

  // Initialize the Arm Holder Servo
  armHolderServo.init(0.0);
  
  // Initialize the Pump component
  pump.init();

  // Configure the I2C connection
  Wire.begin(0x8); // Arduino as a slave, with address 8
  Wire.onRequest(sendData); // Register a callback for outgoing I2C data
  Wire.onReceive(receiveData); // Register a callback for incoming I2C data
}

void loop() {
  // Fetch the current state
  // int state = stateMachine.getState();

  //   // DEBUG CODE FOR TESTING THE STATE MACHINE & I2C CONNECTION
  //   if(stateMachine.getState() == SM_TAPPING_STATE) {
  //     int start = scale.getWeight();
  //     if(start > 200) {
  //       pump.start();
  //       while(scale.getWeight() > start - 200 ) {
  //         delay(5);
  //       }
  //       pump.stop();
  //      }
  //   }

  //   stateMachine.handleInputEvent(SM_ONE); // returns to the idle state 
  // delay(3000);

  /*
    // DEBUG CODE FOR TESTING THE PUMP
    pump.start();
    delay(1000);
    pump.stop();
    delay(1000);
  */

  /*
    // DEBUG CODE FOR TESTING THE CUP HOLDER SERVO
    cupHolderServo.write(0.0);
    delay(1000);
    cupHolderServo.write(100.0);
    delay(1000);
  */

  /*
    // DEBUG CODE FOR TESTING THE ARM HOLDER SERVO
    armHolderServo.write(0.0);
    delay(5000);
    armHolderServo.write(100.0);
    delay(5000);
  */

  /*
    // DEBUG CODE FOR TESTING THE SCALE
    Serial.println(scale.getWeight());
    delay(1000);
  */
}

// Function answer requests from the I2C connection
void sendData() {
  if (stateMachine.getState() == SM_IDLE_STATE) {
    Wire.write(scale.getPercentage() + 100 ); // Sends back percentage of the tank, added 100 so it does not conflict with I2C commands.
  } else Wire.write(stateMachine.getState()); // Send the current state
}

// Function to receive state switches from the I2C connection
void receiveData(int byteCount) {
  while (Wire.available()) {
    stateMachine.handleInputEvent(Wire.read());
  }
}
