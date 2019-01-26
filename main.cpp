// IMPORTANT:
// * Need breakpoint on first line of main to debug without an exception, known error in VSCode
// * Do not use wait statements while debugging
// * For serial print use pc.print, and open "screen mbed sterm" in terminal

#include "ODriveMbed.h"
#include "mbed.h"
#include <string>

DigitalOut led1(LED1);

// Serial to the ODrive
Serial pc(USBTX, USBRX); // tx, rx
// Serial serial1(p9,p10);
Serial odriveSerial(p13,p14); //TX (ODrive RX: GPIO2), RX (ODrive TX: GPIO1)
// Serial odrive_serial(p9,p10); //TX (ODrive RX: GPIO2), RX (ODrive TX: GPIO1)

// Odrive communication object
ODriveMbed odrive(&odriveSerial);

void setup() {
    odriveSerial.baud(115200);
}

int main() {
    setup();
    bool on = false;
    led1 = 1;
    while(1) {
      if(on) {
        odrive.setVelocity(0,6.2);
        pc.printf("Speed set: 6.2, ");
        pc.printf("Bus voltage: %f \n", odrive.readBusVoltage());
        pc.printf("Read set Velocity:: %f \n", odrive.readSetVelocity(0));
        on = false;
      } else {
        odrive.setVelocity(0,1000);
        pc.printf("Speed set: 1000, ");
        pc.printf("Bus voltage: %f \n", odrive.readBusVoltage());
        pc.printf("Read set Velocity:: %f \n", odrive.readSetVelocity(0));
        on = true;
      }
    }
}



