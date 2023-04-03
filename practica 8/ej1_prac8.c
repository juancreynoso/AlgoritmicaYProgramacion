#include<stdio.h>
#include<string.h>
#define Max 150

typedef struct 
{
    char apellido[30];
    int dni;
} TPersona;

typedef struct 
{
    TPersona array[Max];
    int cant;    
} TData;

void cargar(TData *a);
void informar(TData a, int d);

int main() {
    TData lista;
    int dni;
    char apellido[30];

    cargar(&lista);

    printf("Ingrese un dni para verificar si existe en la lista: ");
    scanf("%d", &dni);

    informar(lista, dni);

    return 0;
}

void cargar(TData *a) {
    int i;

    printf("Ingrese la cantidad de apellidos a cargar: ");
    scanf("%d", &(a->cant));

    for (i = 0; i < a->cant; i++) {
        printf("Ingrese el apellido: ");
        scanf("%s", &(*(a->array[i].apellido)));

        printf("Ingrese el dni: ");
        scanf("%d", &(a->array[i].dni));

        printf("Apellidos y dni cargados correctamente.\n");
    };
}

void informar(TData a, int d) {
    int encontro, i, j;

    encontro = 0;

    for (i = 0; i < a.cant; i++) {
        if (d == a.array[i].dni) {
            encontro = 1;
            j = i;
        }
    }
    if (encontro == 1) {
        printf("%s %d\n", a.array[j].apellido, a.array[j].dni);
    } else {
        printf("No existe. \n");
    }
}