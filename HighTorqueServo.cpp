#include "include/HighTorqueServo.h"

#include <Arduino.h>
#include <stdint.h>

// Constructor: Initializes the HighTorqueServo with specified angle limits and initial percentage turned
HighTorqueServo::HighTorqueServo(uint8_t servoPin, int minAngle, int maxAngle) : servoPin(servoPin) {
  this->minMicroseconds = this->angleToMicroseconds(minAngle);
  this->maxMicroseconds = this->angleToMicroseconds(maxAngle);
}

// Public function: Initialize the servo
void HighTorqueServo::init(float percentage) {
  // Check if the servo is already attached
  if (this->servo.attached()) {
    this->servo.detach();
  }

  // Attach the servo and set it in its starting position
  this->servo.attach(this->servoPin);
  this->write(percentage);
}

// Public function: Turn the servo to a percentage of the defined angle range
void HighTorqueServo::write(float percentage) {
  int microseconds = this->percentageToMicroseconds(percentage);
  this->servo.writeMicroseconds(microseconds);
}

// Private function: Map an angle to a PWM signal duration in microseconds
int HighTorqueServo::angleToMicroseconds(int angle) {
  return map(angle, MIN_ANGLE_RANGE, MAX_ANGLE_RANGE, MIN_SERVO_MICROSECONDS, MAX_SERVO_MICROSECONDS);
}

// Private function: Map a percentage to a PWM signal duration in microseconds
int HighTorqueServo::percentageToMicroseconds(float percentage) {
  return map(percentage, 0.0, 100.0, this->minMicroseconds, this->maxMicroseconds);
}
