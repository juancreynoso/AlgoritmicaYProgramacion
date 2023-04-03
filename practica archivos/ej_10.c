#include<stdlib.h>
#include<stdio.h>

typedef struct
{
    char nom[20];
    char ape[20]; 
    char DNI[10];
    int totVentas;
    float sueldo;
} TVendedor;

void borrarEmpleado(FILE* file, char* empleado[20]);

int main() {

    FILE* f;
    TVendedor dat;
    int cantEmp;
    int i;
    char emp[20];

    f = fopen("archivo.dat", "a");
    printf("Ingrese la cantidad de empleados: ");
    scanf("%d", &cantEmp);
    
    i = 0;
    while (i < cantEmp) {
        printf("Ingrese datos del empleado %d \n", i+1);
        printf("Nombre: ");
        scanf("%s", &dat.nom[20]);
        printf("Apellido: ");
        scanf("%s", &dat.ape[20]);
        printf("DNI: ");
        scanf("%s", &dat.DNI[10]);
        printf("Ventas totales: ");
        scanf("%d", &dat.totVentas);
        printf("Sueldo: ");
        scanf("%f", &dat.sueldo);

        fwrite(&dat, sizeof(dat), 1, f);
        i++;
    }

    i = 0;
    while (i < cantEmp) {
        fread(&dat, sizeof(dat), 1, f);
        printf("%s", dat.nom[20]);
        printf("%s", dat.ape[20]);
        printf("%s", dat.DNI[10]);
        printf("%d", dat.totVentas);
        printf("%f", dat.sueldo);
        i++;
    }

    borrarEmpleado(f, &emp[20]);

    fclose(f);

    return 0;
}

void borrarEmpleado(FILE* file, TVendedor emp) {
    TVendedor aux;
    int found = 0;
    fread(&datEmp, sizeof(datEmp), 1, file);

    scanf("%s", &(*empleado[20]));
    printf("Ingrese el empleado que desea eliminar");

    i = 1;
    while (datEmp.ape != *empleado) {
        i++;
    }
    fseek(file, -sizeof(&empleado), ftell(file));
}