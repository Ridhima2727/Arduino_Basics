#include<Wire.h>
#define Led2_Pin 11


void setup() 
{
  Wire.begin(1);
  pinMode(Led2_Pin,OUTPUT);
  Serial.begin(9600);
  Wire.onReceive(Led_Blink);
}
void Led_Blink()
{
  while(Wire.available())
  {
    int C=Wire.read();
    Serial.println(C);
    if (C==1)digitalWrite(Led2_Pin,HIGH);
    if (C==0)digitalWrite(Led2_Pin,LOW);
  }
}
