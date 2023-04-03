//Trabajo Integrador Final - Cornejo Mateo, Avaro Jeremias

//Compilador de Mateo: gcc (Ubuntu 10.3.0-1ubuntu1) 10.3.0. Sistema operativo: Linux
//Compilador Jeremias: gcc.exe (Rev4, Built by MSYS2 project) 12.2.0. Sistema operativo: Windows

//Lexico 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMax 366 //Se define el maximo del arreglo

//Se define el tipo regDiario.

typedef struct{

    int ddmmyyyy;  //Dia, Mes y Anio.
    int tmax;  //Temperatura maxima.
    int tmin;  //Temperatura minima.
    int hum; //Humedad.
    int pnm;  //Presion atmosferica.
    int dv; //Direccion del viento.
    int ff;  //Velocidad del viento.
    int pp;  //Precipitacion Pluvial.
    int borrado; //Borrado logico, 1 = Borrado, 0 = Activo.

}regDiario;

FILE* f;        //Se define el archivo

//Se define el TData.

typedef struct{

    regDiario a[NMax];       //Cada elemento del arreglo va a ser del tipo regDiario
    int cant;       //Cantidad de elementos del arreglo

}TData;

TData arreglo;
int opcion;     //En esta variable se va a guardar la opcion de lo que desee hacer el usuario.
int fechaAbusc; //En esta variable se guarda la fecha que se desea buscar para luego mostrarla.
int pos;       //En esta variable guardamos la posicion del registro que se desea mostrar.
int i;          //Variable que utilizamos para manipular el arreglo
int a;       //Variable que almacena el anio sobre el cual trabajara el usuario. Es el nombre del archivo.
char nombreArchivo[15]; //Variable que almacena el nombre del archivo, el cual va a ser un anio sobre el cual se va a trabajar. Luego concatenado con ".dat"
char nuevo;
int salio;
regDiario rG;
//Cabeceras de los modulos.

int Vacia (TData arreglo);             //La utilizamos para corroborar que el arreglo con el que vamos a "trabajar" no este vacio.
int EsBisiesto (int a);     //Funcion para ver si el anio es bisiesto.
void BubbleSort (TData *a);
void InsertionSort (TData *a);
void Fecha (int *fechaTotal, int a);   //Accion con la cual pedimos pedimos la fecha que desea el usuario.
void Intercambiar (regDiario *x, regDiario *y);     //Accion intercambiar de los algoritmos de ordenamiento, la cual dado dos elementos intercambia sus valores.
void ArchivoParaArreglo (char nomArch[15], TData *arr);  //Accion que pasa un archivo a un arreglo, manteniendo el archivo original.
void Cargar (char nomArch[15], int anio);  //Carga de datos en un registro.
void Suprimir (char nomArch[15], int anio);    //Supresion de datos de un registro del archivo.
void Modificar (char nomArch[15], int anio);   //Accion que permite modificar los campos del registro que el usuario desee, si es que existe.
void MostrarRegAct (char nomArch[15]);       //Accion que muestra los registos activos.
int MostrarArchivoDia (TData arr, int aBuscar);     //Funcion recursiva que devuelve la posicion en el arreglo del registro deseado.
void MaximaTemperatura (char nomArch[15]);           //Accion que muestra el/los dias que tuvieron la maxima temperatura del anio.
void MostrarPrecipitaciones (TData a);              //Accion que muestra los 10 dias de mayor precipitacion del anio en orden, en caso que el registro tenga menos de 10 cargados, los muestra a todos en orden de mayor a menor (Utilizamos InsertSort).
void MostrarVientos (TData a);              //Accion que muestra los 10 dias de mayor velocidad del viento del anio en orden, en caso que el registro tenga menos de 10 cargados, los muestra a todos en orden de mayor a menor (Utilizamos BubbleSort).
void CopiaDeSeguridad (char nomArch[15], int anio);     //Realiza una copia de seguridad del archivo, con todos los datos cargados hasta el momento, los cuales no esten borrados logicamente
void MostrarReg (TData a, int pos);                             //Muestra un registro deseado por el usuario.

/*Recordar que para la manipulacion de arreglos en este lenguaje, los arreglos comienzan de 0, y por lo tanto, a diferencia del 
pseudocodigo tuvimos que hacer varios cambios, ya que no funcionan de la misma forma.*/

