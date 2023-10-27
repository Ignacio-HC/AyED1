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
    int z;
    int y_aux;

    //pido enteros
    x = pedir_entero('x');
    y = pedir_entero('y');
    z = pedir_entero('z'); // se debe pedir al usuario o usar directamente como aux?

    // checkeo precondicion
    assert(true);
    
    // derivacion (intuitiva :)
    y_aux = y;
    z = x;
    x = y;
    y = z;
    // checkeo postcondicion
    assert((y == z) && (x==y_aux));

    return 0;
}