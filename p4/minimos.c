#include <stdio.h>
#include <limits.h>
#define N 3

int minimo_pares(int tam, int a[]) {
    int i = 0;
    int a_min = INT_MAX;

    while (i<tam) {
        if (a[i] < a_min && (a[i] % 2 == 0)) {
            a_min = a[i];
        }
        else if (a[i] >= a_min) {}
        i = i+1;
    }

    return a_min;
}
int minimo_impares(int tam, int a[]) {
    int i = 0;
    int a_min = INT_MAX;

    while (i<tam) {
        if (a[i] < a_min && (a[i] % 2 != 0)) {
            a_min = a[i];
        }
        else if (a[i] >= a_min) {}
        i = i+1;
    }

    return a_min;
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

int main(void) {
    int a[N];
    int minimo_par, minimo_impar;
    //pedir arreglo
    pedir_arreglo(N, a);

    // cacular
    // par
    minimo_par = minimo_pares(N, a);
    //impar
    minimo_impar = minimo_impares(N, a);
    // mostrar resultado
    printf("El minimo impar del arreglo ingresado es %d\n", minimo_impar);
    printf("El minimo par del arreglo ingresado es %d\n", minimo_par);
    return 0;
}