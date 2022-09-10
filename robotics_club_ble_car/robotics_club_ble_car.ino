#include <SoftwareSerial.h>

//initializing software serial
SoftwareSerial SerialBT(3,4);

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
  pinMode(mL1,OUTPUT);
  pinMode(mL2,OUTPUT);
  
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
    switch(data){
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
    }
    
  }
}

/*
void waste(data){
  if(data == 'F' && data != 'B'){
      
    }
    else if(data == 'B' && data != 'F' ){
      Backward();
    }
    else if(data == 'L' && data != 'R'){
      Left();
    }
    else if(data == 'R'  && data != 'L'){
      Right();
    }
    else if(data != 'B' && data != 'L' && data != 'R' && data != 'F'){
      Stop();
    }
}
*/
