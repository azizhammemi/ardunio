#include <TM1637Display.h>
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <LiquidCrystal_I2C.h> 
#include <Keypad.h>
#include <Servo.h>
Servo myservo;
const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //four columns
LiquidCrystal_I2C lcd(0x27, 20, 4);
char keys[ROW_NUM][COLUMN_NUM] = {
{'1','2','3', 'A'},
{'4','5','6', 'B'},
{'7','8','9', 'C'},
{'*','0','#', 'D'}
};
String code="";
byte pin_rows[ROW_NUM] = {A0,A1}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {A2,A3}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

#define CLK1 2
#define DIO1 3
#define CLK2 4
#define DIO2 5
#define CLK3 12
#define DIO3 13
#define TEST_DELAY   300
TM1637Display display1(CLK1, DIO1);// define dispaly 1 object
TM1637Display display2(CLK2, DIO2);// define dispaly 1 object
TM1637Display display3(CLK3, DIO3);
uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 }; 
const int touchPin = 7;
const int touchDelay = 500;
const int touchdeux = 8;
const int touchtrois = 11;
int count=0;// variable holding the count number
int lastButtonState = 0;
int lastButtonStatedeux = 0;
int lastButtonStatetrois = 0;

SoftwareSerial mySoftwareSerial(10,9); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
int count2=0;
int count3=0;
int t1=1,t2=1;
int tt=580;
int w=0;
int f=0;
int a=0;
int pos = 0;
void setup() {
 lcd.init(); // initialisation de l’afficheur
 lcd.clear();
 lcd.backlight(); // active le rétro-éclairage6
  myservo.attach(6);// 1 esm el pin 
    myservo.write(70);
  Serial.begin(9600);// initialize serial monitor with 9600 baud
  pinMode(touchPin,INPUT_PULLUP);// define a pin for touch module
    pinMode(touchdeux,INPUT_PULLUP);// define a pin for touch module
    pinMode(touchtrois,INPUT_PULLUP);// define a pin for touch module

  display1.setBrightness(0x0f);// set brightness of dispaly 1
  display1.setSegments(data);// fill display 1 with whatever data[] array has
  
   display2.setBrightness(0x0f);// set brightness of dispaly 1
  display2.setSegments(data);
    
     display3.setBrightness(0x0f);// set brightness of dispaly 1
  display3.setSegments(data);
   mySoftwareSerial.begin(9600);  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));
  
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
  if(myDFPlayer.readType()!=DFPlayerPlayFinished)
  {
//    myDFPlayer.readType()=x;
    goto atend;
    delay(1);
  }
  myDFPlayer.pause();
}

void loop() {
  // Robojax.com Touch counter 20181029
  lcd.setCursor(0, 0); // se positionner à la première ligne
  lcd.print("enter password");
char key = keypad.getKey();
if(key) // On appuie sur une touche du clavier matriciel
{
 lcd.setCursor(0, 1); // se positionner à la première ligne
code+=key;
lcd.print(code);  // Afficher le carctere saisie sur l'afficheur LCD

delay(100);
}
if ((code.length()==4)){

  if (code=="2222") { 
  f=f+1;
    if(f==1){
    lcd.clear();
     lcd.setCursor(0, 0); // se positionner à la première ligne
  lcd.print("welcome fki"); 
      //le moteur tourne pour ouvrir la porte
openn();
 
  delay(2000);
   lcd.clear();
closee();
}
 if(f==2){
      lcd.clear();
        lcd.setCursor(0, 0); // se positionner à la première ligne
  lcd.print("by fki :");
  lcd.setCursor(0, 1);
  delay(2000);
  lcd.clear();
  f=0;
    }
  }
   if (code=="1111"){
    a=a+1;
    if(a==1){
    lcd.clear();
     lcd.setCursor(0, 0); // se positionner à la première ligne
  lcd.print("welcome aziz"); 
      //le moteur tourne pour ouvrir la porte
openn();
 
  delay(2000);
   lcd.clear();
closee();
}
 if(a==2){
      lcd.clear();
        lcd.setCursor(0, 0); // se positionner à la première ligne
  lcd.print("by aziz :");
  lcd.setCursor(0, 1);
  delay(2000);
  lcd.clear();
  a=0;
    }
    }
  if (code=="4444") {
    w=w+1;
    if(w==1){
    lcd.clear();
     lcd.setCursor(0, 0); // se positionner à la première ligne
  lcd.print("welcome wassim"); 
      //le moteur tourne pour ouvrir la porte
openn();
 
  delay(2000);
   lcd.clear();
closee();
}
 if(w==2){
      lcd.clear();
        lcd.setCursor(0, 0); // se positionner à la première ligne
  lcd.print("by wassim :");
  lcd.setCursor(0, 1);
  delay(2000);
  lcd.clear();
  w=0;
    }
  }
   if (code=="11111"){
    }
    else {
       lcd.clear();
         lcd.print("attende");
         delay(2000);  
         code="";
  } 
  }
  int touchValue = digitalRead(touchPin);// read touchPin and store it in touchValue
 if (touchValue != lastButtonState) {
  // if touchValue is HIGH
  if(touchValue == LOW)
  {
          count++;// increment the count     
          display1.setSegments(data); // clear the screen from previous values   
      display1.showNumberDec(count);// display the count
    appel(1,count);

        
    delay(touchDelay);
  }
 }   
   int touchd =digitalRead(touchdeux);
  if (touchd != lastButtonStatedeux) {
  // if touchValue is HIGH
  if(touchd == LOW)
  {
      count2++;// increment the count   
          display2.setSegments(data); // clear the screen from previous values   
      display2.showNumberDec(count2);// display the count
    appel(2,count2);
        
    delay(touchDelay);
  }
 }
    int toucht =digitalRead(touchtrois);
  if (toucht != lastButtonStatetrois) {
  // if touchValue is HIGH
  if(toucht == LOW)
  {
         count3++;
           display3.setSegments(data); // clear the screen from previous values   
      display3.showNumberDec(count3);// display the count   
    appel(3,count3);
        
    delay(touchDelay);
  }
 }
lastButtonState = touchValue;
lastButtonStatedeux=touchd;
lastButtonStatetrois=toucht;
}
void closee(){
 for (pos = 0; pos <= 60; pos += 2) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
void openn(){
    for (pos = 60; pos >= 0; pos -= 2) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
void appel(uint8_t g_nb, int value){
int s=(value / 100) % 10;
int d=(value / 10) % 10;
int u=(value / 1) % 10;
Serial.println(s);
Serial.println(d);
Serial.println(u);
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
 if (d!=1)
{
fct_a();
}else
 {delay(tt);
 }
}
if (d!=0)
{
Serial.println("d");

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
// delay(t2);
 myDFPlayer.playFolder(1, g_nb); 
 // myDFPlayer.pause();
}
