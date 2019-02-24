// For communication between odrive and mbed
// Ported OdriveArduino to work for mbed
// Original library: https://github.com/madcowswe/ODrive/blob/master/Mbed/ODriveMbed
// Possible commands: https://docs.odriverobotics.com/ascii-protocol.html

#include "../mbed.h"
#include "ODriveMbed.h"

ODriveMbed::ODriveMbed(Serial* serial_) 
    : serial(serial_) {}

void ODriveMbed::activateMotor(int motorNum) {
    setMotorState(motorNum, 8); // 8 is AXIS_STATE_CLOSED_LOOP_CONTROL
}

void ODriveMbed::deactivateMotor(int motorNum) {
    setMotorState(motorNum, 1); // 1 is AXIS_STATE_IDLE
}

void ODriveMbed::setConstantVelocityMode(int motorNum) {
    serial->printf("w axis%d.controller.config.control_mode CTRL_MODE_VELOCITY_CONTROL \n", motorNum);
}

void ODriveMbed::setConstantPowerMode(int motorNum) {
    serial->printf("w axis%d.controller.config.control_mode CTRL_MODE_CURRENT_CONTROL \n", motorNum);
}

void ODriveMbed::setPosition(int motorNum, float position, float velocity_feedforward, float current_feedforward) {
    serial->printf("p %d %f %f %f \n", motorNum, position, velocity_feedforward, current_feedforward);
}

void ODriveMbed::setVelocity(int motorNum, float velocity, float current_feedforward) {
    serial->printf("v %d %f %f \n", motorNum, velocity, current_feedforward);
}

void ODriveMbed::setCurrent(int motorNum, float current) {
    serial->printf("c %d %f\n", motorNum, current);
}

float ODriveMbed::readBusVoltage() {
    serial->printf("r vbus_voltage \n");
    return readFloat();
}

float ODriveMbed::readSetVelocity(int motorNum) {
    serial->printf("r axis%d.controller.vel_setpoint \n", motorNum);
    return readFloat(); 
}

float ODriveMbed::readSetCurrent(int motorNum) {
    serial->printf("r axis%d.controller.current_setpoint \n", motorNum);
    return readFloat(); 
}

void ODriveMbed::setMotorState(int motorNum, int stateNum) {
    serial->printf("w axis%d.requested_state %d \n", motorNum, stateNum);
}


// Helpers

float ODriveMbed::readFloat() {
    return atof(readString().c_str());
}

int32_t ODriveMbed::readInt() {
    return atoi(readString().c_str());
}

string ODriveMbed::readString() {
  string str;
  Timer t;
  t.start();
  while(1) {
    bool readable = serial->readable();
    if(readable) {
      char c = serial->getc();
      if (c == '\n')
        break;
      str += c;
    } else if(t.read_ms() > 500) {
        break; // Protects against infinite loop
    }
  }
  return str;
}