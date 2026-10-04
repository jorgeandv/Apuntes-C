#include <stdio.h>
int factorial(int n);

int main(){
    int x=factorial(3);
    printf("%d", x);
    return 0;
}

int factorial(int n) {
    int f=1;
    while (n>1) {
        f*=n;
        n--;
    }
    return f;
}

//Lo más inteligente era hacer la función factorial con un for pues al saber el numero sabewmos cuantas iteraciones necesitamos
/*
int factorial(int n) {
    int f=1;
    for (int i=n; i>0; i--){
        f*=i;
    }
    return f;
    }
*/