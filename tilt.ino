const int tiltPin = 2;
const int buzzerPin = 3;

int tiltState = 0;

void setup() {
  // initialize the buzzer pin as an output:
  pinMode(buzzerPin, OUTPUT);
  // initialize the tilt pin as an input:
  pinMode(tiltPin, INPUT);
}

void loop() {
  tiltState = digitalRead(tiltPin);

  if (tiltState == LOW) {
    // turn Buzzer off:
    digitalWrite(buzzerPin, HIGH);
  }
  else {
    // turn Buzzer on:
    digitalWrite(buzzerPin, LOW);
  }
}
