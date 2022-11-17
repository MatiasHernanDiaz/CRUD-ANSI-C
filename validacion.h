#ifndef VALIDACION_H_INCLUDED
#define VALIDACION_H_INCLUDED

//Mayusculizador de caracter
//Recibe un caracter
void mayusCaracter(char * c);

//Mayusculiza una cadena
//Recibe una cadena
void mayusCadena(char s[]);

//Miimiza los carecteres de una cadena
//Recibe una cadena
void miniCadena(char m[]);

//Roma una cadena y la corta dejando los
//3 primeros caracteres  ej: argentina -> arg
void cortar3C(char aux[], char s[]);

//Verifica que el mes ingresado sea el correcto
//Se pide un mes y dia. El mes se lo minimiza y se lo corta al tercer caracter
//y se lo guarda en un aux que recibe por parametro.
//Se verifica que el dia concuerde con el mes
//Retorna una 0 si falla la validacion y un 1 si es correcta
int meses(char aux[], int d);

//Comprueba que el orden se encuentre dentro del rango permitido de 0 -100
//de lo contrario vuelve a pedirlo
int valirdarOrden();

//Se asegura que la fecha ingresada no supere a la actual
//Recibe en d = dia, mes en caracter y anio con numeros
int validarFecha(int d, char mes[], int anio);

//Concatena a en c la fecha y hora actual + el formato .xyz
//Recibe una cadena c
void cadenaFecha(char c[]);

//Pide la fecha y la valida
//recibe una cadena donde guarda la fecha
void ingresoFecha(char auxf[]);

//Recibe el nombre generico del archivo y le agrega la fecha y la extesion
//Recibe nombre de archivo y una cadena aux
void completaNombre(char nombf[], char aux[]);

//Peticion del rango de valores para la busqueda
//Recibe por direccion los valores inferior y superior
//y los guarda en las respectivas variables
void rangoValores(float * inf, float * sup);

//Comprueba si en la cadena hay numeros
//Retorna un 1 si lo hay y 0 si no.
//Recibe una cadena
int hayNumeros(char c[]);

//Provee mensajes de errores
//recibe un numero de error
int error(int e);

#endif // VALIDACION_H_INCLUDED
