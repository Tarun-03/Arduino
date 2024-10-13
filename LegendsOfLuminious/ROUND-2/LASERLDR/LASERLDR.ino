const int buzzer = 13;

const int ldrPin = 3;

void setup() {

Serial.begin(9600);

pinMode(buzzer, OUTPUT);

pinMode(ldrPin, INPUT);

}

void loop() {

int ldr = digitalRead(ldrPin);
Serial.println(ldr);
if(ldr == 1){
  digitalWrite(buzzer, HIGH);
  delay(300);
}
else{
  digitalWrite(buzzer, LOW);
}

}


