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
}//fin setup

//mian loop
void loop() {

  while (LTR==WHITE && LTM==BLACK && LTL==WHITE){
    robotSetSpeed (120);
    robotForwardInstant ();
  }
  //brakeInstant ();

  while (LTR==BLACK){
    if (LTM==BLACK)robotSetSpeed (100);
    else robotSetSpeed (120); 
   robotLeftInstant();//ARGUMENTO: En motores=tiempo funcionando
  }

  while (LTL==BLACK){
    if (LTM==BLACK)robotSetSpeed (100);
    else robotSetSpeed (120);
   robotRightInstant();
  }

  /*while (LTM==WHITE && LTR==WHITE && LTL==WHITE){
    robotSetSpeed (120);
    robotRightInstant ();
  }
  while (LTR==BLACK && LTL==BLACK){
    robotSetSpeed(120);
    robotLeftInstant();
  }*/

  /*robotSetSpeed (150);
  robotSquare();*/
}
