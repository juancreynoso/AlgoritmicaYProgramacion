#include <stdio.h>
#include <stdlib.h>
#define max 366
//Registro diario
typedef struct {
    long int ddmmyyyy;
    int tmax;
    int tmin;
    int HUM;
    int PNM;
    int DV;
    int FF;
    int PP;
    int borrado;
}TregDiario;

//arreglo
typedef struct {
    TregDiario n[max];
    int cant; 
}Tdata;

Tdata arraidAux;


//Lista
typedef struct Tnodo{
    TregDiario info;
    struct Tnodo *next;
}Tnodo;

char nombreFile[40];
char nombreCopiaSeg[40];

long int diaBuscado;
int i;
int pos;
int cant;
int esta;
int opcion;
int anio;
//Nos ayuda a tratar ddmmyyyy
typedef struct Tfecha{
    int dia;
    int mes;
}Tfecha;

// Accion para encontrar registros repetidos COMPILADA
void Repetido(char nomFile[40],long int diaIng,int *esta){
  //lexico      
TregDiario reg;
FILE *f;
//inicio
f = fopen(nomFile,"r+b");

    if((feof(f))){
        printf("secuencia vacia \n");
        *esta = 0;
    }else{
        fread(&reg,sizeof(reg),1,f);
        while((!feof(f))&& ((reg.ddmmyyyy!= diaIng) || (reg. borrado == 1))){
            fread(&reg,sizeof(reg),1,f);
            }
        if((reg.ddmmyyyy == diaIng) && (reg.borrado != 1)){
            *esta = 1;
        }else{
            *esta= 0;
        }
    }
fclose(f);
}
//accion necesaria para usar algunos metodos de ordenamiento
void Intercambiar(TregDiario *x ,TregDiario *y){
    TregDiario aux;
    aux = *x;
    *x = *y;
    *y = aux;
}
//con esta accion nos aseguramos de que exista el archivo para poder manipularlo correctamente
void Existe(char nomFile[40]){
    //lexico
    FILE *f;
    //inicio

    f = fopen(nomFile,"wb");
    if(f == NULL){
        fclose(f);
    }else{
        fclose(f);
    }

}


