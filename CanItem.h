#include "mbed.h"

#ifndef CANITEM_H
#define CANITEM_H 

// Abstract class for anything using the CanBus
class CanItem { 
    public:
        CanItem(unsigned canID_);
        virtual void poll() = 0; // Pure virtual function, implement in subclass
        virtual void sendMessage(const char* data); 
    private:
        unsigned canID;
};

#endif 