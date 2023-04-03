/*
    CURSO C LIBRO KERNIGHAN & RITCHIE 
    RETO FINAL 2
*/

#include <stdio.h>
#include <string.h>

#define IN 1
#define OUT 0
#define MAXLINE 1000 /*Definimos el maximo de linea*/

int main(){
    int i, c, def, state; 
    char nletter[MAXLINE], cadena[MAXLINE], code[MAXLINE], decode[MAXLINE];
    def = 0; /* Inicializamos variable */
    state = OUT; /* Inicializamos variable */

    for (i = 97; i < 123; i++) /* Creamos el abcedario en el array nletter */
    {
        nletter[i] = i;
    }
    while((c = getchar()) != EOF){
        if (c == 'c') /* Si el caracter es c entonces codificamos*/
        { 
            while ((c = getchar()) != EOF)
            {
                 
            for (i = 0; (c = getchar()) != EOF; i++)
            {
                cadena[i] = c;  
                def ++;
                
            }
    
            for (i = 0; i < strlen(cadena); i++) /* Encriptamos segun codificado cesar ROT 13*/
            {
                if (cadena[i] < 110)
                    code[i] = nletter[cadena[i] + 13];
                else if (cadena[i] >= 110)
                {
                    code[i] = nletter[cadena[i] - 13];
                }
                
            }
            }
        }
        else if (c == 'd') /* Si la opcion es d decodificamos*/
            state = IN;
            while ((c = getchar()) != EOF)
            {
                 
            for (i = 0; (c = getchar()) != EOF; i++)
            {
                cadena[i] = c;  
                def ++;
                
            }
            
            for (i = 0; i < strlen(cadena); i++) /* Desencriptamos segun codigo cesar ROT 13*/
            {
                if (cadena[i] < 110)
                    decode[i] = nletter[cadena[i] + 13];
                else if (cadena[i] >= 110)
                {
                    decode[i] = nletter[cadena[i] - 13];
                }
                
            }
            }
    
    /* Mostramos resultados */
    if (state == OUT)
    {
        for (i = 0; i < (def - 1); i++){
            printf("%c", code[i]);
        }
    }
    else
        for (i = 0; i < (def - 1); i++)
        {
            printf("%c", decode[i]);
        }
    }
}

/*No pude implementar funciones por el hecho de que no sabia como retornar arrays*/