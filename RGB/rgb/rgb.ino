#define kirmizi 9
#define yesil 10
#define mavi 11

int i=0;

void setup()
{
  pinMode(kirmizi, OUTPUT);
  pinMode(yesil, OUTPUT);
  pinMode(mavi, OUTPUT);
}

void loop()
{
  for(i=9; i<=11; i++){
    digitalWrite(kirmizi, LOW);
    digitalWrite(yesil, LOW);
    digitalWrite(mavi, LOW);
    digitalWrite(i, HIGH);
    delay(1000);
  }
}
