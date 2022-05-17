#include <ESP8266WiFi.h> 
#include <WiFiUdp.h>

IPAddress ClientIP(192,168,4,2); //IPAddress of the client

unsigned int localPort = 2000; // local port to listen for UDP packets

// A UDP instance to let us send and receive packets over UDP
WiFiUDP udp;

//Defines ssid and password of the Access Point WiFi Network
const char *ssid = "joystick";
const char *password = "test1234";

byte checkByte = 0x80; //Byte used to verify meaningful transmission

//Defines the variables for the axis and switch data values
signed char X;
signed char Y;
byte SW;

void setup() {
  Serial.begin(115200);
  APConfig();
}

void loop() {
  serialRead();
  serialPrint();
  serverSend(X, Y, SW);
  delay(100);
}

//Configures the IP and starts the Access Point (softAP) and the udp
void APConfig() {
  Serial.println();
  Serial.println("Initializing Access Point...");
  WiFi.softAP(ssid, password);

  //Start UDP
  Serial.println("Starting UDP");
  udp.begin(localPort);
  Serial.print("Local port: ");
  Serial.println(udp.localPort());
  Serial.print("IP: ");
  Serial.println(WiFi.softAPIP());
  Serial.println("UDP server started");
}

//Reads data sent to serial
void serialRead(){
    if(Serial.read()==checkByte){
    X = Serial.read();
    Y = Serial.read();
    SW = Serial.read();
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
void serverSend(signed char x, signed char y, byte sw){
  byte data[] = {x ,y ,sw};
  udp.beginPacket(ClientIP, localPort);
  udp.write(data, 3);
  udp.endPacket();
}
