#include "../mbed.h"
#include "Motor.h"
#include <iostream>

Motor::Motor(PwmOut pwm_) : pwm(pwm_) {
    pwm.period(2.0f); //TODO: Set actual value
    isActive = false;
}

void Motor::setSpeed(int duty) {
    if(isActive) {
        pwm.write(duty);
    } else {
        stop();
    }
}

void Motor::activate() {
    isActive = true;
}

void Motor::deactivate() {
    stop();
    isActive = false;
}

void Motor::stop() {
    pwm.write(0);
}

