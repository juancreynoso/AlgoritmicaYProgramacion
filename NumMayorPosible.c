
#include<stdio.h>

void main(){

    int a, b, numMayorPosible;

    printf("Ingrese el primer número: ");
    scanf("%i", &a);
    printf("Ingrese el segundo número: ");
    scanf("%i", &b);

    //while (a < 0 || a > 9 || b < 0 || a > 9){

        if (a > b){
            numMayorPosible = a * 10 + b;
        }else{
            numMayorPosible = b * 10 + a;
        }
    //}
        printf("%i es el mayor numero posible de formar", numMayorPosible);

}