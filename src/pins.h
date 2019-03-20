#include "mbed.h"
#include "../mbedCanLib/src/CanButton.h"
#include "../mbedCanLib/src/CanIDs.h"

#ifndef PINS_H
#define PINS_H

// extern CAN can(p30, p29, 1000000); // Actual pins
extern CAN can(p9, p10, 1000000); // Use for testing (current wiring)
extern Serial pc(USBTX, USBRX); // To print to computer terminal, for testing

PwmOut pwmPin(LED1); // TODO: Set actual pin

#endif




