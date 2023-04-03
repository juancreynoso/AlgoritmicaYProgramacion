#include<stdio.h>

typedef struct TNodo //declaracion de nodo (doblete o registro)
{
    struct TNodo *next; //campo next
    int info;   //campo info
} TNodo;

int main() {

    return 0;
}

int cantPares(TNodo* p) {
    if (p = NULL) {
        return 0;
    } else {
        if (p->info mod 2 == 0) {
            return 1 + cantPares(p->next);
        } else {
            0 + cantPares(p->next);
        }
    }
}