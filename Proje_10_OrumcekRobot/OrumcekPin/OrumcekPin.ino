#include<Servo.h>
//________ÖNLER___________//
Servo ServoOnSagUst;
Servo ServoOnSagAlt;
Servo ServoOnSolUst;
Servo ServoOnSolAlt;
//________ARKA____________//
Servo ServoArkaSagUst;
Servo ServoArkaSagAlt;
Servo ServoArkaSolUst;
Servo ServoArkaSolAlt;

void setup() {
//__________ÖNLER____________//
ServoOnSagUst.attach(3);
ServoOnSagAlt.attach(2);
ServoOnSolUst.attach(4);
ServoOnSolAlt.attach(5);
//__________ARKALAR_____________//
ServoArkaSagUst.attach(6);
ServoArkaSagAlt.attach(7);
ServoArkaSolUst.attach(8);
ServoArkaSolAlt.attach(9);
}

void loop() {

hareketEt(0);
hareketEt(90);
hareketEt(180);

}

void hareketEt(int a){
//__________ÖNLER____________//
ServoOnSagUst.write(a);//SAG ON
ServoOnSagAlt.write(a);//DEGİSECEK
ServoOnSolUst.write(a);//
ServoOnSolAlt.write(a);
//________ARKALAR____________//
ServoArkaSagUst.write(a);
ServoArkaSagAlt.write(a);
ServoArkaSolUst.write(a);
ServoArkaSolAlt.write(a);
delay(1000);
}

