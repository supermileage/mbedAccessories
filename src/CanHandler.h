#include "Motor.h"

#ifndef CANHANDLER_H
#define CANHANDLER_H

class CanHandler {
    public:
        CanHandler(Motor motor_);
        void poll();
    private:
        Motor motor;
        void handleThrottle(unsigned char* data);
        void handleIndicatorL();
        void handleIndicatorR();
        void handleHeadlights();
        void handleWiper();
        void handleHazards();
        void handleHorn();
};

#endif 