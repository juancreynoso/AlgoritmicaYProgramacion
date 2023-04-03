#include<stdio.h>
#define Max 60

typedef struct {
    float ventas[Max];
    int cant;
} TData;

void cargarVentas(TData *v);
float sumarVentas(TData v);

int main() {
    TData venta;
    float sumatoria;

    cargarVentas(&venta);
    sumatoria = sumarVentas(venta);

    printf("La sumatoria de las ventas es: %.2f", sumatoria);

    return 0;
}

void cargarVentas(TData *v) {
    int  i;

    printf("Ingrese la cantidad de ventas a cargar: ");
    scanf("%d", &v->cant);

    for (i = 1; i <= v->cant; i++) {
        printf("Ingrese venta %d: ", i);
        scanf("%f", &v->ventas[i]);
    }
}

float sumarVentas(TData v) {
    float sumVentas;
    int i;

    sumVentas = 0;
    for (i = 1; i <= v.cant; i++) {
        sumVentas = sumVentas + v.ventas[i];
    }
    return sumVentas;
}