#include <VirtualWire.h> 
int RF_TX_PIN = 12; // Broche DATA de l'émeteur 
 
void setup()
{
  Serial.begin(9600);
  vw_set_tx_pin(RF_TX_PIN);
  vw_setup(2000); // Vitesse de transmission en Bits par secondes
  pinMode(2,INPUT_PULLUP);
}
 
void loop()
{
  const char *msg ;
  boolean etatBouton=digitalRead(2);
  if (etatBouton == 0) {
    msg = "on";
  }
  else {
    msg = "off";
  } 
  Serial.println(msg) ;
  vw_send((uint8_t *)msg, strlen(msg));  // Envoi le message ...
  delay(400); // ... toute les 400 millisecondes
}
