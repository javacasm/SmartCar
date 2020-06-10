#include "pines_arduino.h"

#define FLASH 170
#define SLOW 150
#define CONFUSSION 120

#define VELOCIDADA 200
#define VELOCIDADB 200
void robotSetSpeed(int speed);

void robotForwardInstant ();
void robotForward(int duracion);

void robotLeftInstant ();
void robotLeft(int duracion);

void robotRightInstant ();
void robotRight(int duracion);

void robotBackwardInstant ();
void robotBackward(int duracion);

void robotSmoothstopInstant ();
void robotSmoothstop(int duracion);

void brakeInstant ();
void robotBrake(int duracion);

void robotSquare();
