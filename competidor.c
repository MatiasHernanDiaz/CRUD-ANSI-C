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

//EN ESTA LIBRERIA SE ENCUENTRAN LAS FUNCIONES QUE TIENEN QUE VER CON LOS CORREDORES
//FUNCIONES DE IMPRESION MODIFICACION Y PETICION DE DATO DEL CORREDOR
//ASI COMO TAMBIEN FUNCIONES QUE TIENEN QUE GRABAR ESOS DATOS SOBRE LOS ARCHIVOS.


struct CorredorEstructura{
    int orden;
    long nCorredor;
    int dia;
    char mes[4];
    int anio;
    int edad;
    char pais[57];
    float tiempo;
    int activo;
};



Corredor crearCorredorTeclado(FILE * fb, char nomb[], int * o){

    //Constructor del corredor por teclado
    //Usa internamenta la funcion crearCorredor
    //Retorna un puntero a la estructura corredor
    //En esta misma funcion se hace llamado a las distintas validaciones

    int e, d, a;
    int minA;
    long n;
    float t;
    int flag, flag2, flag3, flag4, flag5, flag6, flag7;
    char p[57];
    char auxp[]="xxx";
    char auxm[]="xxx";

    fflush(stdin);
    printf("Ingrese corredor: ");
    do{
        flag7 = 0;
        fflush(stdin);
        if(scanf("%ld", &n) == 1){
        flag7 = 1;
        }
        else{
            printf("**Error, intente nuevamente**\n");
        }
    }while(flag7 == 0);
    do{
        do{
            do{
                printf("Ingrese el d%ca (NUMERO): ",161);
                do{
                    flag5 = 0;
                    fflush(stdin);
                    if(scanf("%d", &d) == 1){
                        flag5 = 1;
                    }
                    else{
                    printf("**Error, intente nuevamente**\n");
                    }
                }while(flag5 == 0);

            if((d > 31) || (isdigit(d))) printf("Error en el ingreso de d%ca.\nIngrese un NUMERO menor que 31.\n",161);

            }while(d > 31);

            flag2 = meses(auxm,d);              //la funcion valido mes y dia

        }while((flag2 == 0) && (atoi(auxm) == 0));
        printf("Ingrese el a%co (NUMERO): ",164);
        do{
            flag6 = 0;
            fflush(stdin);
            if(scanf("%d",&a) == 1){
                flag6 = 1;
            }
            else{
            printf("**Error, intente nuevamente**\n");
            }
        }while(flag6 == 0);

        minA = minAnio(fb,nomb);

        if(a < minA) printf("Ingreso un a%co incorrecto, el a%co debe ser mayor que %d\n", 164, 164, minA);

        flag = validarFecha(d, auxm, a);

    }while((a < minA) || (flag == 0));

    printf("Ingrese edad (NUMERO): ");

    do{
        flag4 = 0;
        fflush(stdin);
        if(scanf("%d", &e)==1){
            flag4 = 1;
        }
        else{
            printf("**Error, intente nuevamente**\n");
        }
    }while(flag4 == 0);
    printf("Ingrese pa%cs: ",161);
    fflush(stdin);
    gets(p);
    mayusCadena(p);
    cortar3C(auxp,p);
    printf("Ingrese tiempo (NUMERO): ");

    do{
        flag3 = 0;
        fflush(stdin);
        if(scanf("%f", &t)== 1){
            flag3 = 1;
        }
        else{
            printf("**Error, intente nuevamente**\n");
        }
    }while(flag3 == 0);

    return crearCorredor(*o, n, d, auxm, a, e, auxp, t);

}

Corredor crearCorredor(int o, long n, int d, char m[11], int a, int e, char p[57], float t){

    //Constructor del corredor por parametros
    //Recibe un o = orden, n = corredor, e =edad, p =pais, t = tiempo
    //Retorna un puntero a la estructura corredor

    Corredor c = malloc(sizeof(struct CorredorEstructura));

    c->orden = o;
    c->nCorredor = n;
    c->dia = d;
    strcpy(c->mes,m);
    c->anio = a;
    c->edad = e;
    strcpy(c->pais,p);
    c->tiempo = t;
    c->activo = 1; //por defecto si lo creo esta activo;

    return c;
}

void mostrarCorredor(Corredor c){

    //Imprime una estructura corredor y una estructura fecha
    //Recibe una estructura corredor y una estructura fecha

    printf("|%6d |%8ld  |%3d |%s |%3d |%3d  |%4s   |%3.3f |\n", c->orden, c->nCorredor, c->dia, c->mes, c->anio, c->edad, c->pais, c->tiempo);
    printf("+-------+----------+----+----+-----+-----+-------+--------+\n");
}


