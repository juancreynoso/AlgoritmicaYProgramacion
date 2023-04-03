#include<stdio.h>


    struct TCarta {
        TPalo palo;
        int num;
    };

    typedef char TPalo [4];

    struct TCarta carta1, carta2, carta3;

int main() {

    char TPalo[0] = "oro"; 
    char TPalo[1] = "copa";
    char TPalo[2] = "basto";
    char TPalo[3] = "espada";

    int cantPuntos;

    return 0;
}

int calcularPuntos(struct TCarta a, struct TCarta b, struct TCarta c) {
    if ((a.palo == b.palo) && (!(a.palo == b.palo))) {

    }
}