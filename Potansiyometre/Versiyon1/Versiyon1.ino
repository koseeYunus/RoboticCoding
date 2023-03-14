int potPin=A0;
int ledPin=3;

int deger=0;
int ledDeger=0;

void setup() {
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); 
  
}

void loop() {
  deger=analogRead(potPin); 
  Serial.print("Potansiyometreden gelen deger : ");
  Serial.println(deger);

  ledDeger=map(deger, 0,1023, 0,255);
  Serial.print("Degistirilen deger : ");
  Serial.println(ledDeger);
  //delay(500);

  analogWrite(ledPin, ledDeger);

}
