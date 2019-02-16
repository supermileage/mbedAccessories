#include "ODriveMbed.h"

#ifndef CANHANDLER_H
#define CANHANDLER_H

class CanHandler {
    public:
        CanHandler(Serial* serial);
        void poll();
    private:
        int mode;
        ODriveMbed odrive; // Odrvie communication object
        void handleThrottle(unsigned char* data);
        void handleIndicatorL();
        void handleIndicatorR();
        void handleHeadlights();
        void handleWiper();
        void handleHazards();
        void handleHorn();
};

#endif 