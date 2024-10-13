


// Stage - 1
int a1;
int b11;
int b12;
int b13;
int b14;
int lev1;

//Stage - 2 -----------
int b21;
int b22;
int b23;
int c21;
int d21;
int d22;
int d23;
int lev2;


//Stage - 4 ----------------
int a41;
int a42;
int b41;
int lev4;

//Stage - 5 ----------------
int a51;
int a52;
int a53;
int a54;
int lev5;

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // Pin modes of 1 --------
  pinMode(6 , INPUT);
  pinMode(30 , INPUT);
  pinMode(31 , INPUT);
  pinMode(32 , INPUT);
  pinMode(33 , INPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);


  // Pin modes of 2 -------
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  
}

void loop() {

  //Stage - 1 -------------------
    a1 = digitalRead(6);
    b11 = digitalRead(30);
    b12 = digitalRead(31);
    b13 = digitalRead(32);
    b14 = digitalRead(33);
    //Serial.println(a1);

if(a1 != 1){
      digitalWrite(5, LOW);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);}
    
    if(a1 == 1){
      digitalWrite(5, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      if(b11 == 0){
        if(b14 == 0){
          if(b13 == 0){
            if(b12 == 0){
              lev1 = 1;
            }
          }
        }
      }
    }
    //Serial.println(lev1);

  // Stage 2 ---------------------------------------------------------------------
  b21 = (analogRead(A0))/98;
  b22 = (analogRead(A1))/98;
  b23 = (analogRead(A2))/98;
  c21 = (analogRead(A3))/98;
  d21 = digitalRead(8);
  d22 = digitalRead(9);
  d23 = digitalRead(10);
  Serial.print(b21);
  Serial.print(b22);
  Serial.print(b23);
  Serial.print(c21);
  //Serial.println();

  
  if((b21 == 8) && (b22 == 8) && (b23 == 6)&& (c21 == 7)){
    digitalWrite(22, HIGH); digitalWrite(23, HIGH); digitalWrite(24, HIGH);
    lcd.init();                      // initialize the lcd 
    lcd.init();
    // Print a message to the LCD.
    lcd.backlight();
    lcd.setCursor(3,0);
    lcd.print("Control   Rods");
    lcd.setCursor(2,1);
    lcd.print("Lifted Sucessfully");
    lcd.setCursor(0,2);
    lev2 = 1;
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
  }

  else{
    digitalWrite(22, LOW); digitalWrite(23, LOW); digitalWrite(24, LOW);
  }

  // Stage 4 ---------------------------------------------------------------------
  a41 = (analogRead(A4))/98;
  a42 = (analogRead(A5))/98;
  Serial.println(a42);
  if((a41 == 1) && (a42 == 4)){
    lev4 = 1;
  }

  //Stage 5 ---------------------------------------------------------
  a51 = digitalRead(2);
  a52 = digitalRead(3);
  a53 = digitalRead(4);
  a54 = digitalRead(5);
  if((a51 == 1) && (a52 == 1) && (a53 == 1) && (a54 == 1)){
    lev5 = 1;
  }
  
} 
