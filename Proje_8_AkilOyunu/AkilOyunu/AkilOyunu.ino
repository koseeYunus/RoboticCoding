#define PLAYER_WAIT_TIME 2000 // Düğmeye basmalar arasında izin verilen süre - 2 saniye

byte sequence[100];           // ışık dizisi için depolama
byte  curLen = 0;              // Dizinin geçerli uzunluğu
byte inputCount =  0;          // Oynatıcının belirli bir dönüşte (doğru) bir düğmeye kaç kez bastığı
byte lastInput = 0;           // Oynatıcıdan son giriş
byte  expRd = 0;               // Oynatıcı tarafından yanması gereken LED
bool  btnDwn = false;          // Bir düğmeye basılıp basılmadığını kontrol etmek için kullanılır
bool wait =  false;            // Kullanıcının bir düğmeye basmasını bekleyen programdır
bool  resetFlag = false;       // Oyuncunun bir kez kaybettiğini programa belirtmek için kullanılır

byte soundPin = 11;            // Buzzer output

byte noPins =  4;              // Düğme / LED sayısı 
                              // Ek bir LED / düğme / direnç kombinasyonu ekleyerek oyunu zorlaştırabilirsiniz.
byte pins[] = {2, 3, 4, 5};  // Buton giriş pimleri ve LED çıkış pimleri - düğmelerinizi diğer pinlere bağlamak istiyorsanız bu anahtarları değiştirin
                              // Öğe sayısı aşağıdaki noPins ile eşleşmelidir
                              
long inputTime = 0;           // Kullanıcı girişleri arasındaki gecikme için zamanlayıcı değişkeni

void setup()  {
  delay(3000);                // Bu, arduino'yu bağladıktan sonra nefes almam için bana zaman vermek içindir 
  Serial.begin(9600);         // Seri monitörü başlat. Aşağıdaki Seriye yapılan tüm referansları kaldırdığınız sürece kaldırılabilir
  Reset();
}

///
/// Tüm pimleri 'dir' değerine göre GİRİŞ veya çıkış olarak ayarlar
///
void setPinDirection(byte dir){
  for(byte i = 0; i < noPins; i++){
    pinMode(pins[i], dir); 
  }
}

// Tüm LED pinlerine aynı değeri gönderin
void writeAllPins(byte val){
  for(byte  i = 0; i < noPins; i++){
    digitalWrite(pins[i], val); 
  }
}

// Çok sinir bozucu :) bir bip sesi çıkarır
void beep(byte freq){
  analogWrite(soundPin,  2);
  delay(freq);
  analogWrite(soundPin, 0);
  delay(freq);
}

///
///  Tüm LED'leri birlikte yanıp söner
/// freq yanıp sönme hızıdır - küçük sayı -> hızlı / büyük sayı -> yavaş
///
void flash(short freq){
  setPinDirection(OUTPUT);  /// We're activating the LEDS now
  for(int i = 0; i < 5; i++){
    writeAllPins(HIGH);
    beep(50);
    delay(freq);
    writeAllPins(LOW);
    delay(freq);
  }
}

///
/// Bu işlev tüm oyun değişkenlerini varsayılan değerlerine sıfırlar
///
void Reset(){
  flash(500);
  curLen = 0;
  inputCount  = 0;
  lastInput = 0;
  expRd = 0;
  btnDwn = false;
  wait = false;
  resetFlag = false;
}

///
/// Oyuncu kaybetti
///
void Lose(){
  flash(50);  
}

///
/// Arduino kullanıcıya neyin ezberlenmesi gerektiğini gösterir
///  Ayrıca kaybettikten sonra son dizinizin ne olduğunu göstermek için çağrılır
///
void playSequence(){
  // Saklanan sıra boyunca döngü yapın ve sırayla uygun LED'leri yakın
  for(int i = 0; i < curLen; i++){
      Serial.print("Seq: ");
      Serial.print(i);
      Serial.print("Pin: ");
      Serial.println(sequence[i]);
      digitalWrite(sequence[i],  HIGH);
      delay(500);
      digitalWrite(sequence[i], LOW);
      delay(250);
    } 
}

