#include "Arduino.h"
#include <SoftwareSerial.h>

int rxPin = 5;
int txPin = 6;
int statusPin = 7;

SoftwareSerial BTSerial(rxPin, txPin); // RX TX

char dataByte; //our variable where bluetooth dataByte is stored
char Status; //statusus of the bluetooth module

//right motor
int mR1 = 8;
int mR2 = 9;

//left motor
int mL1 = 10;
int mL2 = 11;


void setup() {
  
  BTSerial.begin(9600);
  Serial.begin(9600); // begin the communication between arduino and bluetooth module

  pinMode(statusPin,INPUT); //making the statusu pin as input
  
  //right motor
  pinMode(mR1, OUTPUT);
  pinMode(mR2, OUTPUT);

  //left motor
  pinMode(mL1, OUTPUT);
  pinMode(mL2, OUTPUT);

}

void Stop() {

  //right motor
  digitalWrite(mR1, LOW); //MOTOR STOPS
  digitalWrite(mR2, LOW);

  //left motor
  digitalWrite(mL1, LOW); //MOTOR STOPS
  digitalWrite(mL2, LOW);
}

void Forward() {

  //right motor
  digitalWrite(mR1, HIGH); //FORWARD
  digitalWrite(mR2, LOW);

  //left motor
  digitalWrite(mL1, HIGH); //FORWARD
  digitalWrite(mL2, LOW);

}
void Backward() {
  //right motor
  digitalWrite(mR1, LOW); //BACKWARD
  digitalWrite(mR2, HIGH);

  //left motor
  digitalWrite(mL1, LOW); //BACKWARD
  digitalWrite(mL2, HIGH);
}
void Left() {
  //right motor
  digitalWrite(mR1, HIGH); //FORWARD
  digitalWrite(mR2, LOW);

  //left motor
  digitalWrite(mL1, LOW); //BACKWARD
  digitalWrite(mL2, HIGH);
}
void Right() {
  //right motor
  digitalWrite(mR1, LOW); //BACKWARD
  digitalWrite(mR2, HIGH);

  //left motor
  digitalWrite(mL1, HIGH); //FORWARD
  digitalWrite(mL2, LOW);
}

void getData(){
  while(BTSerial.available()) {
    dataByte = BTSerial.read();
    Serial.write(dataByte);
  }
  
  while(Serial.available()){
    dataByte = Serial.read();
    BTSerial.write(dataByte);
  }
  Status = digitalRead(statusPin);
}

void loop() {
  getData();
  if (Serial.available()) {
    dataByte = Serial.read();
    Serial.write(dataByte);
  }
  if(Status ==1){
    switch (dataByte) {
      case 'F':
        Forward();
        break;

      case 'B':
        Backward();
        break;

      case 'R':
        Right();
        break;

      case 'L':
        Left();
        break;
        
      case 'S':
        Stop();
        break;
  }
  }else{
    Stop();
  }
}
