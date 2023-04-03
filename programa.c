#include<stdio.h>
#include<math.h>

int main(){

	float h, k; //Coordenadas del círculo
	float r; //Radio
	float x, y; //Coordenadas del punto
	float d; //Distancia

	printf("Ingrese el punto h del círculo: "); scanf("%f", &h);
	printf("Ingrese el punto k del círculo: "); scanf("%f", &k);
	printf("Ingrese el radio del círculo: "); scanf("%f", &r);
	printf("Ingrese el punto x: "); scanf("%f", &x);
	printf("Ingrese el punto y: "); scanf("%f", &y);

	d = sqrt((x-h)*(x-h)+(y-k)*(y-k));

	if (d <= r) {
		printf("El punto está dentro del círculo\n");
	} else {
		printf("El punto está fuera del círculo\n");
	}

	return 0;
}