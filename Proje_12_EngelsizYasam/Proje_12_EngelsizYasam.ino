#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

String readSerial;

int s1 = 2;
int s2 = 2;
int s3 = 2;

int d1,d2,d3;

void setup() {
  mySoftwareSerial.begin(9600);
  Serial.begin(9600);
  Serial.println(F("Voice Controlled mp3 player Demo."));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true);
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.setTimeOut(500); //Set serial communictaion time out 500ms

  //----Set volume----
  myDFPlayer.volume(30);  //Set volume value (0~30).

  //----Set different EQ----
  myDFPlayer.EQ(DFPLAYER_EQ_CLASSIC);
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);

  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
}

void loop() {
  d1 = digitalRead(s1); 
  d2 = digitalRead(s2); 
  d3 = digitalRead(s3); 
  if (d1 == 1) {
    myDFPlayer.play(1);
    Serial.println("Dokunmatik 1");
    }
  if (d2 == 1) {
    myDFPlayer.play(2);
    Serial.println("Dokunmatik 2");
  }
  if (d2 == 1) {
    myDFPlayer.play(3);
    Serial.println("Dokunmatik 3");
  }
  delay(100);
}


