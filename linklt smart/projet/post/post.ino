#include <FileIO.h>
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

  while(!Serial);  // wait for Serial port to connect.
  Serial.println("Filesystem datalogger\n");
}


void loop () {

char filename[] = "/www/compteur.txt";
    buttonState5 = digitalRead(button);
 if (buttonState5 != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState5 == LOW)
    {
      buttonPushCounter++;
      
  File dataFile = FileSystem.open(filename, FILE_WRITE);
     filename[4] = buttonPushCounter / 100 + '0';
      filename[5] = ( buttonPushCounter / 10 ) % 10 + '0';
      filename[6] = buttonPushCounter % 10 + '0';
    dataFile.println(buttonPushCounter);
    dataFile.close();
    Serial.println(buttonPushCounter);
  delay(500);

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
      buttonPushCounterd++;
      
  File dataFilee = FileSystem.open(filenamee, FILE_WRITE);
     filenamee[4] = buttonPushCounterd / 100 + '0';
      filenamee[5] = ( buttonPushCounterd / 10 ) % 10 + '0';
      filenamee[6] = buttonPushCounterd % 10 + '0';
    dataFilee.println(buttonPushCounterd);
    dataFilee.close();
    Serial.println(buttonPushCounterd);
  delay(500);

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
      buttonPushCountert++;
      
  File dataFil = FileSystem.open(filenam, FILE_WRITE);
     filenam[4] = buttonPushCountert / 100 + '0';
      filenam[5] = ( buttonPushCountert / 10 ) % 10 + '0';
      filenam[6] = buttonPushCountert % 10 + '0';
    dataFil.println(buttonPushCountert);
    dataFil.close();
    Serial.println(buttonPushCountert);
  delay(500);

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
      buttonPushCounterq++;
      
  File data = FileSystem.open(fil, FILE_WRITE);
     fil[4] = buttonPushCounterq / 100 + '0';
      fil[5] = ( buttonPushCounterq / 10 ) % 10 + '0';
      fil[6] = buttonPushCounterq % 10 + '0';
    data.println(buttonPushCounterq);
    data.close();
    Serial.println(buttonPushCounterq);
  delay(500);

}
  // if the file isn't open, pop up an error:
  lastButtonStateq = buttonStateq;

 }

}