int main (){  //Inicio del algoritmo

    salio = 0;
    do{
    
        printf("\nDesea trabajar con un archivo existente o con un nuevo archivo? (ingrese N o n si desea trabajar con un nuevo archivo, si no ingrese cualquier tecla): ");
        fflush(stdin);
        scanf("%c", &nuevo);

        printf("\nIngrese el nombre del archivo (sin el .dat): ");  
        fflush(stdin);
        scanf("%s", nombreArchivo); //Pedimos el nombre del archivo

        strcat(strcpy(nombreArchivo, nombreArchivo), ".dat");    //Concatenamos el nombre del archivo con ".dat
        f = fopen (nombreArchivo, "rb");  //Abrimos en este modo 

        if (nuevo == 'N' || nuevo == 'n'){     //Si el usuario desea trabajar con un nuevo archivo

            
            if(f == NULL){          //Si el archivo no esta creado
            
                f = fopen (nombreArchivo, "w+b");    //Se crea el archivo en modo escribir
                printf("Ingrese el anio con el que va a trabajar: ");
                fflush(stdin);
                scanf("%d", &a);      //Pedimos el anio
                rG.ddmmyyyy = a;
                rG.borrado = 1;
                fwrite(&rG, sizeof(rG), 1, f);
                salio = 1;

            }else{

                printf("\nEl archivo ya existe, no se puede transcribir\n");

            }

        }else{
            
            if(f == NULL){

                printf("\nEl archivo no existe, por favor cree uno con ese nombre\n");

            }else{

                fread(&rG, sizeof(rG), 1, f);  
                a = ((((rG.ddmmyyyy / 10000) * 10000) - rG.ddmmyyyy) * -1);          //
                salio = 1;

            }
            
        }
        
        fclose(f);

    }while(salio == 0);

    printf("\nArchivo abierto correctamente\n");

    do{

        printf("\n\nBienvenido al menu de la estacion meteorologica, que desea hacer: \n");  //Menu.
        printf("\n1- Carga del registro meteorologico diario");
        printf("\n2- Suprimir un registro meteorologico diario");
        printf("\n3- Modificar un registro meteorologico diario");
        printf("\n4- Mostrar todos los registros activos");
        printf("\n5- Mostrar todas las estadisticas de un registro meteorologico diario elegido");
        printf("\n6- Listar el dia o dias de maxima temperatura en lo que va del anio");
        printf("\n7- Listar el dia o dias de maxima precipitacion en lo que va del anio");
        printf("\n8- Listar las fechas de mayor a menor velocidad del viento");
        printf("\n9- Realizar una copia de seguridad del archivo del anio en curso");
        printf("\n10- Salir");

        printf("\n\nIngrese una opcion del 1 al 10 a continuacion: ");
        fflush(stdin);
        scanf("%d", &opcion); //Se pide la opcion que desea el usuario

        if(opcion == 1){

            Cargar(nombreArchivo, a);      //Carga de un registro.

        }else{

            if(opcion == 2){

                Suprimir(nombreArchivo, a);    //Supresion de un registro.

            }else{

                if(opcion == 3){

                    Modificar(nombreArchivo, a);   //Modificar campos deseados de un registro.

                }else{

                    if(opcion == 4){

                        MostrarRegAct(nombreArchivo);             //Se muestran los registros activos, es decir los que no estan suprimidos.

                    }else{

                        if(opcion == 5){
                            
                            Fecha(&fechaAbusc, a);     //Se carga la fecha que desea mostrar el usuario.
                            ArchivoParaArreglo(nombreArchivo, &arreglo);    //Pasamos el archivo a un arreglo
                            pos = MostrarArchivoDia(arreglo, fechaAbusc);       //Guardamos la posicion del dia que queremos mostrar en una variable haciendo uso de la funcion recursiva MostrarArchivoDia
                            MostrarReg(arreglo, pos);           //Mostramos los campos del dia deseado, si es que existe

                        }else{

                            if(opcion == 6){

                                MaximaTemperatura(nombreArchivo);               //Mostramos el o los dias de maxima temperatura cargados en el archivo.

                            }else{

                                if (opcion == 7){

                                    ArchivoParaArreglo(nombreArchivo, &arreglo);    //Pasamos el archivo a un arreglo.
                                    InsertionSort(&arreglo);
                                    MostrarPrecipitaciones (arreglo);   //Mostramos los 10 dias de maximas precipitaciones de los registros diarios. 

                                }else{

                                    if(opcion == 8){

                                        ArchivoParaArreglo(nombreArchivo, &arreglo);    //Pasamos el archivo a un arreglo.
                                        BubbleSort(&arreglo);
                                        MostrarVientos(arreglo);    //Mostramos los 10 dias de maximos vientos de los registros diarios.

                                    }else{

                                        if(opcion == 9){

                                            CopiaDeSeguridad (nombreArchivo, a);   //Se hace la copia de seguridad del archivo

                                        }else{

                                            if (opcion == 10){ //Salir
                                        
                                                printf("\nUsted ha salido del menu\n\n");

                                            }else{

                                                printf("\nIngrese una opcion valida porfavor\n"); //En el caso de que ingrese una opcion fuera del subrango (1..10)

                                            }
                                            
                                            

                                        }

                                    }

                                }

                            }

                        }

                    }

                }

            }

        }
    
    }while(opcion != 10);  //Cuando se elije la opcion 10 el usuario sale del menu.


    return 0;
}


//Esta funcion lo que hace es recibir como parametro un arreglo de tipo TData, si la cantidad de elementos del arreglo es igual a 0, entonces la
//funcion retorna verdadero, de lo contrario, retorna falso.

int Vacia (TData arreglo){  

    //Inicio
    
    if (arreglo.cant == 0){

        return 1; //Retorna verdadero

    }else{

        return 0;    //Retorna falso

    }

}//Ffuncion

//Accion que pasados dos parametros de tipo dato-resultado, lo que va a hacer esta accion es basicamente intercambiar sus valores.

void Intercambiar (regDiario *x, regDiario *y){     

    //Lexico Local
    
    regDiario r;          //Variable que utilizamos como "auxiliar" para poder intercambiar los valores de x e y.

    //Inicio

    r = *x;
    *x = *y;
    *y = r;

}//Faccion

//Funcion que pasado un anio va a devolver 1 si el mismo es bisiesto, en caso contrario va a devolver 0. Para que un anio sea bisiesto un anio tiene que ser 
//divisible por 4 y por 400, o ser divisible por 4 y no ser divisible por 100.

int EsBisiesto (int a){     

    //Inicio

    if ((a % 4 == 0) && (a % 100 != 0 || a % 400 == 0)){        //Si el anio es bisiesto

        return 1;    //Retorna verdadero

    }else{

        return 0;   //Retorna falso

    }

}//Ffuncion

void BubbleSort (TData *a){
    
    //Lexico Local

        int i, j;

    //Inicio
    
        i = a->cant - 1;       //Se inicializa i
        while(i > 0){     

            j = 0;    //Se inicializa j
            while(j < i){

                if ((a->a[j].ff) < (a->a[j + 1].ff)){

                    Intercambiar(&(a->a[j]), &(a->a[j + 1]));     //Si el arreglo en la posicion j es mas grande que el arreglo en la posicion j + 1, los elementos se van a intercambiar, ya que lo que se intenta hacer con esto es dejar a los mayores a lo ultimo del arreglo
                    
                } 
                j = j + 1;   //Se incrementa el j en 1
            }
            i = i - 1;   //Se decrementa i en 1
            
        }
    
}

void InsertionSort(TData *a){

    //Lexico Local

        int i, j;
        regDiario aux;

    //Inicio
    
        i = 1;      //Inicializacion de i
        while (i < a->cant){     //Mientras no se termine de recorrer el arreglo
            
            aux = a->a[i];       //Se guarda en aux la informacion del arreglo en la posicion i (Todos los campos)
            j = i - 1;      //A la variable j se le asigna i - 1
            while ((j >= 0) && (a->a[j].pp > aux.pp)){       //Mientras j sea mayor o igual a 0, y las precipitaciones del arreglo en la posicion j, sean mayores a las precipitaciones almacenadas en i
                
                a->a[j + 1] = a->a[j];      //Se mueve el elemento de la posicion j + 1 a su derecha
                j = j - 1;        //Se decrementa el j en 1

            }
            
            a->a[j + 1] = aux;       //Al arreglo en la posicion j + 1, se le asigna aux
            i++;                    //Se incrementa i en 1

        }

}

