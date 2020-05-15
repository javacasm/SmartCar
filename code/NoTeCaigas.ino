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

/*
void setup() {
  M1Setup();
  M1Speed(VELOCIDADA);
  M2Setup();
  M2Speed(VELOCIDADB);
}//fin setup

//mian loop
void loop() {
  
  if (LTR==LOW){ // true if light reflection
    M1Forward ();  
  } else{     
    M1Brake();      
  }

  if (LTL==LOW){ // true if light reflection
    M2Forward ();  
  } else{     
    M2Brake();
  }
 
}
*/