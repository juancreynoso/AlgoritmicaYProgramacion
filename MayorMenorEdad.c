
#include<stdio.h>

void main(){

    int edad;


    do{
        printf("Ingrese su edad: ");
        scanf("%i", &edad);
           
    } while (edad >= 0);
    
    if (edad >= 18){
        printf("Eres mayor de edad");
    }
    else{
        printf("Eres menor de edad");
    }
}