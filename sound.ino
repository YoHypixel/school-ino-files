int ledPin = 3;
int inputPin = 0;
int val = 0;

volatile int blink_leds = 0;

void setup() {
  pinMode(ledPin, OUTPUT);

  attachInterrupt(inputPin, blink, FALLING);
}

void loop() {
int i =0;

if (blink_leds == i) {
  for (i=0;i<5;i++) {
    digitalWrite(ledPin, HIGH);
    delay(50);
    digitalWrite(ledPin, LOW);
    delay(50);
  }
  blink_leds =0;
}
delay(100);
}

void blink() {
  blink_leds = 1;
}
