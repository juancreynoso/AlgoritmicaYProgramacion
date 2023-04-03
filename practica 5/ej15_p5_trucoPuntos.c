#include<stdio.h>
#include<string.h>

    typedef char TPalo [4];
    struct TCarta {
        TPalo palo;
        int num;
    };
    struct TCarta carta1, carta2, carta3;

int main() {

    char TPalo[0][10] = "oro"; 
    char TPalo[1][10] = "copa";
    char TPalo[2][10] = "basto";
    char TPalo[3][10] = "espada";

    int cantPuntos;
    int valor;

    do {
        printf("Ingrese las 3 cartas que le tocaron: ");
        scanf("%c %i", &carta1.palo, &carta1.num);
    } while (!((carta1.num >= 1 && carta1.num <= 7) && (carta1.num >= 10 && carta1.num <= 12)));

    
    return 0;
}

int calcularPuntos(struct TCarta a, struct TCarta b, struct TCarta c) {
    if (((a.palo == b.palo) && (!(a.palo == b.palo))) ||
        ((c.palo == a.palo) && (!(a.palo == b.palo))) ||
        ((b.palo == c.palo) && (!(a.palo == b.palo)))) {
            return 2;
    } else {
        if ((a.palo == b.palo) && (!(b.palo == c.palo))) {
            return 1;
        } else {
            return 0;
        }
    }
}