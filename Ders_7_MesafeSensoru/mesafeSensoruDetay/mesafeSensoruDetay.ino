#define buzzerPin 9
int echoPin = 10;
int trigPin = 11;

int maxDeger = 400;
int minDeger = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  int olcum = mesafe(maxDeger, minDeger);
  melodiCal(olcum*15);

}

int mesafe(int maxD, int minD)
{
  long gecenZaman, uzaklik;

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  gecenZaman = pulseIn(echoPin, HIGH);
  uzaklik = gecenZaman / 58.2;
  delay(50);

  if(uzaklik >= maxD || uzaklik <= minD)
  {
    return 0;
  }
  else{
    return uzaklik;
  }
}

int melodiCal(int beklemeSuresi)
{
  tone(buzzerPin, 256);
  delay(beklemeSuresi);
  
  noTone(buzzerPin);
  delay(beklemeSuresi);
  
}
