#include "robot.h"//incluimos la carpeta con las funciones del robot
#include "display.h"// incluimos carpeta con lo relacionado con el seven segments

void finding (){// Esta función se encarga de encontrar el aparcamiento y parar cuando consiga el objetivo
  int rightDistance = rightMeasuring();
  sevenSegments (rightDistance);
  while(rightDistance <= 25){
    robotForwardInstant();
    rightDistance = rightMeasuring();
    sevenSegments (rightDistance);
  }
  robotBrakeInstant();
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
