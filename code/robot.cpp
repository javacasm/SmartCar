// Los Movimientos del robot a partir de los movmientos de los 2 motores

#include "motores.h"
#include <Arduino.h>

#define SPIN 547
#define FRENO 600
#define MOVEMENT 955
#define TIMES 4


void robotForward(int duracion){
  M1Forward();
  M2Forward();
  //de modo que todos los motores se moveran hacia adelante
  delay (duracion);
 
}

void robotRight(int duracion){
  M1Forward();
  M2Backward();
  delay (duracion);
}

void robotLeft(int duracion){
  M2Forward();
  M1Backward();
  delay (duracion);
}



void robotBackward(int duracion){
  M1Backward();
  M2Backward();
  //lo que indica que ahora todos los motores se moverán hacia atrás
  delay (duracion);
}



void robotSmoothstop(int duracion){
  M1SmoothStop();
  M2SmoothStop();  
  //de este modo todos los motores se apagaran progresivamente
  delay (duracion);
}

void robotBrake(int duracion){
  M1Brake();
  M2Brake();
  //de manera que todos los mostores quedarán repentinamente parados y bloqueados
  delay (duracion);
}

void robotSquare(){
  for(int i = 0; i < TIMES; i++){
    robotForward(MOVEMENT);
    robotRight(SPIN);
  }
}
