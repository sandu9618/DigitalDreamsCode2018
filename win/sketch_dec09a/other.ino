void beep(){
  analogWrite(A7,150);
  }

void light(char color){
  switch(color)
  {
    case 'R': // A13
    analogWrite(A13,200);
    break;

    case 'G': //A11
    analogWrite(A11,200);
    break;
    
    case 'B': // A12
    analogWrite(A12,200);
    break;

  }
}

void wait() {
  analogWrite(rightMotorPWM, 0);
  analogWrite(leftMotorPWM, 0);
}

void off(){
  analogWrite(A7,0);
  analogWrite(A13,0);
  analogWrite(A11,0);
  analogWrite(A12,0);
  }
