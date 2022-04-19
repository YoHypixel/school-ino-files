  const int led1Pin = 2;
  const int led2Pin = 3; 
  const int led3Pin = 4;
  const int led4Pin = 5;

  const int sensorPin =7;

  const int threshold_value = 700; // (700/1024)*5v = 3.41v

  int distance = 0;
  int current_color = 0; //Black = 0, White = 1

void setup ()
{
      Serial.begin(9600);
      pinMode(led1Pin, OUTPUT);
      pinMode(led2Pin, OUTPUT);
      pinMode(led3Pin, OUTPUT);
      pinMode(led4Pin, OUTPUT);
}

void loop () {

  int reading = analogRead(sensorPin);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("\n");

  Serial.print ("Color: ");
   if(current_color == 0)
     Serial.print("White");
   else
     Serial.print("Black");
   Serial.print("\n");

   if(reading > threshold_value) {
     if( current_color == 0) {
      distance++;
      current_color = 1;
     }
   }
   
   else{
     if ( current_color == 1 ) {
       distance++;
       current_color = 0;
     }  
   }
   
   if(distance % 4 == 0){
     digitalWrite(led4Pin, HIGH);
    } else {
     digitalWrite(led4Pin, LOW);
    }
   if(distance % 4 == 1)
     digitalWrite(led3Pin, HIGH);
   else
     digitalWrite(led3Pin, LOW);

   if(distance % 4 == 2)
     digitalWrite(led2Pin, HIGH);
   else
     digitalWrite(led2Pin, LOW);

   if(distance % 4 == 3)
     digitalWrite(led1Pin, HIGH);
   else
     digitalWrite(led1Pin, LOW);

   delay(5);
}

