#ifndef HIGH_TORQUE_SERVO_H
#define HIGH_TORQUE_SERVO_H

#include <Servo.h>
#include <stdint.h>

class HighTorqueServo {
public:
  // Constructor: Initializes the HighTorqueServo with specified angle limits and initial percentage turned
  // minAngle: Minimum angle limit (accepted range: [0, 180])
  // maxAngle: Maximum angle limit (accepted range: [0, 180])
  HighTorqueServo(int minAngle, int maxAngle);

  // Public function: Initialize the High Torque Servo
  // servoPin: Pin number for the servo
  // percentage: Initial percentage turned (accepted range: [0.0, 100.0])
  void init(uint8_t servoPin, float percentage);

  // Public function: Turn the servo to a percentage of the defined angle range
  // percentage: Percentage of range to turn the servo towards (accepted range: [0.0, 100.0])
  void write(float percentage);
  
private:
  // Constants for servo pulse duration range in microseconds
  static const int MIN_SERVO_MICROSECONDS = 500;
  static const int MAX_SERVO_MICROSECONDS = 2500;

  // Constants for default angle range
  static const int MIN_ANGLE_RANGE = 0;
  static const int MAX_ANGLE_RANGE = 180;

  // Member variables representing the angle limits and current percentage turned
  int minMicroseconds;
  int maxMicroseconds;
  Servo servo;

  // Private function: Map an angle to a PWM signal duration in microseconds
  // angle: Input angle (accepted range: [MIN_ANGLE_RANGE, MAX_ANGLE_RANGE])
  // Returns: Corresponding PWM signal duration in microseconds
  int angleToMicroseconds(int angle);

  // Private function: Map a percentage to a PWM signal duration in microseconds
  // percentage: Input percentage (accepted range: [0.0, 100.0])
  // Returns: Corresponding PWM signal duration in microseconds
  int percentageToMicroseconds(float percentage);
};

#endif // HIGH_TORQUE_SERVO_H
