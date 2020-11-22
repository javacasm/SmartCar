
#include "ir_control.h"
#include "robot.h"
#include "constants.h"
#include "display.h"

#include <IRremote.h>


IRrecv irrecv(RECV_PIN);
decode_results results;

void detect_IR(){
  //Serial.begin(9600);
  bool bDetectIR = true;
  
  irrecv.enableIRIn();  
  int speed = MEDIUM;
  Display(COD_BLANK);
  while(bDetectIR == true){
   if (irrecv.decode(&results)){ 
      unsigned long val = results.value;
      irrecv.resume();
      switch(val){
        //Serial.println(val);
        
        // Movimientos
        case FORWARD: 
        case UNKNOWN_FORWARD: robotSetSpeed(speed); robotForwardInstant();  Display(COD_F);   break;
        case BACWARD: 
        case UNKNOWN_BACWARD: robotSetSpeed(speed); robotBackwardInstant(); Display(COD_B);   break;
        case LEFT: 
        case UNKNOWN_LEFT:    robotSetSpeed(speed); robotLeftInstant();     Display(COD_L);   break;
        case RIGHT: 
        case UNKNOWN_RIGHT:   robotSetSpeed(speed); robotRightInstant();    Display(COD_R);   break;
        // Pivote
        case KEY7:            robotSetSpeed(speed); robotRightPivotInstant(); Display(COD_L); break;
        case KEY9:            robotSetSpeed(speed); robotLeftPivotInstant(); Display(COD_R); break;

        
        // Parada
        case STOP: 
        case UNKNOWN_STOP: robotBrakeInstant (); Display(COD_BLANK);   break;
        
        // Control de velocidad
        case KEY1:speed = SLOW;     Display(COD_1);   break;
        case KEY2:speed = MEDIUM;   Display(COD_5);   break;
        case KEY3:speed = FAST;     Display(COD_9);   break;
        
        // Control de servo
        case KEY4: setServo(SERVO_LEFT);      Display(COD_L);   break;
        case KEY5: setServo(SERVO_CENTRAL);   Display(COD_C);   break;        
        case KEY6: setServo(SERVO_RIGHT);     Display(COD_R);   break;

        // Sale del modo IR
        case KEY_STAR: bDetectIR = false;     
          Display(COD_3);    delay(500);
          Display(COD_2);    delay(500);
          Display(COD_1);    delay(500);
          Display(COD_BLANK);delay(500);
        
        default: break;
      }
    }
  }
}
