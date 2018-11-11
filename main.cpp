// IMPORTANT:
// * Need breakpoint on first line of main to debug without an exception, known error in VSCode
// * Do not use wait statements while debugging
// * For serial print use pc.print, and open "screen mbed sterm" in terminal

#include "mbed.h"

Serial pc(USBTX, USBRX);

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

// main() runs in its own thread in the OS
int main() {
    while (true) {
        led1 = !led1;
        led2 = !led2;
        led3 = !led3;
        led4 = !led4;
        pc.printf("ECHO\n");
    }
}