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

// EN ESTA LIBRERIA ESTAN LAS FUNCIONES DE VALIDACION O TODAS AQUELLAS QUE AYUDEN A VALIDAR
// ASI COMO TAMBIEN FUNCIONES AUXILIARES DE CADENAS Y FECHA

void mayusCaracter(char *c){

    //Mayusculizador de caracter
    //Recibe un caracter

    *c = toupper(*c);
}


void mayusCadena(char s[]){

    //Mayusculiza una cadena
    //Recibe una cadena

    for(int i = 0; i < strlen(s); i++){
        s[i] = toupper(s[i]);
    }
}


void miniCadena(char m[]){

    //Miimiza los carecteres de una cadena
    //Recibe una cadena

    for(int i = 0; i < strlen(m); i++){
        m[i] = tolower(m[i]);
    }
}

void cortar3C(char aux[], char s[]){

    //Roma una cadena y la corta dejando los
    //3 primeros caracteres  ej: argentina -> arg

    strncpy(aux,s,3);
}


int meses(char aux[], int d){

    //Verifica que el mes ingresado sea el correcto
    //Pide el al usuario los datos del mes como cadena
    //Solo va tener encuenta los 3 primeros caracteres.
    //Si el usuario ingresa EnErito -> sale ene y lo reconoce como enero.
    //Se pide un mes y dia. El mes se lo minimiza y se lo corta al tercer caracter
    //y se lo guarda en un aux que recibe por parametro.
    //Se verifica que el dia concuerde con el mes
    //Retorna una 0 si falla la validacion y un 1 si es correcta.

    char m[11];
    char * mes[]={"ene","feb","mar","abr","may","jun","jul","ago","sep","oct","nov","dic"};
    char * mes30[]={"abr","jun","sep","nov"};
    int digito;
    int flag = 0;
    int flag2 = 1;  //validacion de dias respecto del mes.
    int flag3 = 0;  //Validacion de texto o numero para le mes

    printf("Ingrese le mes: ");
    fflush(stdin);
    gets(m);

    //verificar si es realmente una cadena, si es un numero entra al switch
    flag3 = hayNumeros(m);

    if(flag3 == 0){

        //ingreso una cadena

        miniCadena(m);
        cortar3C(aux,m);
    }
    else{
        //INGRESO UN NUMERO

        digito = (int) strtol(m, NULL, 10); // de string a int

        switch(digito){
            case 1:
                strcpy(aux,"ene");
                break;
            case 2:
                strcpy(aux,"feb");
                break;
            case 3:
                strcpy(aux,"mar");
                break;
            case 4:
                strcpy(aux,"abr");
                break;
            case 5:
                strcpy(aux,"may");
                break;
            case 6:
                strcpy(aux,"jun");
                break;
            case 7:
                strcpy(aux,"jul");
                break;
            case 8:
                strcpy(aux,"ago");
                break;
            case 9:
                strcpy(aux,"sep");
                break;
            case 10:
                strcpy(aux,"oct");
                break;
            case 11:
                strcpy(aux,"nov");
                break;
            case 12:
                strcpy(aux,"dic");
                break;
            default:
                printf("Mes no encontrado**\n");
            }
            while(flag == 0){
            for(int i = 0; i < 12; i++){
                if(strcmp(aux,mes[i]) == 0){
                    flag = 1;
                }
            }
            if(flag == 0){
                printf("**Error al ingresar el mes, intentelo nuevamente (CADENA)**\n");
                printf("Ingrese le mes: ");
                fflush(stdin);
                gets(m);
                miniCadena(m);
                cortar3C(aux,m);
            }
        }

        if(d == 31){
            for(int i = 0; i < 7; i++){
                if(strcmp(aux,mes30[i]) == 0){
                    flag2 = 0;
                    printf("**El numero de dias excede a los del mes.**\n**Intentelo nuevamente (CADENA).**\n");
                }
            }
        }
        else if(d >= 29){
            if(strcmp(aux,"feb") == 0){
                flag2 = 0;
                printf("**El numero de dias excede a los del mes.**\n**Intentelo nuevamente (CADENA).**\n");
            }
        }
        else{
            flag2 = 1;
        }
    }

    return flag2;
}


int valirdarOrden(){

    //Comprueba que el orden se encuentre dentro del rango permitido de 0 -100
    //de lo contrario vuelve a pedirlo

    int o;

    printf("Ingrese numero de orden del corredor: ");
    fflush(stdin);
    scanf("%d",&o);

    while((o < 0) || (o > 100)){
        printf("Error en el ingreso de numero de orden\nDebe ser mayor que cero y menor que cien (0 - 100).\n");
        fflush(stdin);
        scanf("%d",&o);
    }

    return o;
}

int validarFecha(int d, char mes[], int anio){

    //Se asegura que la fecha ingresada no supere a la actual
    //Recibe en d = dia, mes en caracter y anio con numeros

    int i, flag = 0;
    char * meses[]={"ene","feb","mar","abr","may","jun","jul","ago","sep","oct","nov","dic"};
    time_t t = time(NULL);
    struct tm tiempoLocal = *localtime(&t);



    if(anio == (tiempoLocal.tm_year + 1900)){
            for(i = 0; i < 12; i++){
                if(strcmp(mes,meses[i]) == 0){
                    if(i == (tiempoLocal.tm_mon)){
                        if(d > tiempoLocal.tm_mday){
                            printf("La fecha no puede superar a la actual %d/%d/%d\n",tiempoLocal.tm_mday,tiempoLocal.tm_mon+1,tiempoLocal.tm_year+1900);
                        }
                        else{
                            flag = 1;
                        }
                    }
                    else{
                        flag = 1;
                    }
                }
            }
    }
    if(anio < (tiempoLocal.tm_year + 1900)){
        flag = 1;
    }
    if(anio > (tiempoLocal.tm_year + 1900)){
        printf("La fecha no puede superar a la actual %d/%d/%d\n",tiempoLocal.tm_mday,tiempoLocal.tm_mon+1,tiempoLocal.tm_year+1900);
    }



    return flag;
}

