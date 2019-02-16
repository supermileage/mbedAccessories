#include "mbed.h"
#include "CanHandler.h"
#include "CanIDs.h"

//TEMP
#include <iostream>

extern CAN can; // Importing can object

CanHandler::CanHandler(Serial* serial) : odrive(serial) {
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
    if(strlen(dataCasted) >= 1) {
        cout << "Original Data: " << data << endl;
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
        }
    }
}
  

// TODO: Get pin mapping from Luke for these, toggle pins when these get called
void CanHandler::handleIndicatorL() {

}

void CanHandler::handleIndicatorR() {
    
}

void CanHandler::handleHeadlights() {
    
}

void CanHandler::handleWiper() {
    
}

void CanHandler::handleHazards() {
    
}

void CanHandler::handleHorn() {
    
}




