#include "mbed.h"
#include "CanButton.h"

#ifndef PINS_H
#define PINS_H

extern CAN can(p30, p29);
extern Serial pc(USBTX, USBRX);

// TODO: Actually define can id's

CanButton indicatorR(p5, 1);
CanButton indicatorL(p6, 2);
CanButton headlights(p8, 3);
CanButton wiper(p9, 4);
CanButton harards(p10, 5);

CanButton dial1(p15, 6);
CanButton dial2(p16, 7);
CanButton dial3(p17, 8);
CanButton dial4(p18, 9);
CanButton dial5(p19, 10);

CanButton dialB(p22, 11);
CanButton dialA(p23, 12);
CanButton horn(p24, 13);


// TODO: Add screen pins
DigitalIn pcbPower(p7);
DigitalIn dms(p21);

Serial serial(p28,p27);

#endif