void eliminarCorredor(Corredor c){

    //Destructor Corredor
    //Libera la memoria
    //Recibe un puntero a la estructura EstructuraCorredor

    free(c);
}

void migrar(FILE *f, FILE *fb, char nomb[]){

    //recorre todas las lineas del archivo csv aplicando la funcion extraerDatos
    //separando los datos y convirtiendolos a los tipos correspondientes
    //Recibe un puntero al archivo y el nombre del archivo binario
    //linea hasta el \n
    //o variable orden
    //n variable corredor
    //d variable dia
    //m variable mes
    //a variable anio
    //e variable edad
    //p variable pais
    //t variable tiempo

    f = fopen("datos_csv\\corredores_v1.csv","r");

    fb = fopen(nomb,"rb+");

    char linea[2000], m[4], p[4];
    int o, d, a, e;
    float t;
    long n;
    Corredor aux;

    fseek(fb, 0*sizeof(struct CorredorEstructura), SEEK_SET);

    if(f!=NULL){
        fgets(linea,2000,f);

        while(!feof(f)){

            extraerDatos(linea, &o, &n, &d, m, &a, &e, p, &t);

            aux = crearCorredor(o, n, d, m, a, e, p, t); //Creo corredor

            fwrite(aux, sizeof(struct CorredorEstructura), 1, fb);

            fgets(linea,2000,f);

            }

        eliminarCorredor(aux);           //vacio de memoria

        fclose(f);

        fclose(fb);

        printf("**Datos migrados correctamente en %s **\n", nomb);
    }
    else{
        printf("Error en la extracci%cn de datos\n", 162);
    }
}



void leerCSVB(FILE * fb, char nomf[], int act, char pa[], float ran_inf, float ran_sup){

    //Lee un archivo binario y lo muestra por pantalla. Posee los siguientes variables a modo de filtros
    // act = 0 -> muestra los inactivos
    // act = 1 -> muestra activos
    // act = 2 -> muestra todo
    // act = 3 -> desactivado
    // pa[] = "" -> desactivado
    // pa[] = "nombre de pais" -> muestra los paises con esos nombres
    // ran_inf = 0 -> desactivado si esta activado establece el valor inferior
    // ran_sup = 999 -> desactivado si esta activado establece el rango superior..


    fb = fopen(nomf,"rb");

    if(fb != NULL){

        campos();

        Corredor aux = malloc(sizeof(struct CorredorEstructura));

        //aca modifique Struct CorredorEstructura * aux

        aux = vacioCorredor();

        fread(aux, sizeof(struct CorredorEstructura), 1, fb);

        while (!feof(fb)){

            //muestra por actividad

            switch(act){
                case 0:
                    if((aux->activo == 0) && (aux->orden != 0)) mostrarCorredor(aux);
                    break;
                case 1:
                    if(aux->activo == 1) mostrarCorredor(aux);
                    break;
                case 2:
                    mostrarCorredor(aux);
                    break;
                case 3:
                    break;
            }

            // Muestra por pais

            if(strcmp(pa," ") != 0){
               if((strcmp(aux->pais,pa) == 0) && (aux->activo != 0)) mostrarCorredor(aux);
            }

            //Muestro por rango

            if((ran_inf >= 0) && (ran_sup != 999)){
                if((aux->tiempo >= ran_inf) && (aux->tiempo <= ran_sup) && (aux->activo != 0)) mostrarCorredor(aux);
            }

            fread(aux, sizeof(struct CorredorEstructura), 1, fb);

        }
        fclose(fb);
    }
    else{
        printf("Error en la apertura del archivo binario\n");
    }

}

Corredor vacioCorredor(){
    //Crea un puntero a una estructura Corredor {0,0,...,0}
    Corredor aux = crearCorredor(0, 0, 0, "0", 0, 0, "0", 0);
    aux->activo = 0;

    return aux;
}


void escribirVacioNRegistro(FILE * fb, int n){

    //Se utiliza en la migracion de datos
    //Agrega una cantidad fija de registro cargados con corredor vacio
    //Recibe un puntero al archivo binario y una cantidad de registro a crear

    Corredor aux = vacioCorredor();
    for(int i = 0; i < n; i++){
        fwrite(aux, sizeof(struct CorredorEstructura), 1, fb);
    }
}

