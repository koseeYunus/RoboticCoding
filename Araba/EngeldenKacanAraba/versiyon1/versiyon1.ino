const int solMotorIleri=2;
const int solMotorGeri=3;
const int sagMotorIleri=4;
const int sagMotorGeri=5;


void setup() {
  for(int i=2; i<6; i++){
    pinMode(i, OUTPUT);
  }

}

void loop() {
  ileri();
  delay(2000);
  dur();
  sag();
  delay(2000);
  dur();
  sol();
  delay(2000);
  geri();
  delay(2000);
}

void ileri(){
  digitalWrite(solMotorIleri, 1);
  digitalWrite(solMotorGeri, 0);
  digitalWrite(sagMotorIleri, 1);
  digitalWrite(sagMotorGeri, 0);
  delay(2000);
}
void dur(){
  digitalWrite(solMotorIleri, 0);
  digitalWrite(solMotorGeri, 0);
  digitalWrite(sagMotorIleri, 0);
  digitalWrite(sagMotorGeri, 0);
}
void geri(){
  digitalWrite(solMotorIleri, 0);
  digitalWrite(solMotorGeri, 1);
  digitalWrite(sagMotorIleri, 0);
  digitalWrite(sagMotorGeri, 1);
}

void sag(){
  digitalWrite(solMotorIleri, 1);
  digitalWrite(solMotorGeri, 0);
  digitalWrite(sagMotorIleri, 0);
  digitalWrite(sagMotorGeri, 1);
}

void sag(){
  digitalWrite(solMotorIleri, 0);
  digitalWrite(solMotorGeri, 1);
  digitalWrite(sagMotorIleri, 1);
  digitalWrite(sagMotorGeri, 0);
}
