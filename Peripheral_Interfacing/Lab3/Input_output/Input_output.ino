int input = 12;
int output = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(input, INPUT);
  pinMode(output, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pinstate = digitalRead(input);
  if(pinstate==1){
    digitalWrite(output, HIGH);
  } else {
    digitalWrite(output, LOW);
  }
}
