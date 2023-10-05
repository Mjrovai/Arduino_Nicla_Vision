 #include <SoftwareSerial.h>
 
  char estate;
  SoftwareSerial mySerial(10, 11); // RX, TX
 
  void setup()
  {
    Serial.begin(9600);
    mySerial.begin(9600); 

    pinMode(LED_BUILTIN, OUTPUT);
  }
 
  void loop()
  {
    if (mySerial.available())
    {          
      estate = mySerial.read();  
      Serial.print(estate);   
      digitalWrite(LED_BUILTIN, HIGH);  
    } 
    else
    { 
      digitalWrite(LED_BUILTIN, LOW); 
    }   
  }
