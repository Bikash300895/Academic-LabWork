int s3 = 13;
int s2 = 12;
int s1 = 11;
int delTIme = 500;

void setup() {
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  
}

void loop() {
  //000
  digitalWrite(s1,LOW);
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW);
  delay(delTIme);
  
  //001
  digitalWrite(s1,LOW);
  digitalWrite(s2,LOW);
  digitalWrite(s3,HIGH);
  delay(delTIme);

  //010
  digitalWrite(s1,LOW);
  digitalWrite(s2,HIGH);
  digitalWrite(s3,LOW);
  delay(delTIme);

  //011
  digitalWrite(s1,LOW);
  digitalWrite(s2,HIGH);
  digitalWrite(s3,HIGH);
  delay(delTIme);

  //100
  digitalWrite(s1,HIGH);
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW);
  delay(delTIme);

  //101
  digitalWrite(s1,HIGH);
  digitalWrite(s2,LOW);
  digitalWrite(s3,HIGH);
  delay(delTIme);

  //110
  digitalWrite(s1,HIGH);
  digitalWrite(s2,HIGH);
  digitalWrite(s3,LOW);
  delay(delTIme);
  
  //111
  digitalWrite(s1,HIGH);
  digitalWrite(s2,HIGH);
  digitalWrite(s3,HIGH);
  delay(delTIme);
  
  
  
}
