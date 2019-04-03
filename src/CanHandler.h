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
        void handleIndicatorL(int command);
        void handleIndicatorR(int command);
        void handleHeadlights(int command);
        void handleWiper(int command);
        void handleHazards(int command);
        void handleHorn(int command);
        void handleBrakeLights(int command);
};

#endif 