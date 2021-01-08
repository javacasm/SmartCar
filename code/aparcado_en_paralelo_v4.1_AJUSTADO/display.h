//funciones para inicializar los componentes necesarios para que funciones el seven segments
void chip595SetUp ();
void digitsSetUp();

//funciones de proyección de los números individuales
void Display(unsigned char num);
void unidades(int valor);
void decenas(int valor);
void centenas(int valor);
void u_millar(int valor);

//funciones de traducción de datos
int wordReference (int n);
int rae (int n);

//funciones de proyección de números a la vez
void four_digits_once (int um, int c, int d, int u);
void four_digits_n (int um, int c, int d, int u, int n);
void sevenSegments (int n);
void clear_display();
