//---------------------------------------------------------
long leftSideRead()
{
  long distance = leftSideSonar.ping_cm();
  if (distance == 0) return 2000;
  return distance * 10;
}

//---------------------------------------------------------

long rightSideRead()
{
  long distance = rightSideSonar.ping_cm();
  if (distance == 0) return 2000;
  return distance * 10;
}
//---------------------------------------------------------
long leftRead()
{
  long distance = leftSonar.ping_cm();
  if (distance == 0) return 2000;
  return distance * 10;
}

//----------------------------------------------------------------------
long fontRead()
{
  long distance = fontSonar.ping_cm();
  if (distance == 0) return 2000;
  return distance * 10;
 
}

//---------------------------------------------------------

long rightRead()
{
   long distance = rightSonar.ping_cm();
  if (distance == 0) return 2000;
  return distance * 10;
}
//---------------------------------------------------------
bool leftWall(){
 
  long distance = leftRead();
  if(distance < 100 ){  return 1;}
  
  }
//---------------------------------------------------------
bool fontWall(){
  long distance = fontRead();
  if(distance < 100 ){  return 1;}
  }
//---------------------------------------------------------
bool rightWall(){  
  long distance = rightRead();
  if(distance < 100 ){  return 1;}
  }
//---------------------------------------------------------
bool rightSideWall(){
  long distance = rightSideRead();
  if(distance < 100 ){  return 1;}
  }
//---------------------------------------------------------
bool leftSideWall(){
  long distance = leftSideRead();
  if(distance < 100 ){  return 1;}
  }
//---------------------------------------------------------

void checkSonar(){

Serial.print("L side= ");
Serial.print(leftSideRead());
Serial.print("  ");

Serial.print("R side= ");
Serial.print(rightSideRead());
Serial.print("  ");

Serial.print("Left= ");
Serial.print(leftRead());
Serial.print("  ");

Serial.print("Right= ");
Serial.print(rightRead());
Serial.print("  ");

Serial.print("font= ");
Serial.print(fontRead());
Serial.println("  ");
  
  }
