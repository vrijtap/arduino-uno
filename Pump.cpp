#include "Pump.h"

#include <Arduino.h>
#include <stdint.h>

// Constructor definition
Pump::Pump(int relaisPin) : relaisPin(relaisPin) {}

// Public function: Initialize the components for the pump
void Pump::init(void)
{
    // Initialize the relais
    pinMode(this->relaisPin, OUTPUT);
    this->stop();
}

// Public function: Starts the pump
void Pump::start(void)
{
    digitalWrite(this->relaisPin, LOW);
}

// Public function: Stops the pump
void Pump::stop(void)
{
    digitalWrite(this->relaisPin, HIGH);
}
