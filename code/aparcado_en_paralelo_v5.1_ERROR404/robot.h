//funciones que inicializan los componentes
void motorsSetUp();
void servoSetUp();
void ultrasonicSetUp();
void robotSetSpeed(int speed);

//funciones de medida del ultrasonidos
int Distance_test();
int rightMeasuring ();
int middleMeasuring ();
int leftMeasuring ();

//movimientos del servo (que sujeta ultrasonidos)
void setServo(int angle);

//funciones de movimiento del robot (con motores CC, a partir movimientos del fichero "motores.h")
void robotForwardInstant ();
void robotForward(int duracion);

void robotRightInstant ();
void robotRight(int duracion);
void robotRightPivotInstant ();
void robotRightPivot (int duracion);

void robotLeftInstant ();
void robotLeft(int duracion);
void robotLeftPivotInstant ();
void robotLeftPivot (int duracion);

void robotBackwardInstant ();
void robotBackward(int duracion);

void robotBrakeInstant ();
void robotBrake(int duracion);

void robotSmoothstopInstant ();
void robotSmoothstop(int duracion);
