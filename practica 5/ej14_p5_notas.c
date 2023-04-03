#include<stdio.h>

float calcularPromedio(float a, float b, float c);
float notaFinal(float a, float b, float c);

int main() {

    float nota1, nota2, nota3;
    float promedio;
    
    do {
        printf("Ingrese la nota de la 1° Evaluacion: ");
        scanf("%f", &nota1);
    } while (!(nota1 > 0 && nota1 <= 10));

    do {
        printf("Ingrese la nota de la 2° Evaluacion: ");
        scanf("%f", &nota2);
    } while (!(nota2 > 0 && nota2 <= 10));

    do {
        printf("Ingrese la nota de la 3° Evaluacion: ");
        scanf("%f", &nota3);
    } while (!(nota3 > 0 && nota3 <= 10));



    promedio = notaFinal(nota1, nota2, nota3);

    if (promedio < 5) {
        printf("Libre\n");
    } else {
        if ((promedio >= 5) && (promedio <= 7)) {
            printf("Regular\n");
        } else {
            printf("Promoción\n");

        }
    }

    return 0;
}

float calcularPromedio(float a, float b, float c) {
    return (a + b + c) / 3;
}

float notaFinal(float a, float b, float c) {
    if ((a < 4) || (b < 4) || (c < 4)) {
        return 2;
    } else {
        return calcularPromedio(a, b, c);
    }
}