void setup() {
  // put your setup code here, to run once:
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // Show a "S"
  int i;

    for(i=1; i<=9; i++){
    digitalWrite(i, HIGH);
  }
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  delay(1000);
  

  
  for(i=1; i<=9; i++){
    digitalWrite(i, HIGH);
  }
  //digitalWrite(1, LOW);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  //digitalWrite(9, LOW);
  
  delay(1000);

    for(i=1; i<=9; i++){
    digitalWrite(i, HIGH);
  }
  digitalWrite(6, LOW);
  delay(1000);
  

  
}
