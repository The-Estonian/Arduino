const int ledOne = 2;
const int ledTwo = 3;
const int ledThree = 4;
const int ledFour = 5;
const int ledFive = 6;
const int ledSix = 7;
const int trigger = 8;

void lamps() {
  digitalWrite(ledOne, HIGH);
  delay(500);
  digitalWrite(ledTwo, HIGH);
  delay(500);
  digitalWrite(ledThree, HIGH);
  delay(500);
  digitalWrite(ledFour, HIGH);
  delay(500);
  digitalWrite(ledFive, HIGH);
  delay(500);
  digitalWrite(ledSix, HIGH);
  delay(500);
  digitalWrite(ledOne, LOW);
  delay(100);
  digitalWrite(ledTwo, LOW);
  delay(100);
  digitalWrite(ledThree, LOW);
  delay(100);
  digitalWrite(ledFour, LOW);
  delay(100);
  digitalWrite(ledFive, LOW);
  delay(100);
  digitalWrite(ledSix, LOW);
  delay(100);
}

void setup() {
  Serial.begin(115200);
  pinMode(ledOne, OUTPUT);
  pinMode(ledTwo, OUTPUT);
  pinMode(ledThree, OUTPUT);
  pinMode(ledFour, OUTPUT);
  pinMode(ledFive, OUTPUT);
  pinMode(ledSix, OUTPUT);
  pinMode(trigger, INPUT);
  digitalWrite(ledOne, LOW);
  digitalWrite(ledTwo, LOW);
  digitalWrite(ledThree, LOW);
  digitalWrite(ledFour, LOW);
  digitalWrite(ledFive, LOW);
  digitalWrite(ledSix, LOW);
}

void loop() {
  int triggerValue = digitalRead(trigger);
  Serial.println(triggerValue);
  if (triggerValue) {
    lamps();
  }
  delay(500);
}
