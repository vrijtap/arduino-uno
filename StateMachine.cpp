// Made By: Benjamin Kelada
#include "include/StateMachine.h"

// Constructor for the state machine
StateMachine::StateMachine() {
  this->SM_state = SM_IDLE_STATE;
}

// Funcction to get the current state
int StateMachine::getState() const {
    return this->SM_state; // Return the current state
}

// Function to handle SM_state transitions
void StateMachine::handleInputEvent(int SM_event) {
  switch (SM_state) {
    case SM_IDLE_STATE:
      if (SM_event == SM_ONE) {
        this->SM_state = SM_TAPPING_STATE;
        }
      break;
    case SM_TAPPING_STATE:
      if (SM_event == SM_ZERO) {
        this->SM_state = SM_PAUSED_STATE;
      } else if (SM_event == SM_ONE) {
        this->SM_state = SM_IDLE_STATE;
      }
      break;
    case SM_PAUSED_STATE:
      if (SM_event == SM_ONE) {
        this->SM_state = SM_TAPPING_STATE;
      } 
      break;
    default:
      break;
    }
}
