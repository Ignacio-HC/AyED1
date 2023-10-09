#include <stdio.h>

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
    int n;
    char name;

    name = 'n';
    n = pedir_entero(name);
    imprimir_entero(name, n);

    return 0;
}

/*
Ejemplos de ejecucion:
Ingrese un entero para la variable n: 3
el valor del entero n es: 3

Ingrese un entero para la variable n: 44
el valor del entero n es: 44
*/