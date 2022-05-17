// UART Communications Receive
// From ESP8266 Receiver Side
// To Arduino Receive Side

// Create local serial
#include <SoftwareSerial.h> 
SoftwareSerial ESPserial(2, 3); // RX | TX

byte checkByte = 0x80; // Byte used to verify meaningful transmission (Must match Transmit)

// Three variables defined for motion of the motors
signed char X;
signed char Y;
byte SW;


void setup() {
  // Begin the serial communications
  Serial.begin(115200); // Begin communications over USB
  ESPserial.begin(115200); // Begin communications with ESP over software
}

void loop() {
  // Receive communications
  if(Serial.read()==0x80){ // Check for the check byte, if correct: set the desired variables to the received values
    X = Serial.read();
    Y = Serial.read();
    SW = Serial.read();
  } 
  else { // Check byte is incorrect
    Serial.flush(); // Flush all serial values
  }

  // Print the actual values over USB serial
  Serial.print("X-axis: ");
  Serial.println(X);
  Serial.print("Y-axis: ");
  Serial.println(Y);
  Serial.print("Switch: ");
  Serial.println(SW);
  Serial.print("\n");

  delay(100);
}
