int inputButton = 13;
int green = 12;
int yellow = 11;
int red = 10;
bool justGreen = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(inputButton,INPUT);
  pinMode(green,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(red,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(inputButton)
  if(buttonState == HIGH){
    digitalWrite(red, HIGH);
    digitalWrite(yellow,LOW);
    digitalWrite(green, LOW);
    justGreen = true;
  } else if(justGreen == true){
    digitalWrite(yellow,HIGH);
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
    delay(3000);
    justGreen = false;
  } else{
    digitalWrite(green, HIGH);
    digitalWrite(yellow,LOW);
    digitalWrite(red, LOW);
  }
    
}
