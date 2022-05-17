#include <ESP8266WiFi.h> 

//Defines the ssid and password of network to which the ESP is going to connect
const char *ssid = "joystick";
const char *password = "test1234";

IPAddress ip(192, 168, 4, 1);             //IP Address of the network (198.168.4.1)

//Defines a client object
WiFiClient client;

//Defines the variables for the axis and switch data values
signed char X;
signed char Y;
byte SW;

byte checkByte = 0x80; //Byte used to verify meaningful transmission

void setup() {
  Serial.begin(115200);
  APConfig();
}

void loop() {
  serverRead();
  serialPrint();
  serialWrite(checkByte, X, Y, SW);
  delay(100);
}

//Connects to the Access Point
void APConfig() {
  Serial.println();
  Serial.println("Connecting to Access Point...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("Connected");
}

//Reads data sent from server
void serverRead(){
    if(client.read()==checkByte){
    X = client.read();
    Y = client.read();
    SW = client.read();
  }
}

//Prints data in serial monitor
void serialPrint(){
  Serial.print("X-axis: ");
  Serial.println(X);
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(Y);
  Serial.print("\n");
  Serial.print("Switch: ");
  Serial.println(SW);
  Serial.print("\n");
}

//Sends the data to the clients
void serialWrite(byte check, signed char x, signed char y, byte sw){
  Serial.write(check);
  Serial.write(x);
  Serial.write(y);
  Serial.write(sw);
}
