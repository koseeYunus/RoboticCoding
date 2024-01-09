#include <Servo.h>// servo motor kütüphanesi

//motor pinleri
#define SolMotorileri 8
#define SolMotorGeri 9
#define SagMotorileri 10
#define SagMotorGeri 11

//sensör pinleri
int echoPin = 13;
int trigPin = 6;

Servo servo; //servo motor tanımlama

//kullanılacak eleman tanımı
int uzaklik;
int on_uzaklik;
int sol_uzaklik;
int sag_uzaklik;
int zaman;

// program ilk çalıştığında sadece bir kez çalışacak programlar
void setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //motor çıkışları
  pinMode(SolMotorileri, OUTPUT);
  pinMode(SolMotorGeri, OUTPUT);
  pinMode(SagMotorileri, OUTPUT);
  pinMode(SagMotorGeri, OUTPUT);
  servo.attach(12); //servo pin tanımı
  Serial.begin(9600);
}

void loop()
{
  delay(100);
  servo.write(90);
  sensor_olcum();
  on_uzaklik = uzaklik;
  
  if(on_uzaklik > 25 || on_uzaklik < 2){
    ileri();
  }
  else{
    sagSolBak();

    if(sag_uzaklik<25 && sol_uzaklik<25){
      geri();
      delay(1000);

      sagSolBak();

      if(sag_uzaklik>sol_uzaklik){
        sag();
        delay(600);
        ileri();
      }
      else{
        sol();
        delay(600);
        ileri();
      }
    }
    if(sag_uzaklik>sol_uzaklik){
      sag();
      delay(600);
      ileri();
    }
    else if(sol_uzaklik >sag_uzaklik){
      sol();
      delay(600);
      ileri();
    }
    else{
      geri();
      delay(1000);
    }
  }
}
void sagSolBak(){
  dur();
  servo.write(180);
  delay(750);
  sensor_olcum();
  sol_uzaklik = uzaklik;
  servo.write(0);
  delay(750);
  sensor_olcum();
  sag_uzaklik = uzaklik;
  servo.write(90);
  delay(300);
}
  
// robotun yön komutları
void ileri(){
  digitalWrite(SolMotorGeri, LOW);
  digitalWrite(SolMotorileri, HIGH);
  digitalWrite(SagMotorGeri, LOW);
  digitalWrite(SagMotorileri, HIGH);
}
  
void geri(){
  digitalWrite(SolMotorileri, LOW);
  digitalWrite(SolMotorGeri, HIGH);
  digitalWrite(SagMotorileri, LOW);
  digitalWrite(SagMotorGeri, HIGH);
}
  
void sol(){
  digitalWrite(SolMotorileri, LOW);
  digitalWrite(SolMotorGeri, HIGH);
  digitalWrite(SagMotorGeri, LOW);
  digitalWrite(SagMotorileri, HIGH);
}
  
void sag(){
  digitalWrite(SolMotorGeri, LOW);
  digitalWrite(SolMotorileri, HIGH);
  digitalWrite(SagMotorileri, LOW);
  digitalWrite(SagMotorGeri, HIGH);
}
  
void dur(){
  digitalWrite(SolMotorGeri, LOW);
  digitalWrite(SolMotorileri, LOW);
  digitalWrite(SagMotorileri, LOW);
  digitalWrite(SagMotorGeri, LOW);
}
// sensörün mesafe ölçümü
void sensor_olcum(){
  long gecenZaman;

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  gecenZaman = pulseIn(echoPin, HIGH);
  uzaklik = gecenZaman / 58.2;
  delay(50);
  Serial.println(uzaklik);

}