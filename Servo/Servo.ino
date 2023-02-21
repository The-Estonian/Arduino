#include <Servo.h>

Servo firstServo;

const int potePin = A1;
const int servoPin = 9;

int potPosition = 0;
int servoAngle = 0;

void setup() {
  Serial.begin(115200);
  firstServo.attach(servoPin);
}

void loop() {
  potPosition = analogRead(potePin);
  Serial.println(potPosition);
  servoAngle = map(potPosition, 0, 1023, 0, 179);
  Serial.println(servoAngle);
  firstServo.write(servoAngle);
  Serial.println("---------------------------------");
  delay(15);
}
