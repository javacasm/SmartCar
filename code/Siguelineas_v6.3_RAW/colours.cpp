#include "pines_arduino.h"//especificamos que vamos a incluir el fichero "pines_arduino.h"

void red(){//declaramos una función digital llamada red que encenderá el LED RGB en rojo
  digitalWrite (RED, HIGH);//se enciende el color rojo del LED RGB
  digitalWrite (GREEN, LOW);//se apaga el color verde del LED RGB
  digitalWrite (BLUE, LOW); //se apaga el color azul del LED RGB
}//termina el programa que genera la función red, y el resultado es un color rojo intenso

void green(){//declaramos una función digital llamada green que encenderá el LED RGB en verde
  digitalWrite (RED, LOW);//se apaga el color rojo del LED RGB
  digitalWrite (GREEN, HIGH);//se enciende el color verde del LED RGB
  digitalWrite (BLUE, LOW); //se apaga el color azul del LED RGB
}//termina el programa que genera la función green, y el resultado es un color verde intenso

void blue(){//declaramos una función digital llamada blue que encenderá el LED RGB en azul
  digitalWrite (RED, LOW);//se apaga el color rojo del LED RGB
  digitalWrite (GREEN, LOW);//se apaga el color verde del LED RGB
  digitalWrite (BLUE, HIGH);//se enciende el color azul del LED RGB
}//termina el programa que genera la función blue, y el resultado es un color azul intenso

void yellow(){//declaramos una función digital llamada yellow que encenderá el LED RGB en amarillo
  digitalWrite (RED, HIGH);//se enciende el color rojo del LED RGB
  digitalWrite (GREEN, HIGH);//se enciende el color verde del LED RGB
  digitalWrite (BLUE, LOW);//se apaga el color azul del LED RGB
}//termina el programa que genera la función yellow, y el resultado es un color amarillento o anaranjado

void magenta(){//declaramos una función digital llamada green que encenderá el LED RGB en magenta (un tono rosado)
  digitalWrite (RED, HIGH);//se enciende el color rojo del LED RGB
  digitalWrite (GREEN, LOW);//se apaga el color verde del LED RGB
  digitalWrite (BLUE, HIGH);//se enciende el color azul del LED RGB
}//termina el programa que genera la función magenta, y el resultado es un color rosado

void cyan(){//declaramos una función digital llamada green que encenderá el LED RGB en cian (azul claro)
  digitalWrite (RED, LOW);//se apaga el color rojo del LED RGB
  digitalWrite (GREEN, HIGH);//se enciende el color verde del LED RGB
  digitalWrite (BLUE, HIGH);//se enciende el color azul del LED RGB
}//termina el programa que genera la función cyan, y el resultado es un color celeste o azul claro

void white(){//declaramos una función digital llamada green que encenderá el LED RGB en blanco
  digitalWrite (RED, HIGH);//se enciende el color rojo del LED RGB
  digitalWrite (GREEN, HIGH);//se enciende el color verde del LED RGB
  digitalWrite (BLUE, HIGH);//se enciende el color azul del LED RGB
}//termina el programa que genera la función white, y el resultado es un color blanco intenso

void black(){//declaramos una función digital llamada green apagará el LED RGB (color negro)
  digitalWrite (RED, LOW);//se apaga el color rojo del LED RGB
  digitalWrite (GREEN, LOW);//se apaga el color verde del LED RGB
  digitalWrite (BLUE, LOW);//se apaga el color azul del LED RGB
}//termina el programa que genera la función azul, y el resultado es la ausencia de color (negro)
