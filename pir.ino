int ledPin = 2;
int inputPin = 3;
int pirState = LOW;
int  val = 0;
int pinSpeaker = 10;

void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);
  pinMode(pinSpeaker, OUTPUT);
  digitalWrite(pinSpeaker, HIGH);
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(inputPin);
  Serial.println("\n\n\nvalue: " + val);
  if(val == HIGH) {
    digitalWrite(ledPin, HIGH);

    if (pirState == LOW) {
          Serial.println("Motion Detected");
          pirState = HIGH;

          digitalWrite(pinSpeaker, HIGH);
    }
    
  } else {
    digitalWrite(ledPin, LOW);
    if (pirState == HIGH) {
      Serial.println("Motion Ended!");

      digitalWrite(pinSpeaker, LOW);

      pirState = LOW;
    }
  }
}
