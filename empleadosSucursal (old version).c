#include<stdio.h>
#include<string.h> 
#include<stdlib.h> 
#include<ctype.h> 
#define Max 999

//Registro
typedef struct {
    int cant; 
    char arr[Max][50];    
} TData;

//Funciones 
int vacia(TData a);
int llena(TData a);
int comparar(TData a, char *apellido);
int buscar(TData a, char *apellido);

//Acciones
void insertar(TData *a, char *apellido);
void suprimir( TData *a, char *apellido);
void mostrar(TData a);
void modificar(TData *a, char *apellido);

int main() {

    TData listaEmp;
    char empleado[50];
    int eleccion;
    int i;

    listaEmp.cant = 0;
    strcpy(listaEmp.arr[0], "--LISTA VACÍA--\n");

    while (eleccion != 6) {

        printf("\n¿Que acción desea realizar?\n1. Alta de empleado\n2. Baja de empleado\n3. Modificar datos de empleado\n4. Listar empleados\n5. Buscar empleado\n6. Salir\n");
        scanf("\n%d", &eleccion);

        if (eleccion == 1) {
            insertar(&listaEmp, empleado);
        } 
        else {
            if(eleccion == 2) {
                suprimir(&listaEmp, empleado);
            }
            else {
                if(eleccion == 3) {
                    modificar(&listaEmp, empleado);
                }
                else {
                    if(eleccion == 4) { 
                        mostrar(listaEmp);
                    }
                    else {
                        if (eleccion == 5) {
                            printf("Ingrese el apellido que desea buscar: ");
                            scanf("%s", empleado); 
                            
                            i = 0;
                            
                            while (i <= listaEmp.cant) {
                                if (buscar(listaEmp, empleado) == i) {
                                    printf("\nEl apellido %s se encuentra en la %d° posición. \n", empleado, i+1);
                                }
                                i++;
                            }   
                            if (buscar(listaEmp, empleado) < 0  || buscar(listaEmp, empleado) > listaEmp.cant) {
                                printf("\nNo existe este apellido en la lista.\n");
                            }
                        }
                        else {
                            if(eleccion == 6) {
                                printf("Usted salió del menú con éxito.\n");
                                exit(-1);
                            } 
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int vacia(TData a) {
    return (a.cant == 0);    
}

int llena(TData a) {
    return (a.cant == Max);
}

int comparar(TData a, char *apellido) {
    int i; 

    for (i = 0; i <= a.cant; i++ ) {
        if (strcmp(a.arr[i], apellido) == 0) {
            return 1; 
        }
    }
    return 0; 
}

void insertar(TData *a, char *apellido) {
    printf("\nIngrese el apellido que desea agregar: ");
    scanf("%s", &(*apellido));
    
    if (vacia(*a)) {
        strcpy(a->arr[0], apellido);
        a->cant++;
        printf("\nEl apellido %s se ingresó correctamente.\n", apellido);
    } else {  
        if (llena(*a)) {
            printf("\nLa lista está llena, no se puede ingresar otro apellido.\n");
        } else {
            if (comparar(*a, apellido) == 1) {
                printf("\nEste apellido ya existe en la lista. \n");
            } else {
                strcpy(a->arr[a->cant], apellido);
                a->cant++;
                printf("\nEl apellido %s se ingresó correctamente.\n", apellido);
            }
        }  
    }
}

void suprimir(TData *a, char *apellido) { 
    int i, pos;
    
    printf("\nIngrese el apellido que quiere eliminar: "); 
    scanf("%s",&(*apellido));

    pos = buscar(*a, apellido);

    if (pos >= 0){
        for(i = 0; i<=a->cant; i++) {
            if (strcmp(a->arr[i], apellido) == 0) {
                while (i <= a->cant) {
                    strcpy(a->arr[i], a->arr[i+1]);
                    i++;
                }
                if (i == 2) {
                    strcpy(a->arr[0], "--LISTA VACÍA--\n");
                }
                a->cant = a->cant - 1;
                printf("\nEl apellido %s fue eliminado con éxito.\n", apellido);
            }
        }
    } else{
        printf("\nEl apellido que desea eliminar no se pudo encontrar en la lista.\n");
    }
}

int buscar(TData a, char *apellido) {
    int i;

    for (i=0; i<=a.cant; i++) {
        if (strcmp(a.arr[i], apellido) == 0) {
            return i;
        }
    } 
    return -1; 
}

void mostrar(TData a) {
    int i; 

    for (i=0; i <=a.cant; i++) { 
        printf("\n%s", a.arr[i]);
    }  
}

void modificar(TData *a, char *apellido) {
    char nuevoApellido[50];
    int posApellido;
    char respuesta;

    printf("\nIngrese el apellido que desea modificar: ");
    scanf("%s", &(*apellido));

    posApellido = buscar(*a, apellido);

    if (posApellido >= 0) {
        printf("\nEl apellido %s se encuentra en la lista. Desea modificarlo? S/N: ", a->arr[posApellido]);
        scanf("%s", &respuesta);
        if (toupper(respuesta) == 'S') {
            posApellido = buscar(*a, apellido);
            printf("\nIngrese el nuevo apellido: ");
            scanf("%s", nuevoApellido);
            if (comparar(*a, nuevoApellido) == 1) {
                printf("\nEste apellido ya existe en la lista. \n");
            } else {
                strcpy(a->arr[posApellido], nuevoApellido);
                printf("\nLa modificación se realizó con éxito. \n");
            }
        }
    }
    else {
        printf("\nEl apellido que quiere modificar no se pudo encontrar en la lista. \n");
    }  
}

