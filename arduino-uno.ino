// Project Classes
#include "include/HighTorqueServo.h"
#include "include/Pump.h"
#include "include/StateMachine.h"
#include "include/Pump.h"
#include "include/Scale.h"

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
const int ARM_HOLDER_MAX_ANGLE = 70;
HighTorqueServo armHolderServo(ARM_HOLDER_SERVO_PIN, ARM_HOLDER_MIN_ANGLE, ARM_HOLDER_MAX_ANGLE);
const float INITIAL_ANGLE = 0.0;

// Create the Pump Class
const uint8_t PUMP_PIN = 7;
Pump pump(PUMP_PIN);

// Create the State Machine
StateMachine stateMachine;

// Define a struct to hold tapping information
const uint16_t DRINK_VOLUME = 200;

// Define the I2C send/receive functions
int weightpercentage = 0;
void sendData(void);
void receiveData(int byteCount);

void setup() {
  // Initialize the Scale
  Serial.begin(115200);
  scale.init();
  scale.reset();

  // Initialize the Cup Holder Servo
  cupHolderServo.init(INITIAL_ANGLE);

  // Initialize the Arm Holder Servo
  armHolderServo.init(INITIAL_ANGLE);

  // Function to calculate the Servo angle
  float getServoAngle(float volume);
  
  // Initialize the Pump component
  pump.init();

  // Configure the I2C connection
  Wire.begin(0x8); // Arduino as a slave, with address 8
  Wire.onRequest(sendData); // Register a callback for outgoing I2C data
  Wire.onReceive(receiveData); // Register a callback for incoming I2C data

  stateMachine.handleInputEvent(SM_ONE);
}

float startVolume = 0.0;
bool tapping = false;

void loop() {
  float volume = scale.getWeight();
  weightpercentage = scale.weightToPercentage(volume);

  // Switch case for the state machine states
  int state = stateMachine.getState();
  switch (state) {
    // Case to define behaviour when in IDLE mode
    case SM_IDLE_STATE:
      delay(16);
      break;

    // Case to define behaviour when in TAPPING mode
    case SM_TAPPING_STATE:
      if(startVolume == 0.0 && volume > DRINK_VOLUME) {
        // Start values for the hardware
        startVolume = volume;
        float startAngle = getServoAngle(volume);

        // Manage hardware
        for(float angle = INITIAL_ANGLE; angle < startAngle; angle += 5.0) {
          cupHolderServo.write(angle);
          armHolderServo.write(angle);
          delay(32);
        }
        pump.start();

        // Manage control boolean
        tapping = true;
      } else if(startVolume - volume > DRINK_VOLUME) {
        // Manage stopping the pump
        pump.stop();
        float stopWeight = scale.getWeight();
        while(true) {
          float currentWeight = scale.getWeight();
          if(currentWeight >= stopWeight) {
            break;
          } else {
            stopWeight = currentWeight;
          }
        }

        // Set Servo's to INITIAL_ANGLE
        delay(1000);
        cupHolderServo.write(INITIAL_ANGLE);
        armHolderServo.write(INITIAL_ANGLE);

        // Manage control variables
        startVolume = 0.0;
        tapping = false;
        
        // Switch back to IDLE and wait for 5 seconds
        stateMachine.handleInputEvent(SM_ONE);
      }

      // Manage the Servo's while tapping
      if(tapping) {
        float angle = getServoAngle(volume);
        cupHolderServo.write(angle);
        armHolderServo.write(angle * 0.35 + 65.0);
        delay(32);
      }

      // End of the case 
      delay(16);
      break;
    
    // Case to define behaviour when in PAUSED mode
    case SM_PAUSED_STATE:
      /*
        CODE FOR PAUSING THE MACHINE
      */

      delay(16);
      break;
    
    // Case that should stay unreachable
    default:
      Serial.println("Error: Invalid State Received");
  }

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
    Serial.println(scale.getPercentage());
    delay(1000);
  */
}

// Function answer requests from the I2C connection
void sendData() {
  if (stateMachine.getState() == SM_IDLE_STATE) {
    Wire.write(weightpercentage + 100);
  } else Wire.write(stateMachine.getState());
}

// Function to receive state switches from the I2C connection
void receiveData(int byteCount) {
  while (Wire.available()) {
    stateMachine.handleInputEvent(Wire.read());
  }
}

// Function to calculate the servo angle
float getServoAngle(float volume) {
  if(volume < 0.0) {
    return 0.0;
  }

  // Calculate how much we have already tapped
  float percentageTapped = (startVolume - volume) / DRINK_VOLUME;
  float inversePercentage = (1 - percentageTapped) * 100.0;

  // Error check and manage the output
  if(inversePercentage < 0.0) {
    return 0.0;
  } else if(inversePercentage > 100.0) {
    return 100.0;
  } else {
    return inversePercentage;
  }
}
