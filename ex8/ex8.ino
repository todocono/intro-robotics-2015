/*
   Example 8
   Introduction to Robotics
   by Rodolfo Cossovich at New York University
   Description: Using two LDRs we can trigger different states: there is light in front of us, there is none,
   there is light to the left or light to the right. Initially it measures and averages the environment light.
*/

int HYS = 20;
byte state = 0; //default state
int LDR1 = A1;
int LDR2 = A2;


#define E1 10  // Enable Pin for motor 1
#define E2 11  // Enable Pin for motor 2

#define I1 8  // Control pin 1 for motor 1
#define I2 9  // Control pin 2 for motor 1
#define I3 12  // Control pin 1 for motor 2
#define I4 13  // Control pin 2 for motor 2

#define RIGHT 0
#define LEFT  1
int speed1 = 250;
int enviLight = 0;

void setup() {
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);

  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);
  pinMode(I3, OUTPUT);
  pinMode(I4, OUTPUT);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);

  getEnvi();
  Serial.begin(9600);// initialize serial communication at 9600 bits per second:
}

void loop() {
  updateState();
  delay(10);        // delay in between reads for stability
  switch (state) {
    case 0:         // there is no big change in environment light
      stopMotors(); // we decided by design to stop, but what if it is go around randomly?
      break;
    case 1:         // there is a strong light to the left the robot
      turnAngle(30);
      state = 0;
      break;
    case 2:         // there is a strong light to the right
      turnAngle(-30);
      state = 0;
      break;
    case 3:         // there is a strong light in front of the robot
      forwardTime(200);
      state = 0;
      break;
    default:
      stopMotors();
  }
}



void updateState(void) {  //note that this function is giving back the value as a result of evaluating the inputs
  int sensorValue1 = analogRead(LDR1);  // read the input on analog pin:
  Serial.print("LDR1 acquired : ");
  Serial.println(sensorValue1);  // we print on the serial monitor the value, just for debugging
  if (sensorValue1 >= (enviLight - HYS) ) {
    state += 1;         // in case the sensor is reading high value, there is light
  }
  else {
    state =  0;  // in case the sensor is reading low value, it is dark
  }
  int sensorValue2 = analogRead(LDR2);  // read the input on analog pin:
  Serial.print("LDR2 acquired : ");
  Serial.println(sensorValue2);  // we print on the serial monitor the value, just for debugging

  if (sensorValue2 >= (enviLight - HYS) ) {
    state += 2;         // in case the sensor is reading high value, there is light
  }
  else {
    state =  0;  // in case the sensor is reading low value, it is dark
  }
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
    turn(LEFT, angle * 5);
  }
}

void getEnvi( void ) {
  int sensorValue1 = analogRead(LDR1);  // read the input on analog pin:
  Serial.print("LDR1 acquired : ");
  Serial.println(sensorValue1);  // we print on the serial monitor the value, just for debugging

  int sensorValue2 = analogRead(LDR2);  // read the input on analog pin:
  Serial.print("LDR2 acquired : ");
  Serial.println(sensorValue2);  // we print on the serial monitor the value, just for debugging

  enviLight = (sensorValue1 /2) + (sensorValue2 /2);  // read the input on analog pin:
  Serial.print("Environment Light calculated at : ");
  Serial.println(enviLight);  // we print on the serial monitor the value, just for debugging
  
}

void forward( void ) {
  digitalWrite(E1, LOW); // both motors stopped while transitioning
  digitalWrite(E2, LOW);
  delay(200);
  analogWrite(E1, speed1); // Activate both motors at same speed
  analogWrite(E2, speed1);
  digitalWrite(I1, LOW);  // with opposite direction than before
  digitalWrite(I2, HIGH);
  digitalWrite(I3, LOW);
  digitalWrite(I4, HIGH);
}

void back( void ) {
  digitalWrite(E1, LOW); // both motors stopped while transitioning
  digitalWrite(E2, LOW);
  delay(200);
  analogWrite(E1, speed1); // Activate both motors at same speed
  analogWrite(E2, speed1);
  digitalWrite(I1, HIGH); // with opposite direction than foward
  digitalWrite(I2, LOW);
  digitalWrite(I3, HIGH);
  digitalWrite(I4, LOW);
}

void turn ( byte clockwise, unsigned int time ) {
  digitalWrite(E1, LOW); // both motors stopped while transitioning
  digitalWrite(E2, LOW);
  delay(200);
  analogWrite(E1, speed1); // Activate both motors at same speed
  analogWrite(E2, speed1);

  if (clockwise) {
    digitalWrite(I1, LOW);  // with opposite direction than before
    digitalWrite(I2, HIGH);
    digitalWrite(I3, LOW);
    digitalWrite(I4, HIGH);
  } else {
    digitalWrite(I1, HIGH); // with opposite direction than before
    digitalWrite(I2, LOW);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
  }
  delay(time);
  stopMotors();
}

void stopMotors ( void ) {
  digitalWrite(E1, LOW); // both motors stopped while transitioning
  digitalWrite(E2, LOW);
  digitalWrite(I1, LOW);  // with opposite direction than before
  digitalWrite(I2, LOW);
  digitalWrite(I3, LOW);
  digitalWrite(I4, LOW);
}
