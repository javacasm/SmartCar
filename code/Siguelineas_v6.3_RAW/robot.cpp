// Aquí se describen los Movimientos del robot a partir de los movmientos de los 2 motores

#include "colours.h"//especificamos que vamos a incluir el fichero "colours.h"
#include "motores.h"//especificamos que vamos a incluir el fichero "motores.h"
#include <Arduino.h>//especificamos que vamos a incluir el fichero "Arduino.h"
#include <Servo.h>

Servo myservo;

#define WAIT_WHILE 200//declaramos la constante WAIT_WHILE que va a equivaler a 200 y esta hará referencia a una cantidad de tiempo (expresada en milisegundos)
#define DISTURBED 100//declaramos la constante DISTURBED que va a equivaler a 500 y esta hará referencia a una cantidad de tiempo (expresada en milisegundos)

#define SPIN 547//declaramos la constante SPIN que representa la cantidad de tiempo que el robot girará en la funcion digital cuadrado
#define MOVEMENT 955//declaramos la constante MOVEMENT que representa la cantidad de tiempo que el robot avanzará en la funcion digital cuadrado
#define TIMES 4//declaramos la constante MOVEMENT que representa el numero de veces que se repite el for de la función cuadrado digital cuadrado

void robotSetSpeed (int speed){//declaramos la función analógica robotSetSpeed que establece la velocidad a la que se moveran todos los motores mediante la variable entera speed
  M1Speed(speed);//ejecutamos la función analógica M1Speed que configurará los motores M1 a la velocidad especificada en el parentesis de la función analógica robotSetSpeed (variable speed)
  M2Speed(speed);//ejecutamos la función analógica M2Speed que configurará los motores M2 a la velocidad especificada en el parentesis de la función analógica robotSetSpeed (variable speed)
}//termina la función analógica robotSetSpeed con la configuración de todos los motores a la velocidad deseada (variable speed)

void robotForwardInstant(){//declaramos la función digital robotForwardInstant que provocará que todos los motores desplacen al robot hacia adelante indefinidamente
  M1Forward();//ejecutamos la función digital M1Forward que hace que los motores M1 avancen hacia adelante indefinidamente
  M2Forward();//ejecutamos la función digital M2Forward que hace que los motores M2 avancen hacia adelante indefinidamente
}//termina la función digital robotForwardInstant de modo que todos los motores se moveran hacia adelante indefinidamente

void robotForward(int duracion){//declaramos la función analógica robotForward que provocará que todos los motores desplacen al robot hacia adelante durante un tiempo especificado con la variable entera duración
  robotForwardInstant();//ejecutamos la función digital robotForwardInstant que provocará que todos los motores desplacen al robot hacia adelante
  delay (duracion);//ejecutamos un delay que determinará lo que durará la función anterior y equivale a la variable duración
}//termina la función analógica robotForward de modo que todos los motores se moveran hacia adelante durante el tiempo especificado (duración)

void robotRightInstant (){//declaramos la función digital robotRightInstant que provocará que todos los motores desplacen al robot hacia la derecha indefinidamente
  M1Forward();//ejecutamos la función digital M1Forward que hace que los motores M1 avancen hacia adelante indefinidamente
  M2Backward();//ejecutamos la función digital M2Backward que hace que los motores M2 avancen hacia atrás indefinidamente
}//termina la función digital robotRightInstant de manera que el robot gira hacia la derecha indefinidamente

void robotRight(int duracion){//declaramos la función analógica robotRight que provocará que todos los motores desplacen al robot hacia la derecha durante un tiempo especificado con la variable entera duración
  robotRightInstant();// ejecutamos la función digital robotRightInstant de manera que el robot gira hacia la derecha
  delay (duracion);//ejecutamos un delay que determinará lo que durará la función anterior y equivale a la variable duración
}//termina la función analógica robotRight de manera que el robot gira hacia la derecha durante el tiempo especificado (duración)

void robotLeftInstant (){//declaramos la función digital robotLeftInstant que provocará que todos los motores desplacen al robot hacia la izquierda indefinidamente
  M1Backward();//ejecutamos la función digital M1Backward que hace que los motores M1 avancen hacia atrás indefinidamente
  M2Forward();//ejecutamos la función digital M2Forward que hace que los motores M2 avancen hacia adelante indefinidamente
}//termina la función digital robotLeftInstant de modo que todos los motores se moveran hacia la izquierda indefinidamente

