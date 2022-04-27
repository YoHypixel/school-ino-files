int trigPin = 3;
int echoPin = 2;
long duration, cm, inches;

const int led1Pin = 11;
const int led2Pin = 10;
const int led3Pin = 9;
const int led4Pin = 8;
const int led5Pin = 7;
const int led6Pin = 6;
const int led7Pin = 5;
const int led8Pin = 4;


void updateLEDs();


void setup(){
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  pinMode(led5Pin, OUTPUT);
  pinMode(led6Pin, OUTPUT);
  pinMode(led7Pin, OUTPUT);
  pinMode(led8Pin, OUTPUT);
}
void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2)/74;

  updateLEDs();
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(200);
}

void updateLEDs(void){

  if(cm > 80)
    digitalWrite(led8Pin, HIGH);
  else
    digitalWrite(led8Pin, LOW);
  
  if(cm > 70)
    digitalWrite(led7Pin, HIGH);
  else
    digitalWrite(led7Pin, LOW);

  if(cm > 60)
    digitalWrite(led6Pin, HIGH);
  else
    digitalWrite(led6Pin, LOW);

  if(cm > 50)
    digitalWrite(led5Pin, HIGH);
  else
    digitalWrite(led5Pin, LOW);

  if(cm > 40)
    digitalWrite(led4Pin, HIGH);
  else
    digitalWrite(led4Pin, LOW);

  if(cm > 30)
    digitalWrite(led3Pin, HIGH);
  else
    digitalWrite(led3Pin, LOW);

  if(cm > 20)
    digitalWrite(led2Pin, HIGH);
  else
    digitalWrite(led2Pin, LOW);

  if(cm > 10)
    digitalWrite(led1Pin, HIGH);
  else
    digitalWrite(led1Pin, LOW);
}
