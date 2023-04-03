#include<stdio.h>


int main(){

    int num, i, tabla;

    printf("La tabla de qué numero desea saber? ");
    scanf("%d", &num);

    i = 1;
    tabla = 0;
    while (i <= 10) {
        tabla = num * i;
        printf("%d x %d = %d\n", num, i, tabla);
        i++;
    }

    return 0;
}