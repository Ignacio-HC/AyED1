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

int sumatoria(int tam, int a[]) {
    int i = 0;
    int res = 0;

    while (i<tam) {
        res = res + a[i];
        i=i+1;
    }

    return res;
}

int main(void) {
    int a[N];
    int res;
    // pido el arreglo
    pedir_arreglo(N, a);
    // calculo sumatoria y muestro el resultado
    res = sumatoria(N,a);
    printf("El resultado de la suma de los elementos es: %d\n",res);
    return 0;
}