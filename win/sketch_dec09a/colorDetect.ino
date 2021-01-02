void checkColor(){
  redValue();
  greenValue();
  blueValue();

  // should be modified

  if (frequency_R > 230 && frequency_B <  175 && frequency_G < 175) {
    redJun = redJun + 1;
  }
  else if (frequency_G > 200 && frequency_B <  200 && frequency_R < 200) {
    greenJun = greenJun + 1;
  }
  else if ( frequency_R < 100 && frequency_B >   160 && frequency_G < 100 ) {
    blueJun = blueJun + 1;
  }
  
}

void maxColor(){
  maxi=max(max(redJun, greenJun), blueJun);
  if (maxi==redJun){
    light('R');
  }
  else if(maxi==greenJun){
    light('G');
  }
  else if(maxi==blueJun){
    light('B');
  }
}


void Color(){
  redValue();
  greenValue();
  blueValue();
//  Serial.print("G= ");//printing name
//  Serial.print(frequency_G);//printing RED color frequency
//  Serial.print("  ");
//
//  Serial.print("R= ");//printing name
//  Serial.print(frequency_R);//printing RED color frequency
//  Serial.print("  ");
//
//  Serial.print("B= ");//printing name
//  Serial.print(frequency_B);//printing RED color frequency
//  Serial.println("  ");\

  }

bool  colorSeted(){

  redValue();
  greenValue();
  blueValue();

  if (frequency_R <  80 && frequency_B <  80 && frequency_G < 80) {
    return 0;
  }
  else{return 1;}
}
