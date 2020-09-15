//www.elegoo.com

//     Right motor truth table
//Here are some handy tables to show the various modes of operation.
//  ENB         IN3             IN4         Description  
//  LOW   Not Applicable   Not Applicable   Motor is off
//  HIGH        LOW             LOW         Motor is stopped (brakes)
//  HIGH        LOW             HIGH        Motor is on and turning forwards
//  HIGH        HIGH            LOW         Motor is on and turning backwards
//  HIGH        HIGH            HIGH        Motor is stopped (brakes)      

#include "colours.h"//especificamos que vamos a incluir el fichero "colours.h"
#include "robot.h"//espescificamos que vamos a incluir el fichero "robot.h"
#include "motores.h"//especificamos que vamos a incluir el fichero "motores.h"
#include "sensores.h"//especificamos que vamos a incluir el fichero "sensores.h"

#define BLACK HIGH//declaramos la constante BLACK que va a equivaler a lo que entendemos como HIGH (1)
#define WHITE LOW//declaramos la constante WHITE que va a equivaler a lo que entendemos como LOW (0)



void setup() {//comienza el setup o parte de la programación en la que específicamos las condiciones que debe cumplir el robot al comenzar el programa
 M1Setup();//realizamos la función M1Setup que va a declara los cables empleados en este motor como salida para que podamos utilizar el motor 1
 M2Setup();//realizamos la función M2Setup que va a declara los cables empleados en este motor como salida para que podamos utilizar el motor 2

 setup_RGB_led();

 robotSetSpeed(150);

 Serial.begin(9600);//iniciamos el SERIAL PORT a 9600 baudios para poder analizar lo que sucede durante la ejecución del programa

 //showSerialCommand();
 
 
}//fin setup

void followLine(){
int path = LTL + 2*LTM + 4*LTR;
switch(path){
  case 0:
    Serial.println("WHITE CONFUSSION");//el SERIAL PORT nos mostrará el mensaje "WHITE CONFUSSION"
    white();//ejecutamos la función white para que el LED RGB muestre un color blanco
    robotLeftInstant ();//se ejecuta la función robotLefttInstant que dará lugar a que el robot se mueva hacia la izquierda para corregir la trayectoria dibujar circulos indifinidamente hasta que encuentre el rumbo y siga a la línea negra
    while (LTR==WHITE && LTM==WHITE && LTL==WHITE);//este while provoca que el programa que ha sido recién ejecutado se mantenga vigente mientras la condición (LTR==WHITE && LTM==WHITE && LTL==WHITE) se cumpla

  case 1:
    green();//ejecutamos la función green que encenderá el LED RGB en verde
    Serial.println("turning LEFT fast");//el SERIAL PORT mostrará el mensaje "turning LEFT"
    robotSetSpeed (FLASH);// si la condición anterior no se cumple, ejecutaremos la función robotSetSpeed que provocará que los motores avancen a velocidad FLASH
    robotLeftInstant();//se ejecuta la función robotLefttInstant que dará lugar a que el robot se mueva hacia la izquierda para corregir la trayectoria y volver a la línea negra
    while (LTR==WHITE && LTM==WHITE && LTL==BLACK);//este while provoca que el programa que ha sido recién ejecutado se mantenga vigente mientras la condición (LTL==BLACK) se cumpla

  case 2:
    green();//ejecutamos la función green que encenderá el LED RGB en verde
    Serial.println("moving FORWARDS");//el SERIAL PORT mostrará el mensaje "moving FORWARDS"
    robotSetSpeed (FLASH);//se ejecuta la función robotSetSpeed que ajustará todos los motores para que avancen a velocidad FLASH
    robotForwardInstant ();//se ejecuta la función robotForwardInstant que provocará que los motores se desplacen hacia delante indefinidamente
    while (LTR==WHITE && LTM==BLACK && LTL==WHITE);// este while provoca que el programa que ha sido recién ejecutado se mantenga vigente mientras la condición (LTR==WHITE && LTM==BLACK && LTL==WHITE) se cumpla

  case 3:
    green();//ejecutamos la función green que encenderá el LED RGB en verde
    Serial.println("turning LEFT slowly");//el SERIAL PORT mostrará el mensaje "turning LEFT slowly"
    robotSetSpeed (SLOW);//ejecutamos la función robotSetSpeed y para que los motores se muevan a velocidad SLOW
    robotLeftInstant();//se ejecuta la función robotLefttInstant que dará lugar a que el robot se mueva hacia la izquierda para corregir la trayectoria y volver a la línea negra
    while (LTR==WHITE && LTM==BLACK && LTL==BLACK);//este while provoca que el programa que ha sido recién ejecutado se mantenga vigente mientras la condición (LTL==BLACK) se cumpla

  case 4:
    green();//ejecutamos la función green que encenderá el LED RGB en verde
    Serial.println("turning RIGHT fast");//el SERIAL PORT mostrará el mensaje "turning RIGHT fast"
    robotSetSpeed (FLASH);// si la condición anterior no se cumple, ejecutaremos la función robotSetSpeed que provocará que los motores avancen a velocidad FLASH
    robotRightInstant();//se ejecuta la función robotRightInstant que dará lugar a que el robot se mueva hacia la derecha para corregir la trayectoria y volver a la línea negra
    while (LTR==BLACK && LTM==WHITE && LTL==WHITE);//este while provoca que el programa que ha sido recién ejecutado se mantenga vigente mientras la condición (LTR==BLACK && LTM==WHITE && LTL==WHITE) se cumpla

  case 5:
    //emergency();
    //while (LTR==BLACK && LTM==WHITE && LTL==BLACK);//este while provoca que el programa que ha sido recién ejecutado se mantenga vigente mientras la condición ((LTR==BLACK && LTM==WHITE && LTL==BLACK)) se cumpla
  
  case 6:
    green();//ejecutamos la función green que encenderá el LED RGB en verde
    Serial.println("turning RIGHT slowly");//el SERIAL PORT mostrará el mensaje "turning RIGHT slowly"
    robotSetSpeed (SLOW);//ejecutamos la función robotSetSpeed y para que los motores se muevan a velocidad SLOW
    robotRightInstant();//se ejecuta la función robotRightInstant que dará lugar a que el robot se mueva hacia la derecha para corregir la trayectoria y volver a la línea negra
    while (LTR==BLACK && LTM==BLACK && LTL==WHITE);//este while provoca que el programa que ha sido recién ejecutado se mantenga vigente mientras la condición (LTR==BLACK) se cumpla

  case 7:
    blue();//ejecutamos la función blue para que el LED RGB muestre un color azul
    Serial.println("BLACK CONFUSSION");//el SERIAL PORT nos mostrará el mensaje "BLACK CONFUSSION"
    robotRightInstant ();//se ejecuta la función robotRightInstant que dará lugar a que el robot se mueva hacia la derecha para dibujar círculos de manera indefinida hasta volver a la línea negra
    while (LTR==BLACK && LTM==BLACK && LTL==BLACK);//este while provoca que el programa que ha sido recién ejecutado se mantenga vigente mientras la condición (LTR==BLACK && LTM==BLACK && LTL==BLACK) se cumpla
 }  
}

