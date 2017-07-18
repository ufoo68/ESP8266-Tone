#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

#define BUFFER_SIZE 16384
uint8_t buf[BUFFER_SIZE];
const int port13 = 13;
boolean flg;
const char *ssid = "SSID";
const char *password = "pass";
String form =
"<!DOCTYPE html><html><head><meta charset='utf-8'><meta http-equiv='content-type' content='text/html; charset=UTF-8'><meta name='viewport' content='width=device-width, user-scalable=no, initial-scale=1'>\
<meta charset='utf-8'>\
<meta name='viewport' content='width=device-width, user-scalable=no'>\
<title>LED Button</title>\
<style>\
button{\
  font-size:42px;\
  width:100%;\
  height:60px;\
}\
</style>\
<style type='text/css'>\
.test1 {\
vertical-align:middle;\
height:100%;\
}\
</style>\
</head>\
<body>\
<script>\
function send1(){\
  send('/1/');\
}\
function send2(){\
  send('/2/');\
}\
function send3(){\
  send('/3/');\
}\
function send4(){\
  send('/4/');\
}\
function send5(){\
  send('/5/');\
}\
function send6(){\
  send('/6/');\
}\
function send7(){\
  send('/7/');\
}\
function send8(){\
  send('/8/');\
}\
function send(url){\
  var xhr = new XMLHttpRequest();\
  xhr.open('GET', url, true);\
  xhr.send();\
}\
</script>\
<br>\
<div class='test1'>\
<button id='do' onClick=send1()>ド</button>\
<button id='re' onClick=send2()>レ</button>\
<button id='mi' onClick=send3()>ミ</button>\
<button id='fa' onClick=send4()>ファ</button>\
<button id='so' onClick=send5()>ソ</button>\
<button id='ra' onClick=send6()>ラ</button>\
<button id='si' onClick=send7()>シ</button>\
<button id='do_' onClick=send8()>ド’</button>\
</div>\
</body></html>\
";

ESP8266WebServer server(80);

void handleRoot(){
  Serial.println("Access");
  server.send(200, "text/html", form);
}

void tone1(){
  analogWrite(port13, 128);
  analogWriteFreq(262);
  delay(500);
  analogWrite(port13, 0);
  server.send(200, "text/html","OK");
}

void tone2(){
  analogWrite(port13, 128);
  analogWriteFreq(294);
  delay(500);
  analogWrite(port13, 0);
  server.send(200, "text/html","OK");
}

void tone3(){
  analogWrite(port13, 128);
  analogWriteFreq(330);
  delay(500);
  analogWrite(port13, 0);
  server.send(200, "text/html","OK");
}

void tone4(){
  analogWrite(port13, 128);
  analogWriteFreq(349);
  delay(500);
  analogWrite(port13, 0);
  server.send(200, "text/html","OK");
}

void tone5(){
  analogWrite(port13, 128);
  analogWriteFreq(392);
  delay(500);
  analogWrite(port13, 0);
  server.send(200, "text/html","OK");
}

void tone6(){
  analogWrite(port13, 128);
  analogWriteFreq(440);
  delay(500);
  analogWrite(port13, 0);
  server.send(200, "text/html","OK");
}

void tone7(){
  analogWrite(port13, 128);
  analogWriteFreq(494);
  delay(500);
  analogWrite(port13, 0);
  server.send(200, "text/html","OK");
}

void tone8(){
  analogWrite(port13, 128);
  analogWriteFreq(523);
  delay(500);
  analogWrite(port13, 0);
  server.send(200, "text/html","OK");
}


void setup() {
  pinMode(port13, OUTPUT);
  analogWriteRange(255) ; // for ESP8266
  WiFi.softAP(ssid, password);
  server.on("/", handleRoot);
  server.on("/1/", tone1);
  server.on("/2/", tone2);
  server.on("/3/", tone3);
  server.on("/4/", tone4);
  server.on("/5/", tone5);
  server.on("/6/", tone6);
  server.on("/7/", tone7);
  server.on("/8/", tone8);
  server.begin();   
}

void loop() {
  server.handleClient();
}
