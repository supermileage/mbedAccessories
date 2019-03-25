#include "../mbed.h"
#include "Motor.h"
#include <iostream>

Motor::Motor(PwmOut pwm_) : pwm(pwm_) {
    stop(); // Insure stopped on bootup
    pwm.period(0.01f);
    isActive = false;
}

void Motor::setSpeed(float duty) {
    if(isActive) {
        cout << "Writing duty: " << duty << endl;
        pwm.write(duty);
    } else {
        cout << "Set speed but not active" << endl;
        stop();
    }
}

void Motor::activate() {
    cout << "ACTIVE" << endl;
    isActive = true;
}

void Motor::deactivate() {
    cout << "DEACTIVEATED" << endl;
    stop();
    isActive = false;
}

void Motor::stop() {
    pwm.write(0);
}

