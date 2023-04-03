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
    strcpy(listaEmp.arr[0], "--LISTA VACIA--\n"); //La lista se encuentra vacía por defecto.

    while (eleccion != 6) {

        printf("\nQue accion desea realizar?\n1. Alta de empleado\n2. Baja de empleado\n3. Modificar datos de empleado\n4. Listar empleados\n5. Buscar empleado\n6. Salir\n");
        scanf("\n%d", &eleccion);

        if (eleccion == 1) { //Se ingresa un apellido a la lista. 
            insertar(&listaEmp, empleado);
        } 
        else {
            if(eleccion == 2) { //Se elimina un apellido de la lista. 
                suprimir(&listaEmp, empleado);
            }
            else {
                if(eleccion == 3) { //Se modifica un apellido de la lista.
                    modificar(&listaEmp, empleado);
                }
                else {
                    if(eleccion == 4) { //Se muestran todos los apellidos de la lista.
                        mostrar(listaEmp);
                    }
                    else {
                        if (eleccion == 5) { //Permite buscar un apellido y saber si existe o no.
                            printf("Ingrese el apellido que desea buscar: ");
                            scanf("%s", empleado); 
                            
                            i = 0;
                            
                            while (i <= listaEmp.cant) {
                                if (buscar(listaEmp, empleado) == i) {
                                    printf("\nEl apellido %s se encuentra en la %d° posicion. \n", empleado, i+1);
                                }
                                i++;
                            }   
                            if (buscar(listaEmp, empleado) < 0  || buscar(listaEmp, empleado) > listaEmp.cant) {
                                printf("\nNo existe este apellido en la lista.\n");
                            }
                        }
                        else {
                            if(eleccion == 6) { // Se finaliza el programa.
                                printf("Usted salio del menu con exito.\n");
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

//inciso a)
int vacia(TData a) {
    if (a.cant == 0) {
        return 1;
    } else {
        return 0;
    }
}

//inciso b)
int llena(TData a) {
    if (a.cant == Max) {
        return 1;
    } else {
        return 0;
    }
}

//inciso g)
int comparar(TData a, char *apellido) {
    int i; 

    for (i = 0; i <= a.cant; i++ ) { //Se compara cada apellido del arreglo con el ingresado, retornara verdadero si hay dos iguales.
        if (strcmp(a.arr[i], apellido) == 0) {
            return 1; 
        }
    }
    return 0; 
}

//inciso c)
void insertar(TData *a, char *apellido) { //Se inserta un apellido en el arreglo.
    printf("\nIngrese el apellido que desea agregar: ");
    scanf("%s", &(*apellido));
    
    if (vacia(*a)) {
        strcpy(a->arr[0], apellido);
        a->cant++;
        printf("\nEl apellido %s se ingreso correctamente.\n", apellido);
    } else {  
        if (llena(*a)) {
            printf("\nLa lista está llena, no se puede ingresar otro apellido.\n");
        } else {
            if (comparar(*a, apellido) == 1) { 
                printf("\nEste apellido ya existe en la lista. \n");
            } else {
                strcpy(a->arr[a->cant], apellido);
                a->cant++;
                printf("\nEl apellido %s se ingreso correctamente.\n", apellido);
            }
        }  
    }
}

//inciso d)
void suprimir(TData *a, char *apellido) { 
    int i, pos;
    
    printf("\nIngrese el apellido que quiere eliminar: "); 
    scanf("%s",&(*apellido));

    pos = buscar(*a, apellido); //Asignacion de la posición del apellido ingresado.

    if (pos >= 0){
        for(i = 0; i<=a->cant; i++) {
            if (strcmp(a->arr[i], apellido) == 0) {
                while (i <= a->cant) {
                    strcpy(a->arr[i], a->arr[i+1]);
                    i++;
                }
                if (i == 2) {
                    strcpy(a->arr[0], "--LISTA VACIA--\n");
                }
                a->cant = a->cant - 1;
                printf("\nEl apellido %s fue eliminado con exito.\n", apellido);
            }
        }
    } else{
        printf("\nEl apellido que desea eliminar no se pudo encontrar en la lista.\n");
    }
}

//inciso f)
int buscar(TData a, char *apellido) {
    int i;

    for (i=0; i<=a.cant; i++) { //Se compara cada apellido existente en el arreglo con el ingresado, se retorna la ubicación si hay dos iguales.
        if (strcmp(a.arr[i], apellido) == 0) { 
            return i;
        }
    } 
    return -1; 
}

//inciso e)
void mostrar(TData a) {
    int i; 

    for (i=0; i <=a.cant; i++) { //Se muestra cada apellido que exista en el arreglo.
        printf("\n%s", a.arr[i]);
    }  
}

//Acción auxiliar 
void modificar(TData *a, char *apellido) {
    char nuevoApellido[50];
    int pos;
    char respuesta;

    printf("\nIngrese el apellido que desea modificar: ");
    scanf("%s", &(*apellido));

    pos = buscar(*a, apellido); //Se le asigna la ubicacion del apellido ingresado.

    if (pos >= 0) {
        printf("\nEl apellido %s se encuentra en la lista. Desea modificarlo? S/N: ", a->arr[pos]);
        scanf("%s", &respuesta);
        if (toupper(respuesta) == 'S') { //Funcion "toupper"; convierte caracter minus a Mayus
            pos = buscar(*a, apellido);
            printf("\nIngrese el nuevo apellido: ");
            scanf("%s", nuevoApellido);
            if (comparar(*a, nuevoApellido) == 1) {
                printf("\nEste apellido ya existe en la lista. \n");
            } else {
                strcpy(a->arr[pos], nuevoApellido);
                printf("\nLa modificacion se realizo con exito. \n");
            }
        }
    }
    else {
        printf("\nEl apellido que quiere modificar no se pudo encontrar en la lista. \n");
    }  
}