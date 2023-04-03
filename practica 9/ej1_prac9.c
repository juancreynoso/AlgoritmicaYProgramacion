#include<stdio.h>
#include<stdlib.h>

struct TNodo //declaracion de nodo (doblete o registro)
{
    struct TNodo *next; //campo next
    int info;   //campo info
};

int main() {
    //declaracion de variables de tipo puntero a TNodo
    struct TNodo *p;
    struct TNodo *q;
    struct TNodo *r;
    struct TNodo *s;
    struct TNodo *t;

    q = NULL;

    p = malloc(sizeof(struct TNodo)); //creacion de doblete (aislado de la lista) apuntado por s
    p->info = 14; //asignacion de 14 al campo info del doblete apuntado por p
    p->next = q; //a lo que apunta q (nil) tambien apunta el campo next del doblete que es apuntado por p
    q = p; //p apunta a lo mismo  (doblete) que apunta q

    p = malloc(sizeof(struct TNodo));
    p->info = 25;
    p->next = q;
    q = p;

    p = malloc(sizeof(struct TNodo));
    p->info = 20;
    p->next = q;
    q = p;

    p = malloc(sizeof(struct TNodo));
    p->info = 11;
    p->next = q;
    q = p;

    //Cambio de valores en la lista
    r = q;
    r = r->next;
    t = r->next;
    s = malloc(sizeof(struct TNodo));
    s->info = 3;
    s->next = r->next;
    r->next = s;
    p = t;
    t->info = 29;

    //informar valores de la lista
    printf("%d \n", t->info);
    p = p->next;
    printf("%d \n", p->info);
    printf("%d \n", q->info);
    printf("%d \n", s->info);
    printf("%d \n", r->info);


    return 0;
}

 