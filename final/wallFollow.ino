void setWallFollow()
{
  forward();
  
  lastError = 0;
  integral=0;

  Kp = 0.07;
  Kd = 0.6;
  Ki = 0.001;

  minSpeed = 0;//50
  baseSpeed = 200;//150;//200
  maxSpeed = 250;//200;//255
}

//---------------------------------------------------------
void wallFollow()
{
 
  setWallFollow();
  while(leftSideRead() > 200 ) rightWallFollow(130);
  brake();
  
  setWallFollow();
  while(rightSideRead() < 200 ) leftWallFollow(130);
  brake();

  setWallFollow();
  while(rightSideRead() > 200 ) leftWallFollow(130);
  brake();

  setWallFollow();
  while(leftSideRead() < 200 ) leftWallFollow(130);
  brake();

  //wall following till stopping square  
  setWallFollow();
  while(1)
  {
    rightWallFollow(130);
    qtrRead();
    if(dval[0] || dval[1] || dval[2] || dval[3] || dval[4] || dval[5] || dval[6] || dval[7])
    {
      brake();
      break;
    }
  }


}
//---------------------------------------------------------
void leftWallFollow(int setPoint)
{
 int error ;
 //if(leftSideRead() < 150){
        error = leftSideRead() - setPoint;    //}
 //else{  error = leftRead() - setPoint;   }
 
    integral = integral + error;
    
    int controlSpeed = Kp * error + Kd * (error - lastError) + Ki*integral;
    
    lastError = error;
    
    byte rightMotorSpeed = constrain((baseSpeed - controlSpeed),minSpeed, maxSpeed);
    byte leftMotorSpeed = constrain((baseSpeed + controlSpeed),minSpeed, maxSpeed);
    
    motorSpeed(leftMotorSpeed,rightMotorSpeed);
  
}
//-----------------------------------------------------------
void rightWallFollow(int setPoint)
{  
 int error ;
    
    error = rightSideRead() - setPoint; //mm
    integral = integral + error;
    
    int controlSpeed = Kp * error + Kd * (error - lastError)+ Ki*integral;
    
    lastError = error;
    
    int rightMotorSpeed = constrain((baseSpeed - controlSpeed),minSpeed, maxSpeed);
    int leftMotorSpeed = constrain((baseSpeed + controlSpeed),minSpeed, maxSpeed);
    
    motorSpeed(leftMotorSpeed,rightMotorSpeed);
  
}


//---------------------------------------------------------
void wallJunction(){
  
// FW = LW =RW

  findWall();
      if ( (!LW) &&  RW   ) {   // left : turn left
        junction = 'L'; mode  = LEFT_TURN_IN_WALL ;
        light('B');
      }

      else if ( LW  &&  (!RW)   ) {  
        junction = 'R'; mode = RIGHT_TURN_IN_WALL ;
        light('R');
      }

      else if ( (!LW)  &&  (!RW) && (RS) && (LS)  ) {   // T  : turn left
        junction = 'T'; mode = CONT_WALL ;
        light('G');
      }

      else if ( (!LW) && (!FW) &&  (!RW) && (!RS) && (!LS) ) {  // back :
        junction = 'B'; mode = NO_WALL ;
        beep();
      }
      else {
        mode = FOLLOWING_WALL ;
      }
  }
//---------------------------------------------------------
void findWall(){
  FW = fontWall();
  RW = rightWall();
  LW = leftWall();
  RS = rightSideWall();
  LS = leftSideWall();
  }
//---------------------------------------------------------

void twoWallFollow(){
  int error ;
  
    error = rightSideRead() - leftSideRead(); //mm
    integral = integral + error;
    
    int controlSpeed = Kp * error + Kd * (error - lastError)+ Ki*integral;
    
    lastError = error;
    
    int rightMotorSpeed = constrain((baseSpeed - controlSpeed),minSpeed, maxSpeed);
    int leftMotorSpeed = constrain((baseSpeed + controlSpeed),minSpeed, maxSpeed);
    
    motorSpeed(leftMotorSpeed,rightMotorSpeed);
  }
//-----------------------------------------------------------
void followingWall(){
  setWallFollow();
  twoWallFollow();
  }

//---------------------------------------------------------

void turnAtDeadEnd(char type){
  switch (type){
    case 'A':
    break;
    }
  }
bool roboInWall(){
  findWall();
  if (  FW || RW || LW || RS || LS  ){
    return 1;
    }
  }

//---------------------------------------------------------
