void setup()
{
  //Create Serial Object
  Serial.begin(9600);//comm speed
}

void loop()
{
  //Have the arduino wait to receive input
  while(Serial.available()==0);

  //read the input
  int val = Serial.read()-'0'; //its sending chrand giving us decimal value '0'->48;'1'->49; therefore to read one we do '1'-'0'i.e.1

  //echo the input
  Serial.println(val);
}
