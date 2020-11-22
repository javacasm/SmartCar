#include "robot.h"//incluimos la carpeta con las funciones del robot
#include "display.h"// incluimos carpeta con lo relacionado con el seven segments
#include "constants.h"

void finding (){// Esta función se encarga de encontrar el aparcamiento y parar cuando consiga el objetivo
  //Serial.begin(9600);
  clear_display();
  //Serial.println("Empezamos");
  delay(1000);
  setServo(SERVO_RIGHT);
  int rd = rightMeasuring();

  for(int i =0; i<5; i++){
    rd = rightMeasuring();
    //Serial.print("for: ");
    //Serial.println(rd);
    sevenSegments (rd);
  }
  while(rd <= 25 ){  // hay poco espacio
    robotForwardInstant();
    rd = rightMeasuring();
   // Serial.print("while: ");
//    Serial.println(rd);
    sevenSegments (rd);
  }
  //Serial.println("Terminamos");
  robotBrakeInstant();
  for(int i =0; i<10; i++) sevenSegments (rd);
  
}

void movement1 (){// primer giro (derecha) para que el coche se ponga de cara a la pared
 int middleDistance = middleMeasuring();
  while(middleDistance > 10){
  robotRightPivotInstant();
  middleDistance = middleMeasuring();
  }
  robotBrakeInstant();  
}

void movement2 (){// segundo giro (izquierda) para que el lado del coche se ponga de cara a la pared
 
  
}

void finish (){//ajustar las distancias con los coches
  
}
