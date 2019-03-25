#include "../mbed.h"
#include "CanHandler.h"
#include "../mbedCanLib/src/canIDs.h"

#include <iostream>

extern CAN can; // Importing can object

CanHandler::CanHandler(Motor motor_) : motor(motor_) {}

// If this gets to long consider a lookup table with call backs
// Must break in each case, defualt behavior is fallthrough
void CanHandler::poll() {
    CANMessage msg;
    if(can.read(msg)) {
        unsigned char* data = msg.data;
        switch(msg.id) {
            case throttleID:
                handleThrottle(data);
                break;
            case indicatorRID:
                handleIndicatorR();
                break;
            case indicatorLID:
                handleIndicatorL();
                break;
            case headlightsID:
                handleHeadlights();
                break;
            case wiperID:
                handleWiper();
                break;
            case hazardsID:
                handleHazards();
                break;
            case hornID:
                handleHorn();
                break;
        }
    }
}

void CanHandler::handleThrottle(unsigned char* data) {
    const char* dataCasted = reinterpret_cast<const char*>(data);
    if(strlen(dataCasted) >= 1) {
        int command = data[0] - '0';
        float value = atof(dataCasted + 1); // Removes most significant digit, which was the command indicator
        switch(command) {
            case 7: // Update speed, motor must be active otherwise sets speed to 0
                motor.setSpeed(value);
                break;
            case 8: // Activate motor
                motor.activate();
                break;
            case 9: // stop motor
                motor.deactivate();
                break;
        }
    }
}
  

// TODO: Get pin mapping from Luke for these, toggle pins when these get called
void CanHandler::handleIndicatorL() {
    cout << "L indicator" << endl;
}

void CanHandler::handleIndicatorR() {
    cout << "R indicator" << endl;
}

void CanHandler::handleHeadlights() {
    cout << "Headlights" << endl;
}

void CanHandler::handleWiper() {
    cout << "Wiper" << endl;
}

void CanHandler::handleHazards() {
    cout << "Hazards" << endl;
}

void CanHandler::handleHorn() {
    cout << "Horn" << endl;
}




