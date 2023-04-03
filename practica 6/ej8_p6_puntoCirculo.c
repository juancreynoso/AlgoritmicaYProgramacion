#include<stdio.h>

typedef struct {
    int a, b;
} TRecta;

typedef struct {
    int x, y;
} TPunto;

void CargarCoordenadas(TPunto *coordenada);
void CargarCoeficientes(TRecta *coeficiente);
void PerteneceRecta(TPunto punto, TRecta coeficiente);

int main() {
    TPunto coor;
    TRecta coef;
    int pert;

    CargarCoeficientes(&coef);
    CargarCoordenadas(&coor);
    PerteneceRecta(coor, coef);

    return 0;
}


void CargarCoordenadas(TPunto *coordenada) {
    printf("Ingrese coordenada x del punto:"); scanf("%d", &coordenada -> x);
    printf("Ingrese coordenada y del punto: "); scanf("%d", &coordenada -> y);
}

void CargarCoeficientes(TRecta *coeficiente) {
    printf("Ingrese el coeficiente a: "); scanf("%d", &coeficiente -> a);
    printf("Ingrese el coeficiente b: "); scanf("%d", &coeficiente -> b);
}

void PerteneceRecta(TPunto punto, TRecta coeficiente) {
    if (coeficiente.a * punto.x + coeficiente.b == punto.y) {
        printf("Pertenece a la recta.");
    } else {
        printf("No pertenece a la recta.");
    }
}