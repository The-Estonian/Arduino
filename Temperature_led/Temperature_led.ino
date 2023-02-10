int sensorPin = A0;
int counter = 1;
float baseTemp = 20.0;
int firstLed = 2;
int secondLed = 3;
int thirdLed = 4;

void setup() {
  Serial.begin(115200);
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal/1024.0)*5.0;
  float temperature = (voltage - 0.5) * 100;
  Serial.println("-----------------------------------------");
  Serial.println("     Temperature count: " + String(counter));
  Serial.println("     Sensor Value: " + String(sensorVal));
  Serial.println("     Sensor voltage: " + String(voltage));
  Serial.println("     Temperature in Celcius: " + String(temperature));
  counter++;
  if (temperature < baseTemp + 3) {
    digitalWrite(firstLed, LOW);
    digitalWrite(secondLed, LOW);
    digitalWrite(thirdLed, LOW);
  } else if (temperature >= baseTemp + 3 && temperature < baseTemp + 4) {
    digitalWrite(firstLed, HIGH);
    digitalWrite(secondLed, LOW);
    digitalWrite(thirdLed, LOW);
  } else if (temperature >= baseTemp + 4 && temperature < baseTemp + 5) {
    digitalWrite(firstLed, HIGH);
    digitalWrite(secondLed, HIGH);
    digitalWrite(thirdLed, LOW);
  } else if ( temperature >= baseTemp + 5) {
    digitalWrite(firstLed, HIGH);
    digitalWrite(secondLed, HIGH);
    digitalWrite(thirdLed, HIGH);
  }
  delay(2000);
}

