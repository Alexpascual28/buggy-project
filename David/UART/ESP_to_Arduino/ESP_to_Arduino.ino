// UART Communications Transmit
// From ESP8266 Receiver Side
// To Arduino Receive Side

byte checkByte = 0x80; //Byte used to verify meaningful transmission


// The three variables and their respective lengths which will be used for communicaitons
signed char X;
signed char Y;
byte SW;


int SendData(byte check, signed char x, signed char y, byte sw); // Made for sending the control byte and three data points in series


void setup() {
  // Begin serial communications
  Serial.begin(115200); // Begin communications with the Arduino
}

void loop() {
  // This definition will be replaced with the definition of values from the wifi communications
  X = 0x30;
  Y = 0x39;
  SW = 0x35;

  // Send the information defined above
  SendData(checkByte, X, Y, SW);
  Serial.print("\n");
  
  // Delay for tests
  delay(1000);
}


int SendData(byte check, signed char x, signed char y, byte sw) { //Define the sending protocol
  Serial.write(check);
  Serial.write(x);
  Serial.write(y);
  Serial.write(sw);
}
