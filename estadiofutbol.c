#include<stdio.h>
#include<math.h>

int main(){
    
    const float PI = 3.1416;
    float a, b, c; //Datos de entrada
    float areaCancha, areaCabeceras, areaPistaCurva, areaPistaRecta, perimetroC; //Datos intermedios
    float supPS, supPav, longLineas; //Datos de salida

    printf("Ingrese el valor de a en metros:");
    scanf("%f", &a);
    printf("Ingrese el valor de b en metros:");
    scanf("%f", &b);
    printf("Ingrese el valor de c en metros:");
    scanf("%f", &c);
    printf("Los valores ingresados son: \na: %.2f metros \nb: %.2f metros \nc: %.2f metros\n", a, b, c);
    
    areaCabeceras = b/2 * b/2 * PI;
    areaCancha = a * b;
    supPS = areaCabeceras + areaCancha;
    areaPistaCurva = (b/2 + c) * (b/2 + c) * PI;
    areaPistaRecta = a * c * 2;
    supPav = areaPistaCurva + areaPistaRecta;
    perimetroC = PI * 9.15 * 2;
    longLineas = perimetroC + b * 2 + a * 3 + 40.32 * 2 + 18.32 * 2 + 16.5 * 4 + 5.5 * 4;

    printf("La superficie total a completar con césped sintético es de: %.2f m2\n", supPS);
    printf("La superficie total a completar con pavimento es de: %.2f m2\n", supPav);
    printf("La longitud total en líneas a pintar dentro de la cancha es de: %.2f metros\n", longLineas);
    
    return 0;
}   