#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <ctype.h>
#include <time.h>
#include "archivos.h"
#include "competidor.h"
#include "intefaz.h"
#include "validacion.h"


//EN ESTA LIBRERIA ESTAN LAS FUNCIONES RELACIONADAS CON LOS MENUS, LOS CAMPOS Y DEMAS.

void menu(int * op){

    //Menu principal con las opciones para el usuario
    //recibe una direccion a la opcion elegida. do{

    printf("\n\t\t\t\t\t\t MENU PRINCIPAL\n\n");
    printf("\t\t\t\t\t\tElija una opci%cn\n\n",162);
    printf("\t\t\t\t\t1  - Listar archivo.csv\n");
    printf("\t\t\t\t\t2  - Crear archivo binario (.dat)\n");
    printf("\t\t\t\t\t3  - Migrar datos de .csv a .dat\n");
    printf("\t\t\t\t\t4  - Listar archivo .dat\n");
    printf("\t\t\t\t\t5  - Dar de alta a un corredor nuevo\n");
    printf("\t\t\t\t\t6  - Buscar a un corredor\n");
    printf("\t\t\t\t\t7  - Modificar corredor\n");
    printf("\t\t\t\t\t8  - Baja l%cgica de corredor por sistema\n",162);
    printf("\t\t\t\t\t9  - Baja f%csica de corredor\n",161);
    printf("\t\t\t\t\t10 - Listar bajas\n");
    printf("\t\t\t\t\t0  - Salir\n");
    fflush(stdin);
    scanf("%d",op);
}


void menu2(int * op2){

    //Menu de muestra de datos binarios
    //Recibe una direccion de opcion

    printf("MENU - MUESTRAS DE DATOS\n");
    printf("1 - Mostrar todo el archivo binario .dat\n");
    printf("2 - Mostrar corredores activos\n");
    printf("3 - Mostrar corredores inactivos\n");
    printf("4 - Mostrar por pa%cs\n",161);
    printf("5 - Mostrar por rango de tiempo\n");
    printf("0 - Salir al men%c principal\n",163);
    fflush(stdin);
    scanf("%d",op2);
}

void menuBusqueda(int * op3){

    //Menu de busqueda de datos de corredor
    //Recibe una direccion de la opcion

    printf("MENU - MUESTRAS DE BUSQUEDA\n");
    printf("Se busca a un corredor en un archivo binario .dat\n");
    printf("1 - Buscar por n%cmero de orden\n",162);
    printf("2 - Buscar por n%cmero de corredor\n",162);
    printf("0 - Salir a Men%c principal\n",163);
    fflush(stdin);
    scanf("%d",op3);
}

void menuModificar(int * op3){

    //Menu de modificacion para la busqueda de datos
    //Recibe la direccion del numero de opcion

    printf("MENU - MODIFICACION\n");
    printf("Busqueda del corredor para su modificaci%cn\n",162);
    printf("1 - Buscar por n%cmero de orden\n",163);
    printf("2 - Buscar por n%cmero de corredor\n",163);
    printf("0 - Salir al Men%c principal\n", 163);

    fflush(stdin);
    scanf("%d",op3);

}

void menuModificar2(int * op4){

    //Menu de modificacion de datos
    //Recibe la direccion del numero de opcion

    printf("Que datos desea modificar?\n");
    printf("1 - Edad\n");
    printf("2 - Tiempo\n");
    fflush(stdin);
    scanf("%d",op4);
}

void menuBajaLogica(int * op5){

    //Menu de baja logica
    //Recibe la direccion del numero de opcion

    printf("MENU - BAJA LOGICA\n");
    printf("Se busca a un corredor para su baja logica\n");
    printf("1 - Buscar por n%cmero de orden\n",163);
    printf("2 - Buscar por n%cmero de corredor\n",163);
    printf("0 - Salir a Men%c principal\n",163);
    fflush(stdin);
    scanf("%d",op5);

}

void menuLeerBajas(int * op6){

    //Menu de muestra de baja
    //Recibe una direccion del numero de opcion

    printf("MENU - MUESTRA DE BAJAS\n");
    printf("1 - Muestra las todas las fechas de bajas\n");
    printf("2 - Ingresar una fecha para ver bajas\n");
    printf("0 - Salir al Men%c principal\n",163);
    fflush(stdin);
    scanf("%d", op6);
}


void campos(){

    //Imprecion de los titulos de campos

    printf("-----------------------------------------------------------\n");
    printf("|%6s | %6s |%3s |%3s |%3s |%3s |%3s   |%s  |\n", "Orden", "Corredor", "Dia", "Mes", "Anio", "Edad", "Pais", "Tiempo");
    printf("+-------+----------+----+----+-----+-----+-------+--------+\n");
}

void msj1(){

    //Emite mensaje de opcion

    system("cls");
    printf("CREACION DE ARCHIVO BINARIO\n");
    printf("Se creara un archivo binario de nombre 'competidores.dat' en la carpeta 'BINARIOS' \n");
    printf("Desea continuar? [Y/N] \n");
}
void msj2(){

    //Emite mensaje de opcion

    system("cls");
    printf("MIGRAR DATOS\n");
    printf("Se procede a la migraci%cn de datos\nESTADO DE PROCEDIMIENTO: ",162);
}

void password(int * pass){

    //Pide pass de admin
    //Recibe una variable por direccion

    printf("FUNCION DEL ADMINISTRADOR\nINGRESE PASSWORD: ");
    scanf("%d", pass);
}

void apertura(){
    printf("\n*********************************************************************************************************************\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t\t  TRABAJO FINAL\t\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t  Laboratorio de computaci%cn II\t\t\t\t\t\t    *\n",162);
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t     2do cuatrimestre 2022\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t\t    C.R.U.D   \t\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t     Registro de corredores\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t    *\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\tD%caz, Mat%cas Hern%cn *\n",161,161,160);
    printf("*********************************************************************************************************************\n");
    getchar();
    system("cls");
}

void fin(){
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tFIN\n\n");
    printf("\t\t\t\t\t\tDiaz Matias Hernan\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    system("pause");
}
