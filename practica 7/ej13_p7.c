#include<stdio.h>
#define Max 10

typedef struct 
{
    int arr[Max];
    int cant;
} TData;

void CargarArreglo(TData *a);
void InsertarNum(TData *a);
void MostrarArreglo(TData a);

int main() {
    TData a;
    /*
    int arr[10] = {1, 3, 4, 5, 7, 8, 10};
    cant = 7;
*/

    CargarArreglo(&a);
    InsertarNum(&a);
    MostrarArreglo(a);
    
    return 0;
}

void CargarArreglo(TData *a){
    int i;

    printf("Ingrese la cantidad de numeros a cargar: "); 
    scanf("%d",&(a->cant));

    for(i=0; i<(a->cant);i++){
        printf("Ingrese el número %d: ", i); 
        scanf("%d",&a->arr[i]); 
    }

    printf("La lista contiene los siguientes numeros: \n");
    for (i=0; i<(a->cant); i++) {
        printf("%d\n", a->arr[i]);
    }
}

void InsertarNum(TData *a) {
    int i, j, nuevo;

    printf("Ingrese el número que quiere ingresar en la lista: ");
    scanf("%d", &nuevo);

    i = 0;

    if (a->cant > 0) {
        while (a->arr[i] < nuevo) {
            i++;
        }
        j = a->cant;
        while (j >= i) {
            a->arr[j+1] = a->arr[j];
            j = j-1;
        }
    }
    a->arr[i] = nuevo;
    a->cant++;
}

void MostrarArreglo(TData a) {
    int i;
    printf("La nueva lista contiene los siguientes numeros: \n");
    for (i=0; i<(a.cant); i++) {
        printf("%d\n", a.arr[i]);
    }
}

    Función Llena(dato a E TData) → Lógico
    Inicio
        si (a.cant = Max) entonces
            ← Verdadero
        sino
            ← Falso
    Ffunción

    Acción InsertarApellido(dato-resultado a E TData, resultado apellido E cadena)
    Léxico local
        i, j E Z
        msj E Cadena
    Inicio
        Entrada: apellido
        i ← 1
        j ← a.cant
        si Vacía(a) entonces
            a.arr[i] ← apellido
        sino
            si Llena(a) entonces
        msj ← “La lista está llena, no se puede insertar otro apellido”
        Salida: msj
            sino
                a.arr[j+1] ← apellido
                a.cant ← a.cant + 1
            fsi
        fsi
    Facción

    Acción SuprimirApellido(dato-resultado a E TData, resultado apellido E TData)
    Léxico local
        i E Z
    Inicio
        Entrada: apellido
        para (i ←1, i<=a.cant, i ← i+1) hacer
            si a.arr[i] = apellido entonces
        mientras (i<=a.cant) hacer
            a.arr[i] ← i+1
        fmientras
        a.cant ← a.cant - 1
            fsi
        fpara
    Facción

    Acción MostrarApellidos(dato a E TData)
    Léxico local
        i E Z
    Inicio
        para (i ←1, i<=a.cant, i ← i+1) hacer
            Salida: a[i]
        fpara
    Facción

    Función BuscarApellido(dato a E TData, apellido E cadena) → Z
    Léxico local
        i E Z
    Inicio
        para (i ←1, i<=a.cant, i ← i+1) hacer
            si a.arr[i] = apellido entonces 
    ← i
            fsi
        fpara
    Ffunción

    Función ApellidosRepetidos (dato apellido1, apellido2 E cadena) → Lógico
    Inicio
        si apellido1 = apellido2 entonces
            ← Verdadero
        sino
            ← Falso
        fsi
    Ffunción

    Acción ModificarEmpleado(dato-resultado a E TData, resultado apellido E cadena)
    Léxico local
        i E Z
        nuevoApellido E cadena
        posApellido E Z
        respuesta E Z+
    Inicio
        Entrada: apellido  
        posApellido ← BuscarApellido(listEmp, apellido)
        msj ← “¿Desea modificar el apellido en esta posición? posApellido
    Si
    No”
        Salida: msj 
        Entrada: respuesta 
        si (respuesta = 1) entonces
            Entrada: nuevoApellido
            i ← posApellido 
            a.arr[i] ← nuevoApellido
        fsi
    Facción

Inicio
    msj ← “¿Qué acción desea realizar?
Alta de empleado
Baja de empleado
Modificar datos de empleado
Listar empleados
Buscar empleado
Salir”
    Salida: msj
    Entrada: eleccion
    según
         (eleccion = 1): InsertarApellido(listaEmp, empleado)
         (eleccion = 2): SuprimirApellido(listaEmp, empleado)
         (eleccion = 3): ModificarEmpleado(listaEmp, empleado)
         (eleccion = 4): MostrarApellidos(listaEmp)
         (eleccion = 5): si (1 <= BuscarApellido(listEmp, empleado) <= listaEmp.cant) entonces
			 salida: empleado
		         sino
			 msj ← “Apellido inexistente.”
			 Salida: msj
		         fsi
         (eleccion = 6): Nada()
    fsegun
Fin
