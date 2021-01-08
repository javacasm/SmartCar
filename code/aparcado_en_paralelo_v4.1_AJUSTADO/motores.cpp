#include "arduino_pins.h"//fichero con los pines en los que se conectan los cables

//funciones que inicializan las parejas de motores (IN1 e IN2, M1;y IN3 e IN4, M2) 
    void M1Setup(){
      pinMode(IN1, OUTPUT); 
      pinMode(IN2, OUTPUT);
      pinMode(ENA, OUTPUT);
    }
    
    void M2Setup(){
      pinMode(IN3, OUTPUT);
      pinMode(IN4, OUTPUT);
      pinMode(ENB, OUTPUT);
    }
    
    void M1Speed(int speed){//función con argumento que configura la velocidad de M1
      analogWrite(ENA, speed );
    }
    
    void M2Speed(int speed){//función con argumento que configura la velocidad de M2
      analogWrite(ENB, speed);
    }

//funciones con los movimientos de cada pareja de motores (M1 y M2)
    void M1Forward(){//función sin argumento para que M1 se desplace hacia adelante indefinidamente
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
    }
    
    void M2Forward(){//función sin argumento para que M2 se desplace hacia adelante indefinidamente
      digitalWrite(IN3, LOW); 
      digitalWrite(IN4, HIGH); 
    }
    
    void M1Backward(){//función sin argumento para que M1 avance hacia atrás indefinidamente
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
    }
    
    void M2Backward(){//función sin argumento para que M2 avance hacia atrás indefinidamente
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }
    
    void M1Brake(){//función sin argumento para que M1 pare en seco indefinidamente
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
    }
    
    void M2Brake(){//función sin argumento para que M2 pare en seco indefinidamente
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
    }
    
    void M1SmoothStop(){//función sin argumento para que M1 pare suave, progresiva e indefinidamente
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
    }
    
    void M2SmoothStop(){//función sin argumento para que M2 pare suave, progresiva e indefinidamente
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
