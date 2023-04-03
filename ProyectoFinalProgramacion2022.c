#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 400

typedef struct {
    int ddmmyyyy;
    int tmax;
    int tmin;
    int HUM;
    int PNM;
    int DV;
    int FF;
    int borrado;
    int PP;
} RegDiario;

typedef struct {
    RegDiario a[Max];
    int cant;
} TData;

typedef struct TNodo {
    RegDiario info; 
    struct TNodo *next;
} TNodo;

char nomArch[20]; //se guarda el año con extension .dat
char arch[20]; // Se guarda el año en string
int anio;

int Buscar(TData s, int i, int fecha);
int esBisiesto(int x);
int Vacia(TData s);
void DeArchivoAArreglo(FILE *f,TData *s);
void DeArchivoALista(FILE* f, TNodo *p);
void SolicitarFecha( int *fecha);
void AltaRegDiario(FILE* f);
void SuprRegDiario(FILE* f);
void MostrarRegAct(FILE *f);
void ModifRegDiario(FILE *f);
void inicializar(TNodo** list);
void Insertar(TNodo* p, RegDiario elem);
void CopiaDeSeguridad(FILE *f, FILE *g);
void ListarMaxTemp(TNodo *p, FILE* f);
void MostrarPP(TData *s, FILE *f);
void OrdenarPP(TData *s);
void InfoParametros(FILE *f); 
void OrdenarFF(TData *s);
void MostrarFF(FILE *f, TData s);
void cargarReg(RegDiario *reg);
void CrearArch(char arch[20]);

