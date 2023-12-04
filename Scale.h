// Made By: Benjamin Kelada

#ifndef Scale_h
#define Scale_h

#include <Arduino.h>


class Scale {
public:
    Scale();
    int getWeight() const;
    void handleInput(int Raw_Data);
    

private:
    int Scale_data;
};

#endif