//accion para manipular correctamente la fecha
void transformarFecha (int anio, long int *fecha){
    //Pasamos el anio como dato
    //Lexico Local
    int acum;
    Tfecha dia;
    //Inicio
    printf("ingrese el dia\n");
    scanf("%d",&dia.dia);
    
    printf("ingrese el mes\n");
    scanf("%d",&dia.mes);
   
    //Verifico mes
    while(dia.mes<1 || dia.mes>12){
        printf("Mes no valido. Vuelva a ingresar el mes\n");
        scanf("%d",&dia.mes);
    }
    //mes correcto
    if(dia.mes>=1 && dia.mes<=12){
        //depende del mes me fijo el dia
        if(dia.mes==1 || dia.mes == 3 || dia.mes==5 || dia.mes==7 || dia.mes==8 || dia.mes==10 || dia.mes==12){
            if(dia.dia>=1 && dia.dia<=31){
                //fecha correcta
            }
            else{
                //fecha incorrecta, vuelve a ingresar fecha
                while(dia.dia<1 || dia.dia>31){
                    printf("Vuelva a ingresar el dia, fecha incorrecta \n");
                    scanf("%d",&dia.dia);
                }
            }
        }
        if(dia.mes==4 || dia.mes==6 || dia.mes==9 || dia.mes==11){
            if(dia.dia>=1 && dia.dia<=30){
                //fecha correcta
            }
            else{
                //fecha incorrecta, vuelva a ingresar la fecha
                while(dia.dia<1 || dia.dia>30){
                    printf("Vuelva a ingresar el dia, fecha incorrecta\n");
                    scanf("%d",&dia.dia);
                }
            }
        }
        if(dia.mes==2){
            if((anio%4 == 0) && (anio%100 != 0 || anio%400 ==0)){
                //anio bisiesto
                if(dia.dia>=1 && dia.dia <=29){
                    //fecha correcta
                }
                else{
                    //fecha incorrecta, vuelva a ingresar la fecha
                    printf("anio bisiesto, dia incorrecto. Por favor, ingrese un dia entre 1 y 29 \n");
                    while(dia.dia<1 || dia.dia>29){
                        printf("Vuelva a ingresar el dia, fecha incorrecta\n");
                        scanf("%d",&dia.dia);
                    }
                }
            }
            else{
                //anio no bisiesto
                if(dia.dia>=1 && dia.dia <=28){
                    //fecha correcta
                }
                else{
                    //fecha incorrecta, vuelva a ingresar la fecha
                    printf("anio no bisiesto, dia incorrecto. Por favor, ingrese un dia entre 1 y 28 \n");
                    while(dia.dia<1 || dia.dia>28){
                        printf("Vuelva a ingresar el dia, fecha incorrecta\n");
                        scanf("%d",&dia.dia);
                    }
                }
            }
        }
    }
    else{
        //ERROR mes no valido
        printf("Mes no valido");
    }
    *fecha = dia.dia*1000000 + dia.mes*10000 + anio;
}
// Accion cargar archivo
void cargarArchivo(char nomFile [40],int yyyy){
    //Lexico local
    TregDiario reg;
    int esta;
    int i;
    int n;
    FILE *f;
    //Inicio
    //Secuencia marca final R1
    //Inicializacion de la adquisicion
    i = 0;
    printf("Cuantos desea cargar?\n");
    scanf("%d",&n);
    //reviso que el numero ingresado sea correcto
    while(n>366 || n<1){
        printf("Ingrese un numero valido, entre 1 y 366\n");
        scanf("%d",&n);
    }
    //numero correcto
    //no fin de secuencia
    while(i<n){
        transformarFecha(yyyy,&reg.ddmmyyyy);
        Repetido(nomFile,reg.ddmmyyyy,&esta);
        
        while(esta == 1){
            printf("el dia ingresado esta en el archivo\n");
            printf("por favor ingrese uno nuevo\n");
            transformarFecha(yyyy,&reg.ddmmyyyy);
            Repetido(nomFile,reg.ddmmyyyy,&esta);
        }
       f= fopen(nomFile, "a+");
        printf("ingrese la temperatura maxima\n");
        scanf("%d",&reg.tmax);
        printf("ingrese la temperatura minima del dia cargado\n");
        scanf("%d",&reg.tmin);
        printf("ingrese el porcentaje de humedad\n");
        scanf("%d",&reg.HUM);
        while(reg.HUM>100|| reg.HUM<0){
            printf("ingrese valores validos entre 0 y 100 del porcentaje de humedad\n");
            scanf("%d",&reg.HUM);
        }
        printf("ingrese la presion atmosferica del dia cargado debe ser un valor entre 900 y 3500\n");
        scanf("%d",&reg.PNM);
        while(reg.PNM>3500 || reg.PNM <900){
            printf("por favor ingrese un valor valido entre 3500 y 900\n");
            scanf("%d",&reg.PNM);
        }
        printf("ingrese la direccion del viento cuando se produjo el maximo registro del dia\n");
        scanf("%d",&reg.DV);
        while(reg.DV>360 || reg.DV<0){
            printf("por favor ingrese un valor valido entre 0 y 360\n");
            scanf("%d",&reg.DV);
        }
        printf("ingrese la velocidad maxima del viento del dia ingresado \n");
        scanf("%d",&reg.FF);
        printf("ingrese las precipitaciones del dia ingresado\n");
        scanf("%d",&reg.PP);
        while(reg.PP>1000 || reg.PP<0){
            printf("por favor ingrese un valor valido entre 0 y 1000\n");
            scanf("%d",&reg.PP);
        }
        reg.borrado = 0;
        fwrite(&reg,sizeof(reg),1,f);
        i = i+1;
       fclose(f);
       }
    
}


//Opcion 1 COMPILADA

