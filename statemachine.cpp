#include "StateMachine.h"

// Constructor
StateMachine::StateMachine() {
  SM_state = SM_IDLE_STATE;
}

// Function to handle SM_state transitions
void StateMachine::handleInputEvent(int SM_event) {
  switch (SM_state) {
    case SM_IDLE_STATE:
      if (SM_event == SM_ONE) {
        SM_state = SM_TAPPING_STATE;
        Serial.println("Transitioned from Idle to Tapping");
      }
      // Stay in SM_IDLE_STATE if SM_ZERO is received
      break;
    case SM_TAPPING_STATE:
      if (SM_event == SM_ZERO) {
        SM_state = SM_PAUSED_STATE;
        Serial.println("Transitioned from Tapping to Paused");
      } else if (SM_event == SM_ONE) {
        SM_state = SM_IDLE_STATE;
        Serial.println("Transitioned from Tapping to Idle");
      }
      break;
    case SM_PAUSED_STATE:
      if (SM_event == SM_ONE) {
        SM_state = SM_TAPPING_STATE;
        Serial.println("Transitioned from Paused to Tapping");
      } else if (SM_event == SM_ZERO) {
        SM_state = SM_IDLE_STATE;
        Serial.println("Transitioned from Paused to Idle");
      }
      break;
    default:
      Serial.println("Invalid SM_state!");
      break;
  }
}
