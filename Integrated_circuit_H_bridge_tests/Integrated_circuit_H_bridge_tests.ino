const int potePin = A0;
const int direction = 4;
const int onOff = 5;
const int enablePin = 9;
const int controlPin1 = 2;
const int controlPin2 = 3;

int onOffState = 0;
int previousOnOffState = 0;
int directionState = 0;
int previousDirectionState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
  Serial.begin(115200);
  pinMode(direction, INPUT);
  pinMode(onOff, INPUT);
  pinMode(controlPin1, OUTPUT); 
  pinMode(controlPin2, OUTPUT); 
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);
}

void loop() {
  int motorSpeed = analogRead(potePin);
  int directionState = digitalRead(direction);
  int onOffState = digitalRead(onOff);
  delay(1);
  if (onOffState != previousOnOffState) {
    if (onOffState == HIGH) {
      motorEnabled = !motorEnabled;
      Serial.println("Motor enabled!");
    }
  }

  if (directionState != previousDirectionState) {
    if (directionState == HIGH) {
      motorDirection = !motorDirection;
      Serial.println("Motor direction adjust!");
    }
  }

  if (motorDirection == 1) {
    Serial.println("Motor direction forward!");
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  } else {
    Serial.println("Motor direction backwards!");
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  }

  if (motorEnabled == 1) {
    analogWrite(enablePin, motorSpeed);
    Serial.println("Motor activated!");
  } else {
    Serial.println("Motor disabled!");
    analogWrite(enablePin, 0);
  }

  previousOnOffState = onOffState;
  previousDirectionState = directionState;
}
