#include <FileIO.h>
#include <TM1637Display.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h> 

SoftwareSerial mySoftwareSerial(14,15 ); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
int num_t=311;
int t1=1,t2=1;
int tt=100;
int n1=0,n2=0,n3=0,n4=0;

#define button 23
#define buttond 22
#define buttont 21
#define buttonq 20
int buttonState5 = 0;         // current state of the button
int lastButtonState = 0;

int buttonStated = 0;         // current state of the button
int lastButtonStated = 0;

int buttonStatet = 0;         // current state of the button
int lastButtonStatet = 0;

int buttonStateq = 0;         // current state of the button
int lastButtonStateq = 0;  


#define CLK1 2
#define DIO1 3

// Module 2 connection pins (Digital Pins)
#define CLK2 4
#define DIO2 5

#define CLK3 6
#define DIO3 7

#define CLK4 8
#define DIO4 9

#define TEST_DELAY   300
TM1637Display display1(CLK1, DIO1);// define dispaly 1 object
TM1637Display display2(CLK2, DIO2);// define dispaly 1 object
TM1637Display display3(CLK3, DIO3);// define dispaly 1 object
TM1637Display display4(CLK4, DIO4);// define dispaly 1 object

   uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 };  // all segments clear 
boolean premiereFois = false;
boolean deuxiemeFois = false;
boolean  troisFois = false;
boolean quatreFois = false;

void setup() {


  // Bridge takes about two seconds to start up
  // it can be helpful to use the on-board LED
  // as an indicator for when it has initialized
    FileSystem.begin();
pinMode(button,INPUT_PULLUP);
pinMode(button,INPUT_PULLUP);
pinMode(buttond,INPUT_PULLUP);
pinMode(buttont,INPUT_PULLUP);
pinMode(buttonq,INPUT_PULLUP);
  Bridge.begin();
    Serial.begin(9600);


   // Robojax.com two or more TM1637 Display 20181029  
  display1.setBrightness(0x0f);// set brightness of dispaly 1
  display2.setBrightness(0x0f);// set brightness of dispaly 1  
  display3.setBrightness(0x0f);// set brightness of dispaly 1  
   display4.setBrightness(0x0f);// set brightness of dispaly 1  

  display1.setSegments(data);// fill display 1 with whatever data[] array has
  display2.setSegments(data);// // fill display 2 with whatever data[] array has 
  display3.setSegments(data);// fill display 1 with whatever data[] array has
  display4.setSegments(data);// fill display 1 with whatever data[] array has

 
  mySoftwareSerial.begin(9600) ;

  myDFPlayer.begin(mySoftwareSerial) ;
    
  myDFPlayer.setTimeOut(500); //Set serial communictaion time out 500ms
  myDFPlayer.volume(30);  //Set volume value (0~30).
  myDFPlayer.EQ(DFPLAYER_EQ_CLASSIC);
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
}

void fct_a(){

  atend:
do{
}
  while(! myDFPlayer.available());
  if(myDFPlayer.readType()==DFPlayerPlayFinished)
  {
      myDFPlayer.pause();
//    myDFPlayer.readType()=x;
   
  }    
    delay(1500);
}
void loop() {
 char letter[5];
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
         n1 = atoi(letter);
     
      
    }
    myFile.close(); //close file
  }
  if((n_p1>n1)||(n_p1<n1)){
   premiereFois = false;
}
     n_p1=n1;   
     if((n_p1>=1000)||(n_p1==0)){
  n_p1=0;
   premiereFois = true;
}
 display1.setSegments(data); // clear the screen from previous values   
      display1.showNumberDec(n_p1);// display the count 
    if (!premiereFois){
 appel(1,n_p1);
  premiereFois = true;
}




      
    //////////////////////////////////////////////////////////
     indx = 0;
  File myFilee = FileSystem.open("/www/compterpost2.txt"); // open the file for reading
  if (myFilee) { 
    while (myFilee.available()) { //execute while file is available
     letter[ indx ] = myFilee.read(); //read next character from file
     letter[ indx+1 ] = 0;
      indx ++; 
         n2 = atoi(letter);
      
      
    }
    myFilee.close(); //close file
  }
  if((n_p2>n2)||(n_p2<n2)){
   deuxiemeFois = false;
}
 n_p2=n2; 
if((n_p2>=1000)||(n_p2==0)){
  n_p2=0;
     deuxiemeFois = true;

}
              display2.setSegments(data); // clear the screen from previous values   
      display2.showNumberDec(n_p2);// display the count  
     if (!deuxiemeFois){
 appel(2,n_p2);
  deuxiemeFois = true;
}    
    /////////////////////////////////////////////////////////
 
