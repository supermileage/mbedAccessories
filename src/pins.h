#include "mbed.h"
#include "../mbedCanLib/src/CanButton.h"
#include "../mbedCanLib/src/CanIDs.h"

#ifndef PINS_H
#define PINS_H

// extern CAN can(p30, p29, 50000); // Actual pins
extern CAN can(p9, p10, 50000); // Use for testing (current wiring)
extern Serial pc(USBTX, USBRX); // To print to computer terminal, for testing


Serial serial(p28,p27); // For communication with motor controller over UART (TX, RX) (GPIO2, GPIO1 on odrive)

#endif




