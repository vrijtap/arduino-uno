//Made by: Benjamin Kelada

// Define states as constants
#define IDLE_STATE 0
#define TAPPING_STATE 1
#define PAUSED_STATE 2

// Define events as constants
#define ZERO_EVENT 0
#define ONE_EVENT 1

// Define the tapping state machine structure
typedef struct {
    int state;
} StateMachine;

// Function to handle state transitions
void handleEvent(StateMachine *sMachine, int event) {
    switch (sMachine->state) {
        case IDLE_STATE:
            if (event == ONE_EVENT) {
                sMachine->state = TAPPING_STATE;
                Serial.println("Transitioned from Idle to Tapping");
            }
            // Stay in IDLE_STATE if ZERO_EVENT is received
            break;
        case TAPPING_STATE:
            if (event == ZERO_EVENT) {
                sMachine->state = PAUSED_STATE;
                Serial.println("Transitioned from Tapping to Paused");
            } else if (event == ONE_EVENT) {
                sMachine->state = IDLE_STATE;
                Serial.println("Transitioned from Tapping to Idle");
            }
            break;
        case PAUSED_STATE:
            if (event == ONE_EVENT) {
                sMachine->state = TAPPING_STATE;
                Serial.println("Transitioned from Paused to Tapping");
            } else if (event == ZERO_EVENT) {
                sMachine->state = IDLE_STATE;
                Serial.println("Transitioned from Paused to Idle");
            }
            break;
        default:
            Serial.println("Invalid state!");
            break;
    }
}

void setup() {
    // Initialize Serial communication
    Serial.begin(9600);

    // Create a tapping state machine instance
    StateMachine sMachine = {IDLE_STATE};

    // Simulate state transitions based on events
    handleEvent(&sMachine, ONE_EVENT);
    handleEvent(&sMachine, ZERO_EVENT);
    handleEvent(&sMachine, ONE_EVENT);
    handleEvent(&sMachine, ZERO_EVENT);
    handleEvent(&sMachine, ZERO_EVENT); // This will stay in IDLE_STATE
    handleEvent(&sMachine, ONE_EVENT);
}//Made by: Benjamin Kelada

// Define states as constants
#define IDLE_STATE 0
#define TAPPING_STATE 1
#define PAUSED_STATE 2

// Define events as constants
#define ZERO_EVENT 0
#define ONE_EVENT 1

// Define the tapping state machine structure
typedef struct {
    int state;
} StateMachine;

// Function to handle state transitions
void handleEvent(StateMachine *sMachine, int event) {
    switch (sMachine->state) {
        case IDLE_STATE:
            if (event == ONE_EVENT) {
                sMachine->state = TAPPING_STATE;
                Serial.println("Transitioned from Idle to Tapping");
            }
            // Stay in IDLE_STATE if ZERO_EVENT is received
            break;
        case TAPPING_STATE:
            if (event == ZERO_EVENT) {
                sMachine->state = PAUSED_STATE;
                Serial.println("Transitioned from Tapping to Paused");
            } else if (event == ONE_EVENT) {
                sMachine->state = IDLE_STATE;
                Serial.println("Transitioned from Tapping to Idle");
            }
            break;
        case PAUSED_STATE:
            if (event == ONE_EVENT) {
                sMachine->state = TAPPING_STATE;
                Serial.println("Transitioned from Paused to Tapping");
            } else if (event == ZERO_EVENT) {
                sMachine->state = IDLE_STATE;
                Serial.println("Transitioned from Paused to Idle");
            }
            break;
        default:
            Serial.println("Invalid state!");
            break;
    }
}

void setup() {
    // Initialize Serial communication
    Serial.begin(9600);

    // Create a tapping state machine instance
    StateMachine sMachine = {IDLE_STATE};

    // Simulate state transitions based on events
    handleEvent(&sMachine, ONE_EVENT);
    handleEvent(&sMachine, ZERO_EVENT);
    handleEvent(&sMachine, ONE_EVENT);
    handleEvent(&sMachine, ZERO_EVENT);
    handleEvent(&sMachine, ZERO_EVENT); // This will stay in IDLE_STATE
    handleEvent(&sMachine, ONE_EVENT);
}

void loop() {
    // Your Arduino code can continue here if needed
}


void loop() {
    // Your Arduino code can continue here if needed
}
