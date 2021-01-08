#include "ir_control.h"//fichero con los casos y las funciones del control remoto IR
#include "arduino_pins.h"//fichero con los pines en los que se conectan los componentes
#include "robot.h"//fichero con las funciones del robot en general
#include "constants.h"//fichero con todas las constantes
#include "display.h"// fichero con lo relacionado con el seven segments
#include <IRremote.h>

IRrecv irrecv(RECV_PIN);//clase objeto(constructor);
decode_results results;//decode_results=tipo de variable complejo con muchos valores diferentes e independientes

void detect_IR(){
  Serial.begin(9600);
  bool bDetectIR = true;//bool=tipo de variable que puede ser true o false
  irrecv.enableIRIn();//inicializamos el objeto irrecv
  int speed = MEDIUM;
  Display(COD_BLANK);
  // Error 2 al definirla dentro del while no mantenia el valor de la iteracion anterior
  unsigned long ircode = 0, newCode;
  unsigned long codigo404 = 4294967295;
  
  while(bDetectIR == true){
   
   if (irrecv.decode(&results) == true){//decode mide los datos IR grabados y los "escribe" como los valores de la variable results 
      // ERROR 3 usamos una variable intermedia para no perder el ultimo valor valido de ircode
      newCode = results.value;//unsigned long=tipo de variable que ocupa 32 bits (int solo 16 bits) que son todos números, es decir no hay cabida para signos
      // ERROR 1 SI NO LLAMAMOS a irrecv.resume ¡¡¡¡¡NO SE LEEN NUEVOS CODIGOS!!!!!!!
      irrecv.resume();//graba los datos IR para que el decode los lea
      if (newCode == codigo404) { 
          Serial.print(newCode);
          Serial.println(" - 404"); 
          continue; 
      }
      // Es un codigo valido
      ircode = newCode;
      
      switch(ircode){
        //casos de movimientos
          case FORWARD: 
          case UNKNOWN_FORWARD:  Serial.println ("FORWARD ");    robotSetSpeed(speed); robotForwardInstant();     break;
          
          case BACKWARD: 
          case UNKNOWN_BACKWARD: Serial.println ("BACKWARD ");   robotSetSpeed(speed); robotBackwardInstant();  break;
          
          case LEFT: 
          case UNKNOWN_LEFT:     Serial.println ("LEFT ");       robotSetSpeed(speed); robotLeftInstant();     Display(COD_L);   break;
          case RIGHT: 
          case UNKNOWN_RIGHT:    Serial.println ("RIGHT ");      robotSetSpeed(speed); robotRightInstant();    Display(COD_R);   break;
          // Pivote
          case KEY7:             Serial.println ("LEFT PIVOT");  robotSetSpeed(speed); robotLeftPivotInstant();  Display(COD_L); break;
          case KEY9:             Serial.println ("RIGHT PIVOT"); robotSetSpeed(speed); robotRightPivotInstant(); Display(COD_R); break;

        
        // Parada
        case STOP: 
        case UNKNOWN_STOP: Serial.println ("BRAKE");robotBrakeInstant (); Display(COD_BLANK);   break;
        
        // Control de velocidad
        case KEY1:         Serial.println ("SLOW");   speed = SLOW;     Display(COD_1);   break;
        case KEY2:         Serial.println ("MEDIUM"); speed = MEDIUM;   Display(COD_5);   break;
        case KEY3:         Serial.println ("FAST");   speed = FAST;     Display(COD_9);   break;
        
        // Control de servo
        case KEY4:         Serial.println ("SERVO LEFT");      setServo(SERVO_LEFT);      Display(COD_L);   break;
        case KEY5:         Serial.println ("SERVO CENTRAL");   setServo(SERVO_CENTRAL);   Display(COD_C);   break;        
        case KEY6:         Serial.println ("SERVO RIGHT");     setServo(SERVO_RIGHT);     Display(COD_R);   break;

        // Sale del modo IR
        case KEY_STAR: 
          bDetectIR = false;   
          Serial.println("EXIT IN .. 3");  
          Display(COD_3);    delay(500);
          Serial.println("EXIT IN .. 2");  
          Display(COD_2);    delay(500);
          Serial.println("EXIT IN .. 1");  
          Display(COD_1);    delay(500);
          Serial.println("EXIT IN .. 0");  
          Display(COD_BLANK);delay(500);
          break;
        
        default:
        codigo404 = ircode;
        Serial.print ("ERROR 404 ");
        Serial.println (ircode); 
        break;
      }
    }
    else {
      switch(ircode){
        case FORWARD:
        case UNKNOWN_FORWARD:
          four_digits_once (COD_F,COD_O,COD_R,COD_D); 
          //Serial.println("FORD");
          break;
        case BACKWARD:
        case UNKNOWN_BACKWARD:
          four_digits_once (COD_B,COD_C,COD_R,COD_D); 
          //Serial.println("BCRD");
          break;

        case LEFT: 
        case UNKNOWN_LEFT:    
          four_digits_once (COD_L,COD_E,COD_F,COD_T); 
          //Serial.println("LEFT");          
          break;
        
        case RIGHT: 
        case UNKNOWN_RIGHT:
          four_digits_once (COD_R,COD_G,COD_H,COD_T); 
          //Serial.println("RGHT");        
          break;
        default:
          //four_digits_once (COD_EYES,COD_EYES,COD_EYES,COD_EYES);
          //Serial.println("YYYY");
          break;
        
      }
    }
  }
}
