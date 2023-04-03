
#include<stdio.h>

int main(){

    float dineroRecibido;
    float dineroCardio, dineroTerapia, dineroNeo, dineroAdmin;

    printf("Ingresar el dinero de la donacion: ");
    scanf("%f", &dineroRecibido);
    
    dineroCardio = dineroRecibido * 0.3;
    dineroNeo = dineroCardio * 0.7;
    dineroTerapia = dineroNeo * 0.8;
    dineroAdmin = dineroRecibido - dineroCardio - dineroNeo - dineroTerapia;

    printf("Dinero para cardiologia: %.2f, dinero para neonatología: %.2f, dinero para terapia %.2f, dinero para administración %.2f",
        dineroCardio, dineroNeo, dineroTerapia, dineroAdmin);

    return 0;
}