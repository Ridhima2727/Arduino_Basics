int motorPin = 8;

void setup()
{
  pinMode (motorPin,OUTPUT);
}

void loop()
{
  //Accelerate Motor from 0->255
  for (int i =0; i<=255; i++)
  {
    analogWrite(motorPin,i);
    delay(10);
  }

  //Hold at Top Speed
  delay(500);

  //Decrease Speed from 255->0
  for (int j=255 ; j>=0; j--)
  {
    analogWrite(motorPin,j);
    delay(10);
  }

  //Hold at zero
}
