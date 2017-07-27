#include<SoftwareSerial.h>
const int ml = 5;//give a pin to the motor
const int mr = 6;//give a pin to the motor
const int ml2 = 9;//give a pin to the motor
const int mr2 = 10;//give a pin to the motor
#define TxD 3
#define RxD 2
#define LED_PIN 13

SoftwareSerial bluetoothSerial(TxD, RxD);

char c;

void setup() {
  pinMode(ml, OUTPUT);//set motor as output
pinMode(mr, OUTPUT);//set motor as output
pinMode(ml2, OUTPUT);//set motor as output
pinMode(mr2, OUTPUT);//set motor as output
  bluetoothSerial.begin(9600);
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  }

void loop() {
  if(bluetoothSerial.available()){
    c = bluetoothSerial.read();
    Serial.println(c);
    if(c=='f'){
            digitalWrite(ml, HIGH);//left motor goes ahead
    digitalWrite(mr, HIGH);//right motor goes ahead
    digitalWrite(ml2, LOW);
    digitalWrite(mr2, LOW);}
    if(c=='b'){
      digitalWrite(ml2, HIGH);//left motor goes back
   digitalWrite(mr2, HIGH);//right motor goes back
   digitalWrite(ml, LOW);
   digitalWrite(mr, LOW);
    }
    if(c=='l'){
      digitalWrite(ml, LOW);
  digitalWrite(mr, HIGH);//right motor goes ahead
  digitalWrite(ml2, HIGH);//left motor goes back
  digitalWrite(mr2, LOW);
    }
    if(c=='r'){
      digitalWrite(ml, HIGH);//left motor goes ahead
  digitalWrite(mr, LOW);
  digitalWrite(ml2, LOW);
  digitalWrite(mr2, HIGH);//right motor goes back
    }
    if(c=='s'){
      digitalWrite(ml2, LOW);
   digitalWrite(mr2, LOW);
   digitalWrite(ml, LOW);
   digitalWrite(mr, LOW);
    }
  }
}

