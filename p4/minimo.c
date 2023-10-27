#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

int pedir_entero(char name) {
    int n;

    printf("Ingrese un entero para la variable %c: ", name);
    scanf("%d",&n);

    return n;
}

void imprimir_entero(char name, int x) {
    printf("el valor del entero %c es: %d\n",name,x);
}

int main(void) {
    int x;
    int y;
    int m;

    //pido enteros
    x = pedir_entero('x');
    y = pedir_entero('y');

    // checkeo precondicion
    assert(true);

    // derivacion (intuitiva :) )
    if (x<=y) {
        m = x;
    }
    else if (x>y) {
        m = y;
    }
    // checkeo postcondicion
    assert((m<=x && m<=y)&&(m==x)||(m==y));

    return 0;
}