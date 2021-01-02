//Digital Sensor Values ------------------------

void checkQTR()
{
  for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println('\t');
   //Serial.println(position); // comment this line out if you are using raw values
  
   delay(250);
}
void qtrRead()
{
  position=qtrrc.readLine(sensorValues);

  for(int i=0; i< NUM_SENSORS ; i++ )
  {
    if(sensorValues[i] < 300) dval[i] = 1;    // for white line  
    //if(sensorValues[i] > 300) dval[i] = 0;    //for black line
    
    else dval[i] = 0;
    Serial.print (dval[i] ) ;
  }
  Serial.println (" ");
//  if(dval[7]==1)beep();
}
