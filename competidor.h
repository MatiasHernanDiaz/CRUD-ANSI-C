#ifndef COMPETIDOR_H_INCLUDED
#define COMPETIDOR_H_INCLUDED


struct CorredorEstructura;

//Se define Corredor como un puntero a la estructura
typedef struct CorredorEstructura * Corredor;


//Constructor del corredor por teclado
//Usa internamenta la funcion crear Corredor
//Retorna un puntero a la estructura CorredorEstructura
//En esta misma funcion se hace llamado a las distintas validaciones
Corredor crearCorredorTeclado(FILE * fb, char nomb[], int * o);

//Constructor del corredor por parametros
//Recibe un o = orden, n = corredor, e =edad, p =pais, t = tiempo
//Retorna un puntero a la estructura corredor
Corredor crearCorredor(int o, long n, int d, char m[11], int a, int e, char p[57], float t);

//Imprime una estructura CorredorEstructura
//Recibe un puntero a la estructura
void mostrarCorredor(Corredor c);

//Destructor Corredor
//Libera la memoria
//Recibe un puntero a la estructura CorredorEstructura
void eliminarCorredor(Corredor c);

//Migra el archivo csv a uno binario;
//Recibe un puntero al archivo csv y el nombre del archivo binario al cual migrara.
void migrar(FILE *f, FILE * fb, char nomb[]);

//Lee el archivo binario
//Recibe el puntero y el nombre del binario
void leerCSVB(FILE * fb, char nomf[], int act, char pa[], float ran_inf, float ran_sup);

//Crea un puntero a una estructura Corredor {0,0,...,0}
Corredor vacioCorredor();

//Se utiliza en la migracion de datos
//Agrega una cantidad fija de registro cargados con corredor vacio
//Recibe un puntero al archivo binario y una cantidad de registro a crear
void escribirVacioNRegistro(FILE * fb, int n);

//Agrega un nuevo corredor en el archivo binario
//Recibe un puntero al archivo y el nombre del mismo
//Se hace llamado a funciones de validacion y creacion de struct CorredorEstructura
void nuevoCorredor(FILE *fb, char nomb[]);

//Busca el minimo anio entre todo los corredores
//para poder setearlo de base en la validacion
//Recibe un puntero al archivo binario y un nombre
//Devuelve el min anio
int minAnio(FILE * fb, char nomb[]);

//Buscar binaria del corredor
//Recibe puntero archivo, nombre de archivo, N# corredor buscado,
//y un puntero a una variable que almacena la linea del corredor encontrado
//xO = 1 y xC = 0 --> por orde
//xO = 0 y xC = 1 --> por corredor
//retorna un puntero a un struct corredorEstructura si no encuentra corredor
Corredor buscar(FILE * fb, char nomb[], int xO, int xC, int buscado, long * linea);

//modifica edad o tiempo del puntero de la estructura corredorEstructura
//Recibe a un puntero a corredorEstructura y un entero para seleccionar la opcion la opcion
void modificar(Corredor c, int op);

//Escribe en un archivo binario el un corredor.
//Utiliza la funcion busqueda y mediante la variable fila (ubicacion del corredor a modificar)
//Graba el modificado en el archivo.
//Recibe un puntero al archivo, el nombre de archivo y el corredor a grabar
void escribirModificacion(FILE * fb, char nomb[], Corredor aux);

//Cambia el campo activo 1 a 0 para darlo den baja
//Recibe un puntero a la struct corredor
void bajaLogica(Corredor c);

//Realiza el pase de las bajas logicas del archivo .dat al archivo .xyz
//Recibe el puntero al archivo .dat, el nombre de archivo.dat
//Recibe el puntero al archivo .xyz, el nombre de archivo.xyz
//Escribe en el archivo xyz las bajas de .dat
void paseBajasXYZ(FILE * fb, char nomf[], FILE * fbz, char nombz[]);

//Elimina las bajas logicas, remplazando por ceros los campos
//Recibe el puntero al archivo .dat y el nombre del mismo
void bajaFisica(FILE * fb, char nomf[]);



#endif // COMPETIDOR_H_INCLUDED