/*Esta accion tiene el fin de que el usuario pueda ingresar una fecha valida. Pedimos los dias y los meses por separado y el anio se 
pasa como parametro*/

void Fecha (int *fechaTotal, int a){

    //Lexico local

    int dd; //(1..31)
    int mm;  // (1..12)

    //Inicio
    
    do{
        printf("\nIngrese el mes: ");   
        fflush (stdin);
        scanf("%d", &mm);  //Se pide la entrada del mes del registro diario que se quiere ingresar
        printf("\nIngrese el dia: ");
        fflush (stdin);
        scanf("%d", &dd);       //Se pide la entrada del dia del registro diario que se quiere ingresar
        
        
        if( (mm == 2) && (dd > 29)){   //Un dia no valido de febrero
           
           *fechaTotal = -1;
            printf("\nIngrese una fecha valida porfavor\n");
        
        }else{
            
            if ((mm == 2) && (dd == 29)){
                
                if (EsBisiesto(a)){  //Si el anio es bisiesto la fecha es valida, si no, no es valida
                    
                    *fechaTotal = ((dd*1000000) + (mm * 10000) + a);   
                
                }else{
                    
                    *fechaTotal = -1;  
                    printf("\nIngrese una fecha valida porfavor\n");
                
                }

            }else{

                if ((mm == 2) && (dd < 29 && dd > 0)){  //Se ingresa un dia valido de febrero
                    
                    *fechaTotal = ((dd*1000000) + (mm * 10000) + a);
                
                }else{

                    if (((mm == 4) || (mm == 6) || (mm == 9) || (mm == 11)) && (dd >= 31)){  //Se ingresa un dia 31 o mas en los meses de hasta 30 dias
                       
                       *fechaTotal = -1;   //Dia no valido de un mes de 30 dias
                       printf("\nIngrese una fecha valida porfavor\n");
                    
                    }else{
                        
                        if (((mm == 4) || (mm == 6) || (mm == 9) || (mm == 11)) && (dd < 31 && dd > 0)){  //Se ingresa un dia valido en los meses de 30 dias
                            
                            *fechaTotal = ((dd*1000000) + (mm * 10000) + a);
                            
                        }else{
                                
                            if(((mm == 1) || (mm == 3) || (mm == 5) || (mm == 7) || (mm == 8) || (mm == 10) || (mm == 12)) && (dd < 32 && dd > 0)){ //Si ingresa un dia valido en los meses de 31 dias.

                                *fechaTotal = ((dd*1000000) + (mm * 10000) + a); 
                                   
                            }else{

                                *fechaTotal = -1;   //Si ingresa un mes o un dia inexistente
                                printf("\nIngrese una fecha valida porfavor \n"); 

                            }
                            
                        }
                    }
                        
                }
                    
                    
            }
                
                
        }
        
    }while (*fechaTotal == -1);  //Va a dejar de ciclar cuando la fecha ingresada sea valida.
    
}//Faccion   

/*Esta accion lo que hace es recibir un archivo y un arreglo como parametros, y la funcion que tiene es la de
pasar todos los datos/registros del archivo a un arreglo*/

void ArchivoParaArreglo (char nomArch[15], TData *arr){

    //Lexico local
    
    int i;    //Variable que utilizamos como indice para ingresar a cada componente del arreglo.
    regDiario c;    //Variable en la que vamos a almacenar lo que vayamos "extrayendo" del archivo
    FILE* f;        //Nombre interno del archivo
    int tam;      //Definimos una variable que va a almacenar la cantidad de registros que posee el archivo.

    //Inicio

    f = fopen (nomArch, "r+b");       //Se abre el archivo en modo lectura/escritura binaria
    fseek(f, 0, SEEK_END);           //Se posiciona el cursor al final del archivo.
    tam = ftell(f);            //Se guarda en tam la cantidad de registros del archivo.
    if(tam == 0){         //Si tam = 0 entonces no hay registros en el archivo.

        arr->cant = 0;     //A la cantidad de elementos del arreglo le asignamos 0 

    }else{     

        fseek(f, 0, SEEK_SET);      //Se posiciona el cursor en la primera posicion
        i = 0;           //Se incializa i en 0
        arr->cant = 0;        //Se inicializa el arr.cant en 0
        fread(&c, sizeof(c), 1, f);    //Usamos la primitiva leer de archivo, y guardamos la informacion que se extrae en la variable c. Leemos antes de entrar al ciclo y luego del condicional para que no sea lea dos veces el ultimo.
        while (!(feof(f))){   //Mientras no termine el archivo

            if(c.borrado == 0){    //Si el registro no esta borrado se guarda en el arreglo, si no, no se agregara.
                
                arr->a[i] = c;    //Se guarda en la posicion i del arreglo la variable c de tipo regDiario.
                arr->cant++;     //Incrementamos arr.cant en 1.
                i++;      //Incrementamos el i en 1
                
            }
            fread(&c, sizeof(c), 1, f);  //Usamos la primitiva leer de archivo, y guardamos la informacion que se extrae en la variable c. 
            
        }
        

    }
    
    fclose(f);      //Cerramos el archivo

}//Faccion

/*Lo que hace esta accion es recibir como parametro el nombre del archivo el cual va a ser el anio en el que se esta trabajando y la variale de tipo 
entero anio que tiene almacenado el anio sobre el cual se esta trabajando. Esta accion tiene el fin de cargar un registro diario. Primero se pide la fecha, 
luego se compara con las demas para corroborar que no haya sido ingresada antes. Si ya fue ingresada antes, se pisara con nuevos datos,
si no fue ingresada antes, se pide todo el registro y se guardara en la ultima posicion del archivo.*/

