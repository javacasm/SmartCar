#include <Arduino.h>//carpeta imprescindible para saber cuales son los pines. NUNCA OLVIDAR

#define DATA  A1//74HC595  pin A1  data (DS)
#define LATCH A2//74HC595  pin A2  latch (STCP)
#define CLOCK A3//74HC595  pin A1 clock (SHCP)

#define echoUltrasonido A4
#define trigUltrasonido A5

//#define JAVACASM 1

#define SERVO 3

#define RECV_PIN  12

#ifdef JAVACASM

#define ENA 5//indicamos que vamos a utilizar el cable ENA(cable que ajusta la frecuencia en la que se enciende y apaga los motores izquierdos, es decir, la velocidad de los mismos) y este estará conectado al pin 5
#define IN1 8//indicamos que vamos a utilizar el cable IN1 en el PIN 7
#define IN2 7//indicamos que vamos a utilizar el cable IN2 en el PIN 8

#define ENB 6 //indicamos que vamos a utilizar el cable ENB(cable que ajusta la frecuencia en la que se enciende y apaga los motores derchos, es decir, la velocidad de los mismos) y este estará conectado al PIN 6
#define IN3 11//indicamos que vamos a utilizar el cable IN3 en el PIN 9
#define IN4 9//indicamos que vamos a utilizar el cable IN4 en el PIN 11

#else

#define ENA 5//indicamos que vamos a utilizar el cable ENA(cable que ajusta la frecuencia en la que se enciende y apaga los motores izquierdos, es decir, la velocidad de los mismos) y este estará conectado al pin 5
#define IN1 7//indicamos que vamos a utilizar el cable IN1 en el PIN 7
#define IN2 8//indicamos que vamos a utilizar el cable IN2 en el PIN 8

#define ENB 6 //indicamos que vamos a utilizar el cable ENB(cable que ajusta la frecuencia en la que se enciende y apaga los motores derchos, es decir, la velocidad de los mismos) y este estará conectado al PIN 6
#define IN3 9//indicamos que vamos a utilizar el cable IN3 en el PIN 9
#define IN4 11//indicamos que vamos a utilizar el cable IN4 en el PIN 11

#endif
