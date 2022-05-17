#include <SoftwareSerial.h>

int rxPin = 10;
int txPin = 9;

// set up a new serial object
SoftwareSerial mySerial (rxPin, txPin);

void serialConfig(){
  Serial.begin(9600);
  mySerial.begin(115200);
}

int Y_pin = 0;
int X_pin = 1;
int SW_pin = 3;

signed char X;
signed char Y;
byte SW;

void setup() {
  serialConfig();
  pinMode(SW_pin, INPUT_PULLUP);
}

void loop() {
  //Test for joysticks
  //Prints values in serial monitor
  
  X = map(analogRead(X_pin), 0, 1023, -127, 127);
  Y = map(analogRead(Y_pin), 0, 1023, -127, 127);
  SW = digitalRead(SW_pin);

  if(X>-5&&X<5){
    X = 0;
  }
  if(Y>-5&&Y<5){
    Y = 0;
  }
  
  Serial.print("X-axis: ");
  Serial.print(X);
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(Y);
  Serial.print("\n");
  Serial.print("Switch: ");
  Serial.println(SW);
  Serial.print("\n");
  
  mySerial.write(0x80);
  mySerial.write(X);
  mySerial.write(Y);
  mySerial.write(SW);

  delay(100);
}
