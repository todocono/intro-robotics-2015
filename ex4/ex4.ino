/*
   Example 4
   Introduction to Robotics
   by Rodolfo Cossovich at New York University
   Description: Motors are actuators with no feedback loop. We are using here a servo motor to showcase hardware.
   Note the analogRead using the input of sensors. Test different inputs and different actions.
*/

#include <Servo.h>

Servo servo1;  // create servo object to control a servo
// twelve servo objects can be created on most boards

void setup() {
  servo1.attach(6);  // attaches the servo on pin 6 to the servo object
  Serial.begin(9600);

}

void loop() {
  Serial.print("Reading Sensor1 with ");
  int value1 = readSensor1();
  Serial.println( value1 );
  
  if (value1 > 100) {             //note the usage of a conditional to compare the value coming from the sensor
    Serial.println("Moving Servo");
    sweepServo1();
  }
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
