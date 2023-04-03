#include<stdio.h>

int NMaxCar = 20;
int NmaxVoc = 10;

char caracter[20];
char vocal[10];

int main(){

    char carac;

    CapturarDatos(carac);

    return 0;
}

void CapturarDatos(char *x){
    int i;
    for (i=1; i<=NMaxCar; i++){
        printf("Ingrese un caracter: "); scanf("%c", &(*x));
        caracter[i] = *x;
    }
}