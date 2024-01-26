//#include "deneyap.h"  
//#include "ServoESP32.h"

//#include <deneyap.h>
//#include <Deneyap_Servo.h>

#include <Servo.h>

int sag_sol_aci=90;
int ileri_geri_aci=90;
int asagi_yukari_aci=90;
int kiskac_aci=90; 

int sag_sol = 0;      
int ileri_geri = 0;
int asagi_yukari = 0;
int kiskac = 0;

int joyBtn1= 1;
int joyBtn2= 1;

Servo servo_1;    //Servo_1 isimli nesne oluşturuldu
Servo servo_2;    //Servo_2 isimli nesne oluşturuldu
Servo servo_3;    //Servo_3 isimli nesne oluşturuldu
Servo servo_4;    //Servo_4 isimli nesne oluşturuldu

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);

  pinMode(D0, INPUT_PULLUP);
  pinMode(D1, INPUT_PULLUP);

  servo_1.attach(D11);    //Servo_1 motorun sinyal pini 4 nolu arduino pinine bağlandı (alttaki servo)
  servo_2.attach(D12);    //Servo_2 motorun sinyal pini 5 nolu arduino pinine bağlandı (Sağ yandaki servo)
  servo_3.attach(D13);    //Servo_3 motorun sinyal pini 6 nolu arduino pinine bağlandı (Sol yandaki servo)
  servo_4.attach(D14);    //Servo_4 motorun sinyal pini 7 nolu arduino pinine bağlandı (kıskaç)
  Serial.begin(9600);
}

void loop() {
  //Joysticklerin bağlı olduğu analog pinler okunup değişkenlere kaydediliyor
  sag_sol = analogRead(A0);      
  ileri_geri = analogRead(A1);
  asagi_yukari = analogRead(A2);
  kiskac = analogRead(A3);

  joyBtn1= digitalRead(D0);
  joyBtn2= digitalRead(D2);

  //Degerleri serial ekrana yazdırıyor
  Serial.println("-----  OKUNAN DEGERLER  -----");
  Serial.print("Sag - Sol => ");
  Serial.println(sag_sol);
  Serial.print("Ileri - Geri => ");
  Serial.println(ileri_geri);
  Serial.print("Asagi - Yukari => ");
  Serial.println(asagi_yukari);
  Serial.print("Kiskac => ");
  Serial.println(kiskac);
  Serial.println("       ---------------       ");
  delay(250);

  if(sag_sol > 3000 && sag_sol_aci<180){
    sag_sol_aci = sag_sol_aci + 1;
  }
  if(sag_sol < 1000 && sag_sol_aci>0){
    sag_sol_aci = sag_sol_aci - 1;
  }
  if(ileri_geri > 3000 && ileri_geri_aci<180){
    ileri_geri_aci = ileri_geri_aci + 1;
  }
  if(ileri_geri < 1000 && ileri_geri_aci>0){
    ileri_geri_aci = ileri_geri_aci - 1;
  }
  if(asagi_yukari > 3000 && asagi_yukari_aci<180){
    asagi_yukari_aci = asagi_yukari_aci + 1;
  }
  if(asagi_yukari < 1000 && asagi_yukari_aci>0){
    asagi_yukari_aci = asagi_yukari_aci - 1;
  }
  if(kiskac > 3000 && kiskac_aci<180){
    kiskac_aci = kiskac_aci + 1;
  }
  if(kiskac < 1000 && kiskac_aci>0){
    kiskac_aci = kiskac_aci - 1;
  }

  servo_1.write(sag_sol_aci);
  servo_2.write(ileri_geri_aci);
  servo_3.write(asagi_yukari_aci);
  servo_4.write(kiskac_aci);
}