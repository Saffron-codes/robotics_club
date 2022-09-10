#include <SoftwareSerial.h>

//initializing software serial
SoftwareSerial SerialBT();

//right motor
int mr1 = 10;
int mr2 = 11;

//left motor
int ml1 = 12;
int ml2 = 13;


void setup() {
  // begin the communication between arduino and bluetooth module
  Serial.begin(38400);
  SerialBT.begin(38400);

  //right motor
  pinMode(mr1,OUTPUT);
  pinMode(mr2,OUTPUT);
  
  //left motor
  pinMode(ml3,OUTPUT);
  pinMode(ml4,OUTPUT);
  
}

void Stop(){
  
  //right motor 
  digitalWrite(mr1,HIGH); //MOTOR STOPS
  digitalWrite(mr2,HIGH);

  //left motor
  digitalWrite(ml1,HIGH);  //MOTOR STOPS
  digitalWrite(ml2,HIGH);
}

void Forward(){
  
  //right motor 
  digitalWrite(mr1,HIGH); //FORWARD
  digitalWrite(mr2,LOW);

  //left motor
  digitalWrite(ml1,HIGH);  //FORWARD
  digitalWrite(ml2,LOW);
  
}
void Backward(){
  //right motor 
  digitalWrite(mr1,LOW);  //BACKWARD
  digitalWrite(mr2,HIGH);

  //left motor
  digitalWrite(ml1,LOW);  //BACKWARD
  digitalWrite(ml2,HIGH);
}
void Left(){
  //right motor 
  digitalWrite(mr1,HIGH); //FORWARD
  digitalWrite(mr2,LOW);

  //left motor
  digitalWrite(ml1,LOW);  //BACKWARD
  digitalWrite(ml2,HIGH);
}
void Right(){
  //right motor 
  digitalWrite(mr1,LOW);  //BACKWARD
  digitalWrite(mr2,HIGH);

  //left motor
  digitalWrite(ml1,HIGH);  //FORWARD
  digitalWrite(ml2,LOW);
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
