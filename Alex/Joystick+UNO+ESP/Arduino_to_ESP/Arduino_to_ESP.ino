#include <SoftwareSerial.h>

//Defines pins for the software serial receiver and transmiter
int rxPin = 10;
int txPin = 9;

//Sets up a new serial object in defined receiver and transmitter pins 
SoftwareSerial mySerial (rxPin, txPin);

//Defines axis and switch pins from joystick
const int Y_pin = A0;
const int X_pin = A1;
const int SW_pin = 3;

byte checkByte = 0x80; //Byte used to verify meaningful transmission

//Defines the variables for the axis and switch data values
int X;
int Y;
byte SW;

// Motor output variables
signed char L = 0;
signed char R = 0;

// Initialize the output function
int joyToMotor(int m, int n, signed char *L, signed char *R);

void setup() {
  serialConfig();
  pinMode(SW_pin, INPUT_PULLUP);
}

void loop() {
  X = analogRead(X_pin);
  Y = analogRead(Y_pin);
  SW = digitalRead(SW_pin);
  
  joyToMotor(X, Y, &L, &R);
  serialPrint();
  serialWrite(checkByte, L, R, SW);
  delay(100);
}

//Starts the serial and the software serial
void serialConfig(){
  Serial.begin(115200);
  mySerial.begin(115200);
}

// Define the translation from XY coordinate space to LR
int joyToMotor(int n, int m, signed char *L, signed char *R) {  
  // Map values to usable figures
  int x = map(n, 0, 1023, -100, 100);
  int y = map(m, 0, 1023, -100, 100);

  // Correct for any initial offsets
  if(x > -5 && x < 5){
    x = 0;
  }
  if(y > -5 && y < 5){
    y = 0;
  }
  
  // Calculate Motor values
  x = -1 * x; //Invert x
  int v = (100 -abs(x))* (y/100) +y; //Calculate a v value: R-L
  int w = (100 -abs(y))* (x/100) +x; //Calculate a w value: R+L
  int r = (v +w)/2; //Calcualte r
  int l = (v -w)/2; //Calculate l
  r = map(r, -100, 100, -127, 127); //Map to bytes
  l = map(l, -100, 100, -127, 127);

  // Set to the output bytes
  *L = l;
  *R = r;
}

//Prints values in serial monitor
void serialPrint(){
  Serial.print("X-axis: ");
  Serial.println(X);
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(Y);
  Serial.print("\n");
  Serial.print("Left-output: ");
  Serial.println(L);
  Serial.print("\n");
  Serial.print("Right-output: ");
  Serial.println(R);
  Serial.print("\n");
  Serial.print("Switch: ");
  Serial.println(SW);
  Serial.print("\n");
}

//Sends data to the ESP
void serialWrite(byte check, signed char l, signed char r, byte sw){
  mySerial.write(check);
  mySerial.write(l);
  mySerial.write(r);
  mySerial.write(sw);
}
