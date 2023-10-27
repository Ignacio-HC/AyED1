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
    int a;

    //pido enteros
    x = pedir_entero('x');

    // checkeo precondicion
    assert(true);

    // derivacion (intuitiva :)
    if (x<0) {
        a = (-1) * x;
    }
    else if (x>=0) {
        a = x;
    }

    // checkeo postcondicion
    assert(a == (-1)*x || a == x);

    return 0;
}