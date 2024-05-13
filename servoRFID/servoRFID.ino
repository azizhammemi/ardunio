

int buzzer = A3;


void setup() {

  pinMode(buzzer, OUTPUT);

}

void loop() {
 
    tone(buzzer, 1200, 100);
    delay(1000);
 
}
