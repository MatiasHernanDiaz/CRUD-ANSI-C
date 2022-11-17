
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

int main(){

    struct CorredorEstructura * aux;
    int op, op2, op3, op4, op5, op6;                //Donde se almacenan las opciones de los dif menues
    int buscado;                                    //Usado para pasar lo que se desea buscar en la funcion de busqueda()
    long fila;                                      //Auxiliar de numero de fila
    char nomb[30]="BINARIOS\\competidores.dat";     //Nombre del archivo binario
    char nomc[9]="BINARIOS";                        //Nombre de la carpeta donde se almacenan los binarios
    char nomcz[6]="BAJAS";                          //Nombre de la carpeta donde se almacenaran las bajas fisicas
    char nombz[100]="BAJAS\\competidores_bajas_";   //Nombre del archivo donde se grabaran las bajas
    char nomf[10]="fecha.dat";                      //Nombre archivo donde se guardara la fecha actual para las bajas
    char auxc[20];                                  //Auxiliar de cadena
    char yesno;                                     //Auxiliar de respuesta [Y/N]
    char mPais[57];                                 //Cadena maxima del pais mas largo
    char auxP[4]="0";                               //Inicializacion de variable aux
    float inf, sup;                                 //Variable para rango inferior y superior
    int pass;                                       //pass de administrador
    FILE * f = NULL;                                //puntero a archivo .csv inicializado en NULL
    FILE * fb = NULL;                               //puntero a archivo binario .dat inicializado en NULL
    FILE * fbz = NULL;                              //puntero a archivo binario .xyz inicialzado en NULL
    FILE * ff = NULL;                               //puntero a archivo de fechas

    apertura();

    do{
        menu(&op);
        switch(op){
            case 1:
                    //MUERTRA DE LOS DATOS EN CRUDO DE CSV
                    //EL TIEMPO SE MUESTRA CON 6 DECIMALES
                    system("cls");
                    extraerDatosCSV(f);     //imprime los datos del .csv formateados
                    printf("\n");
                    system("pause");
                    system("cls");
                    break;
            case 2:
                    //CRACION DE LA CARPETA Y ARCHIVO BINARIO
                    msj1();
                    do{
                        fflush(stdin);
                        scanf("%c",&yesno);
                        mayusCaracter(&yesno);
                        switch(yesno){
                            case 'Y':
                                crearCarpeta(nomc);                     //Creo carpeta para el archivo.dat
                                crearCarpeta(nomcz);                    //Creo carpeta de bajas
                                crearArchivo(nomf);                     //Creo archivo para guardar fechas
                                crearArchivoB(nomb);                    //Creo archivo .dat
                                fb = fopen(nomb,"ab");
                                escribirVacioNRegistro(fb,100);         //100 indica la cantidad de registros en blancos se crearan
                                fclose(fb);                             //en el arhivo binario.
                                break;
                            case 'N':
                                break;
                            default:
                                error(0);
                        }
                    }while((yesno != 'N') && (yesno != 'Y'));
                    system("pause");
                    system("cls");
                    break;
            case 3:
                    //MIGRACION DE DATOS
                    //CREAR FUNCION QUE AVISE SI SE MIGRAN MAS DE UNA VEZ LOS DATOS
                    //PARA NO PISARLOS YA MODIFICADOS
                    msj2();
                    migrar(f, fb, nomb);
                    system("pause");
                    system("cls");
                    break;
            case 4:
                    //IMPRESION DE DATOS FILTRADO POR - ACTIVO - INACTIVO - TODOS - PAIS - RANGO TIEMPO
                    //FALTA VALIDAR PAIS
                    system("cls");
                    do{
                        menu2(&op2);
                        switch(op2){
                            case 1:
                                //TODOS ACTIVOS = 1 E INACTIVOS = 0 - FUNCION DE ADMINISTRADOR
                                system("cls");
                                password(&pass);
                                if(pass == 1234){
                                    printf("TODAS LAS CELDAS DEL 1 - 100 (ACTIVOS E INACTIVOS)\n");
                                    leerCSVB(fb,nomb,2," ",0,999);
                                    system("pause");
                                    system("cls");
                                }
                                break;
                            case 2:
                                //SOLO MUESTRA LOS ACTIVOS
                                system("cls");
                                printf("Todos los corredores ACTIVOS\n");
                                leerCSVB(fb,nomb,1," ",0,999);
                                system("pause");
                                system("cls");
                                break;
                            case 3:
                                //MUESTRA CORREDORES INACTIVOS - FUNCION DE ADMINISTRADOR
                                system("cls");
                                printf("Todos los corredores INACTIVOS\n");
                                leerCSVB(fb,nomb,0," ",0,999);
                                system("pause");
                                system("cls");
                                break;
                            case 4:
                                //MUESTRA POR PAIS
                                system("cls");
                                printf("Mostrar por pa%cs\n",161);
                                printf("Ingrese un pa%cs\n",161);
                                fflush(stdin);
                                gets(mPais);
                                mayusCadena(mPais);
                                cortar3C(auxP,mPais);
                                leerCSVB(fb,nomb,3,auxP,0,999);
                                system("pause");
                                system("cls");
                                break;
                            case 5:
                                system("cls");
                                rangoValores(&inf, &sup);           //Peticion de valores sup e inf
                                leerCSVB(fb,nomb,3," ",inf,sup);
                                system("pause");
                                system("cls");
                                break;
                            case 0:
                                system("cls");
                                break;
                            default:
                                error(1);
                        }
                    }while(op2 != 0);
                    break;
            case 5:
                    //CREACION DEL NUEVO CORREDOR - GRABACION DEL MISMO
                    //MODIFICAR FUNCION PARA QUE SEA
                    //CREAR CORREDOR
                    //ESCRIBIRCORREDORMODIFICADO
                    system("cls");
                    printf("ALTA DE CORREDOR\n");
                    nuevoCorredor(fb, nomb); //----> MEJORAR
                    system("pause");
                    system("cls");
                    break;
            case 6:
                    //BUSQUEDA SEGUN ORDEN O NUMERO
                    do{
                        system("cls");
                        menuBusqueda(&op3);
                        switch(op3){
                            case 1:
                                //BUSCA SEGUN EL ORDEN
                                printf("Ingrese n%cmero de orden: ",163);
                                fflush(stdin);
                                scanf("%d",&buscado);
                                aux = buscar(fb,nomb,1,0,buscado, &fila);
                                system("cls");
                                if(aux->orden != 0){
                                    campos();
                                    mostrarCorredor(aux);
                                }
                                else{
                                    error(2);
                                }
                                eliminarCorredor(aux); //ELIMINACION DE AUX EN MEMORIA
                                system("pause");
                                break;
                            case 2:
                                //BUSQUEDA SEGUN EL NUMERO DE CORREDOR
                                printf("Ingrese n%cmero de corredor: ",163);
                                fflush(stdin);
                                scanf("%d",&buscado);
                                aux = buscar(fb,nomb,0,1,buscado, &fila);
                                system("cls");
                                if(aux->orden != 0){
                                    campos();
                                    mostrarCorredor(aux);
                                }
                                else{
                                    error(2);
                                }
                                eliminarCorredor(aux); //ELIMINACION DEL AUX EN MEMORIA
                                system("pause");
                                break;
                            case 0:
                                system("cls");
                                break;
                            default:
                                error(1);
                        }
                    }while(op3 != 0);
                    system("cls");
                    break;
            case 7:
                    //MODIFICACION DE ARCHIVO. -BUSCA -MODIFICA -GRABA
                    do{
                        system("cls");
                        menuModificar(&op3);
                        switch(op3){
                                case 1:
                                    //BUSCA POR EL NUMERO DE ORDEN
                                    printf("Ingrese n%cmero de orden: ",163);
                                    fflush(stdin);
                                    scanf("%d",&buscado);
                                    aux = buscar(fb,nomb,1,0,buscado, &fila);
                                    system("cls");
                                    if(aux->orden != 0){
                                        campos();
                                        mostrarCorredor(aux);
                                    }
                                    else{
                                        error(2);
                                    }
                                    system("pause");
                                    break;
                                case 2:
                                    //BUSCA POR EL NUMERO DE CORREDOR
                                    printf("Ingrese n%cmero de corredor: ",163);
                                    fflush(stdin);
                                    scanf("%d",&buscado);
                                    aux = buscar(fb,nomb,0,1,buscado, &fila);
                                    system("cls");
                                    if(aux->orden != 0){
                                        campos();
                                        mostrarCorredor(aux);
                                    }
                                    else{
                                        error(2);
                                    }
                                    system("pause");
                                    break;
                                case 0:
                                    break;
                                default:
                                    error(1);
                                    system("pause");
                        }
                    }while((op3 != 0) && (op3 != 1) && (op3 !=2));

                    if((aux->orden != 0)&&( op3 != 0)){
                        menuModificar2(&op4);
                        switch(op4){
                            case 1:
                                //edad
                                modificar(aux, op4);
                                campos();
                                mostrarCorredor(aux);
                                printf("Desea modificar al corredor? [Y/N]\n");
                                fflush(stdin);
                                scanf("%c",&yesno);
                                mayusCaracter(&yesno);
                                if(yesno == 'Y'){
                                    escribirModificacion(fb, nomb, aux);
                                    printf("Corredor modificado correctamente!\n");
                                }
                                system("pause");
                                break;
                            case 2:
                                //tiempos
                                modificar(aux, op4);
                                campos();
                                mostrarCorredor(aux);
                                printf("Desea modificar al corredor? [Y/N]\n");
                                fflush(stdin);
                                scanf("%c",&yesno);
                                mayusCaracter(&yesno);
                                if(yesno == 'Y'){
                                    escribirModificacion(fb, nomb, aux);
                                    printf("Corredor modificado correctamente!\n");
                                }
                                system("pause");
                                break;
                            default:
                                error(1);
                                system("pause");
                        }
                    }
                    system("cls");
                    break;
            case 8:
                    //BAJA DE CORREDOR
                    //BUSCA AL CORREDOR, LO IMPRIME, PREGUNTA SI LO DESEA MODIFICAR
                    //MODIFICA Y LO GRABA EN EL ARCHIVO
                    //FINALIZA DESPLEGANDO LA LISTA DE ACTIVOS = 1
                    do{
                        system("cls");
                        menuBajaLogica(&op5);
                        switch(op5){
                            case 1:
                                //BAJA POR NUMERO DE ORDEN
                                printf("Ingrese n%cmero de orden: ",163);
                                fflush(stdin);
                                scanf("%d",&buscado);
                                aux = buscar(fb,nomb,1,0,buscado, &fila);
                                system("cls");
                                if(aux->orden != 0){
                                    campos();
                                    mostrarCorredor(aux);
                                    printf("\nDesea dar de baja a este corredor?[Y/N]\n");
                                    do{
                                        fflush(stdin);
                                        scanf("%c",&yesno);
                                        mayusCaracter(&yesno);
                                        switch(yesno){
                                            case 'Y':
                                                    bajaLogica(aux);
                                                    escribirModificacion(fb, nomb, aux);
                                                    printf("**Corredor dado de bajar**\n");
                                                    system("pause");
                                                    leerCSVB(fb,nomb,1," ",0,999);
                                                    break;
                                            case 'N':
                                                    break;
                                            default:
                                                    error(3);
                                        }
                                    }while((yesno != 'N') && (yesno != 'Y'));
                                }
                                else{
                                    error(2);
                                }
                                eliminarCorredor(aux);
                                system("pause");
                                break;
                            case 2:
                                //BAJA POR NUMERO DE CORREDOR
                                printf("Ingrese n%cmero de corredor: ",163);
                                fflush(stdin);
                                scanf("%d",&buscado);
                                aux = buscar(fb,nomb,0,1,buscado, &fila);
                                system("cls");
                                if(aux->orden != 0){
                                    campos();
                                    mostrarCorredor(aux);
                                    do{
                                        fflush(stdin);
                                        scanf("%c",&yesno);
                                        mayusCaracter(&yesno);
                                        switch(yesno){
                                            case 'Y':
                                                    bajaLogica(aux);
                                                    escribirModificacion(fb, nomb, aux);
                                                    printf("**Corredor dado de bajar**\n");
                                                    system("pause");
                                                    leerCSVB(fb,nomb,1," ",0,999);
                                                    break;
                                            case 'N':
                                                    break;
                                            default:
                                                    error(3);
                                        }
                                    }while((yesno != 'N') && (yesno != 'Y'));
                                }
                                else{
                                    error(2);
                                }
                                eliminarCorredor(aux);
                                system("pause");
                                break;
                            case 0:
                                system("cls");
                                break;
                            default:
                                error(1);
                        }
                    }while(op5 != 0);
                    system("cls");
                    break;
            case 9:
                    //BAJA FISICA SOLO BRINDARA EL MENSAJE DE QUE SE REALIZO
                    //LA PETICION SOLICITADA
                    //SE DETERMINO QUE CUANDO SE REALIZA UNA BAJA EN EL MISMO DIA
                    //SE VERIFICARA SI EL ARCHIVO (NOMBRE+FECHA) YA EXISTE
                    //DE EXISTIR AGREGA AL FINAL DEL MISMO LA NUEVA BAJA
                    //SI NO EXISTE SE CREARA Y SE ESCRIBIRA EN EL LA NUEVA BAJA
                    //ES DECIR. SI SE DA DE BAJA FISICA 2 CORREDORES EN EL MISMO DIA,
                    //DISTINTO MOMENTO, SE GUARDARAN EN EL MISMO ARCHIVO DE ESE DIA.
                    //SI SE DAN DE BAJA EN DIAS DISTINTOS HABRA DOS ARCHIVOS CON DISTINTAS FECHAS
                    system("cls");
                    cadenaFecha(nombz);                         //Agrego la fecha al nombre del archivo
                    escribirArchivo(ff, nomf, nombz);
                    paseBajasXYZ(fb, nomb, fbz, nombz);         //Realizo el pase de bajas logicas a el archivo .xyz
                    bajaFisica(fb, nomb);                       //Baja fisca, sobrescribo de 0s la baja logica
                    strcpy(nombz,"BAJAS\\competidores_bajas_"); //Vuelvo a renombrar el archivo
                    system("pause");
                    system("cls");
                    break;
            case 10:
                    //SE PEDIRA AL USUARIO INGRESAR UNA FECHA Y SE LEERA EL ARCHIVO
                    //CORRESPONDIENTE A LA MISMA
                    // PEDIR FECHA, ARMAR LA CADENA Y CONCATENARCON NOMBZ PARA PODER INDICARLE
                    //QUE ARCHIVO ABRRIR
                    system("cls");
                    do{
                        strcpy(nombz,"BAJAS\\competidores_bajas_");
                        menuLeerBajas(&op6);
                        switch(op6){
                            case 1:
                                system("cls");
                                leerArchivo(ff, nomf);
                                system("pause");
                                system("cls");
                                break;
                            case 2:
                                ingresoFecha(auxc);
                                completaNombre(nombz, auxc);
                                leerCSVB(fbz,nombz,0," ",0,999);
                                system("pause");
                                system("cls");
                                break;
                        }
                    }while(op6 != 0);
                    system("cls");
                    break;
            case 0:
                    fin();
                    break;
            default:
                    system("cls");
                    error(1);
                    system("pause");
                    system("cls");
        }
    }while(op > 0);

    return 0;
}