void Cargar (char nomArch[15], int anio){

    //Lexico local
    
    regDiario d, nuevo;   //Variables que vamos a utilizar para manipular el archivo
    FILE* f;       //Nombre interno del archivo
    int fecha;      //Variable que almacena la fecha que desea cargar el usuario.

    //Inicio

    f = fopen (nomArch, "r+b");       //Apertura del archivo en modo lectura/escritura binaria
    fseek(f, 0, SEEK_SET);      //Se posiciona el cursor en el primer registro del archivo
    Fecha(&fecha, anio);       //Se pide la entrada de la fecha por medio de una accion
    nuevo.ddmmyyyy = fecha;          //A la variable nuevo en el campo fecha se le asigna la fecha cargada recientemente.

        do{

            fread(&d, sizeof(d), 1, f);       //Se lee lo almacenado en el archivo y se guarda en la variable d

        }while((!(feof(f)) && nuevo.ddmmyyyy != d.ddmmyyyy));     //Mientras no termine la secuencia o encuentre el registro
        
        if((nuevo.ddmmyyyy == d.ddmmyyyy) && (d.borrado == 0)){    //Si encontro el registro y no tiene el campo borrado en falso, no se puede cargar.

            printf("\nEl registro diario ya fue anteriormente cargado");
            
        }else{

            if((nuevo.ddmmyyyy == d.ddmmyyyy) && (d.borrado != 0)){        //Si se enconto el registro y tiene el campo borrado en verdadero.

                fseek(f, ftell(f)-sizeof(nuevo), 0);       //Situamos el cursor en posicionActual(f) - 1
            
            }else{

                fseek(f, 0, SEEK_END);      //Situamos el cursor al final del archivo

            }

            printf("\nIngrese la temperatura maxima del registro diario: ");
            fflush(stdin);
            scanf("%d", &nuevo.tmax);    //Se pide la entrada de la temperatura maxima
                
            do{
                
                printf("\nIngrese la temperatura minima del registro diario (Debe ser menor o igual a la maxima temperatura): ");
                fflush(stdin);
                scanf("%d", &nuevo.tmin);      //Se pide la entrada de la temperatura minima, la cual no debe ser mayor a la temperatura maxima
                
                if(nuevo.tmin > nuevo.tmax){

                    printf("La temperatura ingresada no es valida, ingrese una correcta\n");

                }

            }while(nuevo.tmin > nuevo.tmax);   //Deja de ciclar cuando se ingrese una temperatura minima menor a la maxima.

            do{
                printf("\nIngrese la humedad del registro diario: ");
                scanf("%d", &nuevo.hum);        //Se pide la entrada de la humedad
                if (nuevo.hum > 100 || nuevo.hum < 0){

                    printf("La humedad ingresada debe estar en 0 y 100 g/m3, porfavor ingrese un numero valido: ");  

                }
                
            }while (nuevo.hum > 100 || nuevo.hum < 0);   //Para que se respete el subrango (1..100)

            do{

                printf("\nIngrese la presion atmosferica del registro diario: ");
                scanf("%d", &nuevo.pnm);        //Se pide la entrada de la presion atmosferica
                if (nuevo.pnm < 900 || nuevo.pnm > 3500){
                    
                    printf("La presion atomsferica debe estar entre 900ATM Y 3500ATM, ingrese un numero valido\n");
                    
                } 
                                
            }while(nuevo.pnm < 900 || nuevo.pnm > 3500);  //Para que se respete el subrango (900..3500)

            do{

                printf("\nIngrese la direccion del viento del registro diario: ");
                scanf("%d", &nuevo.dv);         //Se pide la entrada de la direccion del viento 
                if (nuevo.dv > 360 || nuevo.dv < 0){

                    printf("La direccion del viento ingresada debe estar entre los 0 y los 360 grados, porfavor ingrese un numero valido\n");

                }

            }while (nuevo.dv > 360 || nuevo.dv < 0);        //Para respetar el subrango (1..360)
            
            do{

                printf("\nIngrese la velocidad del viento del registro diario: ");
                scanf("%d", &nuevo.ff);

                if(nuevo.ff < 0){

                    printf("La velocidad del viento no puede ser menor a 0 km/h, ingrese  un valor valido\n");

                }

            }while(nuevo.ff < 0);      //No se puede ingresar una velocidad del viento negativa

            do{

                printf("\nIngrese las precipitaciones del registro diario: ");
                scanf("%d", &nuevo.pp);     //Se pide la entrada de las precipitaciones
                if (nuevo.pp > 1000 || nuevo.pp < 0){

                    printf("La precipitacion pluvial ingresada debe estar entre 0 y 1000mm, porfavor ingrese un numero valido\n");

                }
                
            }while (nuevo.pp > 1000 || nuevo.pp < 0);   //Para respetar el subrango (1..1000)
            
            nuevo.borrado = 0;   //Al campo borrado del registro le asignamos 0, es decir, no borrado logicamente

            fwrite(&nuevo, sizeof(nuevo), 1, f);          
            printf("\nRegistro cargado!!!\n");
    
        }

    fclose(f);          //Se cierra el archivo

}//Faccion

/*Esta accion lo que es recibir como parametro el nombre del archivo que va a ser el anio en el que se esta trabajando y la variale de tipo entero anio
que tiene almacenado el anio sobre el cual se esta trabajando. Al invocar a este modulo se va a posibilitar la oportunidad de borrar logicamente un registro, 
es decir que el campo borrado va a cambiar a verdadero (1 en nuestro caso) si es que el registro existe en el archivo, de lo contrario, no se podra suprimir*/

