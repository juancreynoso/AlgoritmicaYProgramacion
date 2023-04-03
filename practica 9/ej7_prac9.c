#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char nom[20];
    char tel[20];
    char dir[40];
    int edad;
} TEmpleado;

typedef struct TNodo //declaracion de nodo (doblete o registro)
{
    struct TNodo *next; //campo next
    TEmpleado info;   //campo info
} TNodo;


void inicializar(TNodo** list);
void insertarC(TNodo* list, TEmpleado elem);
void insertarF(TNodo* list, TEmpleado elem);
void insertarPos(TNodo* list, int pos, TEmpleado elem);
void mostrar(TNodo* list);
void eliminarPos(TNodo* list, int pos);
void cargarEmp(TEmpleado* emp);


int main() {
    TNodo* lista;
    TEmpleado empleado;
    int eleccion, posicion;

    inicializar(&lista);
    
    while (eleccion != 6) {
        eleccion = 0;

        printf("Que accion desea realizar: \n1. Insertar al comienzo\n2. Insertar al final\n3. Insertar en posicion\n4. Eliminar\n5. Mostrar\n6. Salir\n");
        scanf("%d", &eleccion);

        if (eleccion == 1) {
            cargarEmp(&empleado);
            insertarC(lista, empleado);
        } else {
            if (eleccion == 2) {
                cargarEmp(&empleado);
                insertarF(lista, empleado);
            } else {
                if (eleccion == 3) {
                    cargarEmp(&empleado);
                    printf("Ingrese la posicion en que desea insertar el empleado: ");
                    scanf("%d", &posicion);
                    insertarPos(lista, posicion, empleado);
                } else {
                    if (eleccion == 4) {
                        printf("Ingrese la posicion en que desea eliminar el empleado: ");
                        scanf("%d", &posicion);
                        eliminarPos(lista, posicion);
                    } else {
                        if (eleccion == 5) {
                            mostrar(lista);
                        } else 
                        if (eleccion == 6) {
                            exit(-1);
                        } else {
                            printf("Ingrese una opcion valida");
                        }
                    }
                }
            }
        }
    }
    
}

void inicializar(TNodo** list) {
    //lexico local
    TNodo* aux;
    //inicio
    aux = malloc(sizeof(TNodo));
    aux->next = NULL;
    (*list) = aux;
    printf("Lista inicializada correctamente.\n");
}

void insertarC(TNodo* list, TEmpleado elem) {
    //lexico local
    TNodo* aux;
    //inicio
    aux = malloc(sizeof(TNodo));
    strcpy(aux->info.dir, elem.dir);
    strcpy(aux->info.nom, elem.nom);
    strcpy(aux->info.tel, elem.tel);
    aux->info.edad = elem.edad;

    aux->next = list->next;
    list->next = aux;
}

void insertarF(TNodo* list, TEmpleado elem) {
    TNodo* aux;

    while (list->next != NULL) {
        list = list->next;
    }
    aux = malloc(sizeof(TNodo));
    aux->info = elem;
    aux->next = list->next;
    list->next = aux;
}

void insertarPos(TNodo* list, int pos, TEmpleado elem) {
    TNodo* aux;
    int i;

    aux = list;
    i = 0;
    while ((list->next != NULL) && (i != pos)) {
        i++;
        list = list->next;
    }
    if (pos == i) {
        aux = malloc(sizeof(TNodo));
        aux->info = elem;
        aux->next = list->next;
        list->next = aux;
    } else {
        printf("Imposible insertar.\n");
    }
}

void mostrar(TNodo* list) {
    TNodo* aux;
    
    aux = list->next;
    while (aux != NULL) {
        printf("%s", list->info.nom);
        printf("%s", list->info.dir);
        printf("%d", list->info.edad);
        printf("%s", list->info.tel);
        aux = aux->next;
    }
}

void eliminarPos(TNodo* list, int pos) {
    TNodo* aux;
    int i;

    i = 0;
    while ((list->next != NULL) && (i != (pos-1) )) {
        i++;
        list = list->next;
    }
    if (pos == i) {
        aux = list->next;
        list->next = aux->next;
        free(aux);
    } else {
        printf("Imposible eliminar.}\n");
    }
}

void insertar(TNodo* list, TEmpleado elem) {
    TNodo* aux;
    
    strcpy(aux->info.dir, elem.dir);
    strcpy(aux->info.nom, elem.nom);
    strcpy(aux->info.tel, elem.tel);
    aux->info.edad = elem.edad;
}


void cargarEmp(TEmpleado* emp) {
    printf("Ingrese los datos del empleado: \n");
    printf("Nombre: ");
    scanf("%s", &(*(emp->nom)));
    printf("Telefono: ");
    scanf("%s", &(*(emp->tel)));
    printf("Edad: ");
    scanf("%d", &((emp->edad)));
    printf("Direccion: ");
    scanf("%s", &(*(emp->dir)));
}