void Alta(char nomFile[40],int anio){
    //lexico
    FILE *f;
    TregDiario reg;
    int esta;
    
    //inicio
    printf("proceda a ingresar la fecha de su registro\n");
    transformarFecha(anio,&reg.ddmmyyyy);
    Repetido(nomFile,reg.ddmmyyyy,&esta);
    while(esta == 1){
        printf("el dia ingresado esta en el archivo por favor ingrese uno nuevo\n");
        printf("\n");
        transformarFecha(anio,&reg.ddmmyyyy);
        Repetido(nomFile,reg.ddmmyyyy,&esta);
    }
    f = fopen(nomFile,"a");
    
    
    printf("ingrese la temperatura maxima\n");
    scanf("%d",&reg.tmax);
    

    printf("ingrese la temperatura minima del dia cargado\n");
        scanf("%d",&reg.tmin);

    printf("ingrese el porcentaje de humedad\n");
        scanf("%d",&reg.HUM);
    
    while(reg.HUM>100|| reg.HUM<0){     
        printf("ingrese valores validos entre 0 y 100 del porcentaje de humedad\n");
        scanf("%d",&reg.HUM);
    }
    printf("ingrese la presion atmosferica del dia cargado debe ser un valor entre 900 y 3500\n");
        scanf("%d",&reg.PNM);
    
    while(reg.PNM>3500 || reg.PNM <900){
        printf("por favor ingrese un valor valido entre 3500 y 900\n");
        scanf("%d",&reg.PNM);
    }
    
    printf("ingrese la direccion del viento cuando se produjo el maximo registro del dia\n");
        scanf("%d",&reg.DV);
    
    while(reg.DV>360 || reg.DV<0){
            printf("por favor ingrese un valor valido entre 0 y 360\n");
            scanf("%d",&reg.DV);
    }
    printf("ingrese la velocidad maxima del viento del dia ingresado \n");
        scanf("%d",&reg.FF);

    printf("ingreselas precipitaciones del dia ingresado\n");
        scanf("%d",&reg.PP);
    
    while(reg.PP>1000 || reg.PP<0){
            printf("por favor ingrese un valor valido entre 0 y 1000\n");
            scanf("%d",&reg.PP);
    }
    
    reg.borrado = 0;
    fwrite(&reg,sizeof(reg),1,f);

fclose(f);

}
//opcion 2
void Suprimir(char nomFile[40],int yyyy){
    //lexico
    FILE* f;
    TregDiario reg;
    long int dia;

    //inicio
    f = fopen(nomFile,"r+b");
   
    if(f == NULL){
      printf("error no hay archivos para eliminar\n");
     }else{
        printf("proceda a escribir los datos del dia que quiere eliminar\n");
        transformarFecha(yyyy,&dia);
        
        fread(&reg,sizeof(reg),1,f);
        while((!feof(f))&&(dia!=reg.ddmmyyyy || reg.borrado == 1)){
            fread(&reg,sizeof(reg),1,f);
        }

        if((reg.ddmmyyyy == dia) && (reg.borrado != 1)){
            reg.borrado = 1;
            fseek(f,-sizeof(reg),SEEK_CUR);
            fwrite(&reg,sizeof(reg),1,f);     
            printf("hecho\n");
        }else{
            printf("dia no encontrado\n");
        }
    }
    fclose(f);
}
//opcion 3 
void Modificar(int diaB,char nomFile[40]){
    //lexico
    FILE *f;
    TregDiario reg;
    int opcion;
    //inicio
    f = fopen(nomFile,"r+b");
    if(feof(f)){
         printf("error secuencia vacia\n");
    }
    else{
        fread(&reg,sizeof(reg),1,f);
        while((!feof(f))&&(diaB!=reg.ddmmyyyy || reg.borrado != 0)){
            fread(&reg,sizeof(reg),1,f);
        }
        if(reg.ddmmyyyy == diaB){
            if(reg.borrado != 1){
                //Posicion anterior
                fseek(f,-sizeof(reg),SEEK_CUR);
                while(opcion!=9){
                printf("¡que desea modificar de su dia cargado?\n");
                printf("\n");
                printf("Presione 1 si desea modificar la temperatura maxima\n");
                printf("Presione 2 si desea modificar la temperatura minima\n");
                printf("Presione 3 si desea modificar el porcentaje de humedad\n");
                printf("Presione 4 si desea modificar la presion atmosferica\n");
                printf("Presione 5 si desea modificar la direccion del viento\n");
                printf("Presione 6 si desea modificar la velocidad del viento\n");
                printf("Presione 7 si desea modificar la precipitacion pluviar acumulada\n");
                printf("Presione 8 si desea modificar su borrado\n");
                printf("Presione 9 si desea salir \n");
                scanf("%d",&opcion);
                if(opcion == 1){
                    printf("ingrese la temperatura maxima\n");
                    scanf("%d",&reg.tmax);
                }
                if(opcion == 2){
                    printf("ingrese la temperatura minima\n");
                    scanf("%d",&reg.tmin);
                }

                if(opcion == 3){
                    printf("ingrese el porcentaje de humedad\n");
                    scanf("%d",&reg.HUM);
                    while((reg.HUM>100) || (reg.HUM<0)){
                        printf("por favor ingrese valores validos entre 0 y 100\n");
                    }
                }
                if(opcion == 4){                    
                    printf("ingrese la presion atmosferica\n");
                    scanf("%d",&reg.PNM);                       
                    while((reg.PNM <900)||(reg.PNM>3500)){
                        printf("por favor ingrese valores posibles entre 900 y 3500\n");
                        scanf("%d",&reg.PNM);
                    }
                }
                if(opcion == 5){
                    printf("ingrese la direccion del viento\n");
                    scanf("%d",&reg.DV);                    
                    while((reg.DV>360) || (reg.DV<0)){
                        printf("ingrese valores validos entre 360 y 0\n");
                        scanf("%d",&reg.DV);
                    }
                }
                if(opcion == 6){
                    printf("ingrese la velocidad del viento\n");
                    scanf("%d",&reg.FF);
                }
                if(opcion == 7){
                    printf("ingrese el nuevo registro pluvial\n");
                    scanf("%d",&reg.PP);                        
                    while(reg.PP>1000 || reg.PP<0){
                        printf("ingrese valores validos entre 1000 y 0\n");
                        scanf("%d",&reg.PP);
                    }
                }
                if(opcion == 8){
                    printf("ingrese su nuevo valor de borrado \n");
                    printf("ingrese 1 si desea que el registro se elimine, ingrese 0 si desea que \n");
                    scanf("%d",&reg.borrado);                    
                    while((reg.borrado <0) || (reg.borrado > 1)){
                        scanf("%d",&reg.borrado);
                    }
                }            
                printf("hecho!\n");
                printf("\n");
                }
            }
            else{
            printf("no se encuentra el registro ha sido borrado\n");
            }
        
        }
        else{
            printf("Registro inaccesible\n");
        }
        fwrite(&reg,sizeof(reg),1,f);
        fclose(f);
    }
}
//Opcion 4
void Mostrar(char nomFile[]){
    //lexico
    TregDiario reg;
    FILE *f;
    int tamArchivo;
    //inicio
    
    f = fopen(nomFile,"rb");
    fseek(f,0,SEEK_END);
     tamArchivo = ftell(f);
     fclose(f);
     f = fopen(nomFile,"r");   
    if(tamArchivo == 0){
            printf("el archivo esta vacio no hay elementos que mostrar\n");
    }else{
           fread(&reg,sizeof(reg),1,f);
    
                while(!feof(f)){
        
                if(reg.borrado !=1){
                printf("\n");
                printf("dia/mes/anio %ld \n", reg.ddmmyyyy);
                printf("temperatura maxima %d \n", reg.tmax);
                printf("temperatura minima %d \n", reg.tmin);
                printf("porcentaje de humedad %d \n", reg.HUM);
                printf("presion atmosferica %d\n",reg.PNM);
                printf("direccion del viento %d \n", reg.DV);
                printf("velocidad del viento %d \n", reg.FF);
                printf("registro pluvial diario %d \n", reg.PP);
                printf("\n");
        
                }else{
                    printf("registro borrado\n");
                }
                fread(&reg,sizeof(reg),1,f); 
                }
            } 
    fclose(f);
}

