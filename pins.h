#include "mbed.h"

#ifndef PINS_H
#define PINS_H

DigitalIn indicatorR(p5);
DigitalIn indicatorL(p6);
DigitalIn pcbPower(p7);
DigitalIn headlights(p8);
DigitalIn wiper(p9);
DigitalIn harards(p10);
// TODO: Add screen pins

DigitalIn dial1(p15);
DigitalIn dial2(p16);
DigitalIn dial3(p17);
DigitalIn dial4(p18);
DigitalIn dial5(p19);

DigitalIn dms(p21);
DigitalIn dialB(p22);
DigitalIn dialA(p23);
DigitalIn horn(p24);

Serial serial(p28,p27);
CAN can(p30, p29);
Serial pc(USBTX, USBRX);

#endif




