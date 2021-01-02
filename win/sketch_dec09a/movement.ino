void brake() //active brake
{
  digitalWrite(rightMotorPWM, 255);
  digitalWrite(leftMotorPWM, 255);

  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(leftMotorBackward, HIGH);
  digitalWrite(rightMotorForward, HIGH);
  digitalWrite(rightMotorBackward, HIGH);
}

void motorStop(){
  digitalWrite(rightMotorPWM, 0);
  digitalWrite(leftMotorPWM, 0);

  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(leftMotorBackward, HIGH);
  digitalWrite(rightMotorForward, HIGH);
  digitalWrite(rightMotorBackward, HIGH);
  }

void motorSpeed(bool state)
{
  digitalWrite(leftMotorPWM, state);
  digitalWrite(rightMotorPWM, state);
}

void motorSpeed(byte leftSpeed, byte rightSpeed)
{
  analogWrite(leftMotorPWM, leftSpeed);
  analogWrite(rightMotorPWM, rightSpeed);
}

void forward()
{
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorBackward, LOW);
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(rightMotorForward, HIGH);
}

void forward(int LSpeed, int RSpeed)
{
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorBackward, LOW);
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(rightMotorForward, HIGH);

  analogWrite(leftMotorPWM, LSpeed);
  analogWrite(rightMotorPWM, RSpeed);
}

void backward()
{
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(leftMotorBackward, HIGH);
  digitalWrite(rightMotorBackward, HIGH);
}

void backward(int LSpeed, int RSpeed)
{
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(leftMotorBackward, HIGH);
  digitalWrite(rightMotorBackward, HIGH);

  analogWrite(leftMotorPWM, LSpeed);
  analogWrite(rightMotorPWM, RSpeed);
}

void leftTurn()
{
  digitalWrite(rightMotorBackward, LOW);
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, HIGH);
  digitalWrite(rightMotorForward, HIGH);
}

void leftTurn(int LSpeed, int RSpeed)
{
  digitalWrite(rightMotorBackward, LOW);
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, HIGH);
  digitalWrite(rightMotorForward, HIGH);

  analogWrite(leftMotorPWM, LSpeed);
  analogWrite(rightMotorPWM, RSpeed);
}

void rightTurn()
{
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, HIGH);
  digitalWrite(leftMotorForward, HIGH);
}

void rightTurn(int LSpeed, int RSpeed)
{
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, HIGH);
  digitalWrite(leftMotorForward, HIGH);
  
  analogWrite(leftMotorPWM, LSpeed);
  analogWrite(rightMotorPWM, RSpeed);
}


void centerAtJunction(){
  forward(150,150);
  delay(150);
  brake();
  }

void centerAtJunction(int time){
  forward(200,200);
  delay(time);
  brake();
  }
  
void turnInLine(char angle){
   switch(angle)
  {
    case 'L':
    leftTurn(150,150);
    delay(100); 
    while(1){
      qtrRead();
      if(dval[3])
      {
        brake();
        break;
      }
    }
    break;

    case 'R':
    rightTurn(150,150);
    delay(100); 
    while(1){
      qtrRead();
      if(dval[4])
      {
        brake();
        break;
      }
    }
    break;

    case 'B':
    rightTurn(150,150);
    delay(100); 
    while(1){
      qtrRead();
      if(dval[4])
      {
        brake();
        break;
      }
    }
    break;

    case 'T':
    leftTurn(150,150);
    delay(200); 
    while(1){
      qtrRead();
      if(dval[3])
      {
        brake();
        break;
      }
    }
    break;

  }
}

void turnInWall(char angle){
  switch(angle){
    case 'R':
      rightTurn(150,150);
      delay(425);
      brake();
    break;

    case 'L':
      leftTurn(150,150);
      delay(425);
      brake();
    break;

    case 'B':
      rightTurn(150,150);
      delay(840);
      brake();
    break;
    
    }
  }

void centerAtWall(){
  forward(200,200);
  delay(450);
  brake();
  }
  void centerAtWall( int time){
  forward(200,200);
  delay(time);
  brake();
  }
void goToWall(){
  forward(200,200);
  delay(500);
  brake();
  }

void goToWall(int time){
  forward(200,200);
  delay(time);
  brake();
  }
