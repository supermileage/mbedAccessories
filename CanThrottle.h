#include "mbed.h"
#include "CanItem.h"
#include <vector>

#ifndef CANTHROTTLE_H
#define CANTHROTTLE_H 

// Defualt throttleMode: constantPower , Defualt throttleRange: low
class CanThrottle: private CanItem {
    public:
        enum ThrottleMode {constantVelocity = 0, constantPower = 1};
        enum ThrottleRange {low = 0, mid = 1, high = 2};
        CanThrottle(PinName throttlePin, unsigned canID_, DigitalIn *rangePins_, DigitalIn *modePins_); 
        void poll();
    private:
        unsigned canID;
        AnalogIn throttle;
        ThrottleMode throttleMode;
        ThrottleRange throttleRange;
        DigitalIn *rangePins; // [lo, mid, high]
        DigitalIn *modePins; // [constVel, constPow]
        void updateConfiguration();
        void stopMotor();
};

#endif 