#include <stdio.h>

int main() {

    int cotaSup, i, s;

    printf("Ingrese cotaSup: ");
    scanf("%d", &cotaSup);
    s = 0;
    i = 0;

    while (i <= cotaSup) {
        s = s + i;
        i++;
    }
    printf("La suma de los %d primeros número naturales es: %d", cotaSup, s);

    return 0;
}