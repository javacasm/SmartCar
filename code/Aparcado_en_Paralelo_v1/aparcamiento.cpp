#include "robot.h"//espescificamos que vamos a incluir el fichero "robot.h"

void finding (){// Esta función se encarga de encontrar el aparcamiento y parar cuando consiga el objetivo
  int rightDistance = rightMeasuring();
  while(rightDistance <= 25){
    robotForwardInstant();
    rightDistance = rightMeasuring();
  }
  robotBrakeInstant();
}

void movement1 (){// primer giro (derecha) para que el coche se ponga de cara a la pared
 int middleDistance = middleMeasuring();
 if (middleDistance > 10){
  while(middleDistance > 10){
  robotRightInstant();
  middleDistance = middleMeasuring();
  }
}
    else {
      robotBrakeInstant();
    }
}

void movement2 (){// segundo giro (izquierda) para que el lado del coche se ponga de cara a la pared
 
  
}

void finish (){//ajustar las distancias con los coches
  
}



  
  /*
  if (rightDistance > 25){
    robotBrakeInstant();
    middleMeasuring();
  }
  else {
    robotForwardInstant();
    rightMeasuring();
  }
 
  /*while (middleDistance > 10){
    robotRightInstant();
    middleMeasuring();
  }
  if (middleDistance <= 10)robotBrakeInstant();
  }
    //while (middleDistance > 10);
  
/*    delay(WAIT_WHILE);                    
    rightMeasuring ();
    delay(WAIT_WHILE);                                         
    leftMeasuring ();
    delay(WAIT_WHILE);   
    middleMeasuring();
    delay(WAIT_WHILE);   
    Serial.print (rightDistance);
    Serial.print(" ");
    Serial.print (middleDistance);
    Serial.print(" ");
    Serial.print (leftDistance);

  if (rightDistance <= HAND){
    green ();
    Serial.println(" turning RIGHT");
    robotRight (SPIN);
    robotBrakeInstant ();
  }
  else if (middleDistance <= HAND){
    green ();
    Serial.println(" moving FORWARDS");
    robotForwardInstant ();
  }
  else if (leftDistance <= HAND){
    green ();
    Serial.println(" turning LEFT");
    robotLeft (SPIN);
    robotBrakeInstant ();
  }
  else if (leftDistance > HAND && middleDistance > HAND && rightDistance > HAND){
    red ();
    Serial.println(" Did you flee?");
    robotBrakeInstant();
  }
  else {
    blue ();
    Serial.println(" What's going on?");
  }
  */
