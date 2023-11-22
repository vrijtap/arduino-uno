#include "MyServo.h"

MyServo::MyServo() {
    // Constructor
}

void MyServo::attach(int pin, int minPulseWidth, int maxPulseWidth) {
    servo.attach(pin, minPulseWidth, maxPulseWidth);
}

void MyServo::write(int angle) {
    servo.write(angle);
}

void MyServo::detach() {
    servo.detach();
}
