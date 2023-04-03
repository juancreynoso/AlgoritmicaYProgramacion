#include<stdio.h>
#include<math.h>


typedef struct {
    int x, y;
} TPunto;

void CargarCoordenadas(TPunto *coordenada);
void CargarCoordenadasCirc(TPunto *coordenada, float *radio);
void DentroOFuera(TPunto p, TPunto c, float r, int *pertenece);
void Mostrar(int res);

int main() {

    TPunto punto;
    TPunto centroCirculo;
    float radio;
    int estaDentro;

    CargarCoordenadas(&punto);
    CargarCoordenadasCirc(&centroCirculo, &radio);
    DentroOFuera(punto, centroCirculo, radio, &estaDentro);
    Mostrar(estaDentro);
    
    return 0;
}

void CargarCoordenadas(TPunto *coordenada) {
    printf("Ingrese coordenada x del punto: "); scanf("%d", &coordenada -> x);
    printf("Ingrese coordenada y del punto: "); scanf("%d", &coordenada -> y);
}

void CargarCoordenadasCirc(TPunto *coordenada, float *r) {
    printf("Ingrese coordenada x del centro del círculo: "); scanf("%d", &coordenada -> x);
    printf("Ingrese coordenada y del centro del círculo: "); scanf("%d", &coordenada -> y);
    printf("Ingrese radio del círculo: "); scanf("%f", &(*r));
}

void DentroOFuera(TPunto p, TPunto c, float r, int *pertenece) {
    if (r >= sqrt(pow((p.x-c.x), 2) + pow((p.y-c.x), 2))) {
        *pertenece = 1;
    } else {
        *pertenece = 0;
    }
}

void Mostrar(int res) {
    if (res == 1) {
        printf("El punto está dentro del círculo.");
    } else {
        printf("El punto está fuera del círculo.");
    }
}
