
#include<stdio.h>

void main(){

    float pcPagOf, pcPagAlt;

    printf("Ingrese precio de la pc de la tienda oficial: ");
    scanf("%f", &pcPagOf);
    printf("Ingrese precio de la pc de la tienda alternativa: ");
    scanf("%f", &pcPagAlt);

    pcPagOf = pcPagOf * 1.01;
    
    if (pcPagOf < pcPagAlt){
        printf("La mejor opción es comprar en la tienda oficial");
    }
    else if (pcPagOf > pcPagAlt){
        printf("La mejor opción es comprar en la tienda alternativa");
    }
    else{
        printf("Cualquier opción es buena");
    }
    
}

    

