#include "constants.h"//carpeta donde se referencia a las constantes
#include "display.h"//carpeta donde se referencia a las funciones
#include "aparcamiento.h"
#include "robot.h"

int rightDistance = 0;
int middleDistance = 0;
int leftDistance = 0;

void setup() {
  chip595SetUp();
  digitsSetUp();
  ultrasonicSetUp();
  servoSetUp();
  //Serial.begin(9600);

  robotSetSpeed(SLOW);
  //termina configuración

  //empieza aparcamiento (en setup para que solo se haga una vez)
  //delay (1000);
  three_digits_n (COD_F,COD_D,COD_G,DISPLAY1S);
  finding ();
  three_digits_n (COD_BLANK,COD_O,COD_C,DISPLAY1S);
  three_digits_n (COD_N,COD_U,COD_1,DISPLAY1S);
  movement1();
  three_digits_n (COD_BLANK,COD_O,COD_C,DISPLAY1S);
  //CALIBRAR GIRO DERECHA 90º Y LECCIÓN 3 LEER
}

void loop() {// el seven segments está en el loop para que se repita continuamente
int distance = Distance_test();
sevenSegments (distance);
}
