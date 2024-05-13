#define enablePin 8

#define ledpin1 13

#define button1 3

 void setup() 

{

  Serial.begin(9600);                   // Begins Serial Communication with baud rate 9600  

  pinMode(ledpin1,OUTPUT);


  pinMode(button1,INPUT_PULLUP);
  pinMode(enablePin, OUTPUT);

  delay(10);

  digitalWrite(enablePin, LOW);        //  (Pin 8 always LOW to receive value from Master)

}


void loop() 


{

   int button1val = digitalRead(button1);         //Reads the status of the Push Button

 

    if (button1val == LOW)

    {
  digitalWrite(enablePin, HIGH);        //  (Pin 8 always LOW to receive value from Master)

      
     Serial.print(button1val);  
      Serial.println("i");                //Sends Push button value 1 if HIGH (Pressed) 

    }
   else

   {
  digitalWrite(enablePin, LOW);        //  (Pin 8 always LOW to receive value from Master)


Serial.print(button1val); 
                  //Sends 0 if any of push button is not pressed

   }

  while (Serial.available())            //While having data at Serial port this loop executes

     {         

        int receive = Serial.parseInt();  // Reads the integer value sent from STM32

    

        if (receive == 1)                //Depending Upon Recieved value the corresponding LED is turned ON or OFF

        {

          digitalWrite(ledpin1,HIGH);

        }

    
        else

        {

         digitalWrite(ledpin1,LOW);

       

        }

     }

}
