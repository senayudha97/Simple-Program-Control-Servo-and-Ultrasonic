#include <Servo.h>

Servo servo;
const int trigPin = 9;
const int echoPin = 10;

//variable
long duration;
int distance;
int safetyDistance;



void setup() {
  servo.attach(8);
  servo.write(0);
  delay(2000);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;

  safetyDistance = distance;

  //print distane on serial monitor

  Serial.print("Distance: ");
  Serial.println(distance);

  if( distance <= 3000)
  {
    servo.write(100);
    delay(500);
    servo.write(0);
    delay(500);
    }
  else
  {
    servo.write(50);
    }

  

}
