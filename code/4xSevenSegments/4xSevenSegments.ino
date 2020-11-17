//www.elegoo.com
//2016.12.12

int latch = 9;   //74HC595  pin 9  latch (STCP)
int clock = 10;   //74HC595  pin 10 clock (SHCP)
int data  = 8;   //74HC595  pin 8  data (DS)


// ![pinout 74595 ShiftRegister ](./images/ShiftRegisterPinOut.jpg)

/*   74595 protocol
 *   The most common method of using 74CH595
 *   latch->LOW : Begin transmitting signals.
 *   shiftOut(dataPin, clockPin, bitOrder, value)
 *   dataPin: the pin on which to output each bit. Allowed data types: int.
 *   clockPin: the pin to toggle once the dataPin has been set to the correct value. Allowed data types: int.
 *   bitOrder: which order to shift out the bits; either MSBFIRST or LSBFIRST. (Most Significant Bit First, or, Least Significant Bit First).
 *   value: the data to shift out. Allowed data types: byte. 
 *   latch->HIch : The end of the transmission signal.
*/

/*
Nombres de los 7 segmentos
 
     A
    ---
 F | G | B
    ---
 E |   | C
    ---
     D

// ![Pinout de 4 x 7 segmentos](./images/4-digit-7-segment-display-pinout.jpg)

*/

// string alumnos[] = {"Antonio", "Miguel", "Juanjo"}; // Ejemplo de array/lista

// Representación de los números en hexadecimal 0x7B

unsigned char table [] =  // Tabla de segmentos a encender para un numero/caracter dado
{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c // '0', ... '9'
,0x39,0x5e,0x79,0x71,    // , 'a',...,'f', '
0x00, // Blanco
0x99, // emoji
};  



// [conversor Hexadecimal a binario ](https://www.rapidtables.com/convert/number/hex-to-binary.html?x=0x7f)




/*

Representación de números en binario
{B00000000, B00000001,B00000010}


// Ejemplos
table[1] = 0x06 ; B00000110 // encendemos los segmentos B y C 
table[7] = 0x07 ; B00000111 // encendemos los segmentos A, B y C 
table[8] = 0x7f ; B01111111 // encendemos todos
                   PGFEDCBA // segmentos 

*/

// [Montaje 74595 y display de 4 dígitos de 7 segmentos](./images/Montaje7-segments_74595.png)

void setup() {
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(data, OUTPUT);
  Serial.begin(9600);
}



void Display(unsigned char num)
{

  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,table[num]);
  digitalWrite(latch,HIGH);
  
}

void loop() {
  for(int i = 0; i <= 16; i++){
    Display(i);  
    delay(500);
    Serial.println(i);
  }
}
