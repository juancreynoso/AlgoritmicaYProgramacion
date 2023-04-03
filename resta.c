#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main () {
    int ddmmyyyy = 23102022; // 1 <= dd <= 31, 1 <= mm <= 12, 1900 <= yyyy
    int dia, mes, anio;

    dia = ddmmyyyy / 1000000;
    mes = ddmmyyyy / 10000;
    anio = ddmmyyyy;

    printf("%d %d %d", dia, mes, anio);
    
}