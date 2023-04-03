#include<stdio.h>
#include<stdlib.h>
#define Max 30

typedef struct {
    int loteria[Max];
    int cant;
    int l;
} TData;

void AlmacenarNum(TData *lote);

int main(){
    TData loteria;

    AlmacenarNum(&loteria);

    return 0;
}

void AlmacenarNum(TData *lote) {
    int i;

    printf("Ingrese cantidad de numeros a cargar: ");
    scanf("%d", &lote->cant);

    for (i = 1; i<=lote->cant; i++) {
        lote->loteria[i] = rand() %1000;
        printf("El numero %d es: %d\n", i, lote->loteria[i]);
    }
}