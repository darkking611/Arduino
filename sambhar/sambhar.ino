Slave_init()
{
  pinMode(SCK, OUTPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(MISO, INPUT);
  pinMode(sse,OUTPUT);
  pinMode(sss,OUTPUT);
  digitalWrite(sse,HIGH);
  digitalWrite(sss,HIGH);
  SPCR = (1<<SPE)

  SPSR &= ~(1<<SPI2X);
}

uint8_t slave_recieve()
{
  while(!(SPSR & ((1<<SPIF)));
  return SPDR;
}

void setup() {
  // put your setup code here, to run once:
  Slave_init();

}

void loop() {
  // put your main code here, to run repeatedly:

}
