#include<stdio.h>

int main(){

    int num, i;

    i = 1;
    while (i < 10 || num != 73) {
        printf("Ingrese un numero entre 1 y 99: \n"); scanf("%d", &num);
        if (num == 73) {
            printf("Ganaste!\n");
        } 
        else {
            printf("Este es tu intentento %d, tienes 10 intentos!\n", i);
            i++;
        }

        if (i >= 10) {
            printf("Perdiste!\n");
        }
    }

    return 0;
}