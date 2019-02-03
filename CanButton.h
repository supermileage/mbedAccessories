#include "mbed.h"

#ifndef CANBUTTON_H
#define CANBUTTON_H 

class CanButton {
    public:
        CanButton(PinName pin, unsigned canID_);
        void poll();
    private:
        unsigned canID;
        DigitalIn button;
        bool on;
        void toggleButton();
        void sendMessage();
        void debounceDelay();
};

#endif 