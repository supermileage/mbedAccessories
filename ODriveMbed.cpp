// For communication between odrive and mbed
// Ported OdriveArduino to work for mbed
// Original library: https://github.com/madcowswe/ODrive/blob/master/Mbed/ODriveMbed

#include "mbed.h"
#include "ODriveMbed.h"

static const int kMotorOffsetFloat = 2;
static const int kMotorStrideFloat = 28;
static const int kMotorOffsetInt32 = 0;
static const int kMotorStrideInt32 = 4;
static const int kMotorOffsetBool = 0;
static const int kMotorStrideBool = 4;
static const int kMotorOffsetUint16 = 0;
static const int kMotorStrideUint16 = 2;

ODriveMbed::ODriveMbed(Serial serial_) 
    : serial(serial_) {}

void ODriveMbed::setPosition(int motor_number, float position) {
    setPosition(motor_number, position, 0.0f, 0.0f);
}

void ODriveMbed::setPosition(int motor_number, float position, float velocity_feedforward) {
    setPosition(motor_number, position, velocity_feedforward, 0.0f);
}

void ODriveMbed::setPosition(int motor_number, float position, float velocity_feedforward, float current_feedforward) {
    serial.printf("p %d %f %f %f \n", motor_number, position, velocity_feedforward, current_feedforward);
    // serial_ << "p " << motor_number  << " " << position << " " << velocity_feedforward << " " << current_feedforward << "\n";
}

void ODriveMbed::setVelocity(int motor_number, float velocity) {
    setVelocity(motor_number, velocity, 0.0f);
}

void ODriveMbed::setVelocity(int motor_number, float velocity, float current_feedforward) {
    serial.printf("v %d %f %f \n", motor_number, velocity, current_feedforward);
    // serial_ << "v " << motor_number  << " " << velocity << " " << current_feedforward << "\n";
}

float ODriveMbed::readFloat() {
    return readString().toFloat();
}

int32_t ODriveMbed::readInt() {
    return readString().toInt();
}

bool ODriveMbed::run_state(int axis, int requested_state, bool wait) {
    int timeout_ctr = 100;
    serial.printf("w axis %d %d \n");
    // serial_ << "w axis" << axis << ".requested_state " << requested_state << '\n';
    if (wait) {
        do {
            delay(100);
            // TODO: Check this (missing the .current...)
            serial.printf("r axis %d \n");
            // serial_ << "r axis" << axis << ".current_state\n"; 
        } while (readInt() != AXIS_STATE_IDLE && --timeout_ctr > 0);
    }

    return timeout_ctr > 0;
}

// TODO: implement
// string ODriveMbed::readString() {
//     string str = "";
//     static const unsigned long timeout = 1000;
//     unsigned long timeout_start = millis();
//     for (;;) {
//         while (!serial_.available()) {
//             if (millis() - timeout_start >= timeout) {
//                 return str;
//             }
//         }
//         char c = serial_.read();
//         if (c == '\n')
//             break;
//         str += c;
//     }
//     return str;
// }