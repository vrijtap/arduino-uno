#ifndef StateMachine_h
#define StateMachine_h

#include <Arduino.h>

// Define states as constants
#define SM_IDLE_STATE 0
#define SM_TAPPING_STATE 1
#define SM_PAUSED_STATE 2

// Define events as constants
#define SM_ZERO 0
#define SM_ONE 1

class StateMachine {
public:
    StateMachine(); // Constructor
    void handleInputEvent(int SM_event);

private:
    int SM_state;
};

#endif
