#include<stdio.h>
#include<stdlib.h>
#define Max 50

void genArray(int arr[], int seed);
void mostrarArreglo(int a[]);
void bubbleSort(int a[]);
void Swap (int *x,int *y);

int main() {
    int a[Max];

    genArray(a, 1234);
    mostrarArreglo(a);
    bubbleSort(a);
    mostrarArreglo(a);

    return 0;
}

void genArray(int arr[], int seed) {
    srand(seed);
    for (int i = 0; i < Max; i++) {
        arr[i] = rand() % 100;
    }
}

void mostrarArreglo(int a[]) {
    int i = 0;
    while (i < Max) {
        printf("%d ", a[i]);
        i++;
    }
}

void bubbleSort(int a[]) {
    for (int i = Max; i > 1; i++) {
        for (int j = 0; j <= Max; j++) {
            if (a[j] <= a[i+1]) {
                Swap(&(a[j]), &(a[i+1]));
            }
        }  
        i--;
    }
}

void Swap (int *x,int *y) {
    int s;
    s = *x;
    *x = *y;
    *y = s;
}