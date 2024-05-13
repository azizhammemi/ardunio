#define enablePin 8

#define ledpin3 12

 void setup() 
{
  Serial.begin(9600);                   // Begins Serial Communication with baud rate 9600  
  pinMode(ledpin3,OUTPUT);

  pinMode(enablePin, OUTPUT);
  delay(10);
  digitalWrite(enablePin, LOW);        //  (Pin 8 always LOW to receive value from Master)
}

void loop() 

{
  while (Serial.available())            //While having data at Serial port this loop executes
     {         
        int receive = Serial.parseInt();  // Reads the integer value sent from STM32
    
        if (receive == 2)                //Depending Upon Recieved value the corresponding LED is turned ON or OFF
        {
          digitalWrite(ledpin3,HIGH);
        }
      
        else
        {
         digitalWrite(ledpin3,LOW);
       
        }
     }
}
