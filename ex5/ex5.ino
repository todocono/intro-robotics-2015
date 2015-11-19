/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

 This example code is in the public domain.
 */

// the setup routine runs once when you press reset:
void setup() {
  pinMode(13, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  readSensor();
  delay(10);        // delay in between reads for stability
  if (day()) {
    digitalWrite (13, HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }
}

void readSensor(void){
  // read the input on analog pin 0:
  int sensorValue = analogRead(A1);
  // print out the value you read:
  Serial.println(sensorValue);
}

int day(void){
  // read the input on analog pin 0:
  int sensorValue = analogRead(A1);
  if (sensorValue > 200){
    return 1;
  }
  else{
    return 0;
  }
    
}


