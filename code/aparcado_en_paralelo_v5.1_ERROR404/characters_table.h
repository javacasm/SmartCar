/*
table[0] = B00000000 ; 0X00 // apagamos todos
table[1] = B00111111 ; 0x3f // 0: encendemos los segmentos A, B, C, D, E y F
table[2] = B00000110 ; 0x06 // 1: encendemos los segmentos B y C 
table[3] = B01011011 ; 0x5b // 2: encendemos los segmentos A, B, D, E, y G
table[4] = B01001111 ; 0x4f // 3: encendemos los segmentos A, B, C, D y G
table[5] = B01100110 ; 0x66 // 4: encendemos los segmentos B, C, F y G
table[6] = B01101101 ; 0x6d // 5: encendemos los segmentos A,C D, F y G
table[7] = B01111101 ; 0x7d // 6: encendemos los segmentos A, C, D, E, F y G
table[8] = B00000111 ; 0x07 // 7: encendemos los segmentos A, B y C
table[9]= B01111111 ; 0x7f // 8: encendemos los segmentos A, B, C, D, E, F y G
table[10]= B01100111 ; 0x67 // 9: encendemos los segmentos A, B, B, F y G
table[11]= B01110111 ; 0x77 // A: encendemos los segmentos A, B, C, E, F y G
table[12]= B01111100 ; 0x7c // B: encendemos los segmentos C, D, E, F y G
table[13]= B00111001 ; 0x39 // C: encendemos los segmentos A, D, E y F
table[14]= B01011110 ; 0x5e // D: encendemos los segmentos B, C, D, E y G
table[15]= B01111001 ; 0x79 // E: encendemos los segmentos A, D, E, F y G
table[16]= B01110001 ; 0x71 // F: encendemos los segmentos A, E, F y G
table[17]= B00111101 ; 0X3d // G: encendemos los segmentos A, C, D, E y F
table[18]= B01110110 ; 0x76 // H: encendemos los segmentos B, C, E, F y G
table[19]= B00110000 ; 0x30 // I: encendemos los segmentos E y F
table[20]= B00001110 ; 0x0e // J: encendemos los segmentos B, C y D
table[21]= B00111000 ; 0x38 // L: encendemos los segmentos D, E, y F
table[22]= B01010100 ; 0x54 // N: encendemos los segmentos C, E y G
table[23]= B01010101 ; 0x55 // Ñ: encendemos los segmentos A, C, E y G
table[24]= B01011100 ; 0x5c // O: encendemos los segmentos C, D, E, y G
table[25]= B01110011 ; 0x73 // P: encendemos los segmentos A, B, E, F, y G
table[26]= B01100111 ; 0x67 // Q: encendemos los segmentos A, B, C, F, y G
table[27]= B01010000 ; 0x50 // R: encendemos los segmentos E y G
table[28]= B01101101 ; 0x6d // S: encendemos los segmentos A,C D, F y G
table[29]= B01110000 ; 0x70 // T: encendemos los segmentos E, F y G
table[30]= B00111110 ; 0x3e // U: encendemos los segmentos B, C, D, E y F
table[31]= B00101010 ; 0x2a // pockerface: encendemos los segmentos B, D y F
tabke[32]= B00001111 ; 0x0f // smile: encendemos los segmentos A, B, C y D
table[33]= B00001001 ; 0x09 // eyes: encendemos los segmentos D y A
            HGFEDCBA         // segmentos 

 * Nombres de los 7 segmentos:
     A
    ---
 F | G | B
    ---
 E |   | C
    ---
     D
*/
unsigned char table [] =  // Tabla de segmentos a encender para un numero/caracter dado
{0X00,//apagado
0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67,// '0', ... '9'
0x77,0x7c,0x39,0x5e,0x79,0x71,0X3d,0x76,0x30,0x0e,0x38,0x54,0x55,0X5c,0x73,0x67,0x50,0x6d,0x70,0x3e, // , 'a',...,'u',
0x2a,//pockerface
0x0f,//smile
0x09//eyes

};  
