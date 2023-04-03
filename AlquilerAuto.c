
#include <stdio.h>

void main(){

    float cantKm, costoTotal;

    printf("Ingrese la cantidad de kilometros realizados: ");
    scanf("%f", &cantKm);

    
    while (cantKm > 0){
        
        if (cantKm <= 300){
            costoTotal = cantKm * 30;    
        }
        else if (cantKm > 300 && cantKm <= 1000){
            costoTotal = (cantKm - 300) * 30.75 + 300 * 30;
        }
        else{
            costoTotal = (cantKm - 1000) * 30.5 + 1000 * 30;
        }

        printf("El precio a pagar es: %.2f", costoTotal);
    }
        
    
}

