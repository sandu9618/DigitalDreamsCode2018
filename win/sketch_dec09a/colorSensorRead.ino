void redValue(){
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frequency = pulseIn(sensorOut, LOW);
  frequency = map(frequency, R_H, R_L, 0, 255);
  frequency_R = frequency;
  delay(1);  
  }

void blueValue(){
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(sensorOut, LOW);
 frequency = map(frequency, B_H, B_L, 0, 255);
  frequency_B = frequency;
  delay(1);
  }

void greenValue(){
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(sensorOut, LOW);
  frequency = map(frequency, G_H, G_L, 0, 255);
  frequency_G = frequency;
  delay(1);
  }