void robotLeft(int duracion){//declaramos la función analógica robotLeft que provocará que todos los motores desplacen al robot hacia la izquierda durante un tiempo especificado con la variable entera duración
  robotLeftInstant();// ejecutamos la función digital robotLeftInstant de manera que el robot gira hacia la izquierda
  delay (duracion);//ejecutamos un delay que determinará lo que durará la función anterior y equivale a la variable duración
}//termina la función analógica robotLeft de manera que el robot gira hacia la izquierda durante el tiempo especificado (duración)

void robotBackwardInstant (){//declaramos la función digital robotBackwardInstant que provocará que todos los motores desplacen al robot hacia atrás indefinidamente
  M1Backward();//ejecutamos la función digital M1Backward que hace que los motores M1 avancen hacia atrás indefinidamente
  M2Backward();//ejecutamos la función digital M2Backward que hace que los motores M2 avancen hacia atrás indefinidamente
}//termina la función digital robotBackwardInstant de modo que todos los motores se moveran hacia atrás indefinidamente

void robotBackward(int duracion){//declaramos la función analógica robotBackward que provocará que todos los motores desplacen al robot hacia atrás durante un tiempo especificado con la variable entera duración
  robotBackwardInstant();// ejecutamos la función digital robotBackwardInstant de manera que el robot avanza hacia atrás
  delay (duracion);//ejecutamos un delay que determinará lo que durará la función anterior y equivale a la variable duración
}//termina la función analógica robotBackward de manera que el robot  avanza hacia atrás durante el tiempo especificado (duración)

void robotSmoothStopInstant(){//declaramos la función digital robotSmoothStopInstant que provocará que todos los motores se frenen suave y progresivamente indefinidamente
  M1SmoothStop();//ejecutamos la función digital M1SmoothStop que hace que los motores M1 frenen suave y progresivamente
  M2SmoothStop();//ejecutamos la función digital M2SmoothStop que hace que los motores M2 frenen suave y progresivamente
}//termina la función digital robotSmoothStopInstant de modo que todos los motores se frenarán suave y progresivamente indefinidamente

void robotSmoothstop(int duracion){//declaramos la función analógica robotSmoothstop que provocará que todos los motores se frenen suave y progresivamente durante un tiempo especificado con la variable entera duración
   robotSmoothStopInstant();// ejecutamos la función digital robotSmoothStopInstant de manera que el robot frene suave y progresivamente
  delay (duracion);//ejecutamos un delay que determinará lo que durará la función anterior y equivale a la variable duración
}//termina la función analógica robotSmoothstop de manera que el robot se frene suave y progresivamente durante el tiempo especificado (duración)

void robotBrakeInstant (){//declaramos la función digital robotBrakeInstant que provocará que todos los motores se frenen en seco indefinidamente
  M1Brake ();//ejecutamos la función digital M1Brake que hace que los motores M1 frenen en seco
  M2Brake ();//ejecutamos la función digital M2Brake que hace que los motores M2 frenen en seco
}//termina la función digital robotBrakeInstant de modo que todos los motores se frenarán en seco indefinidamente

void robotBrake(int duracion){//declaramos la función analógica robotBrake que provocará que todos los motores se frenen en seco durante un tiempo especificado con la variable entera duración
  robotBrakeInstant();// ejecutamos la función digital robotBrakeInstant de manera que el robot frene en seco
  delay (duracion);//ejecutamos un delay que determinará lo que durará la función anterior y equivale a la variable duración
}//termina la función analógica robotBrake de manera que el robot se frene en seco durante el tiempo especificado (duración)

void emergency(){
  robotBrakeInstant();
  Serial.println ("APAGA Y VAMONOH");
  white();
  delay (DISTURBED);
  yellow();
  delay (DISTURBED);
  green();
  delay (DISTURBED);
  cyan();
  delay (DISTURBED);
  blue();
  delay (DISTURBED);
  magenta();
  delay (DISTURBED);
  red();
  delay (DISTURBED);
  black();
  delay (DISTURBED);
  myservo.write (10);
  delay (WAIT_WHILE);
  myservo.write (90);
  delay (WAIT_WHILE);
  myservo.write (180);
  delay (WAIT_WHILE);
}
