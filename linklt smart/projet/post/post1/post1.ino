#include <FileIO.h>
#include <TM1637Display.h>
#define CLK1 2
#define DIO1 3
#define TEST_DELAY   300
TM1637Display display1(CLK1, DIO1);// define dispaly 1 object
   uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 };  // all segments clear 

#define button 23
#define buttond 22
#define buttont 21
#define buttonq 20
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState5 = 0;         // current state of the button
int lastButtonState = 0;

int buttonPushCounterd = 0;   // counter for the number of button presses
int buttonStated = 0;         // current state of the button
int lastButtonStated = 0;


int buttonPushCountert = 0;   // counter for the number of button presses
int buttonStatet = 0;         // current state of the button
int lastButtonStatet = 0;

int buttonPushCounterq = 0;   // counter for the number of button presses
int buttonStateq = 0;         // current state of the button
int lastButtonStateq = 0;
void setup() {
  // Initialize the Bridge and the Serial
  Bridge.begin();
  Serial.begin(9600);
  FileSystem.begin();
pinMode(button,INPUT_PULLUP);
pinMode(buttond,INPUT_PULLUP);
pinMode(buttont,INPUT_PULLUP);
pinMode(buttonq,INPUT_PULLUP);
      display1.setBrightness(0x0f);// set brightness of dispaly 1
  display1.setSegments(data);// fill display 1 with whatever data[] array has

  while(!Serial);  // wait for Serial port to connect.
  Serial.println("Filesystem datalogger\n");
}


void loop () {

 char letter[5];
 
  int n;
   byte indx = 0;
    int n_p1=0;
    int n_p2=0;
  int n_p3=0;
  int n_p4=0;
   while(true){
    //////////////////////////
       indx = 0;
File myFile = FileSystem.open("/www/compteur.txt"); // open the file for reading
  if (myFile) { 
    while (myFile.available()) { //execute while file is available
     letter[ indx ] = myFile.read(); //read next character from file
     letter[ indx+1 ] = 0;
      indx ++; 
         n = atoi(letter);
      delay(300);
      
    }
    myFile.close(); //close file
  }
     n_p1=n;   
    Serial.println(n);
    //////////////////////////////////////////////////////////
     indx = 0;
  File myFilee = FileSystem.open("/www/compterpost2.txt"); // open the file for reading
  if (myFilee) { 
    while (myFilee.available()) { //execute while file is available
     letter[ indx ] = myFilee.read(); //read next character from file
     letter[ indx+1 ] = 0;
      indx ++; 
         n = atoi(letter);
      delay(300);
      
    }
    myFilee.close(); //close file
  }
 n_p2=n;   
    Serial.println(n);
    /////////////////////////////////////////////////////////
 indx = 0;
   File myFil = FileSystem.open("/www/compterpost3.txt"); // open the file for reading
  if (myFil) { 
    while (myFil.available()) { //execute while file is available
     letter[ indx ] = myFil.read(); //read next character from file
     letter[ indx+1 ] = 0;
      indx ++; 
         n = atoi(letter);
      delay(300);
      
    }
    myFil.close(); //close file
  }
     n_p3=n;   
    Serial.println(n);
    /////////////////////////////////////////////////////////////////////////
     indx = 0;
     File myFi = FileSystem.open("/www/compterpost4.txt"); // open the file for reading
  if (myFi) { 
    while (myFi.available()) { //execute while file is available
     letter[ indx ] = myFi.read(); //read next character from file
     letter[ indx+1 ] = 0;
      indx ++; 
         n = atoi(letter);
      delay(300);
      
    }
    myFi.close(); //close file
  }
    n_p4=n;   
    Serial.println(n);
 display1.setSegments(data); // clear the screen from previous values   
      display1.showNumberDec(n_p1);// display the count 
   }
}
