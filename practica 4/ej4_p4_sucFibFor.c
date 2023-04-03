
#include<stdio.h>

int main() {

    int n, i, fib, fib1, fib2;

    printf("Ingrese la cantidad de números de la serie que desea saber: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("%d", n);
    
    }
    else {
        fib = 0;
        fib2 = 0;
        fib1 = 1;
        printf("%d\n", fib2);
        printf("%d\n", fib1);
        for (i = 3; i <= n; i++) {
            fib = fib2 + fib1;
            fib2 = fib1;
            fib1 = fib;
            printf("%d\n", fib);
        }
    }

    return 0;
}