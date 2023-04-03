#include<stdio.h>
#include<string.h> 
#include<stdlib.h> 
#define Max 999

//Registro
typedef struct {
    int cant; 
    char arr[Max];    
} TData;

//Funciones 
int vacia(TData a);
int llena(TData a);
int compararApellidos(TData a, char apellido);
int buscarApellido(TData a, char apellido);

//Acciones
void insertarApellido(TData *a, char apellido);
void suprimirApellido( TData *a, char *apellido);
void mostrarApellido(TData a);
void modificarEmpleado(TData *a, char *apellido);

int main() {

    TData listaEmp;
    char empleado[15];
    int eleccion;
    int i;

    listaEmp.cant = 0;

    while (eleccion != 6) {

        printf("¿Que accion desea realizar?\n1. Alta de empleado\n2. Baja de empleado\n3. Modificar datos de empleado\n4. Listar empleados\n5. Buscar empleado\n6. Salir\n");
        scanf("%d", &eleccion);

        if (eleccion == 1) {
            printf("Ingrese el apellido que desea ingresar: ");
            scanf("%s", empleado);
            insertarApellido(&listaEmp, empleado);
        } 
        else {
            if(eleccion == 2){
                suprimirApellido(&listaEmp, empleado);
            }
            else {
                if(eleccion == 3) {
                    modificarEmpleado(&listaEmp, empleado);
                }
                else {
                    if(eleccion == 4){
                        mostrarApellido(listaEmp);
                    }
                    else {
                        if(eleccion == 5){
                            printf("Que apellido desea buscar: ");
                            scanf("%s", &empleado); //hasta aca esta bien dea 
                            //ta to gucci 
                            i = 0;
                            while (i <= listaEmp.cant) {
                                if (buscarApellido(listaEmp, *empleado) == i) {
                                    printf("El apellido %s se encuentra.", empleado);
                                }
                                else {
                                    printf("Apellido inexistente.\n");
                                }
                                i++;
                            }
                        }
                        else {
                            if(eleccion == 6) {
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
    int i, contador;

    contador = 0;

    for (i = 1; 1 <= a.cant; i++) {
        contador++;
        if (contador >= 1) {
            return 0;
        }
    }
    return 1;
}

int llena(TData a) {
    if (a.cant == Max) {
        return 1;
    } else {
        return 0;
    }
}

int compararApellidos(TData a, char apellido) {
    int i; 

    for (i = 0; i <= a.cant; i++ ) {
        if (strcmp(a.arr, &apellido) == 0) {
            return 1; 
        }
    }
    return 0; 
}

int buscarApellido(TData a, char apellido) {
    int i;
    int pos;

    for (i = 0; i <= a.cant; i++) {
        if (strcmp(a.arr[i], apellido) == 0) {
            return pos;
        }
        pos++;
    } 
    return -1; 
}

void insertarApellido(TData *a, char apellido) {
    int i, j;

    i = 1;
    j = a->cant;
    
    if (vacia(*a)) {
        strcpy(&(a->arr[0]), &apellido);
        //a->arr[i] = *apellido;
        printf("El apellido se ingresó correctamente.\n");
    } else {  
        if (llena(*a)) {
            printf("La lista está llena, no se puede ingresar otro apellido.\n");
        } else {
            if (compararApellidos(*a, apellido)) {
                printf("Este apellido ya existe");
            } else {
                //a->arr[j+1] = *apellido;
                strcpy(&(a->arr[j+1]), apellido);
                printf("El apellido se ingresó correctamente.\n");
            }
        }  
    }
}

void suprimirApellido ( TData *a, char *apellido) { 
    int i; 
    
    printf("Ingrese el apellido a eliminar: "); 
    scanf("%s",&(*apellido));

    for( i = 1; i <= a->cant; i++ ) {
        if(strcmp(a->arr, apellido) == 0) {
            while (i <= a->cant) {
                a->arr[i] = a->arr[i+1];
                i++;
            }
            a->cant = a->cant - 1;
            printf("El apellido se borro con éxito.\n");
        } else {
            printf("No existe el apellido %s \n en la lista.\n", apellido);
        }
    }
}

void mostrarApellido(TData a) {
    int i; 

    for (i=1; i <=a.cant; i++) { 
        printf("%c", a.arr[i]);
    }    
}

void modificarEmpleado(TData *a, char *apellido) {
    int i;
    char nuevoApellido;
    int posApellido;
    char respuesta;

    printf("Ingrese un apellido: ");
    scanf("%s", &(*apellido));

    if (buscarApellido(*a, *apellido) >= 0) {
        posApellido = buscarApellido(*a, *apellido);

        printf("\nEl apellido %c se encuentra en la lista. Desea modificarlo? S/N: ", a->arr[posApellido]);
        scanf("%c", &respuesta);
    } else {
        printf("El apellido que quiere modificar no se pudo encontrar en la lista. \n");
    }
    
    if (strcmp("s", &respuesta) == 0) {
        printf("Ingrese el nuevo apellido: ");
        scanf("%c", &nuevoApellido);
        strcpy(a->arr[i], nuevoApellido);
    }
}

