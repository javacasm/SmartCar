//www.elegoo.com

#include "colours.h"//especificamos que vamos a incluir el fichero "colours.h"
#include "robot.h"//espescificamos que vamos a incluir el fichero "robot.h"
#include "motores.h"//especificamos que vamos a incluir el fichero "motores.h"
#include "sensores.h"//especificamos que vamos a incluir el fichero "sensores.h"
#include "aparcamiento.h"



void setup() {//comienza el setup o parte de la programación en la que específicamos las condiciones que debe cumplir el robot al comenzar el programa
 motorsSetUp();
 servoSetUp();
 RGBSetUp();
 ultrasonicSetUp();
 
 robotSetSpeed(FAST);
 
 Serial.begin(9600);//iniciamos el SERIAL PORT a 9600 baudios para poder analizar lo que sucede durante la ejecución del programa


finding ();
/*movement1 ();
movement2 ();
finish ();*/

}//fin setup


void loop() {//comienza el loop o parte de la programación que va a realizarse en bucle 
  
}
