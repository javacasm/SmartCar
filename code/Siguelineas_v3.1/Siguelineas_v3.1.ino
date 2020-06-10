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

#define BLACK HIGH
#define WHITE LOW

void setup() {
  M1Setup(); 
  M1Speed(VELOCIDADA);
  M2Setup();
  M2Speed(VELOCIDADB);

 /* testAdelanteAtras();
  delay(5000);
  testCuadrado();
  delay(5000);   */

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

#define VELOCIDAD_GIRO_RAPIDO 200
#define VELOCIDAD_GIRO_LENTO 170


//main loop
void loop() {


  while (LTR == WHITE && LTM == BLACK && LTL == WHITE){
    robotSetSpeed (VELOCIDAD_GIRO_RAPIDO);
    robotForwardInstant ();
  }


  while (LTR == BLACK){
    if (LTM == BLACK)robotSetSpeed (VELOCIDAD_GIRO_LENTO);
    else robotSetSpeed (VELOCIDAD_GIRO_RAPIDO); 
   robotLeftInstant();//ARGUMENTO: En motores=tiempo funcionando
  }

  while (LTL == BLACK){
    if (LTM == BLACK)robotSetSpeed (VELOCIDAD_GIRO_LENTO);
    else robotSetSpeed (VELOCIDAD_GIRO_RAPIDO);
   robotRightInstant();
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
