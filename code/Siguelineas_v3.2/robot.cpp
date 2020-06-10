// Los Movimientos del robot a partir de los movmientos de los 2 motores

#include "motores.h"
#include <Arduino.h>

#define FLASH 170
#define SLOW 150
#define CONFUSSION 120
#define SPIN 547
#define FRENO 600
#define MOVEMENT 955
#define TIMES 4

void robotSetSpeed (int speed){
  M1Speed(speed);
  M2Speed(speed);
}

void robotForwardInstant(){
  M1Forward();
  M2Forward();
  //de modo que todos los motores se moveran hacia adelante
}

void robotForward(int duracion){
  robotForwardInstant();
  //de modo que todos los motores se moveran hacia adelante
  delay (duracion);
 
}

void robotLeftInstant (){
  M1Forward();
  M2Backward();
}

void robotLeft(int duracion){
  robotLeftInstant();
  delay (duracion);
}

void robotRightInstant (){
  M2Forward();
  M1Backward();
}

void robotRight(int duracion){
  robotRightInstant();
  delay (duracion);
}

void robotBackwardInstant (){
  M1Backward();
  M2Backward();
}


void robotBackward(int duracion){
  robotBackwardInstant();
  //lo que indica que ahora todos los motores se moverán hacia atrás
  delay (duracion);
}

void robotSmoothStopInstant(){
  M1SmoothStop();
  M2SmoothStop(); 
}

void robotSmoothstop(int duracion){
   robotSmoothStopInstant();
  //de este modo todos los motores se apagaran progresivamente
  delay (duracion);
}

void brakeInstant (){
  M1Brake ();
  M2Brake ();
}

void robotBrake(int duracion){
  brakeInstant();
  //de manera que todos los mostores quedarán repentinamente parados y bloqueados
  delay (duracion);
}

void robotSquare(){
  for(int i = 0; i < TIMES; i++){
    robotForward(MOVEMENT);
    robotRight(SPIN);
  }
}
