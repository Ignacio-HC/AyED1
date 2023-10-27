#include <stdio.h>

#define N 5

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

int main(void) {
    int a[N];
    // pido el arreglo
    pedir_arreglo(N, a);

    // imprimo el arreglo
    imprimir_arreglo(N, a);
    return 0;
}