void nuevoCorredor(FILE *fb, char nomb[]){

    //Agrega un nuevo corredor en el archivo binario
    //Recibe un puntero al archivo y el nombre del mismo
    //Se hace llamado a funciones de validacion y creacion de struct CorredorEstructura

    int o;
    int flag = 0;
    char yesno;

    fb = fopen(nomb, "rb+");

    Corredor nuevo = vacioCorredor();

    do{

        o = valirdarOrden();

        fflush(stdin);

        fseek(fb, (o - 1) * sizeof(struct CorredorEstructura), SEEK_SET);

        fread(nuevo, sizeof(struct CorredorEstructura), 1, fb);


        if (nuevo->orden != 0){
            printf("El n%cmero de orden ya existe.\n",163);
            printf("Intentelo nuevamente\n");
            system("pause");
        }
        else{

            flag = 1;

            nuevo = crearCorredorTeclado(fb, nomb, &o);

            printf("Desea agregar el acorredor?. [Y/N]\n");
            printf("+-------+----------+----+----+-----+-----+-------+--------+\n");
            mostrarCorredor(nuevo);
            do{
                fflush(stdin);
                scanf("%c",&yesno);
                mayusCaracter(&yesno);
                switch(yesno){
                    case 'Y':
                        fseek(fb, (o - 1) * sizeof(struct CorredorEstructura), SEEK_SET);
                        fwrite(nuevo, sizeof( struct CorredorEstructura), 1, fb);
                        printf("**Corredor grabado correctamente**\n");
                        fclose(fb);
                        break;
                    case 'N':
                        break;
                    default:
                        printf("Opci%cn incorrecta. Desea agregar al corredor? [Y/N]\n",162);
                    }
                }while((yesno != 'N') && (yesno != 'Y'));
        }
    }while(flag == 0);

}

int minAnio(FILE * fb, char nomb[]){
    //Busca el minimo anio entre todo los corredores
    //para poder setearlo de base en la validacion
    //Recibe un puntero al archivo binario y un nombre
    //Devuelve el min anio

    int min = 9999;

    Corredor aux = vacioCorredor();

    fb = fopen(nomb,"rb");

    fread(aux, sizeof(struct CorredorEstructura), 1, fb);

    while(!feof(fb)){

        if((aux->anio < min) && (aux->anio != 0)) min = aux->anio;

        fread(aux, sizeof(struct CorredorEstructura), 1, fb);
    }

    eliminarCorredor(aux);

    return min;
}



Corredor buscar(FILE * fb, char nomb[], int xO, int xC, int buscado, long * linea){

    //Buscar binaria del corredor
    //Recibe puntero archivo, nombre de archivo, N# corredor buscado,
    //y un puntero a una variable que almacena la linea del corredor encontrado
    //xO = 1 y xC = 0 --> por orde
    //xO = 0 y xC = 1 --> por corredor
    //retorna un puntero a un struct corredorEstructura si no encuentra corredor

    Corredor aux;

    fb = fopen(nomb,"rb");

    if(fb != NULL){

        aux = malloc(sizeof(struct CorredorEstructura));

        aux = vacioCorredor();

        fread(aux, sizeof(struct CorredorEstructura), 1, fb);

        if(xO != 0){
            if(aux->orden == buscado){
                *linea = ftell(fb) / sizeof(struct CorredorEstructura);
                return aux;
            }
        }
        else{
            if(aux->nCorredor == buscado){
                *linea = ftell(fb) / sizeof(struct CorredorEstructura);
                return aux;
            }
        }

        while (!feof(fb)){

            fread(aux, sizeof(struct CorredorEstructura), 1, fb);

            if(xO != 0){
                if(aux->orden == buscado){
                    *linea = ftell(fb) / sizeof(struct CorredorEstructura);
                    return aux;
                }
            }
            else{
                if(aux->nCorredor == buscado){
                    *linea = ftell(fb) / sizeof(struct CorredorEstructura);
                    return aux;
                    }
                }
            }
        fclose(fb);
    }

    else{
        system("cls");
        printf("Error en la apertura del archivo binario\n");
        system("pause");
        system("cls");
    }

    return aux;
}


