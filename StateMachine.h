// Made By: Benjamin Kelada

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
    // Constructor: Initializes the StateMachine object
    StateMachine();

    // Function to get the current state
    int getState() const;

    // Function to handle input events and change states
    void handleInputEvent(int SM_event);

private:
    int SM_state;   // Variable to hold the current state
};

#endif  // End of header guard
