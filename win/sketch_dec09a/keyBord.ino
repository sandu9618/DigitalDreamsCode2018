
void keyCheck(){
    char key=check.getKey();

  if(key=='1'){
    Serial.println("hi 1");
    //first round
  }
  else if(key=='2'){
    Serial.println("hi 2");
    //second round
  }
  else if(key=='*'){
    Serial.println("hi *");
    //calibrate
  }
  else if(key=='#'){
    Serial.println("hi #");
    //go
  }

}
