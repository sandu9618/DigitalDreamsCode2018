#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

#define R_H 440
#define R_L 32
#define G_H 377
#define G_L 35
#define B_H 111
#define B_L 2

int frequency = 0;
int frequency_R, frequency_G, frequency_B = 0;

int redJun, greenJun, blueJun = 0;

int maxi=0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  Serial.begin(9600);
}
void loop() {
colorJunction();
 
}

void colorJunction(){
   // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
 // frequency = map(frequency, R_H, R_L, 0, 255);
  frequency_R = frequency;
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(1);


  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
 // frequency = map(frequency, G_H, G_L, 0, 255);
  frequency_G = frequency;
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(1);


  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
 // frequency = map(frequency, B_H, B_L, 0, 255);
  frequency_B = frequency;
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.println("  ");
  delay(1);

  if (frequency_R > frequency_G && frequency_R > frequency_B) {
    redJun = redJun + 1;
   
  }
  else if (frequency_G > frequency_R && frequency_G > frequency_B) {
    greenJun = greenJun + 1;
    
  }
  else if (frequency_B > frequency_G && frequency_B > frequency_R) {
    blueJun = blueJun + 1;
    
  }
}

void ledOn(){
  maxi=max(max(redJun, greenJun), blueJun);
  if (maxi==redJun){
    digitalWrite(A13,HIGH);
  }
  else if(maxi==greenJun){
    digitalWrite(A11,HIGH);
  }
  else if(maxi==blueJun){
    digitalWrite(A12,HIGH);
  }
}

