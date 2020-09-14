// V 0.8

//www.elegoo.com

#include "colours.h"//especificamos que vamos a incluir el fichero "colours.h"
#include "robot.h"//espescificamos que vamos a incluir el fichero "robot.h"
#include "motores.h"//especificamos que vamos a incluir el fichero "motores.h"
#include "sensores.h"//especificamos que vamos a incluir el fichero "sensores.h"



int rightDistance = 0;
int middleDistance = 0;
int leftDistance = 0;

void getDistances(){
  rightDistance = rightMeasuring ();
  debug("RIGHT");
  delay(WAIT_SERVO_ULTRASOUND);           
  
  middleDistance = middleMeasuring();
  debug("CENTER");
  delay(WAIT_SERVO_ULTRASOUND);     

  leftDistance = leftMeasuring ();
  debug("LEFT");
  delay(WAIT_SERVO_ULTRASOUND);                    
}

void setup() {//comienza el setup o parte de la programación en la que específicamos las condiciones que debe cumplir el robot al comenzar el programa

 M1Setup();//realizamos la función M1Setup que va a declara los cables empleados en este motor como salida para que podamos utilizar el motor 1
 M2Setup();//realizamos la función M2Setup que va a declara los cables empleados en este motor como salida para que podamos utilizar el motor 2

 setup_servo();
 
 setup_ultrasonido();

 robotSetSpeed(150);
 
 Serial.begin(9600);//iniciamos el SERIAL PORT a 9600 baudios para poder analizar lo que sucede durante la ejecución del programa
}//fin setup

void testDistances(){

    getDistances();
    char strDistance [50];
    sprintf(strDistance,"D: %d %d %d" , rightDistance, middleDistance, leftDistance);
    Serial.println (strDistance);

    int maxDistance = max(rightDistance, middleDistance);
    maxDistance = max(maxDistance ,leftDistance);

    if  (maxDistance == rightDistance) moveServo(MEASURE_RIGHT_ANGLE);
    if  (maxDistance == leftDistance) moveServo(MEASURE_LEFT_ANGLE);
    if  (maxDistance == middleDistance) moveServo(MEASURE_MIDDLE_ANGLE);


    delay(5000);
}

#define DISTANCIA 20
#define MARGEN 3

void loop() {//comienza el loop o parte de la programación que va a realizarse en bucle 
    // testDistances();
   middleDistance = middleMeasuring();

   if (middleDistance < DISTANCIA - MARGEN)        robotBackwardInstant();
   else if (middleDistance > DISTANCIA + MARGEN)   robotForwardInstant();
   else robotBrakeInstant();

}
