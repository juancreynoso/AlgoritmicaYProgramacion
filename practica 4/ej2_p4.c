/*
practica 4 - Ciclos Repetitivos 

2. Desarrolla un Algoritmo que permita dar como resultado los números divisibles por 2, 4 y 6 que están
comprendidos entre 1 y el número 100. Resuelve este algoritmo: Utilizando solo repetir.  

Analisis 

	Datos: i // iniacializo en 1 para que vaya incrementando y se vaya evaluando en la condicion, hasta que sea mayor a 100 
	Resultados: numerosDivisbles  
	Relaciones o subproblemas: i es un dato subrango de los numeros comprendidos entre 1 y 100, en el cual con un ciclo repetitivo mostraremos todos los numeros divisibles por 2,4,6 
							   con la variable numerosDivisbles, para que sea divisible por 2,4,6 se tiene que cumplir la condicion ((2 mod i = 0) y (4 mod i = 0) y (6 mod i = 0)).


Algoritmo DivisiblesEntre1y100
Lexico 
    numerosDivisbles E Z+ 
    i E Z+
Inicio 
 	i <-- 1 
 	Repetir 
        si ((i mod 2 = 0) y (i mod 4 = 0) y (i mod 6 = 0)) entonces
        numerosDivisbles <-- i 
        salida: numerosDivisbles 
        fsi 
        i <-- i + 1
 	hasta que (i > 100)

Fin 

*/

#include <stdio.h>

int main (){

	int numerosDivisbles, i;
	i = 1;
    
	do{
    
		if ((i % 2 == 0) && (i % 4 == 0) && (i % 6 == 0)){

			numerosDivisbles = i; 
			printf("%i \n", numerosDivisbles);
		}     
        i++;
	} while (i <= 100);
    
}

