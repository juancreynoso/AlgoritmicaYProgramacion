#include<stdio.h>
#define Max 200

typedef struct {
    int numero[Max]; //(Entran valores del 1..10)
    int cant;
}TData;

void cargarNotas(TData *notas);
void promedioNotas (TData notas, float *prom);

int main() {

    TData misNotas;
    float promedio;

    cargarNotas(&misNotas);
    promedioNotas(misNotas, &promedio);

    return 0;
}

void cargarNotas(TData *notas) {
    int i;

    printf("Ingrese la cantidad de notas a cargar: ");
    scanf("%d", &notas->cant);

    for (i = 1; i <= notas->cant; i++) {
        printf("Ingrese la nota %d: ", i);
        scanf("%d", &notas->numero[i]);
    }
}

void promedioNotas (TData notas, float *prom) {
    int i;
    int sumNotas;

    sumNotas = 0;
    for (i = 1; i <= notas.cant; i++) {
        sumNotas = sumNotas + notas.numero[i];
    }
    *prom = sumNotas/notas.cant;
    printf("El promedio es: %.2f", *prom);
}