void tranfArraid(char nomFile[40],Tdata *arr){
    //lexico
    FILE *f;
    int i;
    TregDiario reg;
    //HACER CON SECUENCIA VACIA
    //inicio
    arr->cant = 0;
    i = 0;
    f = fopen(nomFile,"r+b");
   
    while(!feof(f)){
         fread(&reg,sizeof(reg),1,f);
         if(reg.borrado != 1){
            arr->n[i] = reg;
            i = i+1;
            arr->cant = arr->cant + 1;
        }
    }
fclose(f);
}

int Busc(Tdata a,int i,int diaBusc){

    if(i == a.cant ){
        return  -1;
    }else{
        if(a.n[i].ddmmyyyy == diaBusc){
            return i;
        }else{
        
            i = i+1;
            return Busc(a,i,diaBusc);
        }
    }

}

//opcion 6
void MaxTemperaturas(char nomFile [40]){
    struct Tnodo *s;
    struct Tnodo *a1;
    struct Tnodo *a2;
    FILE *f;
    TregDiario acum;
    TregDiario reg;
   
    f = fopen(nomFile,"r+b");
   
    if(feof(f)){
        printf("secuencia vacia \n");
    }else{
        fread(&reg,sizeof(reg),1,f);
        while((!feof(f))&&(reg.borrado !=0)){
            fread(&reg,sizeof(reg),1,f);
        }
        if(reg.borrado != 1){
             acum = reg;
              while(!feof(f)){
                fread(&reg,sizeof(reg),1,f);
                if(reg.tmax > acum.tmax){
                    acum = reg;
                }   
            }
        
            fseek(f,0,SEEK_SET);
                s = (Tnodo *) malloc (sizeof(Tnodo));
                s->next = NULL;
                a1 = s;
            fread(&reg,sizeof(reg),1,f);
            while(!feof(f)){
                 if(reg.tmax == acum.tmax){
                    a2 = (Tnodo *) malloc(sizeof(Tnodo));
                    a2->info = reg;
                    a2->next = a1->next;
                    a1->next = a2;
                    a1 = a1->next;
                }
            fread(&reg,sizeof(reg),1,f);
            }
            fclose(f);
            a1 = s->next;
            while(a1!=NULL){
                if(a1->info.borrado != 1){
                    printf(" dia: %ld \n",a1->info.ddmmyyyy);
                    printf(" temperatura: %d\n",a1->info.tmax);
                }
                a1 = a1->next;
            
            }
        }else{
            printf("registros eliminados \n");
        }
    }
}

