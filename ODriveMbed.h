// For communication between odrive and mbed
// Ported OdriveArduino to work for mbed
// Original library: https://github.com/madcowswe/ODrive/blob/master/Arduino/ODriveArduino
// Possible commands: https://docs.odriverobotics.com/ascii-protocol.html

#ifndef ODriveMbed_h
#define ODriveMbed_h

#include "mbed.h"
#include <iostream>
#include <string>

class ODriveMbed {
    public:
        ODriveMbed(Serial* serial_);

        // Commands
        void setPosition(int motorNum, float position);
        void setPosition(int motorNum, float position, float velocity_feedforward);
        void setPosition(int motorNum, float position, float velocity_feedforward, float current_feedforward);
        void setVelocity(int motorNum, float velocity);
        void setVelocity(int motorNum, float velocity, float current_feedforward);
        void setCurrent(int motorNum, float current);
        float readBusVoltage();
        float readSetVelocity(int motorNum);

        // General params
        float readFloat();
        int32_t readInt();

        // State helper
        bool run_state(int axis, int requested_state, bool wait);
    private:
        Serial* serial;
        string readString(); 
};

#endif 