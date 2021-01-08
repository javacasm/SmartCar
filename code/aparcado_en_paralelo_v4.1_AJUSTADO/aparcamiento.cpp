#include "robot.h"//fichero con las funciones del robot en general
#include "constants.h"//fichero con todas las constantes
#include "display.h"// fichero con lo relacionado con el seven segments
#include <Arduino.h>//librería imprescindible para la información básica del robot. NUNCA OLVIDAR

//funciones con los movimientos en los que se divide el aparcamiento
void finding (){//función sin argumento que encuentra aparcamiento y para cuando consigue el objetivo
  //Serial.begin(9600);
  clear_display();
  //Serial.println("Empezamos");
  delay(1000);
  setServo(SERVO_RIGHT);
  int rd = rightMeasuring();
  for(int i =0; i<5; i++){//medimos 5 veces a la derecha
    rd = rightMeasuring();
    //Serial.print("for: ");
    //Serial.println(rd);
    sevenSegments (rd);
  }
  while(rd <= 25 ){//mientras la medida sea menor a 25 (hay poco espacio) avanzamos
    robotForwardInstant();
    rd = rightMeasuring();
    // Serial.print("while: ");
    //Serial.println(rd);
    sevenSegments (rd);
  }
  //Serial.println("Terminamos");
  robotBrakeInstant();//si es mayor a 25 (hay suficiente espacio) paramos
  for(int i =0; i<10; i++) sevenSegments (rd);
}

void movement1 (){//función sin argumento que ejecuta el pivote a la derecha para que el coche se ponga de cara a la pared
  //Serial.begin(9600);
  clear_display();
  //Serial.println("Empezamos");
  delay(1000);
  setServo(SERVO_CENTRAL);
  int cd = middleMeasuring();
  for(int i =0; i<5; i++){//medimos 5 veces a la izquierda
    cd = middleMeasuring();
    //Serial.print("for: ");
    //Serial.println(rd);
    sevenSegments (cd);
  }
  while(cd > 10){//mientras la medida sea mayor a 10 (no hay pared en frente del robot) pivotamos a la derecha
    robotRightPivotInstant();
  cd = middleMeasuring();
    // Serial.print("while: ");
    //Serial.println(md);
    sevenSegments (cd);
  }
  //Serial.println("Terminamos");
  robotBrakeInstant();//si es menor a 10 (hay pared en frente del robot) paramos
  for(int i =0; i<10; i++) sevenSegments (cd);
}

void movement2 (){//función sin argumento que realiza la rotación a la izquierda para que el lado del coche se ponga de cara a la pared
 
}

void finish (){//función sin argumento que ajusta las distancias entres los coches y termina de aparcar
  
}
