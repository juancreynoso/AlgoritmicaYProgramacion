#include<stdio.h>
#include<math.h>

float mayor(float a, float b) {

    return ((a + b) + fabs(a - b)) / 2;
}

int main() {

    int num1, num2, num3, num4, num5, num6;
    float numMayor;

    printf("Ingrese 6 números y obtendra el mayor:\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%d", &num3);
    scanf("%d", &num4);
    scanf("%d", &num5);
    scanf("%d", &num6);

    numMayor = mayor(mayor(mayor(mayor(mayor(num1, num2), num3), num4), num5), num6);

    printf("El numero mayor de los ingresados es: %.2f\n", numMayor);

    return 0;
}



