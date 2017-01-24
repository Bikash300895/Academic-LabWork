int s3 = 13;
int s2 = 12;
int s1 = 11;
int delTIme = 500;

void setup() {
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  
}

int s2Count = 2;
bool s2high = false;

void loop() {
  //000
  digitalWrite(s1,LOW);
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW);
  delay(delTIme);

  int i=0;
  while(i<8){
    
    if(i%2==0){
      digitalWrite(s1,LOW);
    }else{
       digitalWrite(s1,HIGH);
    }

    
    if(s2high==true){
      digitalWrite(s2,HIGH);
      s2Count--;
    } else {
      digitalWrite(s2,LOW);
      s2Count--;
    }
    if(s2Count==0){
      s2Count=2;
      if(s2high==true){
        s2high=false;
      }else{
        s2high=true;
      }
    }

    if(i>4){
      digitalWrite(s3,HIGH);
    }else{
      digitalWrite(s3,LOW);
    }
    i++;
    delay(500);
  }
  
  
  
}
