
#include <Servo.h>

Servo servo1;  // create servo object to control a servo
// twelve servo objects can be created on most boards

#define E1 10  // Enable Pin for motor 1
#define E2 11  // Enable Pin for motor 2

#define I1 8  // Control pin 1 for motor 1
#define I2 9  // Control pin 2 for motor 1
#define I3 12  // Control pin 1 for motor 2
#define I4 13  // Control pin 2 for motor 2

#define RIGHT 0
#define LEFT  1
int speed1 = 250;

void setup() {

  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);

  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);
  pinMode(I3, OUTPUT);
  pinMode(I4, OUTPUT);
  pinMode(A0, INPUT);
  servo1.attach(6);  // attaches the servo on pin 6 to the servo object
  Serial.begin(9600);
}

void loop() {
  Serial.println("Step Forward");
  forward();
  delay(2000);
  stop();

  Serial.println("Step Forward");
  forwardTime(2000);
  
  Serial.println("Step Forward");
  forwardTime(2000);

  Serial.println("Turn Right");
  turn(RIGHT, 500);

  Serial.println("Turn Left");
  turn(LEFT, 500);


  Serial.print("Reading Sensor1 with ");
  int value1 = readSensor1();
  Serial.println( value1 );

  Serial.println("Moving Servo");
  sweepServo1();
}


void forward( void ) {
  digitalWrite(E1, LOW); // both motors stopped while transitioning
  digitalWrite(E2, LOW);

  delay(200);
  analogWrite(E1, speed1); // Activate both motors at same speed
  analogWrite(E2, speed1);

  digitalWrite(I1, LOW);	// with opposite direction than before
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

  digitalWrite(I1, HIGH);	// with opposite direction than foward
  digitalWrite(I2, LOW);
  digitalWrite(I3, HIGH);
  digitalWrite(I4, LOW);
}

void forwardTime( unsigned int time) {
  forward();
  delay(time);
  stop();
}

void turn ( byte clockwise, unsigned int time ) {
  digitalWrite(E1, LOW); // both motors stopped while transitioning
  digitalWrite(E2, LOW);

  delay(200);
  analogWrite(E1, speed1); // Activate both motors at same speed
  analogWrite(E2, speed1);

  if (clockwise) {
    digitalWrite(I1, LOW);	// with opposite direction than before
    digitalWrite(I2, HIGH);
    digitalWrite(I3, LOW);
    digitalWrite(I4, HIGH);
  } else {
    digitalWrite(I1, HIGH);	// with opposite direction than before
    digitalWrite(I2, LOW);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
  }
  delay(time);
  stop();
}

void turnAngle ( int angle ) {
  if (angle > 0) {
    turn(RIGHT, angle * 5);
  }
  else {
    turn(LEFT, angle * 5);
  }
}

  void stop ( void ) {
    digitalWrite(E1, LOW); // both motors stopped while transitioning
    digitalWrite(E2, LOW);
    digitalWrite(I1, LOW);	// with opposite direction than before
    digitalWrite(I2, LOW);
    digitalWrite(I3, LOW);
    digitalWrite(I4, LOW);
  }

  void sweepServo1 ( void ) {
    int pos = 0;
    for (pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees
    { // in steps of 1 degree
      servo1.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -= 1) // goes from 180 degrees to 0 degrees
    {
      servo1.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  }

  int readSensor1( void ) {
    return analogRead(A0);
  }
