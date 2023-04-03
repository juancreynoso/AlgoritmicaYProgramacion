
#include <stdio.h>

void main(){

    float tNad1, tNad2, tNad3;

    printf("Tiempo para Nadador 1: ");
    scanf("%f", &tNad1);
    printf("Tiempo para Nadador 2: ");
    scanf("%f", &tNad2);
    printf("Tiempo para Nadador 3: ");
    scanf("%f", &tNad3);

    if (tNad1 > tNad3 && tNad1 < tNad2){ 
        printf("Nadador 3: %.2f - Nadador 1: %.2f - Nadador 2: %.2f ", tNad3, tNad1, tNad2);
    }
    else{
        if (tNad2 > tNad1 && tNad2 < tNad3){
            printf("Nadador 1: %.2f - Nadador 2: %.2f - Nadador 3: %.2f ", tNad1, tNad2, tNad3);
        }
        else{
            if (tNad1 < tNad3 && tNad1 > tNad2){
                printf("Nadador 2: %.2f - Nadador 3: %.2f - Nadador 1: %.2f ", tNad2, tNad3, tNad1);
            }
            else{
                if (tNad3 > tNad1 && tNad3 < tNad2){
                    printf("Nadador 1: %.2f - Nadador 3: %.2f - Nadador 2: %.2f ", tNad1, tNad3, tNad2);
                }
            }
        }
    }

}