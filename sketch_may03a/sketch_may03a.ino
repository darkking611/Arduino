int led=9;
int brightness=0;
int sensor=0;
void setup() {
  pinMode(led,OUTPUT);
  

}

void loop() {
  int rate=analogRead(sensor);
  brightness=map(rate,200,800,0,255);
  analogWrite(led,brightness);
  delay(5000);
  brightness=0;
}
