#include<Keypad.h>

byte rowPins[2]={29,31};//37,35,33,31,29
byte colPins[3]={33,35,37};

char keys[2][3]={
  {'1','2','3'},
  {'*','0','#'}
};

Keypad check=Keypad(makeKeymap(keys),rowPins,colPins,2,3);

void setup() {
  Serial.begin(9600);

}

void loop() {
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
