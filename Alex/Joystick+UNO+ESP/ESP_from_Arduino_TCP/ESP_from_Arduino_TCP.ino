#include <ESP8266WiFi.h> 
#include <ESP8266WebServer.h>

//Defines server object in port 80
ESP8266WebServer server(80);

IPAddress ip(192, 168, 4, 1);             //IP Address of the network (198.168.4.1)
IPAddress gateway(192,168,0,1);           // gateway of the network
IPAddress subnet(255,255,255,0);          // subnet mask of the network

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

void xValue(String string){}

void loop() {
  X = 0x20;
  Y = 0x11;
  SW = 0x61;
  
  /*serialRead();*/
  serialPrint();
  serverSend();
  delay(100);
}

//Configures the IP and starts the Access Point (softAP) and the server
void APConfig() {
  Serial.println();
  Serial.println("Initializing Access Point...");

  WiFi.config(ip, gateway, subnet);
  WiFi.softAP(ssid, password);
 
  server.begin();
  Serial.println("TCP server started");
}

/*//Reads data sent to serial
void serialRead(){
    if(Serial.read()==checkByte){
    X = Serial.read();
    Y = Serial.read();
    SW = Serial.read();
  }
}*/

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
void serverSend(byte check, signed char x, signed char y, byte sw){
  void xValue(){server.send(200, "text/plain", x);}
  void yValue(){server.send(200, "text/plain", y);}

  server.on("/", xValue);
}