void Suprimir (char nomArch[15], int anio){

    //Lexico Local

    regDiario c;       //Variable que utilizamos para manipular el archivo
    int tam;       //Variable que utilizamos para almacenar el tamanio del archivo
    int fecha;     //Fecha que va a ingresar el usuario
    FILE* f;        //Nombre interno del archivo

    //Inicio
    
    f = fopen (nomArch, "r+b");      //Se abre el archivo en modo lectura/escritura binaria
    fseek(f, 0, SEEK_END);        //Se situa el cursor al final del archivo
    tam = ftell(f);             //A tam se le asigna el tamanio del archivo
    
    if(tam == 0){   //Si tam = 0 significa que no hay registros en el archivo

        printf("\nNo hay registros diarios para suprimir");
         
    }else{ //Si el archivo no esta vacio

        fseek(f, 0, SEEK_SET);  //Se situa el cursor al comienzo del archivo
        Fecha(&fecha, anio);    //Se pide la fecha deseada por el usuario por medio de una accion
        
        do{

            fread(&c, sizeof(c), 1, f);  //Se "lee" el archivo y se guarda lo extraido en la variable c

        }while((!(feof(f)) && (fecha != c.ddmmyyyy)));      //Mientras no termine el archivo y no se encuentre la fecha 
        if (fecha != (c.ddmmyyyy)){           //Si no encuentra el registro entonces el registro no existe.                   

            printf("\nNo se encuentra ese registro");
            
        }else{      
            
            if(c.borrado != 0){         //Si se encontro el registro pero tiene el campo borrado en verdadero

                printf("\nEl registro que desea eliminar ya fue suprimido \n");

            }else{

                fseek(f, ftell(f)-sizeof(c), 0);          //Situamos el cursor en la posicion anterior, posicionActual(f) - 1
                c.borrado = 1;       //Al registro en el campo borrado le asignamos verdadero para borrarlo logicamente
                fwrite(&c, sizeof(c), 1, f);       //Guardamos en el archivo el mismo elemento pero suprimido logicamente
                printf("\nEl registro ha sido suprimido!!!\n");

            }

        }
    }
    fclose(f);      //Se cierra el archivo

}

/*Esta accion lo que es recibir como parametro el nombre del archivo que va a ser el anio en el que se esta trabajando y la variale de tipo entero anio
que tiene almacenado el anio sobre el cual se esta trabajando. Al invocar a este modulo se va a posibilitar la oportunidad de modificar un registro. Se van a
dar las opciones para que el usuario pueda modificar todo y todas las veces que desee, el registro*/

void Modificar (char nomArch[15], int anio){

    //Lexico Local
    
    int fecha;          //Variable que se utiliza para pedir la fecha deseada por el usuario
    regDiario c;        //Variable que utilizamos para poder manipular el archivo
    FILE* f;            //Nombre interno del archivo
    int opcion;         //Variable que usamos para guardar la opcion de que campo se desea modificar 
    int tam;            //Variable  usamos para guardar el tamanio del archivo
    char salir;         //Variable que usamos para controlar si el ususario desea modificar otro campo o no
    char sn;            //Variable que usamos para preguntar si el ususario desea restaurar un archivo eliminado

    //Inicio
    
    f = fopen (nomArch, "r+b");       //Se abre el archivo en modo lectura/escritura binaria
    fseek(f, 0, SEEK_END);       //Se posiciona el cursor en el final del archivo
    tam = ftell(f);              //En tam se guarda el tamanio del archivo
    
    if (tam == 0){   //Si el archivo esta vacio
 
        printf("\nNo hay registros diarios para modificar\n");

    }else{ //Si el archivo no esta vacio

        fseek(f, 0, SEEK_SET);      //Se posicion el cursor en el comienzo del archivo
        Fecha(&fecha, anio);        //Invocamos la accion Fecha para que el usuario pueda ingresar la fecha deseada
        do{

            fread(&c, sizeof(c), 1, f);          //Se "lee" el archivo y lo extraido se guarda en la variable c

        }while((!(feof(f)) && fecha != c.ddmmyyyy));    //Mientras no termine de recorrer el archivo y no encuentre el registro deseado

        if (fecha != c.ddmmyyyy){     //Si no encuentra el registro
        
            printf("\nEl registro que desea modificar no existe\n");

        }else{
        
            if(fecha == c.ddmmyyyy && c.borrado != 0){  //Si encontro el registro pero esta borrado logicamente

                printf("El registro diario fue borrado, si desea restaurarlo ingrese S: ");
                fflush(stdin);
                scanf("%c", &sn);       //Pedimos la entrada de la respuesta del usuario

                if(sn == 'S'  || sn == 's'){

                    c.borrado = 0;                       //Lo restauramos 
                    fseek(f, ftell(f)-sizeof(c), 0);   //Posicionamos el cursor en posicionActual(f) - 1
                    fwrite(&c, sizeof(c), 1, f);          //Guardamos en el archivo el registro restaurado
                    printf("\nRegistro restaurado!!!\n");

                }

            }else{ 

                fseek(f, ftell(f)-sizeof(c), 0);       //Se posiciona el cursor una posicion atras, posicionActua(f) - 1
                do{ 

                    printf("\nQue campo desea modificar?:\n");
                    printf("\n1- Temperatura Maxima\n");
                    printf("\n2- Temperatura Minima\n");
                    printf("\n3- Humedad\n");
                    printf("\n4- Presion Atmosferica\n");
                    printf("\n5- Direccion del viento\n");
                    printf("\n6- Velocidad del viento\n");
                    printf("\n7- Precipitacion Pluvial\n");
                    printf("\nOpcion: ");   
                    fflush(stdin);
                    scanf("%d", &opcion);          //Se pide la entrada de la opcion 
                    printf("\n");          //Usamos este printf por comodidad a la hora de ver la ejecucion
                    
                    if(opcion == 1){
                            
                        do{

                            printf("\nIngrese la nueva temperatura maxima (Debe ser mayor o igual a la minima temperatura): ");
                            fflush(stdin);
                            scanf("%d", &c.tmax);       //Se pide la entrada de la temperatura maxima modificada, la cual debe ser mayor que la minima  

                            if (c.tmax <= c.tmin){

                                printf("\nLa temperatura ingresada no es valida, ingrese una correcta\n");

                            }
                            
                        }while (c.tmax <= c.tmin);  //Se va a ciclar hasta que la temperatura maxima sea una valida
                        
                    }else{

                        if(opcion == 2){

                            do{
                    
                                printf("\nIngrese la nueva temperatura minima del registro diario (Debe ser menor o igual a la maxima temperatura): ");
                                fflush(stdin);
                                scanf("%d", &c.tmin);       //Se pide la entrada de la temperatura minima modificada, la cual debe ser menor que la maxima

                                if(c.tmin >c.tmax){

                                printf("\nLa temperatura ingresada no es valida, ingrese una correcta\n");

                                }

                            }while(c.tmin > c.tmax);   //Se va a ciclar hasta que la temperatura minima sea una valida

                        }else{

                            if(opcion == 3){
                                
                                do{
                                
                                    printf("\nIngrese la nueva humedad: ");   
                                    fflush(stdin);  
                                    scanf("%d", &c.hum);      //Se pide la entrada de la humedad modificada
                                    if (c.hum > 100 || c.hum < 0){

                                        printf("La humedad ingresada debe estar entre 0 y 100 g/m3, porfavor ingrese un numero valido\n");

                                    }
                                    
                                }while (c.hum > 100 || c.hum < 0);        //Para respetar el subrango de la humedad (1..100)
                                
                            }else{

                                if(opcion == 4){

                                    do{
                                        
                                        printf("\nIngrese la nueva presion atmosferica: ");
                                        fflush(stdin);
                                        scanf("%d", &c.pnm);       //Se pide la entrada de la presion atmosferica modificada
                                        
                                        if(c.pnm < 900 || c.pnm > 3500){       //Si el valor ingresado esta fuera del rango

                                            printf("La presion atmosferica ingresada debe tener valores entre 900 y 3500, por favor ingrese un numero valido\n");

                                        }
                                    
                                    }while(c.pnm < 900 || c.pnm > 3500);    //Para que se respete el subrango (900..3500)

                                }else{

                                    if(opcion == 5){

                                        do{

                                            printf("\nIngrese la nueva direccion del viento: "); 
                                            fflush(stdin);       
                                            scanf("%d", &c.dv);      //Se pide la entrada de la direccion del viento modificada

                                            if (c.dv > 360 || c.dv < 0){       //Si el valor ingresado esta fuera del rango

                                                printf("La direccion del viento ingresada debe estar ente 0 y 360 grados, porfavor ingrese un numero valido\n");

                                            }                                       

                                        }while (c.dv < 0 || c.dv > 360);           //Para que se respete el subrango (0..360)
                                        
                                    }else{

                                        if (opcion == 6){

                                            do{

                                                printf("\nIngrese la nueva velocidad del viento: ");
                                                fflush(stdin);
                                                scanf("%d", &c.ff);         //Se pide la entrada de la velocidad del viento modificada

                                                if(c.ff < 0){         //Si el valor ingresado esta fuera del rango

                                                    printf("La velocidad del viento no puede ser menor a 0 km/h, ingrese un valor valido\n");

                                                }

                                            }while(c.ff < 0);        //Se va a ciclar hasta que la velocidad del viento ingresada sea mayor a 0

                                        }else{

                                            if(opcion == 7){

                                                do{

                                                    printf("\nIngrese la nueva precipitacion pluvial: ");
                                                    fflush(stdin);
                                                    scanf("%d", &c.pp);       //Se pide los mm de precipitaciones modificados
                                                    if (c.pp > 1000 || c.pp < 0){             //Si el valor ingresado esta fuera del rango

                                                        printf("La precipitacion pluvial ingresada debe estar entre y los 1000mm, porfavor ingrese un numero valido\n");
                                                    
                                                    }

                                                }while (c.pp < 0 || c.pp > 1000);  //Para que se respete el subrango (0..1000)
                                                
                                            }

                                        }

                                    }
                                                                                            
                                }

                            }

                        }

                    }

                    printf("\nSi desea modificar otro campo ingrese S, si no ingrese cualquier letra: ");
                    fflush(stdin);
                    scanf("%c", &salir);      //Pedimos la entrada para saber si el usuario desea seguir modificando o no el registro
                }while ((salir == 'S' || salir == 's'));       //Se va a terminar de ciclar cuando el usuario no quiera modificar ningun campo mas del registro
                fwrite(&c, sizeof(c), 1, f);     //Se guarda en el archivo el registro modificado
                printf("\nRegistro modificado!!!\n");

            }

        }   
                
    fclose(f);      //Se cierra el archivo

}
}//Faccion

