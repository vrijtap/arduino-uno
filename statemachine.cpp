//Made By: Benjamin kelada

#include "StateMachine.h"

// Constructor
StateMachine::StateMachine() {
  this->SM_state = SM_IDLE_STATE;
}

int StateMachine::getState() const {
    return this->SM_state; // Return the current state
}

// Function to handle SM_state transitions
void StateMachine::handleInputEvent(int SM_event) {
  switch (SM_state) {
    case SM_IDLE_STATE:
      if (SM_event == SM_ONE) {
        this->SM_state = SM_TAPPING_STATE;
        Serial.println("Transitioned from Idle to Tapping");
        }
      break;
    case SM_TAPPING_STATE:
      if (SM_event == SM_ZERO) {
        this->SM_state = SM_PAUSED_STATE;
        Serial.println("Transitioned from Tapping to Paused");
      } else if (SM_event == SM_ONE) {
        this->SM_state = SM_IDLE_STATE;
        Serial.println("Transitioned from Tapping to Idle");
      }
      break;
    case SM_PAUSED_STATE:
      if (SM_event == SM_ONE) {
        this->SM_state = SM_TAPPING_STATE;
        Serial.println("Transitioned from Paused to Tapping");
      } 
      break;
    default:
      Serial.println("Invalid SM_state!");
      break;
    }
}
