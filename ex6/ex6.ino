/*
   Example 6
   Introduction to Robotics
   by Rodolfo Cossovich at New York University
   Description: Using example 5 with a Switch-Case statement. Sensor also got hysteresis
*/

int HYS = 20;
byte state = 0; //default state
int LDR1 = A1;

void setup() {
  pinMode(13, OUTPUT);//initialize our only output (the onboard LED)
  Serial.begin(9600);// initialize serial communication at 9600 bits per second:
}

void loop() {
  updateState();
  delay(10);        // delay in between reads for stability
  switch (state) {
    case 0:
      night();
      break;
    case 1:
      day();
      break;
    default:
      day();

  }
}


void updateState(void) {  //note that this function is giving back the value as a result of evaluating the inputs
  int sensorValue = analogRead(LDR1);  // read the input on analog pin:
  Serial.println(sensorValue);  // we print on the serial monitor the value, just for debugging

  if (sensorValue > 200 + HYS ) {
    state = 1;         // in case the sensor is reading high value, there is light
  }
  else if (sensorValue <= 200 - HYS) {
    state =  0;  // in case the sensor is reading low value, it is dark
  }
}

void day(void) {      // what do we do if it's day time
  digitalWrite(13, LOW); //just for the sake of an example, we switch off a light
}

void night(void) {      // what do we do if it's day time
  digitalWrite(13, HIGH); //just for the sake of an example, we switch on during night time
  delay (8000);    //we wait 8 seconds (representing 8 hours of night time)
  state = 0;      // after that, we reset the system status
}


