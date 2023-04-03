
/*
3) Desarrolla un Algoritmo que realice la pregunta: ¿Desea continuar S/N? y que no deje de hacerla hasta
que el usuario teclee N.



Analisis 

	Datos: ingCaracter 
	Resultados:  msg
	Relaciones o subproblemas: al pedir que se ingrese la respuesta dependiendo de si es N o S la pregunta
    se seguira realizando hasta que se ingrese N y ahi terminara el ciclo repetir 

Algoritmo SaleONoSale?
Léxico
    respuesta E caracter
    pregunta E cadena
Inicio
    pregunta <- "¿Desea continuar S/N?"
    repetir
        salida: pregunta
        entrada: respuesta
    hasta que (respuesta = 'N')

*/

#include <stdio.h>

int main(){
    char respuesta;
    char pregunta;
    
    do{
        printf("¿Desea continuar? S/N\n"); scanf("%s",&respuesta); 
    } while (!(respuesta == 'N'));

    return 0;
}