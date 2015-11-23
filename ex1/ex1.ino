/*
   Example 1
   Introduction to Robotics 
   by Rodolfo Cossovich at New York University
   Description: Arduino by itself is not capable of handling big currents or voltage. That is why we use a motor driver.
   We are connecting all wires as the schematic, using an external battery. Tweak numbers of delays and speed
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
  setMotor1(tweakSpeed, reverse);
  setMotor2(tweakSpeed, reverse);
  delay(tweakTime);
  setMotor1(0, 0);
  setMotor2(0, 0);
  delay(100);
  reverse = 1;//
  setMotor1(tweakSpeed, reverse);
  setMotor2(tweakSpeed, reverse);
  delay(tweakTime);
  setMotor1(0, 0);
  setMotor2(0, 0);
  delay(100);
  reverse = 0;
  tweakSpeed = 255;
  setMotor1(tweakSpeed, reverse);
  setMotor2(tweakSpeed, reverse);
  delay(tweakTime);
  setMotor1(0, 0);
  setMotor2(0, 0);
  delay(100);
  reverse = 1;//
  setMotor1(tweakSpeed, reverse);
  setMotor2(tweakSpeed, reverse);
  delay(tweakTime);
}

void setMotor1(int tweakSpeed, boolean reverse)
{
  if (!tweakSpeed) {
    digitalWrite(enablePin1, LOW);
    digitalWrite(in1Pin1, LOW);
    digitalWrite(in2Pin1, LOW);
  }
  analogWrite(enablePin1, tweakSpeed);
  digitalWrite(in1Pin1, ! reverse);
  digitalWrite(in2Pin1, reverse);
}


void setMotor2(int tweakSpeed, boolean reverse)
{
  if (!tweakSpeed) {
    digitalWrite(enablePin2, LOW);
    digitalWrite(in1Pin2, LOW);
    digitalWrite(in2Pin2, LOW);
  }
  analogWrite(enablePin2, tweakSpeed);
  digitalWrite(in1Pin2, ! reverse);
  digitalWrite(in2Pin2, reverse);
}
