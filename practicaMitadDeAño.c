#include<stdio.h>
#include<string.h> 
#include<stdlib.h> 
#define Max 999

//Arreglo
typedef struct {
    char a[Max];
 } TEmpleados;
//Registro

typedef struct {
    int cant; 
    TEmpleados arr;    
} TData;

//Funciones
int vacia(TData a);
int llena(TData a);
int comparar(TData a, char apellido);
int buscar(TData a, char apellido);

//Acciones
void insertar(TData *a, char apellido);
void suprimir(TData *a, char apellido);
void mostrar(TData a);
void modificar(TData *a, char apellido, char *nuevoApellido);


int main() {
    TData listaEmp;
    char empleado[100];
    char nuevoEmpleado;
    int eleccion;
    int i;

    listaEmp.cant = 0;

    while (eleccion != 6) {

        printf("¿Que accion desea realizar?\n1. Alta de empleado\n2. Baja de empleado\n3. Modificar datos de empleado\n4. Listar empleados\n5. Buscar empleado\n6. Salir\n");
        scanf("%d", &eleccion);

        if (eleccion == 1) {
            printf("Ingrese el apellido que desea ingresar: ");
            scanf("%s", empleado);
            insertar(&listaEmp, empleado[100]);
        } 
        else {
            if(eleccion == 2){
                printf("Ingrese el apellido que desea eliminar: ");
                scanf("%s", empleado);
                suprimir(&listaEmp, empleado);
            }
            else {
                if(eleccion == 3) {
                    printf("Ingrese el apellido que quiere modificar: ");
                    modificar(&listaEmp, empleado, nuevoEmpleado);
                }
                else {
                    if(eleccion == 4) {
                        mostrar(listaEmp);
                    }
                    else {
                        if(eleccion == 5) {
                            printf("Ingrese el apellido que desea buscar: ");
                            scanf("%s", empleado); 
                            
                            for (i=0; i<=listaEmp.cant; i++) {
                                if (buscar(listaEmp, empleado) == i) {
                                    printf("El apellido %c existe en la lista de empleados.", empleado);
                                } else {
                                   printf("El apellido %c no existe en la lista de empleados", empleado);
                                }
                            } 
                        } else {
                            if(eleccion == 6) {
                                exit(-1);
                            } else {
                                "Ingrese una opción válida.";
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int vacia(TData a) { // no hay errores con algoritmo.
    if (a.cant = 0) {
        return 1;
    } else {
        return 0;
    }
}

int llena(TData a) { // no hay errores con algoritmo.
    if (a.cant == Max) {
        return 1;
    } else {
        return 0;
    }
}


int comparar(TData a, char apellido) {
    int i; 

    for (i = 0; i <= a.cant; i++ ) {
        if (strcmp(a.arr[i], apellido) == 0) {
            return 1; 
        }
    }
    return 0; 
}

int buscar(TData a, char apellido) {
    int i;

    for (i=0; i<=a.cant; i++) {
        if (comparar(a, apellido)) {
            return i;
        }
    }
}

void insertar(TData *a, char apellido[100]) {
    int i, j;

    i = 0;
    j = a->cant;

    if (vacia(a)) { // duda de &
        strcpy((*a)->arr[i], apellido); //strcpy(*(a->arr[i]), apellido);
    } else {
        if (llena(a)) {
            printf("La lista está llena, no se puede insertar otro apellido.");
        } else {
            if (comparar(&a, apellido)) {
                printf("Este apellido ya existe."); 
            } else {
                strcpy((*a)->arr[j+1], apellido);
                a->cant ++;
            }
        }
    }
}

void suprimir(TData *a, char apellido) {
    int i, j;

    for (i=0; i <= a->cant; i++) {
        if comparar(a.arr[i], apellido) {
            j = i;
            while (j <= a->cant) {
                a->arr[j] = a->arr[j+1];
                j++;
            }
        }
    }
}

void mostrar(TData a) {
    int i;

    for (i=0; i<=a.cant; i++) {
        printf("%s", a.arr[i]);
    }
}

void modificar(TData *a, char apellido, char *nuevoApellido) {
    int pos;
    //hacer entrada de apellido en main
    if (buscar(*a, apellido) >= 0) {
        pos = buscar(*a, apellido);
        printf("El apellido %s se encuentra en la lista.", apellido); 
        printf("Ingrese el nuevo apellido:");
        scanf("%s", &(*nuevoApellido));
        strcpy(a->arr[pos], nuevoApellido) ;
    } else {
        printf("El apellido que quiere modificar no se encuentra en la lista.");
    }
}