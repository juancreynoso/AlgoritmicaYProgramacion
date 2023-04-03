 #include<stdio.h>

int main() {

    int dia, mes, anio;
    int anioBisiesto;

    printf("Ingrese el día: "); scanf("%d", &dia);
    printf("Ingrese el mes: "); scanf("%d", &mes);
    printf("Ingrese el año: "); scanf("%d", &anio);

    anioBisiesto = 0;

    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0 && anio % 100 == 0)) {
        anioBisiesto = 1;
    }

    if ((dia == 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) {
        mes++;
        dia = 1;
    }
    else if ((dia == 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)) {
        if (mes == 12) {
            anio++;
            mes = 1;
            dia = 1;
        }
        else {
            mes++;
            dia = 1;
        }
    }
    else if (dia == 28 && mes == 2 && anioBisiesto == 1) {
        dia++;
    }
    else if (dia == 28 && mes == 2 && anioBisiesto != 1) {
        dia = 1;
        mes++;
    }
    else if (mes == 2 && dia >= 29) {
        if (anioBisiesto == 1){
            dia = 1;
            mes++;
        }
        else {
            printf("El día ingresado es incorrecto.");
        }
    }
    else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
        printf("El día ingresado es incorrecto.");
    }
    else if (dia > 31){
        printf("El día ingresado es incorrecto.");
    }
    else {
        dia ++;
    }
    
    printf("%d/%d/%d", dia, mes, anio);


    return 0;
}