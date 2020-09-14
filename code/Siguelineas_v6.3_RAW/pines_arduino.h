#include <Arduino.h>//especificamos que vamos a incluir el fichero "Arduino.h"

#define BLUE A1//indicamos que vamos a utilizar el cable conectado al ánodo que corresponde al color azul en el LED RGB, en el pin A1
#define GREEN A2//indicamos que vamos a utilizar el cable conectado al ánodo que corresponde al color verde en el LED RGB, en el pin A2
#define RED A3//indicamos que vamos a utilizar el cable conectado al ánodo que corresponde al color rojo en el LED RGB, en el pin A3

#define echoUltrasonido A4//indicamos que vamos a utilizar el cable conectado al sensor de ultrasonidos echo, en el pin A4
#define trigUltrasonido A5//indicamos que vamos a utilizar el cable conectado al sensor de ultrasonidos trig, en el pin A5

#define LeftLineSensor 2//indicamos que vamos a utilizar el cable conectado al sensor IR de la izquierda, en el pin 2
#define MediumLineSensor 4//indicamos que vamos a utilizar el cable conectado al sensor IR del centro, en el pin 4
#define RightLineSensor 10//indicamos que vamos a utilizar el cable conectado al sensor IR de la derechas, en el pin 10

#define ServoUltrasonido 3//indicamos que vamos a utilizar el cable conectado al servo que mueve al sensor de ultrasonidos, en el pin 3

#define ENA 5//indicamos que vamos a utilizar el cable ENA(cable que ajusta la frecuencia en la que se enciende y apaga los motores izquierdos, es decir, la velocidad de los mismos) y este estará conectado al pin 5
#define IN1 7//indicamos que vamos a utilizar el cable IN1 en el PIN 7
#define IN2 8//indicamos que vamos a utilizar el cable IN2 en el PIN 8

#define ENB 6 //indicamos que vamos a utilizar el cable ENB(cable que ajusta la frecuencia en la que se enciende y apaga los motores derchos, es decir, la velocidad de los mismos) y este estará conectado al PIN 6
#define IN3 9//indicamos que vamos a utilizar el cable IN3 en el PIN 9
#define IN4 11//indicamos que vamos a utilizar el cable IN4 en el PIN 11

#define MandoInfraRojo 12//indicamos que vamos a utilizar el cable correspondiente al mando del otro sensor IR, en el pin 12
