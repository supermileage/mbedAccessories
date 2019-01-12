// IMPORTANT:
// * Need breakpoint on first line of main to debug without an exception, known error in VSCode
// * Do not use wait statements while debugging
// * For serial print use pc.print, and open "screen mbed sterm" in terminal

#include "ODriveMbed.h"
#include "mbed.h"
#include <string>

DigitalOut led1(LED1);

// Serial to the ODrive
Serial pc(USBTX, USBRX); // tx, rx
Serial serial1(p9,p10);
Serial serial2(p13,p14);
// Serial odrive_serial(p9,p10); //TX (ODrive RX), RX (ODrive TX)

// Odrive communication object
// ODriveMbed odrive(&pc);

void setup() {
  // ODrive uses 115200 baud
//   odrive_serial.baud(115200);
  
  pc.printf("Ready!");
  pc.printf("Send the character '0' or '1' to calibrate respective motor (you must do this before you can command movement \n)");
  pc.printf("Send the character 's' to exectue test move \n");
  pc.printf("Send the character 'b' to read bus voltage \n");
  pc.printf("Send the character 'p' to read motor positions in a 10s loop \n");
}

string read();

int main() {
    while(1) {
      serial1.printf("testing this out \n");
      // string s = read();
      const char *cstr = read().c_str();
      pc.printf(cstr);
      pc.printf("\n");
    }
}

string read() {
  string str;
  while(1) {
    if(serial2.readable()) {
      char c = serial2.getc();
      if (c == '\n')
        break;
      str += c;
    } else {
      // TODO: guard against infinite loop here
    }
  }
  return str;
}


