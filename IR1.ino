#include <IRremote.hpp>

const int detectPin = 2;
const int statusPin = 4;

IRsend irsend;

void setup() {

pinMode(detectPin, INPUT);
pinMode(statusPin, OUTPUT);

irsend.enableIROut(38);

irsend.mark(0);
Serial.begin(9600);
}

void loop() {

Serial.println("test");
int LED_status = Library();
digitalWrite(statusPin, LED_status);


}


































int Library() {

randomSeed(analogRead(0));
delayMicroseconds(5000);
return random(2);
}
