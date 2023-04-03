
#include <stdio.h>
#include <string.h>
/*
char queEs(int x); 

int main() {

    int num;
    char resp[10];
    printf("Ingrese un número: "); scanf("%i", &num);
    strcpy(resp, queEs(num));
    printf("%s", resp);

    return 0;
}


char queEs(int x) {
    char msg[10];
    if (x == 0) {
        strcpy(msg, "es cero");
    }
    else {
        if (x % 2 == 0) {
            strcpy(msg, "es par");
        } 
        else {
            strcpy(msg, "es impar");
        }
    }

    return msg;
}
*/
/*
Funcion que dado un entero como parametro retorna es par cuando el numero es par. "Es impar" cuando el numero es impar y "Es cero" cuando es cero
*/
char* queEs(int x); 

int main() {

    int num;
    char* resp;
    printf("Ingrese un número: "); scanf("%i", &num);
  
    printf("%s", queEs(num));

    return 0;
}

/*
Funcion que dado un entero como parametro retorna es par cuando el numero es par. "Es impar" cuando el numero es impar y "Es cero" cuando es cero
*/

char* queEs(int x) {
  //  char msg[10];
    if (x == 0) {
        return "es cero";
    }
    else {
        if (x % 2 == 0) {
            return "es par";
        } 
        else {
            return "es impar";
        }
    }

//    return msg;
}
