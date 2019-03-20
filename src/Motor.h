#include "../mbed.h"
#include <iostream>

#ifndef Motor_h
#define Motor_h

class Motor {
    public:
        Motor(PwmOut pwm_);
        void setSpeed(int voltage);
        void activate();
        void deactivate();
    private:
        bool isActive;
        PwmOut pwm;
        void stop();
};

#endif
