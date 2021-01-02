#include <QTRSensors.h> // QTR Sensor
#include <NewPing.h>    //sonar sensor
#include <Servo.h>      //Servo motor
#include<Keypad.h> 
#include "define.h"



void setup() {
Serial.begin(9600);
  
//other----------------------
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
delay(2000);
}




void loop() {


lineMazeSolve();
pathIndex=0;
status=0;
checkkey();

//checkSonar();
//followingWall();
//checkSonar();
//lineMazeSolve();
//wallJunction();

//while(1){
//  followingWall();
//  wallJunction();
//  findWall();
//  if(  (mode == RIGHT_TURN_IN_WALL)  || FW || (!RS) || (!LS)){
//    brake();
//    beep();
//    break;
//    }
//  }
//  light('G');
//  brake();
//delay(10000000);
//
//light('B');

}


