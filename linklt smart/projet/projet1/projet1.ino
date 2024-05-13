/*
  Yún HTTP Client

 This example for the YunShield/Yún shows how create a basic
 HTTP client that connects to the internet and downloads
 content. In this case, you'll connect to the Arduino
 website and download a version of the logo as ASCII text.

 created by Tom igoe
 May 2013

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/HttpClient

 */
#include <stdlib.h>
#include <Bridge.h>
#include <HttpClient.h>

void setup() {
  // Bridge takes about two seconds to start up
  // it can be helpful to use the on-board LED
  // as an indicator for when it has initialized
  pinMode(19, OUTPUT);
 
  Bridge.begin();
 

  SerialUSB.begin(9600);

  while (!SerialUSB); // wait for a serial connection
}

void loop() {
  // Initialize the client library
  HttpClient client;
 char c[5];  // assume a maximum of 4 digits plus a NULL terminator
   int n;
   byte indx = 0;
  // Make a HTTP request:
  client.get("http://192.168.137.85/compteur.txt");

  // from the server, read them and print them:
  while (client.available()) {
  c [ indx ] = client.read();
      c [ indx+1 ] = 0;
      indx ++; 
         n = atoi(c);
         if(n==800)
         {
          digitalWrite(19,HIGH);
          }
    SerialUSB.print(n);
  }
  SerialUSB.flush();

  delay(500);

  
  
}
