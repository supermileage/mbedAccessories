#include "../mbed.h"
#include "CanItem.h"

#ifndef CANBUTTON_H
#define CANBUTTON_H 

class CanButton: private CanItem {
    public:
        CanButton(PinName pin, unsigned canID_);
        void poll();
    private:
        unsigned canID;
        DigitalIn button;
        bool on;
        void toggleButton();
        void debounceDelay();
};

#endif 