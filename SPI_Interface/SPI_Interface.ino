//Include the SPI Library
#include <SPI.h>

//Set the Slac=ve Select Pin
//Other SPI Pins are set automatically
int SS1 = 10;

void setup()
{
  //Set SS Pin Directions 
  //Others are handled automatically
  pinMode(SS1,OUTPUT);

  //Initialise SPI
  SPI.begin();
}

//A func to set LED to a certain level
void setLed(int reg,int level)
{
  digitalWrite(SS,LOW);
  SPI.transfer(reg);
  SPI.transfer(level);
  digitalWrite(SS1,HIGH);
}
void loop()
{
  for (int i=0;i<=2;i++)
  {
    for(int j=50;j<=255;j++)
    {
      setLed(i,j);
      delay(20);
    }
    delay(500);
    for (int j=255;j>=50;j--)
    {
      setLed(i,j);
      delay(20);
    }
  }
}
