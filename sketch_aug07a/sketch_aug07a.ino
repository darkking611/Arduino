const int led=13;
const int motor1=12;
const int motor2 =9;
const int led1=8;
const int led2=7;

void setup() {
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(9,OUTPUT);
pinMode(8,OUTPUT);
pinMode(7,OUTPUT);


}

void loop() {


  digitalWrite(led, HIGH);
  digitalWrite(led1,HIGH);
  digitalWrite(motor1,HIGH);
  delay(5000);
  digitalWrite(led1,LOW);
  digitalWrite(motor1,LOW);
  digitalWrite(led2,HIGH);
  digitalWrite(motor2,HIGH);
  delay(5000);
  digitalWrite(led2,LOW);
  digitalWrite(motor2,LOW);


}
