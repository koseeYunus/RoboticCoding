int buzzerPin=6;
int ledPin=5;
void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(ledPin, LOW);
  Serial.println("buzzer caldi, led sondu.")
  delay(750);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, HIGH);
  Serial.println("buzzer sustu, led yandi.")
  delay(750);
  
}
