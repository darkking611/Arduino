  const int ledPin=13;
  int blinkRate=0;

void setup() {Serial.begin(9600);
pinMode(ledPin,OUTPUT);


}

void loop() {
  if(Serial.available())
  {
    char ch=Serial.read();
    if(ch>='0'&&ch<='9')
    {
      blinkRate=(ch-'0');
      blinkRate=blinkRate*1000;
      
    }
  }
blink();
}

void blink()
{
  digitalWrite(ledPin,HIGH);
  delay(blinkRate);
  digitalWrite(ledPin,LOW);
  delay(blinkRate);
}

