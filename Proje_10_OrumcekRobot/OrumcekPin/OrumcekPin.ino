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
ServoOnSagUst.attach(2);
ServoOnSagAlt.attach(3);
ServoOnSolUst.attach(4);
ServoOnSolAlt.attach(5);
//__________ARKALAR_____________//
ServoArkaSagUst.attach(6);
ServoArkaSagAlt.attach(7);
ServoArkaSolUst.attach(8);
ServoArkaSolAlt.attach(9);
}

void loop() {

//Ust servolar acilma
ServoArkaSagUst.write(120);
ServoArkaSolUst.write(60);
ServoOnSagUst.write(60);
ServoOnSolUst.write(120);//
delay(1000);

//Ust servolar kapanma
ServoArkaSagUst.write(60);
ServoArkaSolUst.write(120);
ServoOnSagUst.write(120);
ServoOnSolUst.write(60);//
delay(1000);

// Bacaktaki servolar asagi inme
ServoArkaSagAlt.write(135);
ServoArkaSolAlt.write(45);
ServoOnSagAlt.write(45);
ServoOnSolAlt.write(135);//
delay(1000);

// Bacaktaki servolar asagi kalkma
ServoArkaSagAlt.write(45);
ServoArkaSolAlt.write(135);
ServoOnSagAlt.write(135);
ServoOnSolAlt.write(45);//
delay(1000);



}

