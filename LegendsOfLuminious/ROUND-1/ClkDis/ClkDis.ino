const int trigPin = D0;
const int echoPin = D1;
#include <Servo.h>
Servo servo;
const int trigPin1 = D7;
const int echoPin1 = D8;

long duration;
int distance;
int K = 1;
int P = 1;
int M = 1;

long duration1;
int distance1;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  servo.attach(D2);
  servo.write(0);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(500);
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;
  Serial.print("Distance1: ");
  Serial.println(distance1);
  if(((distance >= 9)&&(distance <=11))&&(K == 1)){
    M++;
    K--;
  }
   if(((distance1 >= 5)&&(distance1 <=7))&&(P == 1)){
    M++;
    P--;
  }
  if(M == 2){
    for (int pos = 0; pos <= 180; pos += 1) { 
    servo.write(pos);
    delay(5);
  }
      M = M - 2;
  } 
  
}
