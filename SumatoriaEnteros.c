#include<stdio.h>

int n, k, sumatoria;

int main(){

    sumatoria = 0;
    k = 1;
    do {
        printf("Ingrese el numero (positivo) hasta donde quiere la sumatoria ");
        scanf("%d", &n);
    } while (n <= 0);

    do {
        sumatoria = sumatoria + k;
        k++;
    } while (k <= n); 
    printf("La sumatoria de 1 a %d es : %d ", n, sumatoria);

    return 0;
}