const int sensorPin = 7;
const int ledPin = 2; 
const int buzzerPin = 3;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}
void loop() // run over and over again 
{
int reading = analogRead(sensorPin);

float voltage = reading * 5;
voltage /= 1024.0;

Serial.print(voltage); Serial.println("volts");

float temperatureC = (voltage - 0.5) * 100 ;
Serial.print(temperatureC); Serial.println("degrees C");

float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
Serial.print(temperatureF); Serial.println("degrees F");

if (temperatureC < 30 && temperatureC > 25 ){
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, HIGH);
}
else if( temperatureC < 25 )
  digitalWrite(ledPin, HIGH);
else if( temperatureC > 30 )
  digitalWrite(buzzerPin, LOW);

delay(100);
}
