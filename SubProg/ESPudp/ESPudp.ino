#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
 
const char *ssid = "joystick";
const char *pass = "test1234"; 
 
unsigned int localPort = 2000; // local port to listen for UDP packets

IPAddress ServerIP(192,168,4,1);
IPAddress ClientIP(192,168,4,2);
 
// A UDP instance to let us send and receive packets over UDP
WiFiUDP udp;

byte checkByte = 0x80;

signed char X;
signed char Y;
byte SW;

//======================================================================
//                Setup
//======================================================================
void setup()
{
    Serial.begin(115200);
    Serial.println();
 
    WiFi.begin(ssid, pass);   //Connect to access point
  
    Serial.println("");
 
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
    
    //Start UDP
    Serial.println("Starting UDP");
    udp.begin(localPort);
    Serial.print("Local port: ");
    Serial.println(udp.localPort());
}

char data[3];

void loop()
{
    int cb = udp.parsePacket();
    if (!cb) 
    {
      //If serial data is recived send it to UDP
      if(Serial.available()>0)
        {
        udp.beginPacket(ServerIP, 2000);  //Send Data to Master unit
        //Send UDP requests are to port 2000
        
        char a[1];
        a[0]=char(Serial.read()); //Serial Byte Read
        udp.write(a,1); //Send one byte to ESP8266 
        udp.endPacket();
        }
    }
    else {
      // We've received a UDP packet, send it to serial
       //X = udp.read();
       //Y = udp.read();
       //SW = udp.read();

      char data[9];
      udp.read(data, 3);

      signed char L = char(data[0]);
      signed char R = char(data[1]);
      
      //Serial.println(X);
      //Serial.println(Y);
      //Serial.println(SW);
      Serial.println(L);
      Serial.println(R);
      Serial.println(int(data[2]));
      Serial.println("");
      delay(100);
    }
}
