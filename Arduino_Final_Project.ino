#include<Servo.h>
Servo myservo;
int pos = 0;
int angle = 0;
int value1, value2, value3, value4;

void setup()
{
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  //기본 설정을 해 줍니다.

  pinMode(12, OUTPUT);
}

void loop() {
  for (pos = 0; pos <= 90; pos += 1)
  {
    myservo.write(pos);
    delay(10);
    ultraSonicAll();
    angle=angle+1;
    //모터 회전을 설정합니다.
  }
  for (pos = 90; pos >= 0; pos -= 1)
  {
    myservo.write(pos);
    delay(10);
    ultraSonicAll();
    angle=angle-1;
    //모터 회전을 설정합니다.
  }
}

void ultraSonicAll() {
  value1 = ultraSonic(2, 5);
  value2 = ultraSonic(10, 8);
  value3 = ultraSonic(11, 7);
  value4 = ultraSonic(3, 6);
  
  if(value1 <= 10 || value2 <= 10 || value3 <= 10 || value4 <= 10) {
//    Serial.println("Sound Buzzer");
    tone(12, 261, 100);
  }
  
  Serial.print(ultraSonic(2, 5));
  Serial.print(",");
  Serial.print(ultraSonic(10, 8));
  Serial.print(",");
  Serial.print(ultraSonic(11, 7));
  Serial.print(",");
  Serial.print(ultraSonic(3, 6));
  Serial.print(",");
  Serial.print(-angle);
  Serial.print(".");
  //값을 화면에 출력합니다.
}


int ultraSonic(int trigPin, int echoPin) {
  unsigned long duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH,6000);
  int distance  = duration * 17 / 1000;
  if(distance >= 40 || distance == 0) {
    distance = 40;
  }
  return distance;
 //초음파 센서값을 측정합니다.
}
