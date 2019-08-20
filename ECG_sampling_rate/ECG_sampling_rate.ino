
uint16_t lastreading_time;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(micros()-lastreading_time>=1000){
    lastreading_time = micros();
    uint16_t result = analogRead(A0);
    Serial.println(result); 
  }

}
