#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED


//Lee un archivo de texto
//Recibe el puntero archivo y el puntero al nombre del archivo;
void leerArchivo(FILE * f, char nomf[]);

//Escribe en un archivo de texto una cadena
//Recibe el puntero archivo, el nombre de archivo y la cadena
void escribirArchivo(FILE * f, char nomf[], char cadena[]);


//Extrae los datos de una linea de CSV
//Recibe puntero a la linea hasta el \n la direcion de orden (o) corredor (c) dia (d) mes (m) anio(a) edad (e) pais(p) y tiempo (t)
//y los convierte en sus respectivos tipos
void extraerDatos(char *linea, int *o, long *c, int *d, char *m, int *a, int *e, char *p, float *t);

//recorre todas las lineas del archivo csv aplicando la funcion extraerDatos
//separando los datos y convirtiendolos a los tipos correspondientes
//HASTA ACA.... EN VEZ DE IMPRIMIR QUE LO AGUARDE EN EL BINARIO
//Recibe un puntero al archivo
void extraerDatosCSV(FILE *f);

//Crea una carpeta donde se guardaran los archivos binarios
//recibe un nombre de carpeta
//"carpetaB"
void crearCarpeta(char nomc[]);

//Crea un archivo binario
//Recibe un nombre de archivo
//"archivoB\\competidores.dat"
void crearArchivoB(char nomb[]);

//Crea un archivo
//Recibe un nombre de archivo
void crearArchivo(char nomb[]);

#endif // ARCHIVOS_H_INCLUDED
