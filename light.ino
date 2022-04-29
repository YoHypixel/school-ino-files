const int buzzerPin = 2;
const int photoresistorPin = 7;
const int threshold = 800;

void setup(){
  pinMode(buzzerPin, OUTPUT);
  pinMode(photoresistorPin, INPUT);
}

void loop(){
  int voltage = analogRead(photoresistorPin);
  if (voltage > threshold){
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }
  delay(100);
}
