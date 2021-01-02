//---
//Sonars ----------------------------------------------------

#define leftTrig A1
#define leftEcho A0
#define centerTrig A3
#define centerEcho A2
#define rightTrig A5
#define rightEcho A4
#define leftSideTrig A14
#define leftSideEcho A15
#define rightSideTrig A9
#define rightSideEcho A8


byte rowPins[2]={29,31};//37,35,33,31,29
byte colPins[3]={33,35,37};

char keys[2][3]={
  {'1','2','3'},
  {'*','0','#'}
};


Keypad check=Keypad(makeKeymap(keys),rowPins,colPins,2,3);



NewPing leftSideSonar(leftSideTrig, leftSideEcho, 250); 
NewPing rightSideSonar(rightSideTrig, rightSideEcho, 250);
NewPing leftSonar(leftTrig, leftEcho, 150); 
NewPing rightSonar(rightTrig, rightEcho, 150); 
NewPing fontSonar(centerTrig, centerEcho, 150); 

bool FW = 0;
bool LW = 0;
bool RW = 0;
bool LS = 0;
bool RS = 0;

//QTR Sensor ------------------------------------------------------------------------------------------------------

#define NUM_SENSORS  8     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 us for sensor outputs to go low
#define EMITTER_PIN   2

QTRSensorsRC qtrrc((unsigned char[]) { 53, 51, 49, 47, 45, 43, 41, 39} , NUM_SENSORS, TIMEOUT, EMITTER_PIN);

unsigned int position;
unsigned int sensorValues[NUM_SENSORS];
bool dval[NUM_SENSORS];

//junctio -------------
char junction ;


//PID Coefficients and Variables -------------------------------------------------------------------------------------------------------

float Kp; // experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
float Kd; // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd)
float Ki;

byte maxSpeed;
byte minSpeed;
byte baseSpeed;

int lastError = 0;
int integral = 0;

int rightMotorSpeed;
int leftMotorSpeed;


//Mototrs -------------------------------------------
#define leftMotorForward 48  //motor directions
#define leftMotorBackward 46
#define rightMotorForward 50
#define rightMotorBackward 52
#define rightMotorPWM 10 //PWM controls
#define leftMotorPWM 9

//Encoders ------------------------------------------
volatile unsigned long leftCount = 0, rightCount = 0;
void leftISR() //ISR for left motor count
{ leftCount++; Serial. print("left = ");Serial. print(leftCount);}
void rightISR() //ISR for right motor count
{ rightCount++;  Serial. print("   right = ");Serial. println(rightCount);}


//===========LIne Mesh Solve==============================
bool a = 0 ;
int mode = 0;
# define STOPPED 0
# define FOLLOWING_LINE 1
# define NO_LINE 2
# define CONT_LINE 3
# define POS_LINE 4
# define RIGHT_TURN 5
# define LEFT_TURN 6
float  L1 , R1  , M;
char path[500] = "";
unsigned char pathLength = 0; // the length of the path
int pathIndex = 0;
unsigned int status = 0; // solving = 0; reach end = 1
unsigned int sensors[8];

//===============wall Mesh solve===========================


# define FOLLOWING_WALL 7
# define NO_WALL 8
# define CONT_WALL 9
# define RIGHT_TURN_IN_WALL 10
# define LEFT_TURN_IN_WALL 11