indx = 0;
   File myFil = FileSystem.open("/www/compterpost3.txt"); // open the file for reading
  if (myFil) { 
    while (myFil.available()) { //execute while file is available
     letter[ indx ] = myFil.read(); //read next character from file
     letter[ indx+1 ] = 0;
      indx ++; 
         n3 = atoi(letter);
    
    }
    myFil.close(); //close file
  }
 if((n_p3>n3)||(n_p3<n3)){
    troisFois = false;
}
     n_p3=n3;  
    if((n_p3>=1000)||(n_p3==0)){
  n_p3=0;
      troisFois = true;

}
       display3.setSegments(data); // clear the screen from previous values   
      display3.showNumberDec(n_p3);// display the count 
       if (! troisFois){
 appel(3,n_p3);
      Serial.print("3 , ");
   //   Serial.println(n_p3);
  troisFois = true;
}
    /////////////////////////////////////////////////////////////////////////
     indx = 0;
     File myFi = FileSystem.open("/www/compterpost4.txt"); // open the file for reading
  if (myFi) { 
    while (myFi.available()) { //execute while file is available
     letter[ indx ] = myFi.read(); //read next character from file
     letter[ indx+1 ] = 0;
      indx ++; 
         n4 = atoi(letter);
   
      
    }
    myFi.close(); //close file
  }
      if((n_p4>n4)||(n_p4<n4)){
   quatreFois = false;
}
    n_p4=n4;  
    if((n_p4>=1000)||(n_p4==0)){
  n_p4=0;
     quatreFois = true;

}
        display4.setSegments(data); // clear the screen from previous values   
      display4.showNumberDec(n_p4);// display the count 
    if (!quatreFois){
      appel(4,n_p4);
  quatreFois = true;
}

      

char filename[] = "/www/compteur.txt";
    buttonState5 = digitalRead(button);
 if (buttonState5 != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState5 == LOW)
    {
      n_p1++;


  File dataFile = FileSystem.open(filename, FILE_WRITE);
     filename[4] = n_p1 / 100 + '0';
      premiereFois = false;

      filename[5] = ( n_p1 / 10 ) % 10 + '0';
      filename[6] = n_p1 % 10 + '0';
    dataFile.println(n_p1);
    dataFile.close();
 

}
  // if the file isn't open, pop up an error:
  lastButtonState = buttonState5;

 }
 
char filenamee[] = "/www/compterpost2.txt";
    buttonStated = digitalRead(buttond);
 if (buttonStated != lastButtonStated) {
    // if the state has changed, increment the counter
    if (buttonStated == LOW)
    {
      n_p2++;
 deuxiemeFois = false;
  File dataFilee = FileSystem.open(filenamee, FILE_WRITE);
     filenamee[4] = n_p2 / 100 + '0';
      filenamee[5] = ( n_p2 / 10 ) % 10 + '0';
      filenamee[6] = n_p2 % 10 + '0';
    dataFilee.println(n_p2);
    dataFilee.close();



}
  // if the file isn't open, pop up an error:
  lastButtonStated = buttonStated;

 }
char filenam[] = "/www/compterpost3.txt";
    buttonStatet = digitalRead(buttont);
 if (buttonStatet != lastButtonStatet) {
    // if the state has changed, increment the counter
    if (buttonStatet == LOW)
    {
      n_p3++;
   troisFois = false;
  File dataFil = FileSystem.open(filenam, FILE_WRITE);
     filenam[4] = n_p3 / 100 + '0';
      filenam[5] = ( n_p3 / 10 ) % 10 + '0';
      filenam[6] = n_p3 % 10 + '0';
    dataFil.println(n_p3);
    dataFil.close();
 


}
  // if the file isn't open, pop up an error:
  lastButtonStatet = buttonStatet;

 }
 char fil[] = "/www/compterpost4.txt";
    buttonStateq = digitalRead(buttonq);
 if (buttonStateq != lastButtonStateq) {
    // if the state has changed, increment the counter
    if (buttonStateq == LOW)
    {
      n_p4++;
quatreFois = false;
  File data = FileSystem.open(fil, FILE_WRITE);
     fil[4] = n_p4 / 100 + '0';
      fil[5] = ( n_p4 / 10 ) % 10 + '0';
      fil[6] = n_p4 % 10 + '0';
    data.println(n_p4);
    data.close();
    
 
}
  // if the file isn't open, pop up an error:
  lastButtonStateq = buttonStateq;

 }





  delay(100);
   
}
}
void appel(uint8_t g_nb, int value){

int s=(value / 100) % 10;
int d=(value / 10) % 10;
int u=(value / 1) % 10;

myDFPlayer.playFolder(1,150); 
fct_a();
delay(2000);
myDFPlayer.playFolder(1, 21); 
fct_a();
 delay(t2);
if (s!=0)
{
  s=s+100;
myDFPlayer.playFolder(1, s); 
fct_a();
 delay(t1);
if(value % 100!=0){
  myDFPlayer.playFolder(1, 22); 
fct_a();
 delay(t1);
}
}

if(u==1&d==1)
{
   myDFPlayer.playFolder(1, 111); 
fct_a();
}else
{
if (u!=0)
{
 myDFPlayer.playFolder(1, u); 
  if (d==1)
{
delay(800);
}
 
 if (d!=1)
{
fct_a();
}else
 {delay(tt);
 }
}
if (d!=0)
{
if (u!=0 && d!=1)
{
  myDFPlayer.playFolder(1, 22); 
fct_a();  
}
d=d+10;
 myDFPlayer.playFolder(1, d); 
fct_a();
}
}
 //delay(t2);
   myDFPlayer.playFolder(1, 23); 
fct_a();
 delay(t2);
 myDFPlayer.playFolder(1, g_nb); 
delay(600);
 // myDFPlayer.pause();

}