void showSerialCommand(){
  Serial.println(" Serial command controller ");
  Serial.println("===========================");
  Serial.println("        F - Forward");
  Serial.println("L - Left          R - Right");
  Serial.println("        B - Backward");
  Serial.println("        SPACE stop ");
  Serial.println();
  Serial.println("      0,  5  y  9     ");
  Serial.println("      0% 50% y 100% speed");
  
  
}

void checkSerialCommand(){
 if (Serial.available() > 0) {

    int incomingByte = Serial.read();
    switch (incomingByte){
       case 'h':
       case 'H':
          showSerialCommand();
          break;
       case 'f':
       case 'F':
          robotForwardInstant();
          break;
       case 'b':
       case 'B':
          robotBackwardInstant();
          break;     
       case 'l':
       case 'L':
          robotLeftInstant();
          break;
       case 'r':
       case 'R':
          robotRightInstant();
          break;          
       case ' ':
          robotBrakeInstant();
          break;
       case '0':       
          robotSetSpeed(0);
          break;       
       case '5':       
          robotSetSpeed(150);
          break;                 
       case '9':
          robotSetSpeed(250);
          break;
       case '\r': // Caracter de retorno de carro (se manda desde el IDE de Arduino)
       case '\n': // Caracter de fin de l'inea 
          break;
       /* TODO:   
        *  S -> servo 180
        *  c -> servo 90
        *  s -> servo 0
        *  u -> medida ultrasonidos y envio del dato a display 7 segmentos: Leccion 14 del kit Mega
        *  L -> modo siguelineas
        *  q -> sale del modo siguelineas
        */
       default:
          Serial.println(String("Comand not found: ") + char(incomingByte));
          break;
      
    }
 }
 //else
 //   Serial.println("No key");
  
}

void loop() {//comienza el loop o parte de la programación que va a realizarse en bucle
  checkSerialCommand();
}//fin del loop y por tanto de la programación
