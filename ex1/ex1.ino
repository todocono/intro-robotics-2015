/*
   Example 1
   Introduction to Robotics
   by Rodolfo Cossovich at New York University
   Description: Arduino by itself is not capable of handling big currents or voltage. That is why we use a motor driver.
   Connect all wires as the schematic, using an external battery. Tweak numbers of delays and speed
*/
boolean reverse = 0;

int enablePin1 = 3;
int in1Pin1 = 2;
int in2Pin1 = 4;

int enablePin2 = 5;
int in1Pin2 = 6;
int in2Pin2 = 7;

int tweakTime = 1000;   // time expressed in ms
int tweakSpeed = 120;   // what is the minimum sepeed? maximum?

void setup()
{
  pinMode(in1Pin1, OUTPUT);
  pinMode(in2Pin1, OUTPUT);
  pinMode(enablePin1, OUTPUT);

  pinMode(in1Pin2, OUTPUT);
  pinMode(in2Pin2, OUTPUT);
  pinMode(enablePin2, OUTPUT);

}

void loop()
{
  // move forward
  analogWrite(enablePin1, tweakSpeed);
  digitalWrite(in1Pin1, HIGH);
  digitalWrite(in2Pin1, LOW);
  analogWrite(enablePin2, tweakSpeed);
  digitalWrite(in1Pin2, HIGH);
  digitalWrite(in2Pin2, LOW);
  delay(tweakTime);
  //stop both motors
  digitalWrite(enablePin2, LOW);
  digitalWrite(in1Pin2, LOW);
  digitalWrite(in2Pin2, LOW);
  digitalWrite(enablePin1, LOW);
  digitalWrite(in1Pin1, LOW);
  digitalWrite(in2Pin1, LOW);
  delay(tweakTime);
  //reverse direction by inverting the inXpinX
  analogWrite(enablePin1, tweakSpeed);
  digitalWrite(in1Pin1, LOW);
  digitalWrite(in2Pin1, HIGH);
  analogWrite(enablePin2, tweakSpeed);
  digitalWrite(in1Pin2, LOW);
  digitalWrite(in2Pin2, HIGH);
  delay(tweakTime);
  //stop both motors
  digitalWrite(enablePin2, LOW);
  digitalWrite(in1Pin2, LOW);
  digitalWrite(in2Pin2, LOW);
  digitalWrite(enablePin1, LOW);
  digitalWrite(in1Pin1, LOW);
  digitalWrite(in2Pin1, LOW);
  delay(tweakTime);  
}
