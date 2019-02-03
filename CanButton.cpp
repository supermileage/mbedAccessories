#include "CanButton.h"

extern CAN can;
extern Serial pc;

CanButton::CanButton(PinName pin, unsigned canID_) : canID(canID_), button(pin, PullUp), on(false) {}

void CanButton::poll() {
    bool readPin = !button.read(); // Pulled up, so 0 when pushed
    if(!on && readPin) {
        debounceDelay();
        if(!button.read()) {
            toggleButton();
        }
    } else if(on && !readPin) {
        toggleButton();
    }
}

void CanButton::toggleButton() {
    on = !on;
    CANMessage msg;
    msg.id = canID;
    msg.len = 1;
    if(on) {
        msg.data[0] = 1;
        can.write(msg);
        pc.printf("on \n");
    } else {
        msg.data[0] = 0;
        can.write(msg);
        pc.printf("off \n");
    }
}

// Mbed wait doesnt work while debugging
void CanButton::debounceDelay() {
    Timer timer;
    timer.start();
    while (timer.read_ms() < 100) { } // delays by 100ms
}

