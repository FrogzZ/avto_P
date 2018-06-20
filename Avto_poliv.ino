
  int bt1;
  int motor = 10;
  boolean i =0;
  unsigned long nextTime = 0;

void setup() 
  {
  pinMode(A5, INPUT_PULLUP);
  Serial.begin(9600);
  pinMode(motor, OUTPUT);
   }

void loop() {

  if (nextTime <= millis()) 
  {
    nextTime = (millis() + (unsigned long)24*60*60*1000); // через сколько будет включаться
    Serial.print(millis());
    digitalWrite(motor, 1);
    delay(5000); // сколько по времени будет работать
  }
  
  boolean butA7 = !digitalRead(A5);
  //Serial.println(butA7);
  if (butA7 == 1) 
  {
    digitalWrite(10, 1);
    delay(10);
  }
  
  else  digitalWrite(10, 0);
  

  if (Serial.available())
  {
    bt1 = Serial.read();
    
    if (bt1 == '1')
      {
        digitalWrite(motor, HIGH);
        delay(2000);
      }
      
     if (bt1 == '0')
      {
        digitalWrite(motor, LOW);
      }
  }

}
