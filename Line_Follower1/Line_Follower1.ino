

/*F = Forward
  B = Backward
  L = Left
  R = Right
 */

//Forward and Backward
//------------------------ 
int dirF =  12;                                                                           
int dirB = 4;                                                                           
int pwmF = 13;                                                                  
int pwmB = 5;



//Left and right
//-----------------
int dirR =  10; 
int dirL = 6;
int pwmR = 11;
int pwmL = 3;


//Analog Pins
//---------------
const byte analogPinF = 0;
const byte analogPinR=1;
const byte analogPinL=2;

  
const byte junctionPulse = 7;
int readValF,positionValF,readValR,readValL,positionValR,positionValL;    
unsigned int junctionCount = 0,temp;
  
   
void setup() {
  pinMode(junctionPulse,INPUT);
  pinMode(12 , OUTPUT);
  pinMode(13 , OUTPUT);
  pinMode(4 , OUTPUT);
  pinMode(5 , OUTPUT);
  pinMode(10 , OUTPUT);
  pinMode(6 , OUTPUT);
  pinMode(11 , OUTPUT); 
  pinMode(3 , OUTPUT);

  digitalWrite(dirR , LOW);
  digitalWrite(dirL , HIGH);

  digitalWrite(dirF , LOW);
  digitalWrite(dirB , HIGH);

  Serial.begin(9600);
}



void loop()
{
  if(digitalRead(junctionPulse))
  {
    junctionCount++;
   }
    readValF = analogRead(analogPinF);   
    readValR = analogRead(analogPinR);  
    readValL = analogRead(analogPinL);  

  
   positionValF = ((float)readValF/921)*70;
   positionValR = ((float)readValR/921)*70;
   positionValL = ((float)readValL/921)*70;

  //Forward
  //-------------------------------
  if((positionValF>=25 && positionValF<=45)&& junctionPulse==temp)
  {
    Forward(150); 
  }

   //Left Or Right
   // -------------------------------
  else if(junctionPulse!=temp)
        {
          Forward(50);

          //Left
          //-----------------------------------
          if(positionValL>0)
          {
            while(positionValL<25&&positionValL>45)
            {
              Forward(50);
            }
            Wait();
            delay(100);
            Left();
          }
          //Right
          //---------------------------------          
          else if(positionValR>0)
          {
            while(positionValR<25&&positionValR>45)
            {
              Forward(50);
            }
            Wait();
            delay(100);
            Right();
          }
        }
   temp=junctionCount;     
   
}



void Forward(int pulseWidth){
digitalWrite(dirF , LOW);
digitalWrite(dirB , LOW);

analogWrite(pwmR , 0);
analogWrite(pwmL , 0);
analogWrite(pwmF , pulseWidth);
analogWrite(pwmB , pulseWidth);


  
}

void Backward(int pulseWidth){
digitalWrite(dirF , HIGH);
digitalWrite(dirB , HIGH);

analogWrite(pwmR , 0);
analogWrite(pwmL , 0);
analogWrite(pwmF , pulseWidth);
analogWrite(pwmB , pulseWidth);
  
}

void Right(){
  digitalWrite(dirR , LOW); 
  digitalWrite(dirL , HIGH);

  analogWrite(pwmF , 0);
analogWrite(pwmB , 0);
  analogWrite(pwmR , 150);
  analogWrite(pwmL , 150);
}

void Left(){
  digitalWrite(dirR , HIGH); 
  digitalWrite(dirL , LOW);
  
  analogWrite(pwmF , 0);
analogWrite(pwmB , 0);
  analogWrite(pwmR , 150);
  analogWrite(pwmL , 150);
}

void Wait(){
    analogWrite(pwmF , 0);
    analogWrite(pwmB , 0);
    analogWrite(pwmR , 0);
    analogWrite(pwmL , 0);
}

  


