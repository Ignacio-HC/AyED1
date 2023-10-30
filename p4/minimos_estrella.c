#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 3

bool existe_multiplo(int m, int tam, int a[]) {
    bool res = false;
    int i = 0;

    while (i<tam)
    {
        res = res || ((a[i] % m)==0);
        i = i+1;
    }
    return res;
}

bool todos_pares(int tam, int a[]) {
    bool res = true;
    int i = 0;

    while (i<tam)
    {
        res = res && ((a[i] % 2)==0);
        i = i+1;
    }
    return res;
}

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

    // (*) Checkeo si existe algun par y si todos son pares
    bool hay_pares = existe_multiplo(2,N,a);
    bool todos_son_pares = todos_pares(2,a);  
    
    // (*) Checkeo las combinaciones posibles
    if (todos_son_pares) {
        // par
        minimo_par = minimo_pares(N, a);
        // mostrar resultado
        printf("El minimo par del arreglo ingresado es %d\n", minimo_par);
    }
    else if (!todos_son_pares && hay_pares){
        // par
        minimo_par = minimo_pares(N, a);
        printf("El minimo par del arreglo ingresado es %d\n", minimo_par);
        // impar
        minimo_impar = minimo_impares(N, a);
        printf("El minimo impar del arreglo ingresado es %d\n", minimo_impar);
    }
    else {
        //impar
        minimo_impar = minimo_impares(N, a);
        // mostrar resultado
        printf("El minimo impar del arreglo ingresado es %d\n", minimo_impar);
    }
    return 0;
}