#include "Arduino.h"
#include <Wire.h>
#include "HighTorqueServo.h"
#include <stdint.h>

// Constants for Cup Holder Servo
const uint8_t CUP_HOLDER_SERVO_PIN = 6; // Pin number connected to the Cup Holder Servo
const int CUP_HOLDER_MIN_ANGLE = 88;    // Minimum angle for the Cup Holder Servo
const int CUP_HOLDER_MAX_ANGLE = 107;   // Maximum angle for the Cup Holder Servo
int I2CBuffer = 0;

// Create an instance of the HighTorqueServo class for the Cup Holder that initializes at 0.0 percent of the angle range
HighTorqueServo cupHolderServo(CUP_HOLDER_MIN_ANGLE, CUP_HOLDER_MAX_ANGLE);

void setup() {
  // Initialize the High Torque Servo component
  cupHolderServo.init(CUP_HOLDER_SERVO_PIN, 0.0);

  Wire.begin(0x8); // Arduino as a slave, with address 8
  Wire.onReceive(receiveData); // Register a callback for incoming I2C data
  Wire.onRequest(sendData); // Register a callback for outgoing I2C data
  Serial.begin(9600); // Sets baudrate for connection
}

void loop() {

  if(I2CBuffer == 1){
      Serial.println("Buffer turned to 1");
      I2CBuffer = 2; // Idle state
  }
  else if(I2CBuffer == 0){
      Serial.println("Buffer turned to 0");
      I2CBuffer = 2; // Idle state
  }

  /*
    // DEBUG CODE FOR TESTING THE CUP HOLDER SERVO
    cupHolderServo.write(0.0);
    delay(1000);
    cupHolderServo.write(100.0);
    delay(1000);
  */
   delay(10);
}

// Function to receive data on arrival
void receiveData(int byteCount) {
  while (Wire.available()) {
    I2CBuffer = Wire.read();
  }
}
// Function to send data back over I2C 
void sendData() {
  Wire.write(I2CBuffer); // Send back the received data
}
