#include "mbed.h"
#include "../mbedCanLib/src/CanButton.h"
#include "../mbedCanLib/src/CanIDs.h"

#ifndef PINS_H
#define PINS_H

extern CAN can(p30, p29, 500000); // Actual pins
extern Serial pc(USBTX, USBRX); // To print to computer terminal, for testing

PwmOut pwmPin(p21); // TODO: Set actual pin

#endif




