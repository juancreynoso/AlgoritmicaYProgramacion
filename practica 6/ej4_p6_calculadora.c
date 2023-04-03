#include<stdio.h>
#include<string.h>

void ObtenerDatos(float *a, float *b, char *op);
void Calcular(float x, float y, char op, float *res);
void Mostrar(float res);

int main() {
    float op1, op2;
    char operador;
    float resultado;

    ObtenerDatos(&op1, &op2, &operador);
    Calcular(op1, op2, operador, &resultado);
    Mostrar(resultado);
}

void ObtenerDatos(float *a, float *b, char *op) {
    printf("Ingrese el primer número: "); scanf("%f", &(*a));
    printf("Ingrese el segundo número: "); scanf("%f", &(*b));
    printf("Ingrese la operacion: "); scanf("%s", &(*op));
}

void Calcular(float x, float y, char op, float *res) {
    if (op == '+') {
        *res = x + y;
    } else if (op == '-') {
        *res = x - y;
    } else if (op == '*') {
        *res = x * y;
    } else if (op == '/') {
        if (y == 0) {
            *res = 999999;
            printf("Error\n");
        } else {
            *res = x / y;
        }
    } else {
        printf("Operador no soportado.");
    }
}
                        
void Mostrar(float res) {
    printf("%.2f", res);
}
