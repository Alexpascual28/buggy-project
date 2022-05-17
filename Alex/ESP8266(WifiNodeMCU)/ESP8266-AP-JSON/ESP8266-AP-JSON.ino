/*
 * Copyright (c) 2015, Majenko Technologies
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 * 
 * * Neither the name of Majenko Technologies nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Create a WiFi access point and provide a web server on it. */

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h> 
int LDRPin = A0;
int LDRReading = 0; 
/* Set these to your desired credentials. */
const char *ssid = "LightLevelESP";
const char *password = "";
int milisInterval = 2000;
int count = 0;
ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */
void handleRoot() {
LDRReading = analogRead(LDRPin);
String html ="<!DOCTYPE html> <html> <head><meta name=\"viewport\" content=\"width=device-width, minimumscale=1.0, maximum-scale=1.0, initial-scale=1\" /><style> body {text-align: center; max-width: 400px; margin: 10px auto;} #updateView { max-width: 400px; display: none; margin-top: 30px; } #dataVals { max-width: 400px; display: block; margin-top: 30px; } .convertButton { clear: both; position:relative; margin-top: 30px; -moz-box-shadow: 0px 1px 0px 0px #fff6af; -webkit-box-shadow: 0px 1px 0px 0px #fff6af; box-shadow: 0px 1px 0px 0px #fff6af; background:-webkit-gradient(linear, left top, left bottom, color-stop(0.05, #ffec64), color-stop(1, #ffab23)); background:-moz-linear-gradient(top, #ffec64 5%, #ffab23 100%); background:-webkit-linear-gradient(top, #ffec64 5%, #ffab23 100%); background:-o-linear-gradient(top, #ffec64 5%, #ffab23 100%); background:-ms-linear-gradient(top, #ffec64 5%, #ffab23 100%); background:linear-gradient(to bottom, #ffec64 5%, #ffab23 100%); filter:progid:DXImageTransform.Microsoft.gradient(startColorstr='#ffec64', endColorstr='#ffab23',GradientType=0); background-color:#ffec64; -moz-border-radius:6px; -webkit-border-radius:6px; border-radius:6px; border:1px solid #ffaa22; display:inline-block; cursor:pointer; color:#333333; font-family:Arial; font-size:21px; padding:14px 69px; text-decoration:none; text-shadow:0px 1px 0px #ffee66; } .convertButton:hover { background:-webkit-gradient(linear, left top, left bottom, color-stop(0.05, #ffab23), color-stop(1, #ffec64)); background:-moz-linear-gradient(top, #ffab23 5%, #ffec64 100%); background:-webkit-linear-gradient(top, #ffab23 5%, #ffec64 100%); background:-o-linear-gradient(top, #ffab23 5%, #ffec64 100%); background:-ms-linear-gradient(top, #ffab23 5%, #ffec64 100%); background:linear-gradient(to bottom, #ffab23 5%, #ffec64 100%); filter:progid:DXImageTransform.Microsoft.gradient(startColorstr='#ffab23', endColorstr='#ffec64',GradientType=0); background-color:#ffab23; } .convertButton:active { position:relative; top:1px; }</style></head> <body> <a onClick=\"changeView()\" class=\"convertButton\" id=\"viewButton\">Update Rate</a> <div id=\"dataVals\"> <h1>Light Level</h1> <div id=\"light\">";
html += LDRReading;
html +="</div><h1>Count Number</h1><div id=\"countNum\">";
html += count;
html +="</div> </div> <div id=\"updateView\"> <label for=\"fader\">Update rate in Milliseconds</label><br /> <input type=\"range\" style=\"width: 300px\" min=\"200\" max=\"5000\" value=\"2000\" id=\"fader\" step=\"1\" oninput=\"outputUpdate(value)\"> <output for=\"fader\" id=\"volume\">2000</output></div> <script> var changed = false; function changeView(){ if(changed == false){ document.getElementById('updateView').style.display = 'block'; document.getElementById('dataVals').style.display = 'none'; document.getElementById('viewButton').innerHTML = \"Show Data\"; changed = true; } else{ document.getElementById('updateView').style.display = 'none'; document.getElementById('dataVals').style.display = 'block'; document.getElementById('viewButton').innerHTML = \"Update Rate\"; changed = false; } } function loadDoc() { var xhttp = new XMLHttpRequest(); xhttp.onreadystatechange = function() { if (this.readyState == 4 && this.status == 200) { var obj = JSON.parse(this.responseText); document.getElementById(\"light\").innerHTML = obj.data[0].dataValue; document.getElementById(\"countNum\").innerHTML = obj.data[1].dataValue; } }; xhttp.open(\"GET\", \"/data\", true); xhttp.send(); } var timedEvent = setInterval(function(){ loadDoc(); }, 2000); function outputUpdate(vol) { clearInterval(timedEvent); timedEvent = setInterval(function(){ loadDoc(); }, vol); document.querySelector('#volume').value = vol; delayVal = vol; } </script> </body> </html>";

	server.send(200, "text/html", html);
}

void getData() {   
   //This is a JSON formatted string that will be served. You can change the values to whatever like.
   // {"data":[{"dataValue":"1024"},{"dataValue":"23"}]} This is essentially what is will output you can add more if you like
  LDRReading = analogRead(LDRPin);
  String text2 = "{\"data\":[";
  text2 += "{\"dataValue\":\"";
  text2 += LDRReading;
  text2 += "\"},";
  text2 += "{\"dataValue\":\"";
  text2 += count;
  text2 += "\"}";
  text2 += "]}";
  server.send(200, "text/html", text2);
  count++;
}

void setup() {
	delay(1000);
	Serial.begin(115200);
	Serial.println();
	Serial.print("Configuring access point...");
	/* You can remove the password parameter if you want the AP to be open. */
	WiFi.softAP(ssid, password);

	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);
	server.on("/", handleRoot);
 server.on("/data", getData);
	server.begin();
	Serial.println("HTTP server started");
}

void loop() {
	server.handleClient();
}
