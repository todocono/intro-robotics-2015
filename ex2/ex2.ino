#define E1 10  // Enable Pin for motor 1
#define E2 11  // Enable Pin for motor 2

#define I1 8  // Control pin 1 for motor 1
#define I2 9  // Control pin 2 for motor 1
#define I3 12  // Control pin 1 for motor 2
#define I4 13  // Control pin 2 for motor 2

int speed1 = 250;

void setup() {

  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);

  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);
  pinMode(I3, OUTPUT);
  pinMode(I4, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  Serial.println("Step Forward");
  moveForward();
  delay(2000);  // wait in milliseconds

  Serial.println("Step Backward");
  moveBackward();
  delay(2000);

  Serial.println("Turn Right");
  moveRight();
  delay(2000);

  Serial.println("Turn Left");
  moveLeft();
  delay(2000);
}


void moveForward( void ) {
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

void moveBackward( void ) {
  digitalWrite(E1, LOW); // both motors stopped while transitioning
  digitalWrite(E2, LOW);

  delay(200);
  analogWrite(E1, speed1); // Activate both motors at same speed
  analogWrite(E2, speed1);

  digitalWrite(I1, HIGH);	// with opposite direction than before
  digitalWrite(I2, LOW);
  digitalWrite(I3, HIGH);
  digitalWrite(I4, LOW);
}

void moveRight( void ) {
  analogWrite(E1, speed1); // Activate both motors at same speed
  analogWrite(E2, speed1);

  digitalWrite(I1, LOW);	// with opposite direction than before
  digitalWrite(I2, HIGH);
  digitalWrite(I3, LOW);
  digitalWrite(I4, HIGH);
}

void moveLeft ( void ){
  analogWrite(E1, speed1); // Activate both motors at same speed
  analogWrite(E2, speed1);

  digitalWrite(I1, LOW);	// with opposite direction than before
  digitalWrite(I2, HIGH);
  digitalWrite(I3, LOW);
  digitalWrite(I4, HIGH);
}
