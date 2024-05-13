#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h> 

SoftwareSerial mySoftwareSerial(14,15 ); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
int num_t=311;
int t1=1,t2=1;
int tt=580;

void setup() {

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


void loop()
{


 appel(2,num_t);
delay(5000);


  

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
if(num_t % 100!=0){
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
