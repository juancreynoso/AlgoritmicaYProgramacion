#include<stdio.h> 
int main(){
    float a,b,x,y;
    int estaEnLaRecta; 
    int pertenece (float j, float k, float p, float q); 

    printf("Ingrese el valor de a: ");scanf("%f",&a);
    printf("Ingrese el valor de b: ");scanf("%f",&b);
    printf("Ingrese el valor de x: ");scanf("%f",&x);
    printf("Ingrese el valor de y: ");scanf("%f",&y);

    estaEnLaRecta = 0;

    estaEnLaRecta = pertenece(a,b,x,y); 

    printf("Si el resultado es 1 pertenece a la recta. Si el resuktado es 0 no pertenece.\n");
    printf("Resultado es: %d \n", estaEnLaRecta);    
}


int pertenece (float j,float k,float p,float q){
    if( q == j*p + k){
        return(1);

    }
    else{
        return(0);
    }
}