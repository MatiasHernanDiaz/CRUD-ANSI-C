#ifndef INTEFAZ_H_INCLUDED
#define INTEFAZ_H_INCLUDED

//Menu principal
//Recibe una direccion del numero de opcion
void menu(int * op);

//Menu de muestra de datos binarios
//Recibe una direccion del numero de opcion
void menu2(int * op2);

//Menu de muestra de datos binarios
//Recibe una direccion del numero de opcion
void menuBusqueda(int * op2);

//Menu de modificacion para la busqueda de datos
//Recibe la direccion del numero de opcion
void menuModificar(int * op3);

//Menu de modificacion de datos
//Recibe la direccion del numero de opcion
void menuModificar2(int * op4);

//Menu de baja logica
//Recibe la direccion del numero de opcion
void menuBajaLogica(int * op5);

void menuLeerBajas(int * op6);

//Imprecion de los titulos de campos
void campos();

//Emite mensaje de opcion
void msj1();

//Emite mensaje de opcion
void msj2();

//Pide pass de admin
//Recibe por direccion la variable
void password(int * pass);

//Imprime solo texto a modo de presentacion
void apertura();

//Imprime un mensaje final
void fin();
#endif // INTEFAZ_H_INCLUDED
