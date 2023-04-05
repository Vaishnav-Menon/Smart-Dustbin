#include <Servo.h>
Servo S1;

int ultrasonic(int trigPin, int echoPin)
{
  long duration;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  duration = duration/59;
  if((duration <2) || (duration >15)) return 0;
  return duration;
}

void setup ()
{
  Serial.begin(9600);
  digitalWrite(2, LOW);
  S1.attach(9);
}

void loop ()
{
  int a;
  a = ultrasonic(2,3);
  Serial.println(a);
  // delay(1000);

  if (a>2 && a<15){
    for(int angle=0;angle<=90;angle += 1){
      S1.write(angle);
      delayMicroseconds(10000000);
    }
  }

  delay(1000);
  
  if (a==0){
    for(int angle=90;angle>=0;angle-=1){
      S1.write(angle);
      // delayMicroseconds(1000000);
    }
  }
}