int main() {
    FILE* g;
    FILE* h; //Archivo de respaldo
    TData s;
    TNodo *list;
    int eleccion;  

    while ((eleccion != 1) && (eleccion != 2)) {
        printf("Elija una opcion: \n");
        printf("1. Cargar nuevo archivo (Si ya existe se sobrescribira)\n");
        printf("2. Cargar archivo existente\n");
        scanf("%d", &eleccion);
    }

    if (eleccion == 1) {
        do {
            printf("Escribe el año del nuevo archivo: ");
            scanf("%s", arch);
            anio = strtol(arch, NULL, 10);
        } while (!((anio >= 1700) && (anio <= 2022)));
        
        if ((anio >= 1700) && (anio <= 2022)) {
            strcpy(nomArch, strcat(arch, ".dat"));
            CrearArch(nomArch);
            printf("El archivo %s ha sido creado!\n", nomArch);
        }
    } else {
        printf("Escribe el año del archivo existente: ");
        scanf("%s", arch);
        strcpy(nomArch, strcat(arch, ".dat"));
        printf("El archivo %s fue cargado!\n", nomArch);
    }

    while (eleccion != 10) {
        fflush(stdin);
        printf("\nQue accion desea realizar?\n1. Alta de un registro diario\n2. Suprimir un registro diario\n3. Modificar un registro\n4. Mostrar todos los registros activos\n5. Buscar registro y mostrar parametros\n6. Listar dias de maxima temperatura en el año\n7. Listar dias de maxima precipitacion en el año\n8. Listar dias de mayor velocidad del viento\n9. Realizar copia de seguridad\n10. Salir\n");
        scanf("\n%d", &eleccion);

        if (eleccion == 1) { //Se agrega un registro al archivo. 
            AltaRegDiario(g);//Anda Bien
        } 
        else {
            if(eleccion == 2) { //Se elimina un registro del archivo. 
                SuprRegDiario(g); //Anda bien
            }
            else {
                if(eleccion == 3) { //Modifica un archivo, se busca por fecha 
                    ModifRegDiario(g);
                }
                else {
                    if(eleccion == 4) { // Mostrar todos todos los registros activos
                        MostrarRegAct(g);   //Anda Bien
                    }
                    else {
                        if (eleccion == 5) {  //Buscar registro de un día dado y mostrar todos los parámetros
                            InfoParametros(g);
                        }
                        else {
                            if(eleccion == 6) { //Listar el día o días de máxima temperatura en lo que va del año
                                inicializar(&list);
                                ListarMaxTemp(list, g);//Anda Bien
                            } 
                            else {
                                if(eleccion == 7) { //Listar el día o días de máxima precipitación en lo que va del año
                                    MostrarPP(&s, g);
                                } 
                                else {
                                    if(eleccion == 8) { //Listar las fechas de mayor a menor velocidad de viento
                                        MostrarFF(g, s);
                                    } 
                                    else {
                                        if(eleccion == 9) { //Realizar una copia de seguridad del archivo del año en curso
                                            CopiaDeSeguridad(g, h);
                                        }
                                        else {
                                            if(eleccion == 10) { //Salir 
                                                printf("Usted salio del menu con exito.\n");
                                                exit(-1);
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
    }
    return 0;
}

void SolicitarFecha(int *fecha) {
    int mes; 
    int dia; 

    *fecha = 0; 

    do {
        printf("Mes: ");
        scanf("%d",&mes);
    } while (!((1 <= mes) && (mes <= 12 )));

    if (mes == 2 ) {
        if (esBisiesto(anio)==0) {
            do {
                printf("Dia: ");
                scanf("%d",&dia);
            } while (!((1 <= dia) && (dia <= 28)));
        } 
        else {
            do {
                printf("Dia: ");
                scanf("%d",&dia);
            } while (!((1 <= dia) && (dia <= 29)));
        }
    }
    else 
    {
        if ((mes == 6)||(mes == 9)||(mes == 11)) {
            do {
                printf("Dia: ");
                scanf("%d",&dia);
            } while (!((1 <= dia) && (dia <= 30)));
        }       
        else {
            do {
                printf("Dia: ");
                scanf("%d", &dia);
            } while (!((1 <= dia) && (dia <= 31)));
        }
    } 
    
    dia = dia * 1000000;
    mes = mes * 10000;
    *fecha = dia + mes + anio ;
}

int esBisiesto(int x) {
    if (((x % 4 == 0) && (x % 100 != 0)) || ((x % 100 == 0) && (x % 400 == 0))) {
        return 1;      
    } else {
        return 0;
    }
}

void cargarReg(RegDiario *reg) {
    int fecha;
    
    printf("Ingrese los siguientes datos: \n");
    SolicitarFecha(&fecha);
    reg->ddmmyyyy = fecha;
    
    printf("Temperatura maxima: ");
    scanf("%d", &reg->tmax);
    fflush(stdin);       
    
    do {
        printf("Temperatura minima: ");
        scanf("%d", &reg->tmin);
        fflush(stdin);       
    } while (!((reg->tmin)<(reg->tmax)));
    
    do {
        printf("Humedad: ");
        scanf("%d", &reg->HUM);
        fflush(stdin);
    } while (!((0 < reg->HUM) && (reg->HUM < 100)));

    do {
        printf("Presion atmosferica (Desde 900 hasta 3500): "); //900 y 350
        scanf("%d", &reg->PNM);
        fflush(stdin);
    } while(!((900 < reg->PNM) && (reg->PNM < 3500)));

    do {
        printf("Direccion del viento: "); // 0< dv< 360
        scanf("%d", &reg->DV);
        fflush(stdin);
        
    } while (!((reg->DV>0)&&(reg->DV<360)));
    
    do {
        printf("Velocidad del viento: ");
        scanf("%d", &reg->FF);
        fflush(stdin);
        
    } while (!(reg->FF > 0));
    
    
    printf("Precipitacion pluvial: ");
    scanf("%d", &reg->PP);
    reg->borrado = 0;
}

void AltaRegDiario(FILE* f) {
    RegDiario reg;
    RegDiario reg2;
    //TData s;

    f = fopen(nomArch, "rb");
    cargarReg(&reg);
    
    fread(&reg2, sizeof(reg2), 1, f);
    while (!(feof(f)) && ((reg.ddmmyyyy != reg2.ddmmyyyy) || reg2.borrado == 1)) {  
        fread(&reg2, sizeof(reg2), 1, f);
    
    }
    fclose(f);
    f = fopen(nomArch, "ab");
    if (reg.ddmmyyyy != reg2.ddmmyyyy) {
        fwrite(&reg, sizeof(reg), 1, f);
        printf("\nRegistro cargado!");
    } else {
        printf("Ya existe un registro con esta fecha.");
    }
    fclose(f); 
}

//PreCond: i=0
int Buscar(TData s, int i, int fecha) {
    if (i > s.cant) {
        return(-1);
    }
    else {
        if ((s.a[i].ddmmyyyy == fecha) && (s.a[i].borrado == 0)) {
                return(i);
        }
        else {
            return (Buscar(s, (i+1),fecha));
        }
    } 
}

void SuprRegDiario(FILE* f) {
    RegDiario reg;
    int fecha;

    f = fopen(nomArch, "r+b");
    printf("Ingrese la fecha del registro que quiere eliminar: \n");
    SolicitarFecha(&fecha);

    while (!(feof(f)) && ((reg.ddmmyyyy != fecha) || (reg.borrado == 1))) {
        fread(&reg, sizeof(reg), 1, f);
    }

    if (reg.ddmmyyyy == fecha) {
        reg.borrado = 1;
        fseek(f, ftell(f)-sizeof(reg), 0);
        fwrite(&reg, sizeof(reg), 1, f);
        printf("Registro eliminado!");
    } else {
        printf("No existe el registro.");
    }
    fclose(f);
}

void MostrarRegAct(FILE *f) {
    RegDiario reg;

    f = fopen(nomArch, "rb");
    fseek(f, 0, SEEK_END);

    if (ftell(f) == 0) { 
        printf("Archivo sin registros cargados.");
    } else {
        fseek(f, 0, SEEK_SET);
        fread(&reg, sizeof(reg), 1, f);
        int i = 1;
        while (!(feof(f))) {
            if (reg.borrado == 0) {
                printf("\nRegistro %d: ", i);
                printf("\nFecha: %d\n", reg.ddmmyyyy);
                printf("Temperatura maxima: %d\n", reg.tmax);
                printf("Temperatura minima: %d\n", reg.tmin);
                printf("Direccion del viento: %d\n", reg.DV);
                printf("Velocidad del viento: %d\n", reg.FF);
                printf("Presion atmosferica: %d\n", reg.PNM);
                printf("Precipitacion pluvial: %d\n", reg.PP);
                printf("Humedad: %d\n", reg.HUM);
                i++;
            }
            fread(&reg, sizeof(reg), 1, f);
        }
    }
    fclose(f); 
}

void ModifRegDiario(FILE *f) {
    RegDiario reg;
    TData s;
    int pos;
    int fecha;
    
    DeArchivoAArreglo(f, &s);
    SolicitarFecha(&fecha);
    pos = Buscar(s, 0, fecha);
    
    if (pos == -1) {
        printf("No existe el registro.");
    } else {
        f = fopen(nomArch, "r+b");
        cargarReg(&reg);
        fseek(f, pos*(sizeof(reg)), 0);
        fwrite(&reg, sizeof(reg), 1, f);
        fclose(f); 
    }
}

void DeArchivoAArreglo(FILE *f, TData *s) {
    int i;
    RegDiario reg;

    f = fopen(nomArch, "rb");

    s->cant = 0;
    i = 0;
    fread(&reg, sizeof(reg), 1, f);
    while (!(feof(f))) { 
        s->a[i] = reg;
        s->cant++;
        i++;
        fread(&reg, sizeof(reg), 1, f);
    }
    fclose(f);
}

void inicializar(TNodo** list) {
    //lexico local
    TNodo* aux;
    //inicio
    aux = malloc(sizeof(TNodo));
    aux->next = NULL;
    (*list) = aux;
}

void DeArchivoALista(FILE* f, TNodo *p) {
    RegDiario reg;
    int max;
    
    f = fopen(nomArch, "rb");
    max = 0;
    
    while (!(feof(f))) {
        fread(&reg, sizeof(reg), 1, f);
        if (reg.tmax >= max) {
            max = reg.tmax;
        }
    }
    fseek(f, 0, SEEK_SET );
    fread(&reg, sizeof(reg), 1, f);
    while (!(feof(f))) {
        if (reg.tmax == max) {
            Insertar(p, reg);
        }
        fread(&reg, sizeof(reg), 1, f);
    }
    fclose(f);
}

void Insertar(TNodo* p, RegDiario elem) {
    TNodo* aux;
    TNodo* a2;
    aux = p;
    while (aux->next != NULL) {
        aux = aux->next;
    }
    a2 = (TNodo*)malloc(sizeof(TNodo));
    a2->info = elem;
    a2->next = aux->next;
    aux->next = a2;
}

void ListarMaxTemp(TNodo *p, FILE* f) { 
    TNodo* rec;

    DeArchivoALista(f, p);
    rec = p->next;

    f = fopen(nomArch, "rb");
    fseek(f, 0, SEEK_END);

    if (ftell(f) == 0) {
        printf("Archivo sin registros cargados."); 
    } else {
        printf("Mostrando maximas temperaturas...\n");
        while (rec != NULL) {
            if (rec->info.borrado == 0) {
                printf("Maxima temperatura (%d°), fecha: %d\n",rec->info.tmax, rec->info.ddmmyyyy); 
            } 
            rec = rec->next;
        }
    }  
}

void MostrarPP(TData *s, FILE *f) { //Muestra las precipitaciones
    int i, j, k;
    
    DeArchivoAArreglo(f, s);
    OrdenarPP(&(*s));

    f = fopen(nomArch, "rb");
    fseek(f, 0, SEEK_END);

    if (ftell(f) == 0) {
        printf("Archivo sin registros cargados.");      
    } else {
        i = s->cant-1;
        j = 0;
        k = 10; 
        printf("Mostrando maximas precipitaciones...\n");
        while ((j < k) && (i >= 0)) {
            if (s->a[i].borrado == 0) {
                printf("Maxima precipitacion [%d](%d mm), fecha: %d \n", j+1, s->a[i].PP, s->a[i].ddmmyyyy);
                j++;
            }
            i--;
        }
    } 
}

void OrdenarFF(TData *s) { //Ordenamiento de viento por BubbleSort
    int i, j;
    RegDiario aux; 

    i = 0;
    while (i < s->cant) {
        j = s->cant;
        while (j >= i) {
            if ((s->a[j].FF) > (s->a[j-1].FF)) {   
                aux = s->a[j];
                s->a[j] = s->a[j-1]; 
                s->a[j-1] = aux;
            }
            j--;
        }
        i++;
    }    
}                           

void MostrarFF(FILE *f, TData s) { //Muestra los 10 mayores valores de velocidad de viento de mayor a menor
    int i, j;

    DeArchivoAArreglo(f, &s);
    OrdenarFF(&s);
    i = 0;
    j = 1;

    f = fopen(nomArch, "rb");
    fseek(f, 0, SEEK_END);

    if (ftell(f) == 0) {
        printf("Archivo sin registros cargados.");
    } else 
        {
            printf("Mostrando maximas velocidades de viento...\n");
            int k = i;
            while (((k < 10) && (i < s.cant))) {
                if (s.a[i].borrado == 0) {
                    printf("Maxima velocidad de viento [%d]: %d km/h\n", j, s.a[i].FF);
                    j++;
                    k++;
                }
                i++;
            }
        }
}

void OrdenarPP(TData* s) { //Ordenamiento de precipitaciones con InsercionSort
    int i, j;
    RegDiario aux; 
 
    i = 1 ;
    while (i < s->cant){
        aux = s->a[i]; 
        j = i - 1;
        while ((j >= 0 )&&(s->a[j].PP > aux.PP)){
            s->a[j+1] = s->a[j];
            j--;
        }
        s->a[j+1] = aux; 
        i++;        
    } 
}

void InfoParametros(FILE *f) { //Falta informar 
    TData s; 
    int i; 
    int pos; 
    int fecha;

    DeArchivoAArreglo(f, &s);
    printf("Digite la fecha del registro que quiere buscar: \n");
    SolicitarFecha(&fecha);
    i = 1;
    pos = Buscar(s,i,fecha); 

    if(pos != -1) {
        printf("Fecha: %d\n", s.a[pos].ddmmyyyy);
        printf("Direccion del viento: %d\n", s.a[pos].DV);
        printf("Velocidad del viento: %d\n", s.a[pos].FF);
        printf("Presion: %d\n", s.a[pos].PNM);
        printf("Temperatura maxima: %d\n", s.a[pos].tmax);
        printf("Temperatura minima: %d\n", s.a[pos].tmin);
        printf("Precipitacion pluvial: %d\n", s.a[pos].PP);
        printf("Humedad: %d\n", s.a[pos].HUM);
    }
    else {
        printf("El registro no existe."); 
    }    
}

void CopiaDeSeguridad(FILE *f, FILE *g) {
    RegDiario reg; 
    char copiaArch[10];
    
    f = fopen(nomArch, "rb");
    g = fopen("registros12Copia.dat", "wb");
    fread(&reg, sizeof(reg), 1, f);
        while (!(feof(f))){
            fwrite(&reg, sizeof(reg), 1, g);
            fread(&reg, sizeof(reg), 1, f);
        }
        strcat(nomArch, "Copia.dat");
        printf("Copia de seguridad realizada!");
    fclose(f);
    fclose(g); 
}

void CrearArch(char arch[20]) {
    FILE *f;

    f = fopen(nomArch, "wb");
    if (f == NULL) {
        exit(1);
    }
    fclose(f);
}

int Vacia(TData s) {
    return (s.cant = 0);
}