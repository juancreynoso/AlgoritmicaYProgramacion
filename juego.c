#include<stdio.h>
int main(){

    int numero;// variable numero a ingresar
    int intentos; //contador 

    intentos = 1; //Inicio del contador en 1 

    while(intentos<=10 && numero!=73){ // inicio del mientras 
    printf("Intento numero %i \n",intentos); 
    printf("Ingrese un numero entre 1 y 99: ");scanf("%i",&numero); // pedir datos de entrada


        if(numero>=1 && numero<=99){               //comienzo del juego si el numero esta entre 1 y 99 



            if (numero == 73 && intentos<=10){ // numero = 73 e intentos <= 10
                printf("Felicitaciones, ganaste!!\n");
                }
            else if (numero!=73 && intentos<=10){ // numero distinto(!=) de 73 e intentos <= 10

                printf("Vuelve a intentarlo.\n");
                }
            else if(intentos>10){ //intentos mayor a 10 
                    printf("Perdiste\n");
                }
        }
        else{
        printf("El numero ingresado es incorrecto, esta fuera del rango\n");
        }

       intentos++; // intentos = intentos + 1
    }
    printf("Muchas gracias por jugar con nosotros!!"); 
    return 0; 
}
