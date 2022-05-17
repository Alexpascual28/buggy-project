#include <ESP8266WiFi.h> 
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

const char *ssid = "joystick";
const char *password = "test1234";

void APConfig() {;
  Serial.println();
  Serial.print("Initialising Access Point...");
  
  WiFi.softAP(ssid, password);
 
  server.begin();
  Serial.println("HTTP server started");
}

signed char X;
signed char Y;
byte SW;

void setup() {
  Serial.begin(115200);
  APConfig();
}

void loop() {
  if(Serial.read()==0x80){
    X = Serial.read();
    Y = Serial.read();
    SW = Serial.read();
  } else {
    Serial.flush();
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

  delay(100);
}
