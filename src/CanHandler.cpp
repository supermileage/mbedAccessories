#include "../mbed.h"
#include "CanHandler.h"
#include "../mbedCanLib/src/canIDs.h"

#include <iostream>

extern CAN can; // Importing can object

CanHandler::CanHandler(ODriveMbed &odrive_) : odrive(odrive_) {
    mode = 0;
}

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
    cout << dataCasted << endl;
    if(strlen(dataCasted) >= 1) {
        int newMode = data[0] - '0';
        float value = atof(dataCasted + 1); // Removes most significant digit, which was the mode indicator
        switch(newMode) {
            case 0: // set Constant Velocity
                if(mode != newMode) {
                    odrive.setConstantVelocityMode(0);
                    mode = newMode;
                }
                odrive.setVelocity(0, value);
                cout << "Setting velocity: " << value << endl;
                break;
            case 1: // set Constant Power
                if(mode != newMode) {
                    odrive.setConstantPowerMode(0);
                    mode = newMode;
                }
                odrive.setCurrent(0, value);
                cout << "Setting current: " << value << endl;
                break;
            case 8: // Activate motor
                cout << "Activate" << endl;
                odrive.activateMotor(0);
                break;
            case 9: // stop motor
                cout << "Dectivate" << endl;
                odrive.deactivateMotor(0);
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




