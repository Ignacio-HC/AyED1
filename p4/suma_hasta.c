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

int suma_hasta(int n) {
    int res;

    // res = (n*(n+1))/2;
    res = 0;
    while (n>=0) {
        res = res + n;
        n = n-1;
    }

    return res;
}

int main(void) {
    // declaro
    int n, res;
    // inicializo (creo un estado inicial)
    n = pedir_entero('n');
    
    if (n<0) {
        printf("Error, el numero ingresado no debe ser negativo!");
    }
    else if (n>=0) {
        res = suma_hasta(n);
        printf("La suma de los primeros %d naturales es: %d\n", n, res);
    }
    // programa que resuelve

    return 0;
}