int ledPin = 11;
int brightness = 0;
int fadeamount = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  brightness+=fadeamount;
  analogWrite(ledPin, brightness);
  String s = String("Curernt brightness");
  //Serial.write("Current brightness ");
  Serial.println(s + brightness);
  
  if(brightness<=0 || brightness>=255){
    fadeamount = -fadeamount;
  }
  delay(10);
}
