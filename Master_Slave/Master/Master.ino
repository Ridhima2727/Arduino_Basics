#include <Wire.h>
#define Led_Pin 13
#define Button_Pin 12
int Current_Millis = 0;
int Button_Count=0;
unsigned int Prev_Millis = 0;
const int Interval = 500;
const int Prev_Button = 0;
const int Button_Interval = 50;
byte Current_State = LOW;
byte Current_Button_State=HIGH;
byte Prev_Led_State=LOW;


void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
  pinMode(Led_Pin, OUTPUT);
  pinMode(Button_Pin, INPUT_PULLUP);
}

void Read_Button()
{
  if (Current_Millis - Prev_Button >= Button_Interval)
  {
    Current_Button_State=digitalRead(Button_Pin);
    if (Current_Button_State ==LOW and Prev_Led_State==LOW)
    {
      Prev_Led_State=HIGH;
      Wire.beginTransmission(1);
      Wire.write(1);
      Wire.endTransmission(1);
    }
    else if (Current_Button_State ==LOW and Prev_Led_State==HIGH)
    {
      Prev_Led_State=LOW;
      Wire.beginTransmission(1);
      Wire.write(0);
      Wire.endTransmission(1);
    }
  }
}
 void Led_Blink()
{
  Current_Millis = millis();
  if (Current_Millis - Prev_Millis >= Interval)
  {
    Current_State = !Current_State;
    digitalWrite(Led_Pin, Current_State);
    Prev_Millis += Interval;
  }
}

void loop()
{
  Led_Blink();
  Read_Button();
}
