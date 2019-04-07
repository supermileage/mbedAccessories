#include "mbed.h"
#include "../mbedCanLib/src/CanButton.h"
#include "../mbedCanLib/src/CanIDs.h"

#ifndef PINS_H
#define PINS_H

extern CAN can(p9, p10, 500000); 
extern Serial pc(USBTX, USBRX); // To print to computer terminal, for testing
extern PwmOut pwmPin(p21); 

DigitalOut brakeLights(p13, 0); // Specifies pin and inital value
DigitalOut indicatorL(p15, 0); 
DigitalOut indicatorR(p14, 0);
DigitalOut headlights(p16, 0);
DigitalOut wiper(p17, 0);
DigitalOut horn(p18, 0);

#endif




