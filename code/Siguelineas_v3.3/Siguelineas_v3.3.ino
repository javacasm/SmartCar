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

}//fin setup

//mian loop
void loop() {

  if (LTR==WHITE && LTM==WHITE && LTL==WHITE){
    delay (500);
    while (LTR==WHITE && LTM==WHITE && LTL==WHITE){
      robotSetSpeed (CONFUSSION);
      robotRightInstant ();
    }
    if (LTR==WHITE && LTM==BLACK && LTL==WHITE){
      robotBrakeInstant ();
    }
    }
 
  if (LTR==BLACK && LTM==BLACK && LTL==BLACK){
    delay (500);
    while (LTR==BLACK && LTM==BLACK && LTL==BLACK){
      robotSetSpeed (CONFUSSION);
      robotRightInstant ();
    }
    if (LTR==WHITE && LTM==BLACK && LTL==WHITE){
    robotBrakeInstant ();
    }
    } 
    
  while (LTR==WHITE && LTM==BLACK && LTL==WHITE){
    robotSetSpeed (FLASH);
    digitalWrite (L, HIGH);
    robotForwardInstant ();
    digitalWrite (L, LOW);
    delay (500);
    }
  //brakeInstant ();

  while (LTR==BLACK){
    if (LTM==BLACK)robotSetSpeed (SLOW);
    else robotSetSpeed (FLASH); 
   servotest.write(SERVORIGHT);
   robotRightInstant();//ARGUMENTO: En motores=tiempo funcionando
   delay (500);
  }

  while (LTL==BLACK){
    if (LTM==BLACK)robotSetSpeed (SLOW);
    else robotSetSpeed (FLASH);
    servotest.write(SERVOLEFT);
   robotLeftInstant();
    delay (500);
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
