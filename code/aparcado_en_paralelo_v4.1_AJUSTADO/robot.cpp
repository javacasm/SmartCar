#include "arduino_pins.h"//fichero con los pines en los que se conectan los componentes
#include "constants.h"//fichero con todas las constantes
#include "motores.h"//fichero en el que se describen los movimientos de los motores CC
#include <Servo.h>  //librería del servo

//funciones que inicializan los componentes
    void motorsSetUp(){
     M1Setup();
     M2Setup();
    }
    
    Servo myservo;//asociamos un nombre a nuestro servo
    void servoSetUp (){
      myservo.attach(3);
    }
    
    void ultrasonicSetUp(){
     pinMode(echoUltrasonido, INPUT);    
     pinMode(trigUltrasonido, OUTPUT); 
    }
    
    void robotSetSpeed (int speed){//función con argumento que configura la velocidad de los motores CC
      M1Speed(speed);
      M2Speed(speed);
    }

//funciones de medida del ultrasonidos
    int Distance_test() {//función sin argumento que nos devolverá la variable que constituye la distancia medida por el ultrasonidos
      digitalWrite(trigUltrasonido, LOW);   
      delayMicroseconds(2);
      digitalWrite(trigUltrasonido, HIGH);  
      delayMicroseconds(20);
      digitalWrite(trigUltrasonido, LOW);   
      float fDistance = pulseIn(echoUltrasonido, HIGH);  
      fDistance= fDistance / 58;       
      return (int)fDistance;
    }  
    
    int rightMeasuring (){
      myservo.write(SERVO_RIGHT);
      delay (100);
      int rightDistance = Distance_test();
      return rightDistance;
    }
    
    int middleMeasuring(){
      myservo.write(SERVO_CENTRAL);
      delay (100);
      int middleDistance = Distance_test();
      return middleDistance;
    }
    
    int leftMeasuring (){
      myservo.write(SERVO_LEFT);
      delay (100);              
      int leftDistance = Distance_test();
      return leftDistance;
    }

//movimientos del servo (que sujeta ultrasonidos)
    void setServo(int angle){
      myservo.write(angle);
    }

//funciones de movimiento del robot (con motores CC, a partir movimientos del fichero "motores.h")
    void robotForwardInstant(){//función sin argumento para que robot se desplace hacia adelante indefinidamente
      M1Forward();
      M2Forward();
    }
    void robotForward(int duracion){//función con argumento para que robot se desplace hacia adelante durante un tiempo dado
      robotForwardInstant();
      delay (duracion);
    }
    
    void robotRightInstant (){//función sin argumento para que el robot rote hacia la derecha indefinidamente
      M1Forward();
      M2Backward();
    }
    void robotRight(int duracion){//función con argumento para que el robot rote hacia la derecha durante un tiempo dado
      robotRightInstant();
      delay (duracion);
    }
    void robotRightPivotInstant (){//función sin argumento para que el robot pivote hacia la derecha indefinidamente
      M1Forward();
      M2Brake();
    }
    void robotRightPivot (int duracion){//función con argumento para que el robot pivote hacia la derecha durante un tiempo dado
      robotRightPivotInstant();
      delay (duracion);
    }
    
    void robotLeftInstant (){//función sin argumento para que el robot rote hacia la izquierda indefinidamente
      M1Backward();
      M2Forward();
    }
    void robotLeft(int duracion){//función con argumento para que el robot rote hacia la izquierda durante un tiempo dado
      robotLeftInstant();
      delay (duracion);
    }
    void robotLeftPivotInstant (){//función sin argumento para que el robot pivote hacia la izquierda indefinidamente
      M1Brake();
      M2Forward();
    }
    void robotLeftPivot (int duracion){//función con argumento para que el robot pivote hacia la izquierda durante un tiempo dado
      robotLeftPivotInstant();
      delay (duracion);
    }
    
    void robotBackwardInstant (){//función sin argumento para que el robot avance hacia atrás indefinidamente
      M1Backward();
      M2Backward();
    }
    void robotBackward(int duracion){//función sin argumento para que el robot avance hacia atrás durante un tiempo dado
      robotBackwardInstant();
      delay (duracion);
    }
    
    void robotBrakeInstant (){//función sin argumento para que el robot frene en seco indefinidamente
      M1Brake ();
      M2Brake ();
    }
    void robotBrake(int duracion){//función sin argumento para que el robot frene en seco durante un tiempo dado
      robotBrakeInstant();
      delay (duracion);
    }
    
    void robotSmoothStopInstant(){//función sin argumento para que el robot frene suave, progresiva e indefinidamente
      M1SmoothStop();
      M2SmoothStop();
    }
    void robotSmoothstop(int duracion){//función sin argumento para que el robot frene suave y progresivamente durante un tiempo determinado
       robotSmoothStopInstant();
      delay (duracion);
    }
