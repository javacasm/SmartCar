#include "arduino_pins.h"//fichero con los pines en los que se conectan los cables
#include "constants.h"//fichero con las constantes
#include "characters_table.h"//fichero donde se referencia a la tabla

//funciones para inicializar los componentes necesarios para que funciones el seven segments
  void chip595SetUp (){
    pinMode(LATCH, OUTPUT);
    pinMode(CLOCK, OUTPUT);
    pinMode(DATA, OUTPUT);
  }
  
  void digitsSetUp(){
    pinMode(UNIDADES,OUTPUT);
    pinMode(DECENAS,OUTPUT);
    pinMode(CENTENAS,OUTPUT);
    pinMode(U_MILLAR,OUTPUT);
  }

//funciones de proyección de los números individuales
  void Display(unsigned char num){//función con argumento que permite mostrar un número concreto en el seven segments
    digitalWrite(LATCH,LOW);
    shiftOut(DATA,CLOCK,MSBFIRST,table[num]);
    digitalWrite(LATCH,HIGH);
  }
  
  void unidades(int valor){//función con argumento que permite mostrar un número en el dígito de las unidades
    digitalWrite (UNIDADES,LOW);//*NOTA: El dígito solo funcionará si lo ponemos LOW para que la corriente negativa pase por el ánodo
    digitalWrite (DECENAS,HIGH);
    digitalWrite (CENTENAS,HIGH);
    digitalWrite (U_MILLAR,HIGH);
    Display (valor);
    /*Serial.print ("unidades:");
    Serial.println (valor);*/
  }
  
  void decenas(int valor){//función con argumento que permite mostrar un número en el dígito de las decenas
    digitalWrite (UNIDADES,HIGH);
    digitalWrite (DECENAS,LOW);//*VE A LA FUNCIÓN "unidades"
    digitalWrite (CENTENAS,HIGH);
    digitalWrite (U_MILLAR,HIGH);
    Display (valor);
    /*Serial.print ("decenas:");
    Serial.println (valor);*/
  }
  
  void centenas(int valor){//función con argumento que permite mostrar un número en el dígito de las centenas
    digitalWrite (UNIDADES,HIGH);
    digitalWrite (DECENAS,HIGH);
    digitalWrite (CENTENAS,LOW);//*VE A LA FUNCIÓN "unidades"
    digitalWrite (U_MILLAR,HIGH);
    Display (valor);
    /*Serial.print ("decenas:");
    Serial.println (valor);*/
  }
  
  void u_millar(int valor){//función con argumento que permite mostrar un número en el dígito de las unidades de millar
    digitalWrite (UNIDADES,HIGH);
    digitalWrite (DECENAS,HIGH);
    digitalWrite (CENTENAS,HIGH);
    digitalWrite (U_MILLAR,LOW);//*VE A LA FUNCIÓN "unidades"
    Display (valor);
    /*Serial.print ("decenas:");
    Serial.println (valor);*/
  }

//funciones de traducción de datos
  int wordReference (int n){//función que devuelve una variable entera. Esta función permite traducir el valor que introduzcamos a una constante identificable en la tabla
    int sol;
    switch (n){
      case 0:
      sol = COD_0;
      break;
      case 1:
      sol = COD_1;
      break;
      case 2:
      sol = COD_2;
      break;
      case 3:
      sol = COD_3;
      break;
      case 4:
      sol = COD_4;
      break;
      case 5:
      sol = COD_5;
      break;
      case 6:
      sol = COD_6;
      break;
      case 7:
      sol = COD_7;
      break;
      case 8:
      sol = COD_8;
      break;
      case 9:
      sol = COD_9;
      break;
    return sol;
  }
  }
  
  int rae (int n){//función que devuelve una variable entera. Esta función permite traducir el valor que introduzcamos a una constante identificable en la tabla es otra forma de hacer la wordreference
    int traductor[] = {COD_0,COD_1,COD_2,COD_3,COD_4,COD_5,COD_6,COD_7,COD_8,COD_9};// Cuando creamos una variable con [] esta contiene muchos valores
    int sol = traductor[n];
    return sol;
  }

//funciones de proyección de números a la vez
  void four_digits_once (int um, int c, int d, int u){//función con argumento con la que podemos encender varios dígitos (separados, cada uno asociado a um, c, d o u) a la vez por un tiempo apenas visible
    unidades(u);
    delay (BLINK);
    centenas (c);
    delay (BLINK);
    decenas(d);
    delay (BLINK);
    u_millar (um);
    delay (BLINK);
  }

  void four_digits_n (int um, int c, int d, int u, int n){//función con argumento que permite visualizar varios dígitos (separados, cada uno asociado a um, c, d o u) a la vez por un tiempo prolongado
    for (int j = 0; j < n; j++){
    four_digits_once (um, c, d, u);
    }
  }
  
  void sevenSegments (int n){//función con argumento que permite visualizar varios dígitos (en forma de número de x cifras, sin traducir) a la vez por un tiempo prolongado)
    int centenas = n / 100;
    int resto = n % 100;//cálculo del resto
    int decenas = resto / 10;
    resto = resto % 10;
    int unidades = resto;
    four_digits_n(wordReference(u_millar),wordReference(centenas),wordReference(decenas),wordReference(unidades),32);//proyectamos las cifras del nº introducido que son transformadas a COD_X para que el programa lo entienda
  }

  void clear_display(){//función sin argumento que apaga todos los digitos a la vez
    four_digits_n(COD_BLANK,COD_BLANK, COD_BLANK, COD_BLANK, 32);
  }
