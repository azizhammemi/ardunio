#include <VirtualWire.h>
int RF_RX_PIN = 11; // Broche DATA du récepteur à la pin
char message_recu[VW_MAX_MESSAGE_LEN];
int ledverte=2;
void setup()
{
  Serial.begin(9600);    
  vw_setup(2000);               // Transmission en Bits par seconde
  vw_set_rx_pin(RF_RX_PIN);     
  vw_rx_start();                // On démarre le récepteur.
  pinMode (ledverte, OUTPUT);
}

void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(buf, &buflen)) // Si un message est recu...
  {
    for (int i = 0; i < buflen; i++)
      {
        Serial.write(buf[i]); 
        message_recu[i] = buf[i];
      }
      message_recu[buflen] = '\0';
      Serial.println(""); 
  }
  String message = String(message_recu);
  if (message == "on"){
    digitalWrite (ledverte, HIGH);
  }
  else{
    digitalWrite (ledverte, LOW);
  }
  delay(1000);
}
