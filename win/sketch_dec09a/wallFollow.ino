void setWallFollow()
{
  forward();
  
  lastError = 0;
  integral=0;

  Kp = 0.07;
  Kd = 0.55;  //0.6
  Ki = 0.001;

  minSpeed = 0;//50
  baseSpeed = 200;//150;//200
  maxSpeed = 250;//200;//255
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

 L = leftJunction();
 R = rightJunction();
 T = TJunction();


Serial.print("L = ");
Serial.print(L);

Serial.print("  R = ");
Serial.print(R);

Serial.print("  T = ");
Serial.println(T);

 
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
