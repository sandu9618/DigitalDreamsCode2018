void followingLine(){
  setLineFollow('F');
  lineFollow();
  }

void setLineFollow(char manner)
{
  forward();
  
  lastError = 0;
  integral=0;

  switch(manner)
  {
    case 'S'://Slow
    Kp = 1;
    Kd = 10;
    Ki = 0.010;
    minSpeed =0;
    baseSpeed = 100;
    maxSpeed = 120;
    break;

    case 'M'://Moderate
    default:
    Kp = 2;
    Kd = 50;
    Ki = 0;
    minSpeed = 0;
    baseSpeed = 150;
    maxSpeed = 200;
    break;

    case 'F'://Fast
    Kp = 0.0755; //1.5;
    Kd = 9.85 ;//50; //9.75
    Ki = 0.0001 ;//0;
    minSpeed = 0;
    baseSpeed = 200;
    maxSpeed = 255;
    break;
  }
}



//Line Following : PID Algorithm -------------------------------------------------------------------------------------------------------------------------------------------------------------------

void lineFollow()
{
  position = qtrrc.readLine(sensorValues,  QTR_EMITTERS_ON, 0); // get calibrated readings along with the line position, refer to the QTR Sensors Arduino Library for more details on line position.
  int error = position - 3500;
  
  integral = integral + error;
  
  int controlSpeed = Kp * error + Kd * (error - lastError) + Ki*integral;
  
  lastError = error;
  
  byte rightMotorSpeed = constrain((baseSpeed + controlSpeed), minSpeed, maxSpeed);
  byte leftMotorSpeed = constrain((baseSpeed - controlSpeed), minSpeed, maxSpeed);

  motorSpeed(leftMotorSpeed,rightMotorSpeed);
}





//==================Line junction===================
void LineJunction() {

      qtrRead();
      junction = ' ' ;
      bool L = dval[7];
      bool R = dval[0];
      bool M = dval[3];
      
      if ( L && (!R) ) {   // left : turn left
        junction = 'L'; mode  = LEFT_TURN ;
      }

      else if ( (!L)&&R ) {  
        junction = 'R'; mode = RIGHT_TURN ;
      }

      else if ( (dval[0]&&dval[1]&&dval[2]&&dval[3]&&dval[4]&&dval[5]&&dval[6]&&dval[7])  ) {  // T  : turn left
        junction = 'T'; mode = CONT_LINE ;
      }

      else if ( !(dval[0] || dval[1] || dval[2] || dval[3] || dval[4] || dval[5] || dval[6] || dval[7])  ) {  // back :
        junction = 'B'; mode = NO_LINE ;
      }
      else {
        mode = FOLLOWING_LINE ;
      }
}

bool roboInLine(){
  qtrRead();
  if(  dval[0] || dval[1] || dval[2] || dval[3] || dval[4] ||  dval[5] || dval[6] || dval[7]  ){ return 1;}
  }






