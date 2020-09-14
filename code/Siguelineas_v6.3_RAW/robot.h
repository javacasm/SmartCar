#include "pines_arduino.h"//especificamos que vamos a incluir el fichero "pines_arduino.h"

#define WAIT_WHILE 200//declaramos la constante WAIT_WHILE que va a equivaler a 200 y esta hará referencia a una cantidad de tiempo (expresada en milisegundos)
#define DISTURBED 500//declaramos la constante DISTURBED que va a equivaler a 500 y esta hará referencia a una cantidad de tiempo (expresada en milisegundos)

#define FLASH 170//declaramos la constante FLASH que va a equivaler a 170 y esta hará referencia a la velocidad de los motores
#define SLOW 150//declaramos la constante SLOW que va a equivaler a 150 y esta hará referencia a la velocidad de los motores
#define VELOCIDADA 200//declaramos la constante VELOCIDADA que va a equivaler a 200 y esta hará referencia a la velocidad de los motores conecatdos al cable ENA
#define VELOCIDADB 200//declaramos la constante VELOCIDADB que va a equivaler a 200 y esta hará referencia a la velocidad de los motores conecatdos al cable ENB

void emergency();//especificamos la existencia de una función analógica llamada emergency cuyas especificaciones y efectos serán explicados en el fichero robot.cpp

void robotSetSpeed(int speed);//especificamos la existencia de una función analógica llamada robotSetSpeed cuyas especificaciones y efectos serán explicados en el fichero robot.cpp

void robotForwardInstant ();//especificamos la existencia de una función digital llamada robotForwardInstant cuyas especificaciones y efectos serán explicados en el fichero robot.cpp
void robotForward(int duracion);//especificamos la existencia de una función analógica llamada robotForward cuyas especificaciones y efectos serán explicados en el fichero robot.cpp

void robotRightInstant ();//especificamos la existencia de una función digital llamada robotRightInstant cuyas especificaciones y efectos serán explicados en el fichero robot.cpp
void robotRight(int duracion);//especificamos la existencia de una función analógica llamada robotRight cuyas especificaciones y efectos serán explicados en el fichero robot

void robotLeftInstant ();//especificamos la existencia de una función digital llamada robotLeftInstant cuyas especificaciones y efectos serán explicados en el fichero robot.cpp
void robotLeft(int duracion);//especificamos la existencia de una función analógica llamada robotLeft cuyas especificaciones y efectos serán explicados en el fichero robot

void robotBackwardInstant ();//especificamos la existencia de una función digital llamada robotBackwardInstant cuyas especificaciones y efectos serán explicados en el fichero robot.cpp
void robotBackward(int duracion);//especificamos la existencia de una función analógica llamada robotBackward cuyas especificaciones y efectos serán explicados en el fichero robot

void robotSmoothstopInstant ();//especificamos la existencia de una función digital llamada robotSmoothstopInstant cuyas especificaciones y efectos serán explicados en el fichero robot.cpp
void robotSmoothstop(int duracion);//especificamos la existencia de una función analógica llamada robotSmoothstop cuyas especificaciones y efectos serán explicados en el fichero robot

void robotBrakeInstant ();//especificamos la existencia de una función digital llamada robotBrakeInstant cuyas especificaciones y efectos serán explicados en el fichero robot.cpp
void robotBrake(int duracion);//especificamos la existencia de una función analógica llamada robotBrake cuyas especificaciones y efectos serán explicados en el fichero robot
