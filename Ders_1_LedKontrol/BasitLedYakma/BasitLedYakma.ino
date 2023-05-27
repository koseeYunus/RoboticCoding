//Kırmızı ledin bağlı olduğu pin numarasını KirmiziLed adlı değişkene aktardık.
int KirmiziLed=10; 

//Sarı ledin bağlı olduğu pin numarasını SariLed adlı değişkene aktardık.
int SariLed=9; 

//Yeşil ledin bağlı olduğu pin numarasını YesilLed adlı değişkene aktardık.
int YesilLed=8; 
 
void setup() {
  //Kırmızı ledin olduğu (10 numaları) pini çıkış pini olarak belirttik.  
  pinMode(KirmiziLed, OUTPUT); 

  //Sarı ledin olduğu (9 numaları) pini çıkış pini olarak belirttik.  
  pinMode(SariLed, OUTPUT); 

  //Yeşil ledin bağlı olduğu (8 numaları) pini çıkış pini olarak belirttik.  
  pinMode(YesilLed, OUTPUT); 
}
 
void loop() {
  //3 led'e aynı anda güç vererek yakıyoruz.
  digitalWrite(KirmiziLed, HIGH); 
  digitalWrite(SariLed, HIGH); 
  digitalWrite(YesilLed, HIGH); 
  
  delay(1000); // 1saniye bekletiyoruz.

  //Ledlerin gücünü keserek söndürüyoruz.
  digitalWrite(KirmiziLed, LOW); 
  digitalWrite(SariLed, LOW); 
  digitalWrite(YesilLed, LOW); 
 
  delay(1000); // 1 saniye bekletiyoruz.  
 
}
