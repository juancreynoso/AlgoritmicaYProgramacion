#include<stdlib.h>
#include<stdio.h>

int main() {

    FILE* f;
    char string;

    f = fopen("archivo.dat", "a");
    printf("Escribi: ");
    scanf("%c", &string);

    fwrite(&string, sizeof(string), 1, f);
    fclose(f);

}