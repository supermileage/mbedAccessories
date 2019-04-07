#include "../mbed.h"
#include "CanHandler.h"
#include "../mbedCanLib/src/canIDs.h"

#include <iostream>
#include <pins.h>

extern CAN can; // Importing can object

CanHandler::CanHandler(Motor motor_) : motor(motor_) {}

// If this gets to long consider a lookup table with call backs
// Must break in each case, defualt behavior is fallthrough
void CanHandler::poll() {
    CANMessage msg;
    if(can.read(msg)) {
        // cout << "MESSAGE" << endl;
        unsigned char* data = msg.data;
        int command = data[0] - '0';
        switch(msg.id) {
            case throttleID:
                handleThrottle(data);
                break;
            case indicatorRID:
                handleIndicatorR(command);
                break;
            case indicatorLID:
                handleIndicatorL(command);
                break;
            case headlightsID:
                handleHeadlights(command);
                break;
            case wiperID:
                handleWiper(command);
                break;
            case hazardsID:
                handleHazards(command);
                break;
            case hornID:
                handleHorn(command);
                break;
            case brakeID:
                handleBrakeLights(command);
                break;
            default:
                // cout << "Non valid id: " << msg.id << ", data: " << msg.data << endl;
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
  
void CanHandler::handleIndicatorL(int command) {
    // cout << "L indicator: " << command << endl;
    command ? indicatorL.write(1) : indicatorL.write(0);
}

void CanHandler::handleIndicatorR(int command) {
    // cout << "R indicator: " << command << endl;
    command ? indicatorR.write(1) : indicatorR.write(0);
}

void CanHandler::handleHeadlights(int command) {
    // cout << "headlights: " << command << endl;
    command ? headlights.write(1) : headlights.write(0);
}

void CanHandler::handleWiper(int command) {
    // cout << "Wiper: " << command << endl;
    command ? wiper.write(1) : wiper.write(0);
}

void CanHandler::handleHazards(int command) {
    // cout << "Hazards: " << command << endl;
    if(command == 1) {
        indicatorR.write(1);
        indicatorL.write(1);
    } else {
        indicatorR.write(0);
        indicatorL.write(0);
    }
}

void CanHandler::handleHorn(int command) {
    // cout << "Horn: " << command << endl;
    command ? horn.write(1) : horn.write(0);
}

void CanHandler::handleBrakeLights(int command) {
    // cout << "Brake Lights: " << command << endl;
    command ? brakeLights.write(1) : brakeLights.write(0);
}




