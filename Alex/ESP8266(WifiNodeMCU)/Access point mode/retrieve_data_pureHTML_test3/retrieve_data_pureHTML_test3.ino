#include <ESP8266WiFi.h> 
#include <ESP8266WebServer.h>

const char *ssid = "joystick";
const char *password = "test1234";

ESP8266WebServer server(80);

String joystickHTML ="<!DOCTYPE HTML> <html> <head> <title>Joy</title> <style> body { margin: 0px; padding: 0px; } #joystick { border: 1px solid #9C9898; } </style> <script> var JoyStick=function(t,e){function i(){S.beginPath(),S.arc(x,y,G,0,k,!1),S.lineWidth=w,S.strokeStyle=C,S.stroke()}function n(){S.beginPath(),m>Y&&(Y=E),Y+m>L.width&&(Y=L.width-E),m>T&&(T=E),T+m>L.height&&(T=L.height-E),S.arc(Y,T,m,0,k,!1);var t=S.createRadialGradient(x,y,5,x,y,200);t.addColorStop(0,f),t.addColorStop(1,g),S.fillStyle=t,S.fill(),S.lineWidth=v,S.strokeStyle=g,S.stroke()}function o(){W=1}function h(t){t.preventDefault(),1==W&&(Y=t.touches[0].pageX,T=t.touches[0].pageY,Y-=L.offsetLeft,T-=L.offsetTop,S.clearRect(0,0,L.width,L.height),i(),n())}function r(){W=0,Y=x,T=y,S.clearRect(0,0,L.width,L.height),i(),n()}function d(){W=1}function a(t){1==W&&(Y=t.pageX,T=t.pageY,Y-=L.offsetLeft,T-=L.offsetTop,S.clearRect(0,0,L.width,L.height),i(),n())}function l(){W=0,Y=x,T=y,S.clearRect(0,0,L.width,L.height),i(),n()}e=e||{};var c=void 0===e.title?\"joystick\":e.title,u=void 0===e.width?0:e.width,s=void 0===e.height?0:e.height,f=void 0===e.internalFillColor?\"#00AA00\":e.internalFillColor,v=void 0===e.internalLineWidth?2:e.internalLineWidth,g=void 0===e.internalStrokeColor?\"#003300\":e.internalStrokeColor,w=void 0===e.externalLineWidth?2:e.externalLineWidth,C=void 0===e.externalStrokeColor?\"#008000\":e.externalStrokeColor,p=document.getElementById(t),L=document.createElement(\"canvas\");L.id=c,0==u&&(u=p.clientWidth),0==s&&(s=p.clientHeight),L.width=u,L.height=s,p.appendChild(L);var S=L.getContext(\"2d\"),W=0,k=2*Math.PI,m=(L.width-110)/2,E=m+5,G=m+30,x=L.width/2,y=L.height/2,P=L.width/10,R=-1*P,F=L.height/10,X=-1*F,Y=x,T=y,b=\"createTouch\"in document;b?(L.addEventListener(\"touchstart\",o,!1),L.addEventListener(\"touchmove\",h,!1),L.addEventListener(\"touchend\",r,!1)):(L.addEventListener(\"mousedown\",d,!1),L.addEventListener(\"mousemove\",a,!1),L.addEventListener(\"mouseup\",l,!1)),i(),n(x,y),this.GetWidth=function(){return L.width},this.GetHeight=function(){return L.height},this.GetPosX=function(){return Y},this.GetPosY=function(){return T},this.GetX=function(){return(100*((Y-x)/E)).toFixed()},this.GetY=function(){return(100*((T-y)/E)*-1).toFixed()},this.GetDir=function(){var t=\"\",e=Y-x,i=T-y;return i>=X&&F>=i&&(t=\"C\"),X>i&&(t=\"N\"),i>F&&(t=\"S\"),R>e&&(\"C\"==t?t=\"W\":t+=\"W\"),e>P&&(\"C\"==t?t=\"W\":t+=\"E\"),t}}; </script> </head> <body> <div id=\"joyDiv\" style=\"width:200px;height:200px;margin-bottom:20px;\"></div> Position X:<input id=\"posizioneX\" type=\"text\" /></br> Position Y:<input id=\"posizioneY\" type=\"text\" /></br> Direction:<input id=\"direzione\" type=\"text\" /></br> X :<input id=\"X\" type=\"text\" /></br> Y :<input id=\"Y\" type=\"text\" /> <script type=\"text/javascript\"> // Create JoyStick object into the DIV 'joyDiv' var joy = new JoyStick('joyDiv'); var inputPosX = document.getElementById(\"posizioneX\"); var inputPosY = document.getElementById(\"posizioneY\"); var direzione = document.getElementById(\"direzione\"); var x = document.getElementById(\"X\"); var y = document.getElementById(\"Y\"); setInterval(function(){ inputPosX.value=joy.GetPosX(); }, 50); setInterval(function(){ inputPosY.value=joy.GetPosY(); }, 50); setInterval(function(){ direzione.value=joy.GetDir(); }, 50); setInterval(function(){ x.value=joy.GetX(); }, 50); setInterval(function(){ y.value=joy.GetY(); }, 50); let address = \"/?Y=\"+y.value+\"&X=\"+x.value; var xhttp = new XMLHttpRequest(); xhttp.open(\"GET\", address, true); xhttp.send(); </script> </body> </html>";

float forward = 0;
float left_right = 0;

void handleRoot() {
  server.send(200, "text/html", joystickHTML);
}

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  
  WiFi.softAP(ssid, password);

  //hosted in http://192.168.4.1
  IPAddress myIP = WiFi.softAPIP();
  
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();

  if(server.hasArg("Y")){
    String Y = server.arg("Y");
    forward = Y.toFloat();
  }
  if(server.hasArg("X")){
    String  X = server.arg("X");
    left_right= X.toFloat();
  }
  
  Serial.print("Y value: ");
  Serial.println(forward);
  Serial.println("");
  Serial.print("X value: ");
  Serial.println(left_right);  
}
