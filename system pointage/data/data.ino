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
byte pin_rows[ROW_NUM] = {0, 8, 7, 6}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );
//
 unsigned long TSec=1000;
unsigned long Num_ms, Num_sec,Num_min; 
unsigned long Num_heur,Num_jour, Temps_ms; 
//
int pos = 0;
int a=0;
int b=0;
int w=0;

void setup(){
  myservo.attach(1);// 1 esm el pin 
 lcd.init(); // initialisation de l’afficheur
 lcd.clear();
 lcd.backlight(); // active le rétro-éclairage6

pinMode(A3,OUTPUT);
}

void loop(){
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
lcd.clear();
     lcd.setCursor(0, 0); // se positionner à la première ligne
  lcd.print("welcome fiki");
  tone(A3, 1200, 100);
openn();
  delay(2000);
  
closee();
  //stop le moteur
  lcd.clear();
  code="";
  }
    if (code=="3333") {
      w=w+1;
      if(w==1){ 
lcd.clear();
     lcd.setCursor(0,0); // se positionner à la première ligne
  lcd.print("welcome wassim");
openn();
  tone(A3, 1200, 100);
  delay(2000);
closee();
  //stop le moteur
  lcd.clear();
  code="";
  }
  if(w==2){
      tone(A3, 1200, 100);
      lcd.clear();
        lcd.setCursor(0, 0); // se positionner à la première ligne
  lcd.print("by wassim travail:");
  delay(2000);
  lcd.clear();
 
  w=0;    
  }
  }
   if (code=="1111"){
    a=a+1;
    if(a==1){
  Temps_ms=millis();  // 2^32 secondes = 49.71 jours  
TSec=1000;
  // Calcul des secondes  
  Num_sec= (Temps_ms/TSec)%60;


  // Calcul des minutes  
  Num_min= (Temps_ms/(TSec*60))%60;

  // Calcul des heures  
  Num_heur= (Temps_ms/(TSec*3600))%60;
    lcd.clear();
     lcd.setCursor(0, 0); // se positionner à la première ligne
  lcd.print("welcome aziz"); 
  tone(A3, 1200, 100);
      //le moteur tourne pour ouvrir la porte
openn();
 
  delay(2000);
   lcd.clear();
closee();
}
 if(a==2){
  Temps_ms=millis();  // 2^32 secondes = 49.71 jours  

  // Calcul des secondes  
  Num_sec= (Temps_ms/TSec)%60;


  // Calcul des minutes  
  Num_min= (Temps_ms/(TSec*60))%60;

  // Calcul des heures  
  Num_heur= (Temps_ms/(TSec*3600))%60;
   tone(A3, 1200, 100);
      lcd.clear();
        lcd.setCursor(0, 0); // se positionner à la première ligne
  lcd.print("by aziz travail:");
  lcd.setCursor(0, 1);
  lcd.print(Num_heur);
    lcd.print(":");
    lcd.print(Num_min);
    lcd.print(":");
    lcd.print(Num_sec);
  delay(2000);
  lcd.clear();
 
  a=0;
    }
    if(a==0){
      Temps_ms=0;
      b=millis();
    }
    
  //stop le moteur
  lcd.clear();
  code="";
  }
    else {
       lcd.clear();
         lcd.print("code non valide");
         delay(2000);
        
         code="";
  } 
}

}
void closee(){
 for (pos = 0; pos <= 180; pos += 5) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
void openn(){
    for (pos = 180; pos >= 0; pos -= 5) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
