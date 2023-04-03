#include <stdio.h>
/* léxico */
int lado; 
int areaCuad;
int areaTriang;
int areaRayada;

/* función principal (main) en todo programa C */
int main(){
  printf("Ingrese la longitud del lado: ");
  scanf("%d",&lado); // dir de memoria de la var lado
  areaCuad = lado * lado;
  areaTriang = lado/2 * lado/2 * 3.1416;
  areaRayada = areaCuad - areaTriang;
  printf("El area del cuadrado es %d\n",areaCuad);
  printf("El area del triangulo es %d\n", areaTriang);
  printf("El area rayada es: %d \n",areaRayada);
  return 0;
}