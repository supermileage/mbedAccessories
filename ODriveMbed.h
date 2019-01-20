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
        enum AxisState_t {
            AXIS_STATE_UNDEFINED = 0,           //<! will fall through to idle
            AXIS_STATE_IDLE = 1,                //<! disable PWM and do nothing
            AXIS_STATE_STARTUP_SEQUENCE = 2, //<! the actual sequence is defined by the config.startup_... flags
            AXIS_STATE_FULL_CALIBRATION_SEQUENCE = 3,   //<! run all calibration procedures, then idle
            AXIS_STATE_MOTOR_CALIBRATION = 4,   //<! run motor calibration
            AXIS_STATE_SENSORLESS_CONTROL = 5,  //<! run sensorless control
            AXIS_STATE_ENCODER_INDEX_SEARCH = 6, //<! run encoder index search
            AXIS_STATE_ENCODER_OFFSET_CALIBRATION = 7, //<! run encoder offset calibration
            AXIS_STATE_CLOSED_LOOP_CONTROL = 8  //<! run closed loop control
        };

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

#endif //ODriveMbed_h