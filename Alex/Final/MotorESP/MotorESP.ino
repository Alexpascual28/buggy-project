// Final firmwar on the Motor Receiver Arduino

#include <ESP8266WiFi.h>  // Library for opening wifi communications over the ESP
#include <WiFiUdp.h>      // Library for operating udp protocol communications

//Pin for the connection LED
const int LED_pin = 2;

// Read delay
const int wait = 100;

// AP Details to connect
const char *ssid = "joystick";
const char *pass = "test1234"; 
const unsigned int localPort = 2000; // local port to listen for UDP packets
IPAddress ServerIP(192,168,4,1);
IPAddress ClientIP(192,168,4,2);

// A UDP instance to let us send and receive packets over UDP
WiFiUDP udp;

// Three communication variables and receiving variable
signed char Lcomms = 0;
signed char Rcomms = 0;
byte SW = 1;
char data[9];


// UART Settings
// Communication information storage
const byte checkByte = 0x80;

// Define function to sequentially send UART data
int SendData(byte check, signed char x, signed char y, byte sw);


void setup() {
  pinMode(LED_pin, OUTPUT);
  
  Serial.begin(115200); // Begin communications with the Arduino(Note: RX line is not used as ESP is only used as UART TX)
  Serial.println();

  // Initialize WiFi connection
  WiFi.begin(ssid, pass);
  Serial.println("");
 
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If conexion is succesful, turn the LED on
  digitalWrite(LED_pin, HIGH);

  // Confirm connection to the Access Point
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  //Start UDP connection
  Serial.println("Starting UDP");
  udp.begin(localPort);
  Serial.print("Local port: ");
  Serial.println(udp.localPort());
}


void loop() {
  // Check for available UDP Packet Data
  int cb = udp.parsePacket();
  if (cb){                // UDP packet available to be read
    
    // Store three bytes of read data into data
    udp.read(data, 3);

    // Save read data into the output variables
    Lcomms = data[0];
    Rcomms = data[1];
    SW = data[2];
  }

  // Send the variables to the Arduino
  SendData(checkByte, Lcomms, Rcomms, SW);
  Serial.print("\n");

  //if networks disconnects, turn the LED off
  if(WiFi.status() != WL_CONNECTED){
    digitalWrite(LED_pin, LOW);
  }
  
  // Print received data for debugging
//  Serial.print("Lcomms: ");
//  Serial.println(Lcomms);
//  Serial.print("Rcomms: ");
//  Serial.println(Rcomms);
//  Serial.print("Switch: ");
//  Serial.println(SW);
//  Serial.println("");

  delay(wait);
}

int SendData(byte check, signed char x, signed char y, byte sw) { //Define the sending protocol
  Serial.write(check);
  Serial.write(x);
  Serial.write(y);
  Serial.write(sw);
}
