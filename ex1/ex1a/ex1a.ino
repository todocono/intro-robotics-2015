/*
Example 1
*/

int enablePin1 = 10;
int in1Pin1 = 9;
int in2Pin1 = 8;


int enablePin2 = 11;
int in1Pin2 = 12;
int in2Pin2 = 13;

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



  int speed = 120;  //
  boolean reverse = 0;//
  setMotor1(speed, reverse);
  setMotor2(speed, reverse);
  delay(1000);
  setMotor1(0, 0);
  setMotor2(0, 0);

  reverse = 1;//
  setMotor1(speed, reverse);
  setMotor2(speed, reverse);
  delay(1000);
  setMotor1(0, 0);
  setMotor2(0, 0);

  reverse = 0;
  speed = 250;
  setMotor1(speed, reverse);
  setMotor2(speed, reverse);
  delay(1000);
  setMotor1(0, 0);
  setMotor2(0, 0);
  delay(100);
  reverse = 1;//
  setMotor1(speed, reverse);
  setMotor2(speed, reverse);
  delay(1000);
  setMotor1(0, 0);
  setMotor2(0, 0);
    delay(1000);
}

void setMotor1(int speed, boolean reverse)
{
  if (!speed) {
    digitalWrite(enablePin1, LOW);
    digitalWrite(in1Pin1, LOW);
    digitalWrite(in2Pin1, LOW);
  }
  analogWrite(enablePin1, speed);
  digitalWrite(in1Pin1, ! reverse);
  digitalWrite(in2Pin1, reverse);
}


void setMotor2(int speed, boolean reverse)
{
  if (!speed) {
    digitalWrite(enablePin2, LOW);
    digitalWrite(in1Pin2, LOW);
    digitalWrite(in2Pin2, LOW);
  }
  analogWrite(enablePin2, speed);
  digitalWrite(in1Pin2, ! reverse);
  digitalWrite(in2Pin2, reverse);
}
