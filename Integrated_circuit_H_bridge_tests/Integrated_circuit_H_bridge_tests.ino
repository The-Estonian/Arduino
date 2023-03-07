const int potePin = A0;
const int direction = 4;
const int onOff = 5;
const int enablePin = 9;
const controlPin1 = 2;
const controlPin2 = 3;

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
  int poteValue = analogRead(potePin);
  int directionValue = digitalRead(direction);
  int onOffValue = digitalRead(onOff);
  delay(1);

}