/*Esta accion lo que es recibir como parametro el nombre del archivo que va a ser el anio en el que se esta trabajando. Al invocar a este modulo 
se van mostrar todos los registros activos (borrado = 0) que tenga el archivo*/

void MostrarRegAct(char nomArch[15]){

    //Lexico Local

    regDiario d;        //Variable que utilizamos para manipular el archivo
    FILE* f;            //Nombre interno del archivo
    int tam;            //Variable  usamos para guardar el tamanio del archivo
    int i;      //Variable que utilizamos para contabilizar la cantidad de registros activos

    //Inicio

    f = fopen (nomArch, "r+b");     //Apertura del archivo en modo lectura/escritura binaria
    fseek(f, 0, SEEK_END);          //Se situa el cursor en la ultima posicion del archivo.
    tam = ftell(f);                 //Guardamos en tam el tamanio del archivo.

    
    if (tam == 0){      //Si el archivo esta vacio
        
        printf("\nNo hay registros diarios para mostrar");
        
    }else{      //Si el archivo no esta vacio

        i = 0;      //Si inicializa el i en 0
        fseek(f, 0, SEEK_SET);      //Se posiciona el cursor en el comienzo del archivo
        fread(&d, sizeof(d), 1, f);     //Se "lee" el registro del archivo y se guarda en la variable d lo extaido. Leemos de esta forma para que no se lea dos veces el ultimo.
        while (!(feof(f))){     //Mientras no llegue al final del archivo
            
            if (d.borrado == 0){     //Si el registro no esta borrado logicamente
                
                //Se muestra cada campo
                printf("\n");
                printf("\nEn el dia %d\n", d.ddmmyyyy);
                printf("\n- La temperatura maxima fue de %d grados", d.tmax);
                printf("\n- La temperatura minima fue %d grados", d.tmin); 
                printf("\n- La humedad fue de %d g/m3", d.hum); 
                printf("\n- La presion atmosferica fue de %d atm", d.pnm); 
                printf("\n- La direccion del viento fue de %d", d.dv); 
                printf("\n- La velocidad del viento fue de %d km/h", d.ff);  
                printf("\n- La precipitacion fue de %d mm", d.pp); 
                i++;   //Se incrementa el i en 1
                
            }
            fread(&d, sizeof(d), 1, f);     //Se "lee" el registro del archivo y se guarda en la variable d
                
        }
        
        if(i > 0){           //Si hay registros para mostrar

            printf("\n\nCantidad de registros activos: %d\n", i);;

        }else{

            printf("\nNo hay registros para mostrar\n");

        }
       
            
    }
        
    fclose(f);      //Se cierra el archivo

}//Faccion

/*Esta funcion recursiva lo que va a hacer es devolver la posicion donde se encuentra la fecha deseada por el usuario en el caso de que exista*/

