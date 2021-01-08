#include <Arduino.h>//fichero imprescindible para saber cuales son los pines. NUNCA OLVIDAR

//pines a los que se conectan los cables del seven segments
#define DATA  A1//74HC595  pin A1  data (DS)
#define LATCH A2//74HC595  pin A2  latch (STCP)
#define CLOCK A3//74HC595  pin A1 clock (SHCP)

//pines del ultrasonidos
#define echoUltrasonido A4
#define trigUltrasonido A5

//pin al que se conecta el servo
#define SERVO 3

//pines a los que se conectan los cables de los motores CC y sus respectivos cables de velocidad
#ifdef JAVACASM//adaptados a JAVACASM (Elegoo Smart Robot Car Kit V2.0)
#define ENA 5
#define IN1 8
#define IN2 7

#define ENB 6
#define IN3 11
#define IN4 9

#else//adaptados a ITACHISAN25 (Elegoo Smart Robot Car Kit V3.0)
#define ENA 5
#define IN1 7
#define IN2 8

#define ENB 6
#define IN3 9
#define IN4 11

#endif

//pin del infrarrojos para recibir señales
#define RECV_PIN  12

//pines a los que se asocian los dígitos:
#define UNIDADES 14
#define DECENAS 16
#define CENTENAS 18
#define U_MILLAR 20
