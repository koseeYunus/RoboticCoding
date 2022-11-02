#define led 3
int isik=0;
float sonDeger;

void setup() {

  pinMode(led, OUTPUT);
  Serial.begin(9600); 

}
void loop() {

  isik = analogRead(A0);
  sonDeger= map(isik,0,1023,0,255); 
  digitalWrite(led, sonDeger);
  Serial.println(sonDeger);
  delay(50);

  /*if (isik > 300) { 
    digitalWrite(led, LOW);
  }

  else { 
    digitalWrite(led, HIGH);
  }*/

}