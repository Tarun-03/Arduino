//SET-A

#include<Servo.h>
Servo servo;

int pA = D0;
int pB = D7;
int pC = D5;
int pD = D1;
int pE = D6;
int OrdF[5];
int OrdT[5] = {'A', 'B', 'C', 'D', 'E'};
int k = 0;
int x= 1;
int y = 1;
int z = 1;
int p = 1;
int q = 1;





void setup() {
  Serial.begin(9600);
  pinMode(pA, INPUT);
  pinMode(pB, INPUT);
  pinMode(pC, INPUT);
  pinMode(pD, INPUT);
  pinMode(pE, INPUT);
  delay(100);

  //Password Motor
  servo.attach(D4);
  servo.write(0);

}

void loop() {

  int pAD = digitalRead(pA);
  int pBD = digitalRead(pB);
  int pCD = digitalRead(pC);
  int pDD = digitalRead(pD);
  int pED = digitalRead(pE);

  if(k < 5){
    if((pAD == HIGH) && (x == 1)){
      OrdF[k] = 'A';
      k++;
      x = 0;
      Serial.println("first");
    } 
    if((pBD == HIGH) && (y == 1)){
      OrdF[k] = 'B';
      k++;
      y = 0;
      Serial.println("second");
    }
    if((pCD == HIGH) && (z == 1)){
      OrdF[k] = 'C';
      k++;
      z = 0;
      Serial.println("third");
    }
    if((pDD == HIGH) && (p == 1)){
      OrdF[k] = 'D';
      k++;
      p = 0;
      Serial.println("fourth");
    }
    if((pED == HIGH) && (q   == 1)){
      OrdF[k] = 'E';
      k++;
      q = 0;
      Serial.println("fifth");
    }
  }
  int count = 0;
  for(int i = 0; i<5; i++){
    if(OrdF[i] == OrdT[i]){
      count++;
    }

    if(count == 5){
      Serial.println("125462");
      int pos;
      for (pos = 0; pos <= 180; pos += 1) {  // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        servo.write(pos);
      delay(15);
      }
      delay(2000000);
    }
    else{
      
    }
  }


}
