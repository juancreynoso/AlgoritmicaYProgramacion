#include<stdio.h>

int NMax = 30;

int main(){
    int bingo[NMax];
    int i, cont;
    char hayGanador;

    cont = 1;
    i = 1;
    hayGanador = 'N';

    while((i <= NMax) && (hayGanador == 'N')) {
        printf("Ingrese el primer numero: "); scanf("%d\n", &bingo[i]);
        printf("Es ganador? S/N: "); scanf("%c\n", &hayGanador);
        i++;
        cont++;
    }

    for (i=1; i<=cont; i++) {
        printf("%d", bingo[i]);
    }
    
    return 0;
}