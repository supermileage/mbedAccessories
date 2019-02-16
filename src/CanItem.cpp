#include "CanItem.h"
#include <iostream> // TODO: Remove

extern CAN can;

CanItem::CanItem(unsigned canID_) : canID(canID_){}

void CanItem::sendMessage(const char* data) {
    can.write(CANMessage(canID,data,8));
}
