#ifndef MY_SERVO_h
#define MY_SERVO_h

#include <Servo.h>

class MyServo {
public:
    MyServo();
    void attach(int pin, int minPulseWidth, int maxPulseWidth);
    void write(int angle);
    void detach();
private:
    Servo servo;
};

#endif
