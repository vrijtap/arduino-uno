#include "StateMachine.h"

// Constructor
StateMachine::StateMachine() {
  state = IDLE_STATE;
}

// Function to handle state transitions
void StateMachine::handleInputEvent(int event) {
  switch (state) {
    case IDLE_STATE:
      if (event == ONE_EVENT) {
        state = TAPPING_STATE;
        Serial.println("Transitioned from Idle to Tapping");
      }
      // Stay in IDLE_STATE if ZERO_EVENT is received
      break;
    case TAPPING_STATE:
      if (event == ZERO_EVENT) {
        state = PAUSED_STATE;
        Serial.println("Transitioned from Tapping to Paused");
      } else if (event == ONE_EVENT) {
        state = IDLE_STATE;
        Serial.println("Transitioned from Tapping to Idle");
      }
      break;
    case PAUSED_STATE:
      if (event == ONE_EVENT) {
        state = TAPPING_STATE;
        Serial.println("Transitioned from Paused to Tapping");
      } else if (event == ZERO_EVENT) {
        state = IDLE_STATE;
        Serial.println("Transitioned from Paused to Idle");
      }
      break;
    default:
      Serial.println("Invalid state!");
      break;
  }
}
