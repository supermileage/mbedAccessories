// IMPORTANT:
// * Need breakpoint on first line of main to debug without an exception, known error in VSCode
// * Do not use wait statements while debugging
// * For serial print use pc.print, and open "screen mbed sterm" in terminal
// * For some reason during debugging analog read is not working properly, so dont debug while testing throttle

#include "../mbed.h"
#include "Motor.h"
#include "CanHandler.h"
#include <iostream>

extern PwmOut pwmPin; // Importing pwm object
Motor motor(pwmPin);
CanHandler canHandler(motor); // Can message handler
Timer loopTimer;
int runLoopSpeed = 100; //ms

void setup() {
    loopTimer.start();
    while (loopTimer.read_ms() < 500) {} // Waits half a second on boot up
}

int main() {
    setup();
    int prevLoopStartTime = loopTimer.read_ms();

    while(true) {
        while (loopTimer.read_ms() - prevLoopStartTime < runLoopSpeed) {} //Regulate speed of the main loop to runLoopSpeed
		prevLoopStartTime = loopTimer.read_ms();
        canHandler.poll(); // Check and handle any can messages
    }
}

