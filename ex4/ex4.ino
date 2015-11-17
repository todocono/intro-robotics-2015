
#include <Servo.h>

Servo servo1;  // create servo object to control a servo
// twelve servo objects can be created on most boards



void setup() {
  // put your setup code here, to run once:

  servo1.attach(6);  // attaches the servo on pin 6 to the servo object
  Serial.begin(9600);




}

void loop() {
  // put your main code here, to run repeatedly:



  Serial.print("Reading Sensor1 with ");
  int value1 = readSensor1();
  Serial.println( value1 );

  Serial.println("Moving Servo");
  sweepServo1();

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
