  // sensor pins
  const int blueSensor = A2;
  const int greenSensor = A1;
  const int redSensor = A0;
  // led pins
  const int redLed = 9;
  const int blueLed = 10;
  const int greenLed = 11;

  // led/sensor base values

  int redOut = 0;
  int greenOut = 0;
  int blueOut = 0;

  int redIn = 0;
  int greenIn = 0;
  int blueIn = 0;
void setup() {
  Serial.begin(115200);

  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

}

void loop() {
  int currentRedIn = analogRead(redSensor);
  int currentGreenIn = analogRead(greenSensor);
  int currentBlueIn =  analogRead(blueSensor);
  int rgbRed = currentRedIn/4;
  int rgbGreen = currentGreenIn/4;
  int rgbBlue = currentBlueIn/4;
  Serial.print("Red sensor value: ");
  Serial.println(rgbRed);
  Serial.print("Green sensor value: ");
  Serial.println(rgbGreen);
  Serial.print("Blue sensor value: ");
  Serial.println(rgbBlue);
  Serial.println("-------------------------");
  analogWrite(redLed, rgbRed);
  analogWrite(greenLed, rgbGreen);
  analogWrite(blueLed, rgbBlue);
  delay(1000);
}
