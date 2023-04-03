#include<stdio.h>

int main() {

    int num, i, cont;

    printf("Ingrese un número: ");
    scanf("%d", &num);

    i = 1;
    cont = 0;

    while (i <= num) {
        if (num % i == 0) {
            cont++;
        }
        i++;
    }

    if (cont == 2) {
        printf("Es primo");
    }
    else {
        printf("No es primo");
    }

    return 0;
}