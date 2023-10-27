#include <stdio.h>
#define N 6

typedef struct {
    float maximo;
    float minimo;
    float promedio;
} datos_t;

void pedir_arreglo(int n_max, float a[]) {
    int i = 0;
    int elem;
    while (i<n_max) {
        printf("Ingrese el %d-esimo elemento del arreglo: ", i+1);
        scanf("%d", &elem);
        a[i] = elem;
        i=i+1;
    }
}

datos_t stats(int tam, float a[]) {
    datos_t res;
    int i;
    // inicializo
    i = 0;
    res.maximo = a[0];
    res.minimo = a[0];
    res.promedio = 0;
    // recorro el arreglo
    while (i<tam)
    {
        if (a[i] > res.maximo) {
            res.maximo = a[i];
        }
        else if (a[i] < res.minimo) {
            res.minimo = a[i];
        }

        // actualizo promedio
        res.promedio = res.promedio + a[i]/tam; 
        // sigo recorriendo
        i = i+1;
    }
    // calculo el promedio

    return res;
}

int main(void) {
    float a[N];
    datos_t res;
    // pido el arreglo
    pedir_arreglo(N,a);

    // calculo stats y muestro en pantalla
    res = stats(N,a);

    printf("El minimo del arreglo provisto es: %f\n", res.minimo);
    printf("El maximo del arreglo provisto es: %f\n", res.maximo);
    printf("El promedio del arreglo provisto es: %f\n", res.promedio);

    return 0;
}