#include<stdio.h>

int MenorTresNum(int n1, int n2, int n3);
float promedio(int n1, int n2, int n3);
void CondicionAlumno(int *n1, int *n2, int *n3, char *condicion);

int main(){
    int nota1, nota2, nota3;
    char cond;
    CondicionAlumno(&nota1, &nota2, &nota3, &cond);
    return 0;
}

int MenorTresNum(int n1, int n2, int n3){
    int menor;
    
    if ((n1 <= n2) && (n1 <= n3)){
        menor = n1;
    } else if ((n2 < n1) && (n2 <= n3)){
        menor = n2;
    } else if ((n3 < n2) && (n3 < n1)){
        menor = n3;
    }
    
    return menor;
}

float promedio(int n1, int n2, int n3){
    return (n1 + n2 + n3) / 3;
}

void CondicionAlumno(int *n1, int *n2, int *n3, char *condicion){
    float promedioF;
    int menorNumero;

    while (*n1 < 1 || *n1 > 10) {
        printf("Ingrese la 1° nota: "); scanf("%d", &(*n1));
    }
    while (*n2 < 1 || *n2 > 10) {
        printf("Ingrese la 2° nota: "); scanf("%d", &(*n2));
    }
    while (*n3 < 1 || *n3 > 10) {
        printf("Ingrese la 3° nota: "); scanf("%d", &(*n3));
    }

    promedioF = promedio(*n1, *n2, *n3);
    menorNumero = MenorTresNum(*n1, *n2, *n3);

    if (menorNumero < 4){
        printf("Condición: Libre.\n");
    } else 
        if ((menorNumero >= 4) && (menorNumero <= 6) && (promedioF < 7)){
            printf("Condición: Regular.\n");
        } else 
            if ((menorNumero >= 6) && (promedioF >= 7)){
                printf("Condición: Promocionando.\n");
            }
}