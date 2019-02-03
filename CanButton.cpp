#include "CanButton.h"

extern CAN can;

CanButton::CanButton(PinName pin, unsigned canID_) : canID(canID_), button(pin, PullUp), on(false) {}

void CanButton::poll() {
    bool readPin = !button.read(); // Pulled up, so 0 when pushed
    if(!on && readPin) {
        debounceDelay();
        if(!button.read()) { // Debounce
            toggleButton();
        }
    } else if(on && !readPin) {
        toggleButton();
    }
}

void CanButton::toggleButton() {
    on = !on;
    if(on) {
        can.write(CANMessage(canID,"1",1));
    } else {
        can.write(CANMessage(canID,"0",1));
    }
}

// Mbed wait doesnt work while debugging
void CanButton::debounceDelay() {
    Timer timer;
    timer.start();
    while (timer.read_ms() < 100) { } // delays by 100ms
}

