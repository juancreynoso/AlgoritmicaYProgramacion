#include<stdio.h>
#include<string.h>
#define Max 100

typedef struct 
{
    int soja;
    int maiz;
    int trigo;
    int mani;
} TCosecha;

typedef struct 
{
    TCosecha arr[Max];
    int cant;
} TData;

void cargarDatos (TData *a);
void promedioAnual(TData a, TCosecha *p);
void cantAniosTrigoSup(TData a, TCosecha p, int *cantAnios);
void cantAniosManiInf(TData a, TCosecha p, int *cantAnios);

int main() {
    TData cosecha;
    TCosecha prom;
    TCosecha anioMayorTon;
    TCosecha anioMenorTon;
    int cantidadAnios;

    cargarDatos(cosecha);
    promedioAnual(cosecha, &prom);
    cantAniosTrigoSup(cosecha, prom, &cantidadAnios);
    cantAniosManiInf(cosecha, prom, &cantidadAnios);

    return 0;
}

void cargarDatos (TData *a) {
    int i;

    printf("Ingrese la cantidad de de años que va a cargar: ");
    scanf("%d", &(a->cant));

    for (i=0; i<a->cant, i++) {
        printf("Ingrese cantidad en Ton de soja: ");
        scanf("%d", &((a->arr[i].soja)));

        printf("Ingrese cantidad en Ton de maiz: ");
        scanf("%d", &((a->arr[i].maiz)));

        printf("Ingrese cantidad en Ton de trigo: ");
        scanf("%d", &((a->arr[i].trigo)));

        printf("Ingrese cantidad en Ton de mani: ");
        scanf("%d", &((a->arr[i].mani)));
    }
}

void mostrarDatos (TData a) {
    int i;

    for (i=0; i<a->cant; i++) {
        printf();
    }
}

void promedioAnual(TData a, TCosecha *p) {
    int i;
    TCosecha sum;

    sum.soja = 0;
    sum.maiz = 0;
    sum.trigo = 0;
    sum.mani = 0;

    for (i=10; i<20; i++) {
        sum.soja = sum.soja + a.arr[i].soja;
        sum.maiz = sum.maiz + a.arr[i].maiz;
        sum.trigo = sum.trigo + a.arr[i].trigo;
        sum.mani = sum.mani + a.arr[i].mani;
    }
    p->soja = sum.soja / 10;
    p->maiz = sum.maiz / 10;
    p->trigo = sum.trigo / 10;
    p->mani = sum.mani / 10;
}

void cantAniosTrigoSup(TData a, TCosecha p, int *cantAnios) {
    int i;
    
    cantAnios = 0;
    
    for (i=10; i<20; i++) {
        if (p.trigo < a.arr[i].trigo) {
            cantAnios++;
        }
    }
    printf("%d años fueron en los que las toneladas de trigo fueron mayores al promedio anual.", cantAnios);
}

void cantAniosManiInf(TData a, TCosecha p, int *cantAnios) {
    int i;
    
    cantAnios = 0;
    
    for (i=10; i<20; i++) {
        if (p.mani > a.arr[i].mani) {
            cantAnios++;
        }
    }
    printf("%d años fueron en los que las toneladas de maní fueron menores al promedio anual.", cantAnios);
}