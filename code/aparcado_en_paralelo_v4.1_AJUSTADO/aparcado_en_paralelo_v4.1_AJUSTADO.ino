#include "constants.h"//fichero con las constantes
#include "display.h"// fichero con lo relacionado con el seven segments
#include "aparcamiento.h"//fichero en el que se describen los movimientos del coche para aparcar
#include "robot.h"//fichero con las funciones del robot en general
#include "ir_control.h"//fichero con los casos y las funciones del control remoto IR

void setup() {
  chip595SetUp();
  digitsSetUp();
  ultrasonicSetUp();
  servoSetUp();
  //Serial.begin(9600);

  detect_IR();

  robotSetSpeed(MEDIUM);
  //termina configuración

  //empieza aparcamiento (en setup para que solo se haga una vez)
  //delay (1000);
  four_digits_n (COD_F,COD_D,COD_N,COD_G,DISPLAY1S);
  finding ();
  four_digits_n (COD_BLANK,COD_BLANK,COD_O,COD_C,DISPLAY1S);// oC
  
  four_digits_n (COD_P,COD_H,COD_5,COD_1,DISPLAY1S);//PHS1
  movement1();
  four_digits_n (COD_BLANK,COD_BLANK,COD_O,COD_C,DISPLAY1S);// oC
}

void loop() {// el seven segments está en el loop para que se repita continuamente
int distance = Distance_test();
sevenSegments (distance);
}
