#include<stdio.h>

int main() { //mientras

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
        i = 3;
        
        while (i <= n) {
            fib = fib2 + fib1;
            fib2 = fib1;
            fib1 = fib;
            printf("%d\n", fib);
            i++;
        }
    }

    return 0;
}


/*
int main() { //repetir

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
        i = 3;
        
        do {
            fib = fib2 + fib1;
            fib2 = fib1;
            fib1 = fib;
            printf("%d\n", fib);
            i++;
        } while (!(i > n));
    }

    return 0;
}
*/

/*

int main() { //para

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

*/
