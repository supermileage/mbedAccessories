#include "CanItem.h"

extern CAN can;

CanItem::CanItem(unsigned canID_) : canID(canID_){}

void CanItem::sendMessage(const char* data) {
    // TODO: Get the data length to send aswell
    can.write(CANMessage(canID,data,1));
}
