# CRUD-ANSI-C
This is a project for the first year of university.

//Autor: Diaz, Matias Hernan

//LAS CARPETAS:
//El programa esta contenido en una carpeta proyecto de nombre TP_FINAL
//Dentro de la misma contendra una carpeta de nombre "datos_csv" con los datos de los corredores provistos
//Tambien se cuentra una carpeta de nombre "consigna_datos" donde se encuentra la consigana a seguir
//Como parte del proyecto tambien se cuentran sub carpetas de nombre "obj" y "bin" desprovistas de cualquier archivo.o ni .exe
//A su vez el programa creara varias carpetas y archivos;
//Una carpeta de nombre "BINARIO" que contendra un archivo binario de nombre "competidores.dat"
//Una carpeta de nombre "BAJAS" que contrendra varios archivos binarios de nombre "competidores_bajas_<fecha>.xyz"
//Tambien se creara un archivo de texto de nombre fecha.dat el cual contendra cadenas de texto con la fechas de las bajas.

//LIBRERIAS
//Dentro de la carpeta TP_FINAL_Diaz_Matias_Hernan tambien se cuentran 4 (cuatro) archivos .h con sus respectivos .c
//archivos.h   -> Todo lo relacionado a creacion de archivo y lectura de los .txt
//competidor.h -> Todo lo relacionado al corredor. Formas de imprimir, modificar, grabar datos etc
//interfaz.h   -> Menus y plantillas
//validacion.h -> Las funciones de validacion pertinentes a cada caso.

//EL PROGRAMA:
//El archivo fuente se llama main.c
//El programa pretende ser lo mas intuitivo posible.
//Consta de un menu principal donde tiene varias opciones las cuales se eligiran por NUMERO, de no ser asi pedira que reintente
//Cada opcion del menu lleva a sub menues los cuales tienen la misma dinamica de eleccion. En todos los casos se sale con 0 (CERO)
//Cualquier ingreso de datos invalido el programa reintentara la operacion. Accion que no pueda realizar notificara al usuario
//Asi como tambien notifica de la creacion de carpetas y archivos creados exitosamente como no exitosamente.
//** LA OPCION 1 DEL MENU - MUESTRA DE DATOS - QUE SE CONCIDERO AL FINAL QUE NO DEBERIA SER VISTA POR EL USUARIO,
//A DICHA OPCION SE LA BLOQUEO CON UN SIMPLE PASSWORD: 1234 **
