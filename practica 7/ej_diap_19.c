#include<stdio.h>

int NMax = 7;

int main() {

    int notas[NMax];
    int i;

    i = 1;
    while (i <= NMax) {
        printf("Ingrese una nota: "); scanf("%d", &notas[i]);
        i++;
    }

    i = 1;
    while (i <= NMax) {
        printf("Nota %d: %d\n" ,i, notas[i]);
        i++;
    }

    return 0;
}