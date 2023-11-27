#ifndef PUMP_H
#define PUMP_H

#include <stdint.h>

class Pump {
public:
    // Constructor: Initializes the Pump
    // relaisPin: Pin connected to the relais
    Pump(int relaisPin);

    // Public function: Initialize the Pump
    void init(void);

    // Public function: Starts the pump
    void start(void);

    // Public function: Stops the pump
    void stop(void);

private:
    // Member variable representing relais pin number
    uint8_t relaisPin;
};

#endif // PUMP_H