//opcion 7
void MayorPrecipitacion(char nomFile[]){
    //lexico local
    FILE*  f;
    Tdata arr;
    TregDiario aux; 
    int j;
    int i;
    TregDiario reg;
    int tamArchivo; 
    
    //inicio
    f = fopen(nomFile,"r+b");
    fseek(f,0,SEEK_END);
    tamArchivo = ftell(f);
    fseek(f,0,SEEK_SET);
       
    fread(&reg,sizeof(reg),1,f);
        while((!feof(f))&&(reg.borrado !=0)){
            fread(&reg,sizeof(reg),1,f);
        }
     
     if((tamArchivo == 0) || (reg.borrado != 0)){
        printf("archivo vacio\n");
     }else{
        fseek(f,0,SEEK_SET);
        arr.cant = 0;
        i = 0;
        fread(&reg,sizeof(reg),1,f);
        while(!feof(f)){
           if(reg.borrado != 1){
                arr.n[i] = reg;
                i = i+1;
                arr.cant = arr.cant + 1;
            }
         fread(&reg,sizeof(reg),1,f);
        }
        //usamos insercion sort
        if(arr.cant>=1){
            i=1;
            while(i<=arr.cant){
                aux = arr.n[i];
                j = i-1;
                while((j>-1) && (arr.n[j].PP) > (aux.PP)){
                    arr.n[j+1] = arr.n[j];
                    j=j-1;
                }
                arr.n[j+1] = aux;
                i = i+1;
            }
            i = arr.cant;
            while((i>=1) && (i!= arr.cant -10)){
                if(arr.n[i].borrado != 1){
                    printf("dia %ld\n",arr.n[i].ddmmyyyy);
                    printf("precipitacion %d\n",arr.n[i].PP);
                }
                i = i-1;
            }   
        }else{
            i = arr.cant;
            if(arr.n[i].borrado != 1){
                printf("dia %ld\n",arr.n[i].ddmmyyyy);
                printf("precipitacion %d\n",arr.n[i].PP);
            }
        }   
    }
    
}
//opcion 8
void fechasMayorViento(char nomFile [40]){
    //lexico
    Tdata arr;
    int i;
    int j;
    TregDiario reg;
    FILE *f;
    //inicio
    i = 0; 
    arr.cant = 0;
    f = fopen(nomFile,"r+b");
    
    fread(&reg,sizeof(reg),1,f);
    while((!feof(f))&&(reg.borrado !=0)){
        fread(&reg,sizeof(reg),1,f);
    }

    if(reg.borrado != 0){
        printf("secuencia vacia\n");
    }else{ 
        fseek(f,0,SEEK_SET);
        fread(&reg,sizeof(reg),1,f);
        while((!feof(f))){
             if(reg.borrado != 1){
                arr.n[i] = reg;
                i = i+1;
                arr.cant = arr.cant + 1;
            }
            fread(&reg,sizeof(reg),1,f);
         }

         //usamos bubblesort
         i = arr.cant-1;
    
         while(i>0){
             j=0;
            
            while(j<i){
                if(arr.n[j].FF < arr.n[j+1].FF){
                    Intercambiar(&arr.n[j],&arr.n[j+1]);
                }
                j = j+1;
            }
            
            i = i-1;
        }
        i = 0;
        while((i<arr.cant) && (i<10)){
            printf("las fechas de mayor viento son %ld \n",arr.n[i].ddmmyyyy);
            printf("velocidad de viento %d \n",arr.n[i].FF);
            i = i+1;
        }
    }
}

