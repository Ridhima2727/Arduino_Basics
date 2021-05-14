#define LedPin_1 9
#define LedPin_2 6
#define LedPin_3 3
#define LedPin_4 11
#define ButtonPin 12

const int Interval_Led_1 = 500;
const int Interval_Led_2 = 1000;
const int Duration_On_Led_3 = 500;
const int Duration_Off_Led_3 = 3000;
const int Interval_Led_4 = 500;
const int Interval_Button = 50;

int Current_Millis = 0;
int Prev_Led_Millis_1 = 0;
int Prev_Led_Millis_2 = 0;
int Prev_Led_Millis_3 = 0;
int Prev_Led_Millis_4 = 0;
int Prev_Button = 0;
int No_Button_Press = 0;

byte Led_State_1 = LOW;
byte Led_State_2 = LOW;
byte Led_State_3 = LOW;
byte Led_State_4 = LOW;


void setup()
{
  Serial.begin(115200);
  pinMode(LedPin_1, OUTPUT);
  pinMode(LedPin_2, OUTPUT);
  pinMode(LedPin_3, OUTPUT);
  pinMode(LedPin_4, OUTPUT);
  pinMode(ButtonPin, INPUT_PULLUP);
  digitalWrite(LedPin_1, LOW);
  digitalWrite(LedPin_2, LOW);
  digitalWrite(LedPin_3, LOW);
  digitalWrite(LedPin_4, LOW);
}

void loop()
{
  Current_Millis = millis();
  updateLed_1_State();
  updateLed_2_State();
  updateLed_3_State();
  updateLed_4_State();
  Toggle_Leds();
  Read_Buttons();

}
void updateLed_1_State() {

  if (Led_State_1 == LOW) {
    if (Current_Millis - Prev_Led_Millis_1 >= Interval_Led_1) {
      Led_State_1 = HIGH;
      Prev_Led_Millis_1 += Interval_Led_1;
    }
  }
  else {
    if (Current_Millis - Prev_Led_Millis_1 >= Interval_Led_1) {
      Led_State_1 = LOW;
      Prev_Led_Millis_1 += Interval_Led_1;
    }
  }
}

void updateLed_2_State() {

  if (Led_State_2 == LOW) {
    if (Current_Millis - Prev_Led_Millis_2 >= Interval_Led_2) {
      Led_State_2 = HIGH;
      Prev_Led_Millis_2 += Interval_Led_2;
    }
  }
  else {
    if (Current_Millis - Prev_Led_Millis_2 >= Interval_Led_2) {
      Led_State_2 = LOW;
      Prev_Led_Millis_2 += Interval_Led_2;
    }
  }
}
void updateLed_3_State() {

  if (Led_State_3 == LOW) {
    if (Current_Millis - Prev_Led_Millis_3 >= Duration_Off_Led_3) {
      Led_State_3 = HIGH;
      Prev_Led_Millis_3 += Duration_Off_Led_3;
    }
  }
  else {
    if (Current_Millis - Prev_Led_Millis_3 >= Duration_On_Led_3) {
      Led_State_3 = LOW;
      Prev_Led_Millis_3 += Duration_On_Led_3;
    }
  }
}
void Read_Buttons() {
  if (Current_Millis - Prev_Button >= Interval_Button) {
    if (!digitalRead(ButtonPin)) {
      No_Button_Press++;
    }
    Prev_Button += Interval_Button;
  }
}
void updateLed_4_State() {
  if (No_Button_Press % 2 != 0) {
    if (Led_State_4 == LOW) {
      if (Current_Millis - Prev_Led_Millis_4 >= Interval_Led_4) {
        Led_State_4 = HIGH;
        Prev_Led_Millis_4 += Interval_Led_4;
      }
    }
    else {
      if (Current_Millis - Prev_Led_Millis_4 >= Interval_Led_4) {
        Led_State_4 = LOW;
        Prev_Led_Millis_4 += Interval_Led_4;
      }
    }
    No_Button_Press=0;
  }
  else{
    Led_State_4=LOW;
    Prev_Led_Millis_4 += Interval_Led_4;
    
  }
}
void Toggle_Leds() {
  digitalWrite(LedPin_1, Led_State_1);
  digitalWrite(LedPin_2, Led_State_2);
  digitalWrite(LedPin_3, Led_State_3);
  digitalWrite(LedPin_4, Led_State_4);
}
