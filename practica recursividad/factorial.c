#include<stdio.h>

int fact(int n);
int fact2(int n, int m);

int main(){
    int factorial;

    factorial = fact2(4, 1);
    //factorial = fact(5);
    printf("%d", factorial);

    return 0;
}

int fact(int n) {
    if (n == 0) {
        return 1;
    } else if (n > 0) {
        return n * fact(n-1);
    }
}

int fact2(int n, int m) {
    if (n == 0) {
        return m;
    } else {
        return fact2(n-1, m*n);
    }
}