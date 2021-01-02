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
  if(distance < 90 ){  return 1;}
  }
//---------------------------------------------------------
bool rightWall(){  
  long distance = rightRead();
  if(distance < 90 ){  return 1;}
  }
//---------------------------------------------------------
bool rightSideWall(){
  long distance = rightSideRead();
  if(distance < 90 ){  return 1;}
  }
//---------------------------------------------------------
bool leftSideWall(){
  long distance = leftSideRead();
  if(distance < 90 ){  return 1;}
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



bool rightJunction(){
  int FWdistance = fontRead();
  int LWdistance = leftRead();
  int RWdistance = rightRead();
  int LSdistance = leftSideRead();
  int RSdistance = rightSideRead();

  if( LWdistance < 90 && LSdistance < 100 && ( (RWdistance > 400) || (RSdistance > 400)  ) ){
    return 1;
  }
  else{ return 0;}
}

bool leftJunction(){
  int FWdistance = fontRead();
  int LWdistance = leftRead();
  int RWdistance = rightRead();
  int LSdistance = leftSideRead();
  int RSdistance = rightSideRead();

  if( RWdistance < 90 && RSdistance < 100 && ( (LWdistance > 400) || (LSdistance > 400)  ) ){
    return 1;
  }
  else{ return 0;}
}


bool TJunction(){
  int FWdistance = fontRead();
  int LWdistance = leftRead();
  int RWdistance = rightRead();
  int LSdistance = leftSideRead();
  int RSdistance = rightSideRead();

  if( ( RWdistance > 400 && RSdistance > 400 ) && ( (LWdistance > 400) || (LSdistance > 400)  ) ){
    return 1;
  }
  else{ return 0;}
}

