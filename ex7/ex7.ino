/*
   Example 7
   Introduction to Robotics
   by Rodolfo Cossovich at New York University
   Description: Using two LDRs we can trigger different states: there is light in front of us, there is none,
   there is light to the left or light to the right. Initially it measures and averages the environment light.
   For this example we will only use LEDs to indicate the state
*/



int HYS = 20;
byte state = 0; //default state
int LDR1 = A1;
int LDR2 = A2;

int LED1 = 2;
int LED2 = 4;

int enviLight = 0;
#define RIGHT 0
#define LEFT  1

//#define DEBUG        //uncomment this line to activate all Serial Monitor reports (note the delays introduced)

void updateState(void) {  //note that this function is giving back the value as a result of evaluating the inputs
  state = 0;
  int sensorValue1 = analogRead(LDR1);  // read the input on analog pin:
  if (sensorValue1 >= (enviLight + HYS) ) {
    state += 1;         // in case the sensor is reading high value, there is light
  }
 
  int sensorValue2 = analogRead(LDR2);  // read the input on analog pin:
  if (sensorValue2 >= (enviLight + HYS) ) {
    state += 2;         // in case the sensor is reading high value, there is light
  }
  
  
#ifdef DEBUG
  Serial.print("LDR1 : ");
  Serial.println(sensorValue1);  // we print on the serial monitor the value, just for debugging
  Serial.print("LDR2 : ");
  Serial.println(sensorValue2);  // we print on the serial monitor the value, just for debugging
#endif
}

void stopMotors ( void ) {
 digitalWrite(LED1, LOW); // turn OFF both LED
 digitalWrite(LED2, LOW); // turn OFF both LEDs
}

void forward( void ) {
  digitalWrite(LED1, HIGH); // turn ON both LEDs 
  digitalWrite(LED2, HIGH); // turn ON both LEDs 
}

void forwardTime( unsigned int time) {
  forward();
  delay(time);
  stopMotors();
}

void turnAngle ( int angle ) {
  if (angle > 0) {
    turn(RIGHT, angle * 5);
  }
  else {
    turn(LEFT, -angle * 5);
  }
}

void getEnvi( void ) {
  int sensorValue1 = analogRead(LDR1);  // read the input on analog pin:
  int sensorValue2 = analogRead(LDR2);  // read the input on analog pin:
  enviLight = (sensorValue1+sensorValue2) /2;  // read the input on analog pin:
  
#ifdef DEBUG  
  Serial.print("LDR1 acquired : ");
  Serial.println(sensorValue1);  // we print on the serial monitor the value, just for debugging
  Serial.print("LDR2 acquired : ");
  Serial.println(sensorValue2);  // we print on the serial monitor the value, just for debugging
  Serial.print("Envi-Light at : ");
  Serial.println(enviLight);  // we print on the serial monitor the value, just for debugging
#endif
}


void turn ( byte clockwise, unsigned int timeTurn ) {
  if (clockwise) {
    digitalWrite(LED1, HIGH); // turn ON left LED
  } else {
    digitalWrite(LED2, HIGH); // turn ON right LED
  }
  delay(timeTurn);
  stopMotors();
  
}

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);

#ifdef DEBUG
  Serial.begin(9600);// initialize serial communication at 9600 bits per second:
  Serial.println("Starting F.S.M...");
  delay(3000);    // it gives some extra time in the simulator to adjust the light
#endif  
  getEnvi();    // after having the port available, we read the room light
}

void loop() {
#ifdef DEBUG
  delay(500);        // delay in between reads for stability
  Serial.print("State: ");
  Serial.println(state,DEC);
#endif
  updateState();
  switch (state) {
    case 0:         // there is no big change in environment light
      stopMotors(); // we decided by design to stop, but what if it is go around randomly?
      break;
    case 1:         // there is a strong light to the left the robot
      turnAngle(30);
      break;
    case 2:         // there is a strong light to the right
      turnAngle(-30);
      break;
    case 3:         // there is a strong light in front of the robot
      forwardTime(200);
      break;
    default:
      state=0;
      break;
  }
}



