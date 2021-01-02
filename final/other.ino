void beep(){
  analogWrite(A7,150);
  delay(500);
  analogWrite(A7,0);
  }

void light(char color){
  switch(color)
  {
    case 'R': // A13
    analogWrite(A13,200);
    delay(1000);
    analogWrite(A13,0);
    break;

    case 'G': //A11
    analogWrite(A11,200);
    delay(1000);
    analogWrite(A11,0);
    break;
    
    case 'B': // A12
    analogWrite(A12,200);
    delay(1000);
    analogWrite(A12,0);
    break;

  }
  }


  void wait() {
  analogWrite(rightMotorPWM, 0);
  analogWrite(leftMotorPWM, 0);
}

