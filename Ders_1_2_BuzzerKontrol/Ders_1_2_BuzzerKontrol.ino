int buzzerPin=3;
int pot=A0;
int potDeger=0;
void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600);

}

void loop() {
  potDeger=analogRead(pot);
  Serial.println(potDeger);
  analogWrite(buzzerPin, potDeger);
  delay(1000);
  digitalWrite(buzzerPin, LOW);
  delay(1000);
}
