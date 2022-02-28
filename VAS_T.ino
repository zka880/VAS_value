int pres = 1023;    // Value of Pressure sensor (High:0 - Low:1023)

void setup()
{
  pinMode(7, OUTPUT);
  Serial.begin(9600); 
}


void loop()
{
  pres = analogRead(1); // Read from Analog1 (Pressure 0-1023)
  //sp=analogRead(3);
  Serial.println(pres, DEC); // Send data to MATLAB for online feedback
  if(Serial.available()>0)
   { 
    switch (Serial.read())
    {
      case '1':
         digitalWrite(7,HIGH);
         delay(98);
         digitalWrite(7,LOW);
         break;
      case '0':
         digitalWrite(7,LOW);
         delay(98);
         break;
      default:
         delay(98);
         break;
    }
   }
  //delay(98);        // Wait 100ms for next measurement
}
