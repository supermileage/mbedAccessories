// IMPORTANT:
// * Need breakpoint on first line of main to debug without an exception, known error in VSCode
// * Do not use wait statements while debugging
// * For serial print use pc.print, and open "screen mbed sterm" in terminal

#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
CAN can1(p9, p10);
CAN can2(p30, p29);
char counter = 0;

int main() {
    CANMessage msg;
    while(1) {
        if(can1.write(CANMessage(1337, &counter, 8))) {
            counter++;
            printf("Message sent %d\n", counter);
            led1 = !led1;
        } 
        printf("loop()\n");
        if(can2.read(msg)) {
            printf("Message received: %d\n", msg.data[0]);
            led2 = !led2;
        } 
        led2 = !led2;
        printf("CAN 1 - td: %d, rd: %d  \n", can1.tderror(), can1.rderror());
        printf("CAN 2 - td: %d, rd: %d  \n", can2.tderror(), can2.rderror());
    }
}
