
  #define on_nasos_time 1000 * 10  // Время работы движка (1)
  #define off_nasos_time 1800 // Время, пока он не работает (0)
  boolean nasos_stat = 0; // хранение состояния
  unsigned long millis_nasos = millis(); // хранение времени
  int bt1;
  int motor = 10;
  boolean i =0;
  unsigned long nextTime = 0;

void setup() 
  {
  pinMode(A5, INPUT_PULLUP);
  Serial.begin(9600);
  pinMode(motor, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.print(millis());
   }

void loop() {
  if(millis() > millis_nasos){
    nasos_stat = !nasos_stat;
    Serial.print(nasos_stat);
    digitalWrite(6, 1);
    if(nasos_stat){
      millis_nasos = millis() + on_nasos_time;
  }
    else{
      millis_nasos = millis() + off_nasos_time;
      digitalWrite(6, 0);
    }
  }
  
  if (nextTime <= millis()) 
  {
    nextTime = (millis() + (unsigned long)24*60*60*1000); // через сколько будет включаться
    //Serial.print(millis());
    digitalWrite(motor, 1);
    delay(4000); // сколько по времени будет работать
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
