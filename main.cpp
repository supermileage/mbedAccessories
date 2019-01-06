// IMPORTANT:
// * Need breakpoint on first line of main to debug without an exception, known error in VSCode
// * Do not use wait statements while debugging
// * For serial print use pc.print, and open "screen mbed sterm" in terminal

#include "ODriveMbed.h"
#include "mbed.h"
#include "Testing.h"

DigitalOut led1(LED1);

// Serial to the ODrive
Serial pc(USBTX, USBRX); // tx, rx
// Serial odrive_serial(p9,p10); //TX (ODrive RX), RX (ODrive TX)

// Odrive communication object
// ODriveMbed odrive(&pc);

Testing test1(5);

void setup() {
  // ODrive uses 115200 baud
//   odrive_serial.baud(115200);

  // In this example we set the same parameters to both motors.
  // You can of course set them different if you want.
  // See the documentation or play around in odrivetool to see the available parameters
//   for (int axis = 0; axis < 2; ++axis) {
//     odrive_serial << "w axis" << axis << ".controller.config.vel_limit " << 22000.0f << '\n';
//     odrive_serial << "w axis" << axis << ".motor.config.current_lim " << 11.0f << '\n';
//     // This ends up writing something like "w axis0.motor.config.current_lim 10.0\n"
//   }

  pc.printf("Ready!");
  pc.printf("Send the character '0' or '1' to calibrate respective motor (you must do this before you can command movement \n)");
  pc.printf("Send the character 's' to exectue test move \n");
  pc.printf("Send the character 'b' to read bus voltage \n");
  pc.printf("Send the character 'p' to read motor positions in a 10s loop \n");
}


int main() {
    // setup();

    test1.addToNum(4);

    led1 = !led1;
        
    // odrive.setPosition(num, num2);


//     if (Serial.available()) {
//     char c = Serial.read();

//     // Run calibration sequence
//     if (c == '0' || c == '1') {
//       int motornum = c-'0';
//       int requested_state;

//       requested_state = ODriveArduino::AXIS_STATE_MOTOR_CALIBRATION;
//       Serial << "Axis" << c << ": Requesting state " << requested_state << '\n';
//       odrive.run_state(motornum, requested_state, true);

//       requested_state = ODriveArduino::AXIS_STATE_ENCODER_OFFSET_CALIBRATION;
//       Serial << "Axis" << c << ": Requesting state " << requested_state << '\n';
//       odrive.run_state(motornum, requested_state, true);

//       requested_state = ODriveArduino::AXIS_STATE_CLOSED_LOOP_CONTROL;
//       Serial << "Axis" << c << ": Requesting state " << requested_state << '\n';
//       odrive.run_state(motornum, requested_state, false); // don't wait
//     }

//     // Sinusoidal test move
//     if (c == 's') {
//       Serial.println("Executing test move");
//       for (float ph = 0.0f; ph < 6.28318530718f; ph += 0.01f) {
//         float pos_m0 = 20000.0f * cos(ph);
//         float pos_m1 = 20000.0f * sin(ph);
//         odrive.SetPosition(0, pos_m0);
//         odrive.SetPosition(1, pos_m1);
//         delay(5);
//       }
//     }

//     // Read bus voltage
//     if (c == 'b') {
//       odrive_serial << "r vbus_voltage\n";
//       Serial << "Vbus voltage: " << odrive.readFloat() << '\n';
//     }

//     // print motor positions in a 10s loop
//     if (c == 'p') {
//       static const unsigned long duration = 10000;
//       unsigned long start = millis();
//       while(millis() - start < duration) {
//         for (int motor = 0; motor < 2; ++motor) {
//           odrive_serial << "r axis" << motor << ".encoder.pos_estimate\n";
//           Serial << odrive.readFloat() << '\t';
//         }
//         Serial << '\n';
//       }
//     }
//   }
}




