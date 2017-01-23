
int trigPin = 13;
int echoPin = 12;
int speakerpin = 8;
 
 
//시리얼 속도설정, trigPin을 출력, echoPin을 입력으로 설정
void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 

void loop(){
  float duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
 
  
  duration = pulseIn(echoPin, HIGH);


  distance = ((float)(340 * duration) / 10000) / 2;

  if (distance <=50.0)
  {
    tone(speakerpin,100,1000);  /
    delay(1000); 
 
  }
 
  //시리얼모니터에 Echo가 HIGH인 시간 및 거리를 표시해준다.
  Serial.print("Duration:");
  Serial.print(duration);
  Serial.print("\nDIstance:");
  Serial.print(distance);
  Serial.println("cm\n");
  delay(1000);
}

