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

int prim_iguales(int tam, int a[]) {
    int res, i, primerElem;
    res = 0;
    i = 0;
    primerElem = a[0];

    while (i < tam) {
        if (a[i] == primerElem) {
            res = res+1;
        }
        else {
            i = tam-1;
        }
        i=i+1;
    }
    
    return res;
}

int main(void) {
    int a[N];
    int res;
    // pido estado inicial
    pedir_arreglo(N,a);

    // calculo
    res = prim_iguales(N,a);
    // muestro resultado
    printf("el tramo inicial mas grande con elementos iguales es de %d elementos\n", res);

    return 0;
}