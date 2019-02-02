// IMPORTANT:
// * Need breakpoint on first line of main to debug without an exception, known error in VSCode
// * Do not use wait statements while debugging
// * For serial print use pc.print, and open "screen mbed sterm" in terminal

#include "mbed.h"
#include "ODriveMbed.h"
#include "pins.h"
#include <iostream>

DigitalOut led1(LED1);
ODriveMbed odrive(&serial); // Odrive communication object
Timer loopTimer;
int runLoopSpeed = 10; //ms

void setup() {
    serial.baud(115200);
    loopTimer.start();
}

int main() {
    setup();
    int prevLoopStartTime = loopTimer.read_ms();

    bool on = false;

    while(true) {
        while (loopTimer.read_ms() - prevLoopStartTime < runLoopSpeed) { } //Regulate speed of the main loop to runLoopSpeed
		prevLoopStartTime = loopTimer.read_ms();
        cout << prevLoopStartTime << endl;

        led1 = !led1;
    }
}

