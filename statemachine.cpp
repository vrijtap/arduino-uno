#include "StateMachine.h"

// Constructor
StateMachine::StateMachine() {
  state = SM_IDLE_STATE;
}

// Function to handle state transitions
void StateMachine::handleInputEvent(int event) {
  switch (state) {
    case SM_IDLE_STATE:
      if (event == SM_ONE) {
        state = SM_TAPPING_STATE;
        Serial.println("Transitioned from Idle to Tapping");
      }
      // Stay in SM_IDLE_STATE if ZERO_EVENT is received
      break;
    case SM_TAPPING_STATE:
      if (event == SM_ZERO) {
        state = SM_PAUSED_STATE;
        Serial.println("Transitioned from Tapping to Paused");
      } else if (event == SM_ONE) {
        state = SM_IDLE_STATE;
        Serial.println("Transitioned from Tapping to Idle");
      }
      break;
    case SM_PAUSED_STATE:
      if (event == SM_ONE) {
        state = SM_TAPPING_STATE;
        Serial.println("Transitioned from Paused to Tapping");
      } else if (event == SM_ZERO) {
        state = SM_IDLE_STATE;
        Serial.println("Transitioned from Paused to Idle");
      }
      break;
    default:
      Serial.println("Invalid state!");
      break;
  }
}
