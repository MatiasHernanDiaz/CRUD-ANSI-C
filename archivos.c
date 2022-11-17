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

//EN ESTA LIBRERIA ESTAN TODAS LAS FUNCIONES QUE ESTAN RELACIONADAS A LA CREACION DE ARCHIVOS, MANEJO DE DATOS SOBRE LOS MISMO
//Y LA CREACION DE CARPETAS

void leerArchivo(FILE * f, char nomf[]){

    //lee linea por linea el archivo y lo imprime por pantalla
    //tal como esta.
    //FILE * f ---> puntero al archivo
    //nomf     ---> nombre del archivo.

    char linea[2000];
    f = fopen(nomf,"r");
    if(f != NULL){
        fgets(linea, 200, f);
        while(!feof(f)){
         printf("%s", linea);
         fgets(linea, 200, f);
        }
        fclose(f);
        }
    else {
            printf("Error en la apertura del archivo!");
    }
}

void escribirArchivo(FILE * f, char nomf[], char cadena[]){

    char aux[30];

    f = fopen(nomf, "a");

    if(f !=NULL){
        strncpy(aux,cadena+25,14);
        fprintf(f,"%s\n", aux);
        fclose(f);
    }
    else{ printf("Error en la apertura del archivo!");}
}



void extraerDatos(char *linea, int *o, long *c, int *d, char *m, int *a, int *e, char *p, float *t){

    //Separa la linea por el delimitador ";" guarda los datos en sus respectivas variables aux (char)
    //y los convierte al tipo correspondiente
    //*linea *puntero a la linea hasta el \n
    //*o puntero a variable orden
    //*c puntero a variable corredor
    //*d puntero a variable dia
    //*m puntero a variable mes
    //*a puntero a variable anio
    //*e puntero a variable edad
    //*p puntero a variable pais
    //*t puntero a variable tiempo

    char *orden, *corredor, *dia, *mes, *anio, *edad, *pais, *tiempo, *token;
    token = strtok(linea,";");
    orden = (token);
    *o = atoi(orden);
    corredor = strtok(NULL,";");
    *c = atol(corredor);
    dia = strtok(NULL,";");
    *d=atoi(dia);
    mes = strtok(NULL,";");
    strcpy(m,mes);
    anio = strtok(NULL,";");
    *a = atoi(anio);
    edad = strtok(NULL,";");
    *e = atoi(edad);
    pais = strtok(NULL,";");
    strcpy(p,pais);
    tiempo = strtok(NULL,";");
    *t = atof(tiempo);
}



void extraerDatosCSV(FILE *f){

    //recorre todas las lineas del archivo csv aplicando la funcion extraerDatos
    //separando los datos y convirtiendolos a los tipos correspondientes
    //Recibe un puntero al archivo
    //linea hasta el \n
    //o variable orden
    //c variable corredor
    //d variable dia
    //m variable mes
    //a variable anio
    //e variable edad
    //p variable pais
    //t variable tiempo

    f = fopen("datos_csv\\corredores_v1.csv","r");

    char linea[2000], m[4], p[4];
    int o, d, a, e;
    float t;
    long c;

    if(f!=NULL){
        fgets(linea,2000,f);
        printf("%6s %6s %3s %3s %3s %3s %3s   %s\n", "Orden", "Corredor", "Dia", "Mes", "Anio", "Edad", "Pais", "Tiempo");
        while(!feof(f)){
            extraerDatos(linea, &o, &c, &d, m, &a, &e, p, &t);
            printf("%6d %8ld %3d %s %3d %3d %4s  %3.3f\n", o, c, d, m, a, e, p, t); //HASTA ACA, EN VEZ DE IMPRIMERLO QUE LO GUARDE EN EL BINARIO
            fgets(linea,2000,f);
            }
        fclose(f);
    }
    else{
        printf("Error en la extracci%cn de datos\n", 162);
    }
}



void crearCarpeta(char nomc[]){

    //Crea una carpeta donde se guardaran los archivos binarios
    //Recibe un nombre para la carpeta

    mkdir(nomc);
    printf("**Carpeta creada exitosamente**\n");
}



void crearArchivoB(char nomb[]){

    //Crea un archivo binario de nombre competidores.dat en la carpeta archivoB

    FILE * fb;

    fb = fopen(nomb,"wb");

    if(fb != NULL){
        printf("**Archivo creado exitosamente**\n");
        fclose(fb);
    }
    else{
        printf("**Error en la creaci%cn del archivo**\n",162);
    }
}

void crearArchivo(char nomb[]){

    //Crea un archivo binario de nombre competidores.dat en la carpeta archivoB

    FILE * fb;

    fb = fopen(nomb,"w");

    if(fb != NULL){
        printf("**Archivo creado exitosamente**\n");
        fclose(fb);
    }
    else{
        printf("**Error en la creaci%cn del archivo**\n",162);
    }
}





