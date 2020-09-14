#include "robot.h"//especificamos que vamos a incluir el fichero "robot.h"
#include <Arduino.h>//especificamos que vamos a incluir el fichero "Arduino.h"

void M1Setup(){//comienza la función digital M1Setup que configurará y declarará los cables pertenecientes a los motores M1 como salida para poder emplearlos en el programa principal
  pinMode(IN1, OUTPUT); //declaramos el cable IN1 como salida (el ordenador le manda información al robot a través de este)
  pinMode(IN2, OUTPUT);//declaramos el cable IN2 como salida (el ordenador le manda información al robot a través de este)
  pinMode(ENA, OUTPUT);//declaramos el cable ENA como salida (el ordenador le manda información al robot a través de este)  
}//termina la función M1Setup que nos ha permitido preparalo todo para que los motores M1 sean cómodamente utilizados en el programa principal

void M2Setup(){//comienza la función digital M2Setup que configurará y declarará los cables pertenecientes a los motores M2 como salida para poder emplearlos en el programa principal
  pinMode(IN3, OUTPUT); //declaramos el cable IN3 como salida (el ordenador le manda información al robot a través de este)
  pinMode(IN4, OUTPUT);//declaramos el cable IN4 como salida (el ordenador le manda información al robot a través de este)
  pinMode(ENB, OUTPUT);//declaramos el cable ENB como salida (el ordenador le manda información al robot a través de este)  
}//termina la función M2Setup que nos ha permitido preparalo todo para que los motores M2 sean cómodamente utilizados en el programa principal

void M1Speed(int speed){//declaramos la función analógica M1Speed que establece la velocidad a la que se moveran los motores M1 mediante la variable entera speed
  analogWrite(ENA, speed );//el cable ENA transmitirá a los motores M1 la frecuencia con que han de encenderse y apagarse (velocidad) mediante la variable speed 
}//termina el programa relativo a la función analógica M1Speed que permitirá configurar la velocidad a la que se moverán los motores M1

void M2Speed(int speed){//declaramos la función analógica M2Speed que establece la velocidad a la que se moveran los motores M2 mediante la variable entera speed
  analogWrite(ENB, speed);//el cable ENB transmitirá a los motores M2 la frecuencia con que han de encenderse y apagarse (velocidad) mediante la variable speed   
}//termina el programa relativo a la función analógica M2Speed que permitirá configurar la velocidad a la que se moverán los motores M2

// Definimos movimientos basicos de cada motor

void M1Forward(){//declaramos la función digital M1Forward que hace que los motores M1 avancen hacia adelante indefinidamente
  digitalWrite(IN1, HIGH);//el cable IN1 se enciende
  digitalWrite(IN2, LOW);//el cable IN2 se apaga
}//termina el programa relativo a la función analógica M1Forward que provocará que los motores M1 se desplacen hacia delante

void M2Forward(){//declaramos la función digital M2Forward que hace que los motores M2 avancen hacia adelante indefinidamente
  digitalWrite(IN3, LOW); //el cable IN3 se apaga
  digitalWrite(IN4, HIGH);//el cable IN4 se enciende  
}//termina el programa relativo a la función analógica M2Forward que provocará que los motores M2 se desplacen hacia delante

void M1Backward(){//declaramos la función digital M1Backward que hace que los motores M1 avancen hacia detrás indefinidamente
  digitalWrite(IN1, LOW);//el cable IN1 se apaga
  digitalWrite(IN2, HIGH);//el cable IN2 se enciende
}//termina el programa relativo a la función analógica M1Backward que provocará que los motores M1 se desplacen hacia atrás

void M2Backward(){//declaramos la función digital M2Backward que hace que los motores M2 avancen hacia detrás indefinidamente
  digitalWrite(IN3, HIGH);//el cable IN3 se enciende   
  digitalWrite(IN4, LOW); //el cable IN4 se apaga  
}//termina el programa relativo a la función analógica M2Backward que provocará que los motores M2 se desplacen hacia atrás

void M1SmoothStop(){//declaramos la función digital M1SmoothStop que hace que los motores M1 se detengan suave y progresivamente
  digitalWrite(IN1, LOW);//el cable IN1 se apaga
  digitalWrite(IN2, LOW);//el cable IN3 se apaga  
}//termina el programa relativo a la función analógica M1SmoothStop que provocará que los motores M1 se hayan parado suavemente


void M2SmoothStop(){//declaramos la función digital M2SmoothStop que hace que los motores M2 se detengan suave y progresivamente
  digitalWrite(IN3, LOW);//el cable IN1 se apaga
  digitalWrite(IN4, LOW);//el cable IN3 se apaga  
}//termina el programa relativo a la función analógica M2SmoothStop que provocará que los motores M2 se hayan parado suavemente

void M1Brake(){//declaramos la función digital M1Brake que hace que los motores M1 se detengan en seco
  digitalWrite(IN1, HIGH);//el cable IN1 se enciende  
  digitalWrite(IN2, HIGH);//el cable IN2 se enciende
}//termina el programa relativo a la función analógica M1Brake que provocará que los motores M1 se hayan parado en seco

void M2Brake(){//declaramos la función digital M2Brake que hace que los motores M2 se detengan en seco
  digitalWrite(IN3, HIGH);//el cable IN3 se enciende    
  digitalWrite(IN4, HIGH); //el cable IN4 se enciende
}//termina el programa relativo a la función analógica M2Brake que provocará que los motores M2 se hayan parado en seco
