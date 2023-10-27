#include <stdio.h>
#include <assert.h>
#define N 5

int pedir_entero(char name) {
    int n;

    printf("Ingrese un entero para la variable %c: ", name);
    scanf("%d",&n);

    return n;
}

void pedir_arreglo(int n_max, int a[]) {
    int i = 0;
    int elem;
    while (i<n_max) {
        printf("Ingrese el %d-esimo elemento del arreglo: ", i+1);
        scanf("%d", &elem);
        a[i] = elem;
        i=i+1;
    }
}

void imprimir_arreglo(int n_max, int a[]) {
    int i = 0;

    while (i<n_max) {
        printf("el %d-esimo valor del arreglo es: %d\n",i+1, a[i]);
        i=i+1;
    }
}

void intercambiar(int tam, int a[], int i, int j) {
    assert((j < tam && j >= 0) && (i < tam && i >= 0));
    int a_aux;
    a_aux = a[i];
    a[i] = a[j];
    a[j] = a_aux;
}

int main(void) {
    int a[N],i,j;
    // pedir arreglo
    pedir_arreglo(N,a);
    // le pido las posiciones que quiere cambiar
    i = pedir_entero('i');
    j = pedir_entero('j');

    if ((j < N && j >= 0) && (i < N && i >= 0)) {
        // muestro arreglo original
        imprimir_arreglo(N,a);
        printf("\n");
        // intercambio
        intercambiar(N,a,i,j);
        // muestro arreglo intercambiado
        imprimir_arreglo(N,a);   
    }
    else {
        printf("Las posiciones ingresadas no son validas :(");
    }
    
    return 0;
}