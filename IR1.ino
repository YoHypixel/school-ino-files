#include <IRremote.hpp>


const int detectPin = 2;
const int statusPin = 4;

IRsend irsend;

void setup() {

pinMode(detectPin, INPUT);
pinMode(statusPin, OUTPUT);

irsend.enableIROut(38);

irsend.mark(0);

}

void loop() {

int LED_status = !digitalRead(detectPin);
digitalWrite(statusPin, LED_status);


}
