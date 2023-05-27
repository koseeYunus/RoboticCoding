//L298N Bağlantısı   
  const int motorA1  = 5;  // L298N'in IN3 Girişi
  const int motorA2  = 6;  // L298N'in IN1 Girişi
  const int motorB1  = 10; // L298N'in IN2 Girişi
  const int motorB2  = 9;  // L298N'in IN4 Girişi

  int i=0; //Döngüler için atanan rastgele bir değişken
  int j=0; //Döngüler için atanan rastgele bir değişken
  int state; //Bluetooth cihazından gelecek sinyalin değişkeni
  int vSpeed=255;     // Standart Hız, 0-255 arası bir değer alabilir
void setup() {
    // Pinlerimizi belirleyelim
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);    
    // 9600 baud hızında bir seri port açalım
    Serial.begin(9600);
}
 
void loop() {

  //Gelen veriyi 'state' değişkenine kaydet
    if(Serial.available() > 0){     
      state = Serial.read();   
    }
  
  //Uygulamadan ayarlanabilen 4 hız seviyesi.(Değerler 0-255 arasında olmalı)
    if (state == '0'){
      vSpeed=0;}
    else if (state == '1'){
      vSpeed=100;}
    else if (state == '2'){
      vSpeed=180;}
    else if (state == '3'){
      vSpeed=200;}
    else if (state == '4'){
      vSpeed=255;
    }
     
  //Gelen veri 'F' ise araba ileri gider.
    if (state == 'F') {
      analogWrite(motorA1, vSpeed); 
      analogWrite(motorA2, 0);
      analogWrite(motorB1, vSpeed);  
      analogWrite(motorB2, 0); 
    }

  //Gelen veri 'G' ise araba ileri sol(çapraz) gider.
    else if (state == 'G') {
      analogWrite(motorA1,vSpeed ); 
      analogWrite(motorA2, 0);  
      analogWrite(motorB1, 100);   
      analogWrite(motorB2, 0); 
    }

  //Gelen veri 'I' ise araba ileri sağ(çapraz) gider.
    else if (state == 'I') {
        analogWrite(motorA1, 100); 
        analogWrite(motorA2, 0); 
        analogWrite(motorB1, vSpeed);      
        analogWrite(motorB2, 0); 
    }

  //Gelen veri 'B' ise araba geri gider.
    else if (state == 'B') {
      analogWrite(motorA1, 0);   
      analogWrite(motorA2, vSpeed); 
      analogWrite(motorB1, 0);   
      analogWrite(motorB2, vSpeed); 
    }

  //Gelen veri 'H' ise araba geri sol(çapraz) gider
    else if (state == 'H') {
      analogWrite(motorA1, 0);   
      analogWrite(motorA2, 100); 
      analogWrite(motorB1, 0); 
      analogWrite(motorB2, vSpeed); 
    }

  //Gelen veri 'J' ise araba geri sağ(çapraz) gider
    else if (state == 'J') {
      analogWrite(motorA1, 0);   
      analogWrite(motorA2, vSpeed); 
      analogWrite(motorB1, 0);   
      analogWrite(motorB2, 100); 
    }

  //Gelen veri 'L' ise araba sola gider.
    else if (state == 'L') {
      analogWrite(motorA1, vSpeed);   
      analogWrite(motorA2, 150); 
      analogWrite(motorB1, 0); 
      analogWrite(motorB2, 0); 
    }

  //Gelen veri 'R' ise araba sağa gider
    else if (state == 'R') {
      analogWrite(motorA1, 0);   
      analogWrite(motorA2, 0); 
      analogWrite(motorB1, vSpeed);   
      analogWrite(motorB2, 150);     
    }
  

  //Gelen veri 'S' ise arabayı durdur.
    else if (state == 'S'){
        analogWrite(motorA1, 0);  
        analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);  
        analogWrite(motorB2, 0);
    }  
    
}