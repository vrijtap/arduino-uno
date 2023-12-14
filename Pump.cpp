#include "include/Pump.h"

#include <Arduino.h>
#include <stdint.h>

// Constructor definition
Pump::Pump(int relayPin) : relayPin(relayPin) {}

// Public function: Initialize the components for the pump
void Pump::init(void)
{
    // Initialize the relais
    pinMode(this->relayPin, OUTPUT);
    this->stop();
}

// Public function: Starts the pump
void Pump::start(void)
{
    digitalWrite(this->relayPin, LOW);
}

// Public function: Stops the pump
void Pump::stop(void)
{
    digitalWrite(this->relayPin, HIGH);
}
