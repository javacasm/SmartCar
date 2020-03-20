
#include "robot.h"
#include <Arduino.h>

void M2Speed(int speed){
  analogWrite(ENB, speed);  //el cable ENB del motor derecho está encendido    
}

void M1Speed(int speed){
  analogWrite(ENA, speed );  //el cable ENA del motor izquierdo está encendido  
}

void M1Setup(){
  pinMode(IN1, OUTPUT); //declaramos el cable IN1 como salida 
  //(el ordenador le manda información al robot a través de este)
  pinMode(IN2, OUTPUT);//declaramos el cable IN2 como salida 
  //(el ordenador le manda información al robot a través de este)
  pinMode(ENA, OUTPUT);//declaramos el cable ENA como salida 
  //(el ordenador le manda información al robot a través de este)  
}

void M2Setup(){
  pinMode(IN3, OUTPUT); //declaramos el cable IN3 como salida 
  //(el ordenador le manda información al robot a través de este)
  pinMode(IN4, OUTPUT);//declaramos el cable IN4 como salida 
  //(el ordenador le manda información al robot a través de este)
  pinMode(ENB, OUTPUT);//declaramos el cable ENB como salida 
  //(el ordenador le manda información al robot a través de este)  
}


// Definimos movimientos basicos de cada motor
void M1Forward(){
  digitalWrite(IN2, HIGH);//el cable IN1 se enciende
  digitalWrite(IN1, LOW);//el cable IN2 se apaga
}

void M2Forward(){
  digitalWrite(IN4, LOW);   //el cable IN3 se apaga
  digitalWrite(IN3, HIGH);//el cable IN4 se enciende  
}

void M1Backward(){
  digitalWrite(IN2, LOW);//el cable IN1 se apaga
  digitalWrite(IN1, HIGH);//el cable IN2 se enciende
}

void M2Backward(){
  digitalWrite(IN4, HIGH);//el cable IN3 se enciende   
  digitalWrite(IN3, LOW); //el cable IN4 se apaga  
}

void M1SmoothStop(){
  digitalWrite(IN1, LOW);//el cable IN1 se apaga
  digitalWrite(IN2, LOW);//el cable IN3 se apaga  
}

void M2SmoothStop(){
  digitalWrite(IN3, LOW);//el cable IN1 se apaga
  digitalWrite(IN4, LOW);//el cable IN3 se apaga  
}

void M1Brake(){
  digitalWrite(IN1, HIGH);//el cable IN1 se enciende  
  digitalWrite(IN2, HIGH);//el cable IN2 se enciende
}


void M2Brake(){
  digitalWrite(IN3, HIGH);//el cable IN3 se enciende    
  digitalWrite(IN4, HIGH); //el cable IN4 se enciende
}
