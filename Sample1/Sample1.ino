int  LED = 13;
void setup() {
  pinMode(13, OUTPUT);

}

void loop() {
 digitalWrite(LED, HIGH);
 delay(2000);
 digitalWrite(LED, LOW);
 delay(2000);

}
