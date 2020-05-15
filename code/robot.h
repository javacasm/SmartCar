#include "pines_arduino.h"

#define VELOCIDADA 200
#define VELOCIDADB 200

void robotSetSpeed(int speed);
void robotForwardInstant();
void robotForward(int duracion);
void robotLeftInstant();
void robotLeft(int duracion);
void robotLeftInstant();
void robotRight(int duracion);
void robotRightInstant();
void robotBackward(int duracion);
void robotBackwardInstant();
void robotSmoothstop(int duracion);
void robotSmoothstopInstant();
void robotBrake(int duracion);
void robotBrakeInstant();
void robotSquare();