int MostrarArchivoDia (TData arr, int aBuscar){

    if(Vacia(arr) == 1){      //Arreglo vacio

        return -1; 

    }else{      //Si el arreglo no esta vacio

        if ((arr.a[arr.cant - 1].ddmmyyyy == aBuscar) && (arr.a[arr.cant - 1].borrado == 0)){ //Si el arreglo en la posicion arr.cant es igual a la fecha aBuscar,  y el arreglo en la posicion arr.cant, no esta borrado logicamente

            return arr.cant - 1;    //Devuelve la posicion del registro deseado

        }else{      //Si no se encontro

            arr.cant--;         //Se decrementa el arr.cant en 1.
            return MostrarArchivoDia(arr, aBuscar);     //Se invoca la funcion recursiva, con el arr.cant modificado

        }
        
    }

}//Ffuncion

/*Esta accion lo que va a hacer es: primero recorrer todo el archivo buscando el dia con la maxima temperatura, luego de eso se va a volver a recorrer
el archivo para buscar las fechas que tienen esa misma temperatura (la maxima), y se las va a poner en una lista SE. Por ultimo, se van a mostrar
las fechas de todos los registros que tienen la tempetura maxima del anio*/

void MaximaTemperatura (char nomArch[15]){

    //Lexico Local
    
    //Se define el TNodo
    
    struct TNodo{

        regDiario info;
        struct TNodo *next;

    };

    struct TNodo *aux;      //Se define un auxiliar para la lista
    struct TNodo *aux2;     //Se define otro auxiliar para la lista
    struct TNodo *lis;      //Se define la variable de cabeza para la lista
    FILE* f;                //Nombre interno del archivo
    regDiario max;      //Variable que utilizamos para ir guardando el dia de maxima temperatura del archivo
    regDiario c;       //Variable que utilizamos para manipular el archivo
    int tam;          //Variable en donde se va a almacenar el tamanio del archivo
    int i;      //Variable que utilizamos para contabilizar la cantidad de registros mostrados
    
    //Inicio

    f = fopen (nomArch, "r+b");     //Apertura del archivo en modo lectura/escritura binaria
    fseek(f, 0, SEEK_END);          //Se posiciona el cursor en el final del archivo
    tam = ftell(f);                 //Se almacena en tam el tamanio del archivo
    
    if (tam == 0){      //Si el archivo esta vacio
        
        printf("\nNo hay registros para mostrar");
        
    }else{  //Si el archivo no esta vacio
        
        fseek(f, 0, SEEK_SET);          //Se posiciona el cursor en el comienzo del archivo
        fread(&c, sizeof(c), 1, f);     //Se "lee" el registro del archivo y se guarda en la variable c lo extraido
        max = c; 
        
        while (!(feof(f))){             //Mientras no llegue al final del archivo
            
            if (max.tmax < c.tmax && c.borrado == 0){     //Si lo leido y guardado en la variable c en el campo "tmax", es mayor a la variable que almacena el mayor "tmax" actual  
                
                max = c;        //Se le asigna a max, lo leido en el archivo. Se actualiza el registro que contiene la maxima temperatura
                
            }
            fread(&c, sizeof(c), 1, f); //Se "lee" el registro del archivo y se guarda en la variable c.
        }
        lis = (struct TNodo*) malloc (sizeof(struct TNodo));        //Se crea el primer elemento de la lista
        lis->next = NULL;           //Se hace apuntar el primer elemento a nil
        aux = lis;                  //A la variable auxiliar "aux", se le asigna lis
        fseek(f, 0, SEEK_SET);      //Se posiciona el cursor en el comienzo del archivo
        fread(&c, sizeof(c), 1, f);     //Se "lee" el registro del archivo y se guarda en la variable c
        while (!(feof(f))){         //Mientras no llegue al final del archivo
            
            if (max.tmax == c.tmax && c.borrado == 0){      //Si lo leido y guardado en la variable c en el campo "tmax", es igual a la variable que almacena el mayor "tmax", y ademas el registro leido no esta borrado logicamente
                    
                aux2 = (struct TNodo *) malloc (sizeof(struct TNodo));  //Se crea un doblete
                aux2->next = aux->next;     //Se le asigna a aux2, el doblete al que apunta aux en el campo next
                aux->next = aux2;   //Se le asigna a aux, el doblete al que apunta aux2
                aux2->info = c;     //Se guarda en lo apuntado por aux2 en el campo info, el dia de mayor temperatura
                aux = aux2;         //A aux se le asigna lo apuntado por aux2
                    
            }
            fread(&c, sizeof(c), 1, f); //Se "lee" el registro del archivo y se guarda en la variable c
        }
        aux = lis->next;        //A aux se le asigna el primer elemento de la lista
        i = 0;
        while (aux != NULL){        //Mientras no llegue al final de la lista

            printf("\n- En el dia: %d la temperatura fue de: %d grados", aux->info.ddmmyyyy, aux->info.tmax);     //Muestra los dias de maxima temperatura y su respectiva temperatura
            aux = aux->next;     //Avanza al proximo elemento de la lista
            i++;      //Se incrementa el i en 1
            
        } 
        if(i > 0){        //Si hay registros para mostrar

            printf("\n\nCantidad de dias mostrados con maxima temperatura: %d\n", i);

        }else{

            printf("\nNo hay registros para mostrar\n");

        }
        
    
    }
    
    fclose(f);      //Se cierra el archivo

}//Faccion
    
/*Esta accion va a recibir como parametro un arreglo. El fin de este modulo es, si el arreglo no esta vacio, mostrar los 10 dias con mas precipitaciones de 
mayor a menor, y si no tiene 10 dias el archivo como minimo se va mostrar las que tiene pero tambien en orden de mayor a menor*/

