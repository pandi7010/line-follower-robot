// Define sensor pins
#define sensorLeft 2
#define sensorRight 3

// Define motor pins
#define motorA1 9
#define motorA2 10
#define motorB1 5
#define motorB2 6

void setup() {
  // Set sensors as input
  pinMode(sensorLeft, INPUT);
  pinMode(sensorRight, INPUT);
  
  // Set motor pins as output
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
}

void loop() {
  int leftSensor = digitalRead(sensorLeft);  // Read left sensor
  int rightSensor = digitalRead(sensorRight);  // Read right sensor
  
  // Case 1: Both sensors detect the line
  if (leftSensor == HIGH && rightSensor == HIGH) {
    moveForward();  // Move forward
  }
  // Case 2: Left sensor off the line
  else if (leftSensor == LOW && rightSensor == HIGH) {
    turnRight();  // Turn right
  }
  // Case 3: Right sensor off the line
  else if (leftSensor == HIGH && rightSensor == LOW) {
    turnLeft();  // Turn left
  }
  // Case 4: Both sensors off the line (optional, stop or reverse)
  else {
    stopMotors();  // Stop
  }
}

void moveForward() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void turnRight() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void turnLeft() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void stopMotors() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}
