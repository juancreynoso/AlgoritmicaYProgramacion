#include <stdio.h>
#include <string.h>


int main() {

	int diasRest;
	int precioPasaje;
	int idaVuelta;

	printf("Indique los dias faltantes para el día del viaje: ");
	scanf("%i", &diasRest);

	if (diasRest >= 30) {
		precioPasaje = 4650;
	}
	else {
		if (diasRest > 14 && diasRest < 30) {
			precioPasaje = 5350;
		}
		else {
			if(diasRest <= 14 && diasRest >= 1) {
				precioPasaje = 6875;
			}
			else {
				printf("Día ingresado no válido");
			}
		}
	}

	printf("¿Es el pasaje de ida y vuelta? \n[1] - Si \n[0] - No\n"); scanf("%i", &idaVuelta);

	if (idaVuelta == 1) {
		precioPasaje = precioPasaje * 2;
	}

    printf("El precio del pasaje es: %i\n", precioPasaje);

	return 0;
}