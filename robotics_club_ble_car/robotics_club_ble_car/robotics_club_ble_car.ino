#include <SoftwareSerial.h>

//initializing software serial
SoftwareSerial SerialBT();

//right motor
int mR1 = 10;
int mR2 = 11;

//left motor
int mL1 = 12;
int mL2 = 13;


void setup() {
  // begin the communication between arduino and bluetooth module
  Serial.begin(38400);
  SerialBT.begin(38400);

  //right motor
  pinMode(mR1,OUTPUT);
  pinMode(mR2,OUTPUT);
  
  //left motor
  pinMode(mL3,OUTPUT);
  pinMode(mL4,OUTPUT);
  
}

void Stop(){
  
  //right motor 
  digitalWrite(mR1,HIGH); //MOTOR STOPS
  digitalWrite(mR2,HIGH);

  //left motor
  digitalWrite(mL1,HIGH);  //MOTOR STOPS
  digitalWrite(mL2,HIGH);
}

void Forward(){
  
  //right motor 
  digitalWrite(mR1,HIGH); //FORWARD
  digitalWrite(mR2,LOW);

  //left motor
  digitalWrite(mL1,HIGH);  //FORWARD
  digitalWrite(mL2,LOW);
  
}
void Backward(){
  //right motor 
  digitalWrite(mR1,LOW);  //BACKWARD
  digitalWrite(mR2,HIGH);

  //left motor
  digitalWrite(mL1,LOW);  //BACKWARD
  digitalWrite(mL2,HIGH);
}
void Left(){
  //right motor 
  digitalWrite(mR1,HIGH); //FORWARD
  digitalWrite(mR2,LOW);

  //left motor
  digitalWrite(mL1,LOW);  //BACKWARD
  digitalWrite(mL2,HIGH);
}
void Right(){
  //right motor 
  digitalWrite(mR1,LOW);  //BACKWARD
  digitalWrite(mR2,HIGH);

  //left motor
  digitalWrite(mL1,HIGH);  //FORWARD
  digitalWrite(mL2,LOW);
}

void loop() {
  if(SerialBT.available()) {
    char data = SerialBT.read();
    if(data == 'F'){
      Forward();
    }
    else if(data == 'B'){
      Backward();
    }
    else if(data == 'L'){
      Left();
    }
    else if(data == 'R'){
      Right();
    }
  }
}
