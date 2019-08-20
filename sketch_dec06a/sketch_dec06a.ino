int pwm_f = 3;
int pwm_r = 5; 
int pwm_l = 8;
int pwm_b = 10;


void setup() {
  // put your setup code here, to run once:
pinMode(pwm_f, OUTPUT);
pinMode(pwm_r, OUTPUT);
pinMode(pwm_l, OUTPUT);
pinMode(pwm_b, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(pwm_f , HIGH);
digitalWrite(pwm_r , HIGH);
digitalWrite(pwm_l , HIGH);
digitalWrite(pwm_b , HIGH);

delay(1000);

digitalWrite(pwm_f , LOW);
digitalWrite(pwm_r , LOW);
digitalWrite(pwm_l , LOW);
digitalWrite(pwm_b , LOW);

delay(1000);
}
