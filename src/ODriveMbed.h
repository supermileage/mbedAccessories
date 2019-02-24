// For communication between odrive and mbed
// Ported OdriveArduino to work for mbed
// Original library: https://github.com/madcowswe/ODrive/blob/master/Arduino/ODriveArduino
// Possible commands: https://docs.odriverobotics.com/ascii-protocol.html

#ifndef ODriveMbed_h
#define ODriveMbed_h

#include "../mbed.h"
#include <iostream>
#include <string>

class ODriveMbed {
    public:
        ODriveMbed(Serial* serial_);

        // Commands
        void activateMotor(int motorNum);
        void deactivateMotor(int motorNum);
        void setConstantVelocityMode(int motorNum);
        void setConstantPowerMode(int motorNum);
        void setPosition(int motorNum, float position, float velocity_feedforward = 0.0f, float current_feedforward = 0.0f);
        void setVelocity(int motorNum, float velocity, float current_feedforward = 0.0f);
        void setCurrent(int motorNum, float current);
        float readBusVoltage();
        float readSetVelocity(int motorNum);
        float readSetCurrent(int motorNum);
    private:
        void setMotorState(int motorNum, int stateNum);
        float readFloat();
        int32_t readInt();
        Serial* serial;
        string readString(); 
};

#endif 