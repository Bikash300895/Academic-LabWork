#include <Servo.h>
 

const int trigPin = 11;
const int echoPin = 10;

long duration;
int distance;

Servo myServo; 

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  myServo.attach(12); 
}


void loop() {
  
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(100);
  distance = calculateDistance();
  
  Serial.print(i); 
  Serial.print(",");
  Serial.print(distance);
  Serial.print("."); 
  Serial.println();
  }
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(100);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  Serial.println();
  }
}

int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}
