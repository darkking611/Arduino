
#define WREN 6
#define WRDI 4
#define RDSR 5
#define WRSR 1
#define READ 3
#define WRITE 2

#define sse 9
#define sss 10
#define MOSI 11
#define MISO 12
#define SCK 13
uint8_t spi_transfer( uint8_t data){
   for(int i=7; i>=0;i--)
   {
     SPDR = (1>>SPDR);
     SPDR = (data<<i);
     
     
     data = (data<<1);
     data = (i>>SPDR);
     //Serial.println(data,BIN);
     Serial.println(SPDR,BIN);
     //asm volatile("nop");
   }  
   //Serial.print(data);
  // Serial.print("\t");
  // Serial.println(SPDR);
   asm volatile("nop");
   
   
   while(!(SPSR & _BV(SPIF)))
   {
    Serial.println("ipi");
   };
   
   

   
   return SPDR;
 
}

void Master_init()
{
  pinMode(SCK, OUTPUT);
  pinMode(MOSI, INPUT);
  pinMode(MISO, OUTPUT);
  pinMode(sse,OUTPUT);
  pinMode(sss,OUTPUT);
  digitalWrite(sse,HIGH);
  digitalWrite(sss,HIGH);
  SPCR = (1<<SPE)|(1<<MSTR)|(1<<CPOL)|(1<<CPHA)|(1<<SPR0);

  SPSR &= ~(1<<SPI2X);
}

uint8_t eeprom_read(uint32_t e_addr)
{
  uint8_t read_data;
  digitalWrite(sse,LOW);
  spi_transfer(READ);
  spi_transfer((uint8_t(e_addr)>>24)&0xff);
  spi_transfer(uint8_t(e_addr>>16)&0xFF);
  //spi_transfer(uint8_t (e_addr));
  read_data=spi_transfer(0x00);
  digitalWrite(sse,HIGH);
  return read_data;    
}

void eeprom_write(uint32_t e_addr,uint8_t data)
{
  digitalWrite(sse,LOW);

  spi_transfer(WREN);
 
  digitalWrite(sse,HIGH);
  digitalWrite(sse,LOW);
  spi_transfer(WRITE); 
  spi_transfer((uint8_t(e_addr)>>24)&0xff);
  spi_transfer(uint8_t(e_addr>>16)&0xff);
  //spi_transfer(uint8_t (e_addr));
  spi_transfer(data);
  digitalWrite(sse,LOW);
}


uint8_t sram_read(uint32_t s_addr)
{ uint8_t read_data;
  digitalWrite(sss,LOW);
  spi_transfer(READ);
  spi_transfer(((s_addr)>>8)&0xff);
  spi_transfer(uint8_t(s_addr)&0xff);
  spi_transfer(uint8_t (s_addr));
  read_data=spi_transfer(0x00);
  digitalWrite(sss,HIGH);

  return read_data;    
}

void sram_write(uint32_t s_addr,uint8_t data)
 { digitalWrite(sss,LOW);
   
  spi_transfer(WRITE); 
  Serial.println(spi_transfer(((s_addr)>>24)));
  Serial.println(spi_transfer(uint8_t(s_addr>>16)&0xff));
  Serial.println(spi_transfer(uint8_t (s_addr)));
  Serial.println(spi_transfer(data));
  digitalWrite(sss,HIGH);

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Master_init();
  uint8_t e_val;
  uint8_t out_data;
  uint8_t in_data=94;
  uint32_t s_addr=29;
  uint32_t e_addr=40;
  eeprom_write(e_addr, (uint8_t)89);
  delay(50);
  e_val=eeprom_read(e_addr);
  Serial.println(e_val);
 

}

void loop() {
  // put your main code here, to run repeatedly:

}