void cadenaFecha(char c[]){

    //Concatena a en c la fecha y hora actual + el formato .xyz
    //Recibe una cadena c

    time_t t = time(NULL);
    struct tm tiempoLocal = *localtime(&t);
    char fechaHora[70];
    char *formato = "%Y_%m_%d.xyz";

    int bytesEscritos = strftime(fechaHora, sizeof fechaHora, formato, &tiempoLocal);

    if (bytesEscritos != 0) {
        strcat(c,fechaHora);

    }
    else {
        printf("Error formateando fecha");
    }

}

void ingresoFecha(char auxf[]){

    //Pide la fecha y la valida
    //recibe una cadena donde guarda la fecha

    int d, a;
    int flag;
    int flag2;
    char auxm[]="xxx";
    char cd[3];
    char cd2[3];    // Se necesita agregar el cero porque itoa lo saca 0
    char cm[3];
    char ca[5];


      do{
          do{
              do{
                printf("Ingrese el d%ca (NUMERO): ",161);
                fflush(stdin);
                scanf("%d", &d);
                if((d > 31) || (isdigit(d))) printf("Error en el ingreso de d%ca.\nIngrese un NUMERO menor que 31.\n",161);
                }while(d > 31);
                flag2 = meses(auxm, d);              //valido mes y dia
            }while((flag2 == 0) && (atoi(auxm) == 0));
            printf("Ingrese el a%co (NUMERO): ",164);
            fflush(stdin);
            scanf("%d",&a);
            flag = validarFecha(d, auxm, a);
        }while(flag == 0);

        if(strcmp(auxm,"ene") == 0){
            strcpy(cm,"1");
        }
        if(strcmp(auxm,"feb") == 0){
            strcpy(cm,"2");
        }
        if(strcmp(auxm,"mar") == 0){
            strcpy(cm,"3");
        }
        if(strcmp(auxm,"abr") == 0){
            strcpy(cm,"4");
        }
        if(strcmp(auxm,"may") == 0){
            strcpy(cm,"5");
        }
        if(strcmp(auxm,"jun") == 0){
            strcpy(cm,"6");
        }
        if(strcmp(auxm,"jul") == 0){
            strcpy(cm,"7");
        }
        if(strcmp(auxm,"ago") == 0){
            strcpy(cm,"8");
        }
        if(strcmp(auxm,"sep") == 0){
            strcpy(cm,"9");
        }
        if(strcmp(auxm,"oct") == 0){
            strcpy(cm,"10");
        }
        if(strcmp(auxm,"nov") == 0){
            strcpy(cm,"11");
        }
        if(strcmp(auxm,"dic") == 0){
            strcpy(cm,"12");
        }

        //strcat(auxf,"_");

        itoa(a, ca, 10);

        strcpy(auxf, ca);

        strcat(auxf,"_");

        strcat(auxf, cm);

        strcat(auxf,"_");

        itoa(d, cd, 10);

        if(strlen(cd) == 1){

            strcpy(cd2,"0");

            strcat(cd2,cd);

            strcat(auxf, cd2);

        }
        else{
            strcat(auxf, cd);
        }

}

void completaNombre(char nombf[], char aux[]){

    //Recibe el nombre generico del archivo y le agrega la fecha y la extesion
    //Recibe nombre de archivo y una cadena aux

    strcat(nombf,aux);
    strcat(nombf,".xyz");
}

void rangoValores(float * inf, float * sup){

    //Peticion del rango de valores para la busqueda
    //Recibe por direccion los valores inferior y superior
    //y los guarda en las respectivas variables

    int flag, flag2;


    do{
        flag = 0;
        flag2 = 0;
        printf("Se establece un rango de tiempo para la muestra\n");
        printf("Rango inferior: ");
        fflush(stdin);

        if(scanf("%f", inf) == 1){
            flag = 1;
        }

        printf("Rango superior: ");
        fflush(stdin);

        if(scanf("%f", sup) == 1){
            flag2 = 1;
        }

        if((flag == 0) || (flag2 == 0)){
            printf("**Valores ingresados incorrecto, vuelva a intentar**...\n");
        }

    }while((flag == 0) || (flag2 == 0));

}

int hayNumeros(char c[]){

    //Comprueba si en la cadena hay numeros
    //Retorna un 1 si lo hay y 0 si no.
    //Recibe una cadena

    int flag = 0;
    for(int i = 0; i < strlen(c); i++){
        if(isdigit(c[i]) != 0){
            flag = 1;
        }
    }
    return flag;
}

int error(int e){


    char *errores[] = {
		"Opcion incorrecta. Desea crear el archivo binario? [Y/N]\n",
		"Ingrese una de las opciones\n",
		"No se encontro corredor...\n",
		"Opcion incorrecta. Desea dar de baja al corredor? [Y/N]\n"
		};

	printf( "Error n%cmero %i: %s.\n", 163, e, errores[e] );

	return -1;

}