void modificar(Corredor c, int op){

    //modifica edad o tiempo del puntero de la estructura corredorEstructura
    //Recibe a un puntero a corredorEstructura y un entero para seleccionar la opcion la opcion

    int e, flag, flag2;
    float t;

    switch(op){
        case 1:
            printf("Ingrese la nueva edad: ");
            do{
                flag = 0;
                fflush(stdin);
                if(scanf("%d",&e) == 1){
                    flag = 1;
                }
                else{
                    printf("**Error en el ingreso de datos, intente nuevamente**...");
                }
            }while(flag == 0);
            c->edad = e;
            break;
        case 2:
            printf("Ingrese el nuevo tiempo: ");
            do{
                flag2 = 0;
                fflush(stdin);
                if(scanf("%f",&t) == 1){
                    flag2 = 1;
                }
                else{
                    printf("**Error en el ingreso de datos, intente nuevamente**...");
                }
            }while(flag2 == 0);
            c->tiempo = t;
            break;
        case 0:
            break;
        default:
            printf("Elija una de las opciones...");
    }
}

void escribirModificacion(FILE * fb, char nomb[], Corredor aux){

    //Escribe en un archivo binario un corredor.
    //Utiliza la funcion busqueda y mediante la variable fila (ubicacion del corredor a modificar)
    //Graba el modificado en el archivo.
    //Recibe un puntero al archivo, el nombre de archivo y el corredor a grabar

    long fila;

    buscar(fb, nomb, 1, 0, aux->orden, &fila);

    FILE * ff = fopen(nomb, "r+b");

    fseek(ff, (fila-1) * sizeof(struct CorredorEstructura), SEEK_CUR);
    fwrite(aux, sizeof(struct CorredorEstructura), 1, ff);
    fflush(ff);
    fclose(ff);

}

void bajaLogica(Corredor c){

    //Cambia el campo activo 1 a 0 para darlo den baja
    //Recibe un puntero a la struct corredor

    c->activo = 0;
}


void paseBajasXYZ(FILE * fb, char nomf[], FILE * fbz, char nombz[]){
    //Realiza el pase de las bajas logicas del archivo .dat al archivo .xyz
    //Recibe el puntero al archivo .dat, el nombre de archivo.dat
    //Recibe el puntero al archivo .xyz, el nombre de archivo.xyz
    //Escribe en el archivo xyz las bajas de .dat

    int cont = 0;           //controla la cantidad de archivos crados

    fb = fopen(nomf,"rb");

    if(fb != NULL){

        Corredor aux = malloc(sizeof(struct CorredorEstructura));

        aux = vacioCorredor();

        fread(aux, sizeof(struct CorredorEstructura), 1, fb);

        while (!feof(fb)){

            //muestra por actividad y orden

            if((aux->activo == 0)&&(aux->orden != 0)){

                cont += 1;

                if(cont == 1){
                    fbz = fopen(nombz,"r+b");   //si el archivo existe
                    if(fbz == NULL){
                        crearArchivoB(nombz);   //si el archivo no existe lo creo
                        fbz = fopen(nombz,"a+b");
                    }
                    fclose(fbz);
                    fbz = fopen(nombz, "a+b");
                }

                fwrite(aux, sizeof(struct CorredorEstructura), 1, fbz);
                fflush(fbz);
                fclose(fbz);
            }

            fread(aux, sizeof(struct CorredorEstructura), 1, fb);
        }

        if(cont == 0){
            printf("**No hay ningun corredor apto para baja f%csica**\n",161);
        }
        else{
            printf("**Baja f%csica realizada**\n",161);
        }

        fclose(fb);
        eliminarCorredor(aux);
    }
    else{
        printf("Error en la apertura del archivo binario\n");
    }

}

void bajaFisica(FILE * fb, char nomf[]){

    //Elimina las bajas logicas, remplazando por ceros los campos
    //Recibe el puntero al archivo .dat y el nombre del mismo

    fb = fopen(nomf,"r+b");

    if(fb != NULL){

        Corredor aux = malloc(sizeof(struct CorredorEstructura));

        aux = vacioCorredor();

        fread(aux, sizeof(struct CorredorEstructura), 1, fb);

        while (!feof(fb)){


            if((aux->activo == 0)&&(aux->orden != 0)){

                aux = vacioCorredor();

                fseek(fb, -1 * sizeof(struct CorredorEstructura), SEEK_CUR); //vuelvo para atras de la pos actual

                fwrite(aux, sizeof(struct CorredorEstructura), 1, fb); //sobre escribo con vacioCorredor la pos del corredor

                fflush(fb);

            }

            fread(aux, sizeof(struct CorredorEstructura), 1, fb);
        }
        fclose(fb);
        eliminarCorredor(aux);

    }
    else{
        printf("Error en la apertura del archivo binario\n");
    }

}


