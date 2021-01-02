#include <QTRSensors.h> // QTR Sensor
#include <NewPing.h>    //sonar sensor
#include <Servo.h>      //Servo motor
#include<Keypad.h>      //Keybrrd
#include "define.h"



void setup() {
Serial.begin(9600);

//--Color----------------------------------------------
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  
  
//other-----------------------------------------------
//beep----
  pinMode(A7, OUTPUT);
//RED----
  pinMode(A13, OUTPUT);
//GREEN----
  pinMode(A11, OUTPUT);
//BLUE----
  pinMode(A12, OUTPUT);


// encoder---------------
//  attachInterrupt(4, leftISR, CHANGE);
//  attachInterrupt(5, rightISR, CHANGE);
  pinMode(20, INPUT_PULLUP);              //Interrupts assigning for Encoders
  pinMode(21, INPUT_PULLUP);

//motor controlling pins---------------
  pinMode(leftMotorForward, OUTPUT);      
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);


Calibrate();

}



void loop() {

//
//while(1){
//      wallJunction();
//        if( (!L) && (!R) && (T) ) {
//            brake();
//            delay(2000);
//            beep();
//            delay(1000);
//            off();
//          }
//    followingWall();      
//}
//goToWall(170);
//delay(10000000000);
char key=check.getKey();
switch(key){
  case ('#'):
  delay(1000);
  off();
lineMazeSolve();
  break;
  
  }

//Color();
//wallJunction();
//centerAtWall();
//turnInWall('R'); 
//centerAtWall();
//delay(1000000);

//checkSonar();
//followingWall();
//checkSonar();
//lineMazeSolve();
//wallJunction();
//keyCheck();

//while(1){}
}


