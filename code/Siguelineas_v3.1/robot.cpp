// Los Movimientos del robot a partir de los movmientos de los 2 motores

#include "motores.h"
#include <Arduino.h>

#define SPIN 547
#define FRENO 600
#define MOVEMENT 955
#define TIMES 4


void robotSetSpeed(int speed){
  M1Speed(speed);
  M2Speed(speed);
}

void robotForwardInstant(){
  //de modo que todos los motores se moveran hacia adelante  
  M1Forward();
  M2Forward();
}

void robotForward(int duracion){

  robotForwardInstant();
  delay (duracion);
 
}

void robotRightInstant(){
  M2Forward();
  M1Backward();
}

void robotRight(int duracion){
  robotRightInstant();
  delay (duracion);
}

void robotLeftInstant(){
  M1Forward();
  M2Backward();
}

void robotLeft(int duracion){
  robotLeftInstant();
  delay (duracion);
}

void robotBackwardInstant(){
  M1Backward();
  M2Backward();
}

void robotBackward(int duracion){
  //lo que indica que ahora todos los motores se moverán hacia atrás
  robotBackwardInstant();
  delay (duracion);
}

void robotSmoothstopInstant(){
  M1SmoothStop();
  M2SmoothStop();  
}

void robotSmoothstop(int duracion){
  //de este modo todos los motores se apagaran progresivamente
  robotBackwardInstant();
  delay (duracion);
}

void robotBrakeInstant(){
  M1Brake();
  M2Brake();
}

void robotBrake(int duracion){
  robotBrakeInstant();
  //de manera que todos los mostores quedarán repentinamente parados y bloqueados
  delay (duracion);
}

void robotSquare(){
  for(int i = 0; i < TIMES; i++){
    robotForward(MOVEMENT);
    robotRight(SPIN);
  }
}
