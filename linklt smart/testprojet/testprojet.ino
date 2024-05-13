
#include <TM1637Display.h>
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <Bridge.h>
#include <HttpClient.h>

#define CLK1 2
#define DIO1 3


#define TEST_DELAY   300
TM1637Display display1(CLK1, DIO1);// define dispaly 1 object

uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 }; 
const int touchPin = 23;
const int touchDelay = 500;

int count=0;// variable holding the count number
int lastButtonState = 0;
int lastButtonStatedeux = 0;
     


void setup() {

    
  Bridge.begin();

  SerialUSB.begin(9600);
  pinMode(touchPin,INPUT_PULLUP);// define a pin for touch module
  while (!SerialUSB); // wait for a serial connection

  display1.setBrightness(0x0f);// set brightness of dispaly 1
  display1.setSegments(data);// fill display 1 with whatever data[] array has
  
}

void loop() {
  // Robojax.com Touch counter 20181029
  HttpClient client;
  int n_p1=0;
   char c[5];  // assume a maximum of 4 digits plus a NULL terminator
   int n;
   byte indx = 0;
 
  while(true){
 client.get("http://192.168.137.8/compteur.txt");



//////////////////////////////////////////////////////
indx=0;
 while (client.available()) {

 c [ indx ] = client.read();
      c [ indx+1 ] = 0;
      indx ++; 
         n = atoi(c);
       
         }
         
         n_p1=0;
          
          
  if(n_p1>0)
  {
 count++;// increment the count     
          display1.setSegments(data); // clear the screen from previous values   
      display1.showNumberDec(count);// display the count        
    delay(touchDelay);

    }  
SerialUSB.println(n_p1);
         }
    

SerialUSB.flush();
  delay(5000);
}
