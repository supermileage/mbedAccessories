#include "mbed.h"
#include "CanButton.h"
#include "CanThrottle.h"

#ifndef PINS_H
#define PINS_H

// TODO: Define Actual can id's (figure out presedence)

// extern CAN can(p30, p29);
extern CAN can(p9, p10); // Use for testing
extern Serial pc(USBTX, USBRX); // To print to computer terminal, for testing

// Dials for throttle controls
DigitalIn loRangePin(p15, PullUp); // dial1
DigitalIn midRangePin(p16, PullUp); //dial2
DigitalIn highRangePin(p17, PullUp); //dial3
DigitalIn constantVelocityPin(p22, PullUp); //dialB
DigitalIn constantPowerPin(p23, PullUp); //dialA

// Unused dial inputs
DigitalIn dial4(p18, PullUp); //dial4
DigitalIn dial5(p19, PullUp); //dial5

DigitalIn rangePins[] = {loRangePin, midRangePin, highRangePin}; // [lo, mid, high]
DigitalIn modePins[] = {constantVelocityPin, constantPowerPin}; // [constVel, constPow]
CanThrottle throttle(p20,1, rangePins, modePins); 

CanButton indicatorR(p5, 2);
CanButton indicatorL(p6, 3);
CanButton headlights(p8, 4);
// CanButton wiper(p9, 5); // Comment this out for testing (w/ current wiring)
// CanButton harards(p10, 6); // Comment this out for testing (w/ current wiring)
CanButton horn(p24, 14);

// TODO: Add screen pins
DigitalOut pcbPower(p7);
DigitalIn dms(p21);

Serial serial(p28,p27); // For communication between controller over UART

#endif




