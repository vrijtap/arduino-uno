#include "MyServo.h"
#include <Wire.h>

// Define servo constants
const int SERVO_PIN_1 = D2;          
const int MIN_PULSE_WIDTH_1 = 450;   // Replace with your custom minimum pulse width for servo 1
const int MAX_PULSE_WIDTH_1 = 2400;  // Replace with your custom maximum pulse width for servo 1

const int SERVO_PIN_2 = D3;          
const int MIN_PULSE_WIDTH_2 = 450;   // Replace with your custom minimum pulse width for servo 2
const int MAX_PULSE_WIDTH_2 = 2400;  // Replace with your custom maximum pulse width for servo 2

MyServo servo1;
MyServo servo2;

int angle1 = 45;             // Initial angle for servo 1
int targetAngle1 = 0;       // Target angle for servo 1
int angle2 = 0;              // Initial angle for servo 2
int targetAngle2 = 0;       // Target angle for servo 2
int stepSize = 1;           // Step size for angle change
unsigned long previousMillis = 0;
unsigned long interval = 10; // Delay between angle changes (in milliseconds)
unsigned long startTime = 0;
const unsigned long returnTime = 15000; // 15 seconds in milliseconds

int receivedData = 0; // Store received data

void setup() {
    Wire.begin(0x8); // Arduino as a slave, with address 8
    Wire.onReceive(receiveData); // Register a callback for incoming I2C data
    Wire.onRequest(sendData); // Register a callback for outgoing I2C data

    // Initialize servo 1
    servo1.attach(SERVO_PIN_1, MIN_PULSE_WIDTH_1, MAX_PULSE_WIDTH_1);

    // Initialize servo 2
    servo2.attach(SERVO_PIN_2, MIN_PULSE_WIDTH_2, MAX_PULSE_WIDTH_2);
    
    // Initialize serial communication
    Serial.begin(9600);

    // Record the start time
    startTime = millis();
}

void receiveData(int byteCount) {
  while (Wire.available()) {
    receivedData = Wire.read();
    Serial.println("Received data: " + String(receivedData));
    
    if (receivedData == '1') {
        // Set the target angle for servo 1 to 45 degrees
        targetAngle1 = 45;
        
        // Reset the timer
        startTime = millis();
    }
  }
}

void loop() {
    // Gradually change the angle for servo 1
    if (angle1 != targetAngle1) {
        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= interval) {
            if (angle1 < targetAngle1) {
                angle1 += stepSize;
            } else {
                angle1 -= stepSize;
            }
            servo1.write(angle1);
            previousMillis = currentMillis;
        }
    }

    // Check if it's time to move servo 2
    if (angle1 == 45) {
        // Delay for a moment before moving servo 2
        delay(1000); // Adjust the delay time as needed
        
        // Move servo 2 to 180 degrees
        targetAngle2 = 180;
    }

    // Gradually change the angle for servo 2
    if (angle2 != targetAngle2) {
        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= interval) {
            if (angle2 < targetAngle2) {
                angle2 += stepSize;
            } else {
                angle2 -= stepSize;
            }
            servo2.write(angle2);
            previousMillis = currentMillis;
        }
    }
}
