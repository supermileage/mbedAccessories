// For communication between odrive and mbed
// Ported OdriveArduino to work for mbed
// Original library: https://github.com/madcowswe/ODrive/blob/master/Arduino/ODriveArduino

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
        void setPosition(int motor_number, float position);
        void setPosition(int motor_number, float position, float velocity_feedforward);
        void setPosition(int motor_number, float position, float velocity_feedforward, float current_feedforward);
        void setVelocity(int motor_number, float velocity);
        void setVelocity(int motor_number, float velocity, float current_feedforward);

        // General params
        float readFloat();
        int32_t readInt();

        // State helper
        bool run_state(int axis, int requested_state, bool wait);
    private:
        string readString();
        Serial* serial;
};

#endif //ODriveMbed_h