void MostrarPrecipitaciones (TData a){

    //Lexico Local
    
    int z;          //Variable que utilizamos para contabilizar la cantidad de registros mostrados
    int i;        //Variables que utilizamos para el recorrido del arreglo para el InsertSort
    
    //Inicio

    if (Vacia(a) == 1){      //Si el arreglo esta vacio
        
        printf("\nNo hay registros diarios para mostrar");
    
    }else{ //Si el arreglo no esta vacio
 
        z = 0;       //Se inicializa z
        i = a.cant - 1;       //Se inicializa i 
        while ((i >= a.cant-10) && (i >= 0)){      //Se va a ciclar hasta que se muestren 10 registros o, si son menos de 10, hasta que se muestren todos

            printf("\n- En la fecha %d la precipitacion fue de %d mm\n", a.a[i].ddmmyyyy, a.a[i].pp);
            i--;    //Se decrementa el i en 1
            z++;     //Se inrementa el z en 1
        }
        if(z > 0){        //Si hay registros para mostrar

            printf("\n\nCantidad de dias mostrados con mayor precipitacion: %d\n", z);

        }else{

            printf("\nNo hay registros para mostrar\n");

        }
        

    }
     
}//Faccion

/*Esta accion va a recibir como parametro un arreglo. El fin de este modulo es, si el arreglo no esta vacio, mostrar los 10 dias con mas velocidad de viento de 
mayor a menor, y si no tiene 10 dias el archivo como minimo se va mostrar las que tiene pero tambien en orden de mayor a menor*/

void MostrarVientos (TData a){

    int i;    //Variables que utilizamos para recorrer el arreglo 

    if(Vacia(a) == 1){    //Si el arreglo esta vacio

        printf("\nNo hay registros diarios para mostrar");

    }else{ //Si el arreglo no esta vacio
    
        i = 0;      //Inicializacion de i
        
        while((i < 10) && (i < a.cant)){       //Se va a ciclar hasta que se muestren 10 registros o, si son menos de 10, hasta que se muestren todos
        
            printf("\n\n- En la fecha: %d la velocidad del viento fue: %d km/h", a.a[i].ddmmyyyy, a.a[i].ff);
            i++;   //Se incrementa i en 1
            
        }
        if(i > 0){       //Si hay registros para mostrar

            printf("\n\nCantidad de dias mostrados con mayor velocidad del viento: %d\n", i);

        }else{

            printf("\nNo hay registros para mostrar\n");

        }
          
    }
       
}

/*Lo que hace esta accion es recibir como parametro el nombre del archivo que va a ser el anio en el que se esta trabajando y la variale de tipo entero anio
que tiene almacenado el anio sobre el cual se esta trabajando. Esta accion sirve para crear una copia de seguridad de un archivo. La copia de seguridad 
va a contener todos los registros del archivo original, menos los que fueron suprimidos*/

void CopiaDeSeguridad (char nomArch[15], int anio){

    //Lexico Local
    
    FILE* f;    //Nombre interno del archivo
    FILE* g;     //Nombre interno del archivo copia
    int tam;       //Variable que sirve para almacenar el tamanio del archivo
    regDiario c;      //Variable que vamos a utilizar para manipular en el archivo
    int i;     //Variable que utilizamos para contabilizar la cantidad de registros que se guardan en la copia de seguridad
    char nomCopia[15];    //Variable que almacena el nombre de la copia de seguridad

    //Inicio
    
    f = fopen (nomArch, "a+b");      //Apertura del archivo en modo agregar archivos binarios
    fseek(f, 0, SEEK_END);      //Se situa el cursor al final del archivo
    tam = ftell(f);             //En tam se guarda el tamanio del archivo
    fseek(f, 0, SEEK_SET);     //Se situa el cursor al comienzo del archivo
    
    if (tam == 0){      //Si el archivo esta vacio

        printf("\nNo hay registros para hacer copia de seguridad");

    }else{      //Si el archivo no esta vacio

        i = 0;        //Se inicializa i en 0
        fread(&c, sizeof(c), 1, f);     //Se lee el registro y se guarda en la variable c
        while(!(feof(f))){      //Mientras no llegue al final del archivo

            if(c.borrado == 0){         //Si el registro no esta borrado logicamente

                i++;        //Se incrementa i en 1

            }
            fread(&c, sizeof(c), 1, f);    //Se lee el archivo y se guarda en la variable c
            
        }
        
        if(i > 0){

            fseek(f, 0, SEEK_SET); 
            strcat(strcpy(nomCopia, "Copia"), nomArch);     //Se concatena el nombre del archivo con la palabra "Copia"
            g = fopen (nomCopia, "w+b");     //Se crea el archivo de la copia
            i = 0;        //Se inicializa i en 0
            fread(&c, sizeof(c), 1, f);     //Se lee el registro y se guarda en la variable c
            while(!(feof(f))){      //Mientras no llegue al final del archivo

                if(c.borrado == 0){         //Si el registro no esta borrado logicamente
                    fwrite(&c, sizeof(c), 1, g);     //Se almacena en el archivo g lo que tiene guardado c
                    i++;        //Se incrementa i en 1

                }
                fread(&c, sizeof(c), 1, f);    //Se lee el archivo y se guarda en la variable c
            
            }
            printf("\nCopia creada");
            printf("\n\nCantidad de registros copiados: %d\n", i);
            fclose(g);      //Se cierra el archivo copia

        }else{

            printf("\nNo hay registros para hacer copia de seguridad\n");

        }
    
    }

    fclose(f);     //Se cierra el archivo original
    
}//Faccion

/*Esta accion lo que hace es, dado un arreglo y una posicion en el, mostrar cada campo de la posicion dada. En el caso de que la posicion no
exista en el arreglo, entonces no se mostrara ningun campo*/

void MostrarReg(TData a, int pos){
    
    if (pos != -1){     //Se encontro el registro

        //Se informa
        printf("\nEn el dia: %d", a.a[pos].ddmmyyyy);
        printf("\n- La temperatura maxima fue de %d grados", a.a[pos].tmax);
        printf("\n- La temperatura minima fue de %d grados", a.a[pos].tmin); 
        printf("\n- La humedad fue de %d g/m3", a.a[pos].hum);
        printf("\n- La presion atmosferica fue de %d atm", a.a[pos].pnm);
        printf("\n- La direccion del viento fue de %d grados", a.a[pos].dv);
        printf("\n- La velocidad del viento fue de %d km/h", a.a[pos].ff);
        printf("\n- Las precipitacion fue de %d mm", a.a[pos].pp);
        
    }else{      //Si no se encontro

        printf("\nEl registro diario no se encuentra en el archivo, ya sea porque no existe, porque fue suprimido o porque el archivo esta vacio\n");
    
    }
    
}