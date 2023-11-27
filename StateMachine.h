// StateMachine.h

#ifndef StateMachine_h
#define StateMachine_h

#include <Arduino.h>

// Define states as constants
#define IDLE_STATE 0
#define TAPPING_STATE 1
#define PAUSED_STATE 2

// Define events as constants
#define ZERO_EVENT 0
#define ONE_EVENT 1

class StateMachine {
public:
    StateMachine(); // Constructor
    void handleInputEvent(int event);

private:
    int state;
};

#endif