//opcion 9
void CopiaDeSeg(char nomFile[40],char nomCopia[40]){
    //lexico local
    FILE *copiaSeg;
    FILE *f;
    TregDiario reg;
    int tamArchivo;
    int opcion;
   
   //inicio
    f = fopen(nomFile,"r+b");
    copiaSeg = fopen(nomCopia,"w");
    fread(&reg,sizeof(reg),1,f);
    while(!feof(f)){
        
        if(reg.borrado != 1 ){
            fwrite(&reg,sizeof(reg),1,copiaSeg);
        }
    fread(&reg,sizeof(reg),1,f);
    }
        fclose(f);
        fclose(copiaSeg);
        
        printf("copia de seguridad realizada\n");
        printf("\n");
        printf("¿desea mostrarla? \n");
        printf("presione 1 para si y 0 para no\n");
        scanf("%d",&opcion);
        
        while(opcion != 1 && opcion != 0){
            printf("por favor numeros validos\n");
            printf("presione 1 para si y 0 para no\n");
        }
        if(opcion == 1){
            copiaSeg = fopen(nomCopia,"rb");
            fseek(copiaSeg,0,SEEK_END);
            tamArchivo = ftell(copiaSeg);
            if(tamArchivo == 0){
                printf("copia de seguridad vacia\n");
            }else{
                fseek(copiaSeg,0,SEEK_SET);
                fread(&reg,sizeof(reg),1,copiaSeg);
            while(!feof(copiaSeg)){
                printf("\n");
                printf("dia/mes/anio %ld \n", reg.ddmmyyyy);
                printf("temperatura maxima %d \n", reg.tmax);
                printf("temperatura minima %d \n", reg.tmin);
                printf("porcentaje de humedad %d \n", reg.HUM);
                printf("presion atmosferica %d\n",reg.PNM);
                printf("direccion del viento %d \n", reg.DV);
                printf("velocidad del viento %d \n", reg.FF);
                printf("registro pluvial diario %d \n", reg.PP);
                printf("\n");
                fread(&reg,sizeof(reg),1,copiaSeg);
             }
            fclose(copiaSeg);
        }
    }

}


 void obtenerYEAR(char nomFile[40],int *anio){
    //lexico
    Tfecha dia;
    FILE *f;
    TregDiario reg;
     long int tamArchivo; 
    
    f = fopen(nomFile,"r+b");
    fread(&reg,sizeof(reg),1,f);
    if(!feof(f)){
        dia.dia = reg.ddmmyyyy/1000000;
        dia.mes = reg.ddmmyyyy/10000 -(dia.dia *100);
        *anio = reg.ddmmyyyy - (dia.dia*1000000)-(dia.mes*10000);
    }else{
        printf("archivo vacio ingrese el anio con el que desea trabajar \n");
        scanf("%d",&(*anio));
    }
    fclose(f);
}
int main(){
    
    printf("\n");
    printf("Ingrese el nombre del archivo \n");
    scanf("%s",nombreFile);
    Existe(nombreFile);
    obtenerYEAR(nombreFile,&anio);
   
   printf("¿desea cargar el archivo ?\n");
    printf("ingrese 1 si desea cargarlo o cualquier otro numero para no\n");
    scanf("%d",&opcion);
    
    if (opcion == 1){
        cargarArchivo(nombreFile,anio);
    }
    
    opcion=1;
    while(opcion!=10){
        //Menu de opciones
        printf("Presione 1 si desea cargar un registro\n");
        printf("Presione 2 si desea suprimir un registro\n");
        printf("Presione 3 si desea modificar un registro\n");
        printf("Presione 4 si desea mostrar todos los registros activos\n");
        printf("Presione 5 si desea buscar un registro y mostrar sus datos\n");
        printf("Presione 6 si desea listar el dia o los dias de mayor temperatura segun los registros cargados\n");
        printf("Presione 7 si desea listar el dia o los dias de maxima precipitacion segun los registros cargados\n");
        printf("Presione 8 si desea listar las fechas de mayor a menor velocidad de viento\n");
        printf("Presione 9 si desea hacer una copia de seguridad del archivo\n");
        printf("Presione 10 si desea salir \n");
        printf("\n");
        scanf("%d",&opcion);
        //Alta
        if(opcion == 1){
            Alta(nombreFile,anio);
        }
        //Suprimir
        if(opcion == 2){
            Suprimir(nombreFile, anio);
        }
        //Modificar
        if(opcion == 3){
            printf("ingrese la fecha que desea buscar\n");
            transformarFecha(anio,&diaBuscado);
            Modificar(diaBuscado, nombreFile);
        }
        //mostrar
        if(opcion == 4){
            Mostrar(nombreFile);
        }
        //Buscar
        if(opcion == 5){
            tranfArraid(nombreFile,&arraidAux);
            printf("proceda a ingresar la fecha que desea buscar\n");
            transformarFecha(anio,&diaBuscado);
           
            pos = Busc(arraidAux, 0, diaBuscado);
            if((pos!=-1) &&(arraidAux.n[pos].borrado != 1)){
                printf("\n");
                printf("dia/mes/anio %ld \n", arraidAux.n[pos].ddmmyyyy);
                printf("temperatura maxima %d \n", arraidAux.n[pos].tmax);
                printf("temperatura minima %d \n", arraidAux.n[pos].tmin);
                printf("porcentaje de humedad %d \n", arraidAux.n[pos].HUM);
                printf("presion atmosferica %d\n",arraidAux.n[pos].PNM);
                printf("direccion del viento %d \n", arraidAux.n[pos].DV);
                printf("velocidad del viento %d \n", arraidAux.n[pos].FF);
                printf("precipitacion pluvial %d \n", arraidAux.n[pos].PP);
                printf("\n");
            }
            else{
                printf("No se encuentra el registro diario\n");
            }           
        }
        //MaxTemp
        if(opcion==6){
            MaxTemperaturas(nombreFile);
        }
        //MayorPrep
        if(opcion==7){
            MayorPrecipitacion(nombreFile);
        }
        //Mayor a menor Viento
        if(opcion==8){
            fechasMayorViento(nombreFile);          
        }
        //Copia de Seg
        if(opcion==9){
            printf("Ingrese el nombre de la copia de seguridad\n");
            scanf("%s", nombreCopiaSeg);
            CopiaDeSeg(nombreFile, nombreCopiaSeg);
        }
    }
return 0;
}