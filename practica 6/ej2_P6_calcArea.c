#include<stdio.h>
#include<string.h>

void Cargar(float *a, float *b, char *f);
void Calcular(float a, float b, char f, float *area);
void Mostrar(float a, float b, char f, float area);

int main(){
    float x, y, sup;
    char z;
    
    Cargar(&x, &y, &z);
    Calcular(x, y, z, &sup);
    Mostrar(x, y, z, sup);
}


void Cargar(float *a, float *b, char *f){
    printf("Ingrese la primera letra de su figura: "); scanf("%s", &(*f));
    if (*f == 'r') {
        printf("Ingrese lado a: "); scanf("%f", &(*a));
        printf("Ingrese lado b: "); scanf("%f", &(*b));
    } else {
        printf("Ingrese base del triángulo: "); scanf("%f", &(*a));
        printf("Ingrese altura del triángulo: "); scanf("%f", &(*b));
    }
}

void Calcular(float a, float b, char f, float *area){
    if (f == 'r') {
        *area = a * b; 
    } else {
        *area = (a * b) / 2;
    }
}

void Mostrar(float a, float b, char f, float area){
    if (f == 'r') {
        printf("El área del rectangulo dado por los lados: %.2f y %.2f, es de: %.2f", a, b, area); 
    } else {
        printf("El área del triangulo dado por la altura: %.2f y la base: %.2f, es de %.2f", a, b, area);
    }
}