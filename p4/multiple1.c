#include <stdio.h>
#include <assert.h>

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
    // declaro variables
    int x,y,x_aux,y_aux;
    // pido estado inicial
    x = pedir_entero('x');
    x_aux = x;

    y = pedir_entero('y');
    y_aux = y;
    // checkeo precondicion
    assert(((x == x_aux) && (y = y_aux)));
    // programa que resuelve
    x = x_aux + 1;
    y = x_aux + y_aux;
    // checkeo postcondicion
    assert(((x == x_aux + 1) && (y == x_aux + y_aux)));
    return 0;
}