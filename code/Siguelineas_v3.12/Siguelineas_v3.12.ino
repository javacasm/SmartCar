//www.elegoo.com

//     Right motor truth table
//Here are some handy tables to show the various modes of operation.
//  ENB         IN3             IN4         Description  
//  LOW   Not Applicable   Not Applicable   Motor is off
//  HIGH        LOW             LOW         Motor is stopped (brakes)
//  HIGH        LOW             HIGH        Motor is on and turning forwards
//  HIGH        HIGH            LOW         Motor is on and turning backwards
//  HIGH        HIGH            HIGH        Motor is stopped (brakes)      

#include "robot.h"
#include "motores.h"
#include "sensores.h"

#include <Servo.h>
#define SERVO 3
Servo servotest;

#define L 13

#define SERVOCONFUSIONRIGHT 170
#define SERVOCONFUSIONLEFT 20
#define SERVOLEFT 70
#define SERVOCENTER 90
#define SERVORIGHT 110

#define BLACK HIGH
#define WHITE LOW

void setup() {
  M1Setup(); 
  M1Speed(VELOCIDADA);
  M2Setup();
  M2Speed(VELOCIDADB);

  servotest.attach (SERVO);

  pinMode (L, OUTPUT);

 /* testAdelanteAtras();
  delay(5000);
  testCuadrado();
  delay(5000);   */

  Serial.begin(9600);


}//fin setup

// Test para comprobar que el software se coordina bien con el hardware

// 1 segundo adelante, para y 1 segundo atras
void testAdelanteAtras(){
  robotForwardInstant();
  delay(1000);
  robotBrakeInstant();
  robotBackwardInstant();
  delay(1000);
  robotBrakeInstant();
}

// test del cuadrado
void testCuadrado(){
  // repetir x 4 
    // adelante
    // derecha
  robotSetSpeed (150);
  robotSquare();
}

#define VELOCIDAD_GIRO_RAPIDO 230
#define VELOCIDAD_GIRO_LENTO 200


#define PAUSA_WHILE 20

//main loop
void loop() {


  if (LTR==BLACK && LTM==BLACK && LTL==BLACK){
    delay (PAUSA_WHILE);
    servotest.write(SERVOCONFUSIONRIGHT);
    while (LTR==BLACK && LTM==BLACK && LTL==BLACK){
      robotSetSpeed (CONFUSSION);
      robotRightInstant ();
      Serial.println("Dentro Confusion Right");
    }
    servotest.write(SERVOCENTER);
 }

  while (LTR == WHITE && LTM == BLACK && LTL == WHITE){
    robotSetSpeed (VELOCIDAD_GIRO_RAPIDO);
    digitalWrite (L, HIGH);
    robotForwardInstant ();
    digitalWrite (L, LOW);
    delay (PAUSA_WHILE);    
    Serial.println("Dentro de Forward");
  }


  while (LTR == BLACK){
    if (LTM == BLACK)robotSetSpeed (VELOCIDAD_GIRO_LENTO);
    else robotSetSpeed (VELOCIDAD_GIRO_RAPIDO); 
    servotest.write(SERVOLEFT);
    robotLeftInstant();//ARGUMENTO: En motores=tiempo funcionando
    delay (PAUSA_WHILE);
    Serial.println("Dentro de Left");
  }

  while (LTL == BLACK){
    servotest.write(SERVOCENTER);
    if (LTM == BLACK)robotSetSpeed (VELOCIDAD_GIRO_LENTO);
    else robotSetSpeed (VELOCIDAD_GIRO_RAPIDO);
    servotest.write(SERVORIGHT);
    robotRightInstant();
    delay (PAUSA_WHILE);
    Serial.println("Dentro de Right");
  }


 if (LTR==WHITE && LTM==WHITE && LTL==WHITE){
    delay (PAUSA_WHILE);
    servotest.write(SERVOCONFUSIONLEFT);
    while (LTR==WHITE && LTM==WHITE && LTL==WHITE){
      robotSetSpeed (CONFUSSION);
      robotLeftInstant ();
      Serial.println("Dentro de confusion Left");
    }
    servotest.write(SERVOCENTER);
 }

/*
  while (LTM==WHITE && LTR==WHITE && LTL==WHITE){
    robotSetSpeed (VELOCIDAD_GIRO_RAPIDO);
    robotRightInstant ();
  }
  while (LTR==BLACK && LTL==BLACK){
    robotSetSpeed(VELOCIDAD_GIRO_RAPIDO);
    robotLeftInstant();
  }
*/

}