///
/// Bir kayıp üzerine meydana gelen olaylar
///
void DoLoseProcess(){
  Lose();             // Tüm LED'leri hızlı bir şekilde yanıp söner
  delay(1000);
  playSequence();     // Kullanıcıya son diziyi gösterir - Böylece en iyi puanınızı hatırlayabilirsiniz
  delay(1000);
  Reset();            //  Yeni bir oyun için her şeyi sıfırla
}

///
///  Bütün oyunun gerçekleştiği yer
///
void  loop() {  
  if(!wait){      
                            //****************//
                            // Arduino'nun sırası //
                            //****************//
    setPinDirection(OUTPUT);                      // LED'leri kullanıyoruz
    
    randomSeed(analogRead(A0));                   // https://www.arduino.cc/en/Reference/RandomSeed
    sequence[curLen] = pins[random(0,noPins)];    // Sıradaki bir sonraki konuma yeni bir rastgele değer koyun -  https://www.arduino.cc/en/Reference/random
    curLen++;                                     // Dizinin yeni Geçerli uzunluğunu ayarlayın
    
    playSequence();                               //  Diziyi oynatıcıya göster
    beep(50);                                     //  Oynatıcının farkında olması için bir bip sesi çıkarın
    
    wait = true;                                  //  Wait'i true olarak ayarlayın, çünkü şimdi oyuncunun sırası olacak
    inputTime  = millis();                         //  Oyuncunun tepki süresini ölçmek için zamanı saklayın
  }else{ 
                            //***************//
                            //  Oyuncunun sırası //
                            //***************//
    setPinDirection(INPUT);                       // Butonları kullanıyoruz

    if(millis() - inputTime  > PLAYER_WAIT_TIME){  // Oyuncu izin verilen süreden fazla sürerse,
      DoLoseProcess();                            // Oyun biter :(
      return;
    }      
        
    if(!btnDwn){                                  // 
      expRd  = sequence[inputCount];               // Oynatıcıdan beklediğimiz değeri bulun
      Serial.print("Expected: ");                 // Serial Monitor Output - Seriyi kaldırdıysanız kaldırılmalıdır.
      Serial.println(expRd);                      // Beklenen :
      
      for(int i = 0; i < noPins; i++){           //  Tüm pimler arasında döngü yapın
        if(pins[i]==expRd)                        
          continue;                               // Doğru pın'i yoksay
        if(digitalRead(pins[i]) == HIGH){         // Düğmeye basıldı mı
          lastInput = pins[i];
          resetFlag = true;                       //  Resetflag'ı ayarlayın - bu, kaybettiğiniz anlamına gelir
          btnDwn = true;                          //  Bu, programın aynı şeyi tekrar tekrar yapmasını engelleyecektir
          Serial.print("Read: ");                 // Serial Monitor Output - Should  be removed if you removed the Serial.begin above
          Serial.println(lastInput);              // Serial Monitor Output - Should be removed if you removed the Serial.begin  above
        }
      }      
    }

    if(digitalRead(expRd) ==  1 && !btnDwn)        // Oyuncu sağ düğmeye bastı
    {
      inputTime  = millis();                       // 
      lastInput = expRd;
      inputCount++;                               // Kullanıcı tekrar (doğru) bir düğmeye bastı
      btnDwn = true;                              // Bu, programın aynı şeyi tekrar tekrar yapmasını engelleyecektir
      Serial.print("Read: ");                     // Serial Monitor Output - Seriyi kaldırdıysanız kaldırılmalıdır.
      Serial.println(lastInput);                  // 
    }else{
      if(btnDwn && digitalRead(lastInput) == LOW){  // Oynatıcının butonu bırakıp bırakmadığını kontrol edin
        btnDwn = false;
        delay(20);
        if(resetFlag){                              // Bu yukarıda true olarak ayarlanmışsa, kaybettiniz
          DoLoseProcess();                          // olayların kaybetme sırası yapılır
        }
        else{
          if(inputCount == curLen){                 //  Oyuncu diziyi tekrarlamayı bitirdi mi
            wait = false;                           //  Eğer öyleyse, bu bir sonraki dönüşü programın dönüşünü sağlayacaktır
            inputCount  = 0;                         // Oynatıcının bir düğmeye kaç kez bastığını sıfırlayın
            delay(1500);
          }
        }
      }
    }    
  }
}
