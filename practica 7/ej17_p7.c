#include<stdio.h>
#define Max 4

typedef struct 
{
    int matriz[Max][Max];
} TMatriz;

//Funciones y Acciones
int calcCascara(TMatriz m);
int calcCorazon(TMatriz m);
void cargarMatriz(TMatriz *m);

int main() {
    TMatriz matriz;

    cargarMatriz(&matriz);
    
    if (calcCascara(matriz) == calcCorazon(matriz)) {
        printf("Son Iguales \n");
    } else {
        printf("Son diferentes \n");
    }

    return 0;
}

int calcCascara(TMatriz m) {
    int i, j, res;

    res = 0;
    for (i=0; i<Max; i++) {
        for (j=0; j<Max; j++) {
            if ((i == 1) || (i == Max) || (j == 1) || (j == Max)) {
                res = res + m.matriz[i][j];
            }
        }
    }
    return res;
}

int calcCorazon(TMatriz m) {
    int i, j, res;

    res = 0;
    for (i=0; i<Max; i++) {
        for (j=0; j<Max; j++) {
            if ((i != 1) && (i != Max) && (j != 1) && (j != Max)) {
                res = res + m.matriz[i][j];
            }
        }
    }
    return res;
}

void cargarMatriz(TMatriz *m) {
    int i, j, num;

    for (i=0; i<Max; i++) {
        for (j=0; j<Max; j++) {
            printf("Cargue la matriz en la posición [%d][%d]: ", i, j);
            scanf("%d", &num);

            m->matriz[i][j] = num;
        }
    }
}

