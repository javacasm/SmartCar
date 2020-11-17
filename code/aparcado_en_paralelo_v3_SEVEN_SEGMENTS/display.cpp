#include "arduino_pins.h"//carpeta donde se referencia a los pines de arduino
#include "constants.h"//carpeta donde se referencia a las constantes
#include "characters_table.h"//carpeta donde se referencia a la tabla

//funciones necesarias para el seven segments

  //funciones de set up
    void chip595SetUp (){
      pinMode(LATCH, OUTPUT);
      pinMode(CLOCK, OUTPUT);
      pinMode(DATA, OUTPUT);
    }
    
    void digitsSetUp(){
      pinMode(UNIDADES,OUTPUT);
      pinMode(DECENAS,OUTPUT);
      pinMode(CENTENAS,OUTPUT);
    }

  //funciones de proyección de los números
  void Display(unsigned char num){//función con argumento que permite mostrar un número concreto en el seven segments
    digitalWrite(LATCH,LOW);
    shiftOut(DATA,CLOCK,MSBFIRST,table[num]);
    digitalWrite(LATCH,HIGH);
  }
  
  
  void unidades(int valor){//función con argumento que permite mostrar un número en el dígito de las unidades
    digitalWrite (UNIDADES,LOW);//*NOTA: El dígito solo funcionará si lo ponemos LOW para que la corriente negativa pase por el ánodo
    digitalWrite (DECENAS,HIGH);
    digitalWrite (CENTENAS,HIGH);
    Display (valor);
    /*Serial.print ("unidades:");
    Serial.println (valor);*/
  }
  
  void decenas(int valor){//función con argumento que permite mostrar un número en el dígito de las decenas
    digitalWrite (UNIDADES,HIGH);
    digitalWrite (DECENAS,LOW);//*VE A LA FUNCIÓN "unidades"
    digitalWrite (CENTENAS,HIGH);
    Display (valor);
    /*Serial.print ("decenas:");
    Serial.println (valor);*/
  }
  
  void centenas(int valor){//función con argumento que permite mostrar un número en el dígito de las centenas
    digitalWrite (UNIDADES,HIGH);
    digitalWrite (DECENAS,HIGH);
    digitalWrite (CENTENAS,LOW);//*VE A LA FUNCIÓN "unidades"
    Display (valor);
    /*Serial.print ("decenas:");
    Serial.println (valor);*/
  }
  
  void u_millar(int valor){//función con argumento que permite mostrar un número en el dígito de las unidades de millar
    digitalWrite (UNIDADES,HIGH);
    digitalWrite (DECENAS,HIGH);
    digitalWrite (CENTENAS,HIGH);
    Display (valor);
    /*Serial.print ("decenas:");
    Serial.println (valor);*/
  }
  
  
  void three_digits_once (int c, int d, int u){//función con argumento con la que podemos encender los cuatro dígitos a la vez
    centenas (c);
    delay (BLINK);
    decenas(d);
    delay (BLINK);
    unidades(u);
    delay (BLINK);
  }

  void three_digits_n (int c, int d, int u, int n){
    for (int j = 0; j < n; j++){
    three_digits_once (c, d, u);
    }
  }
  
  int wordReference (int n){
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
    }
    return sol;
  }
  
  int wordReference2 (int n){
    int traductor[] = {COD_0,COD_1,COD_2,COD_3,COD_4,COD_5,COD_6,COD_7,COD_8,COD_9};
    int sol = traductor[n];
    return sol;
  }
  
  void sevenSegments (int n){
  int centenas = n / 100;
  int resto = n % 100;//cálculo del resto
  int decenas = resto / 10;
  resto = resto % 10;
  int unidades = resto;
  three_digits_n(wordReference(centenas),wordReference(decenas),wordReference(unidades),32);
  }
