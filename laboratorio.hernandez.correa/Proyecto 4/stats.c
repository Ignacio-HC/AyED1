#include <stdio.h>
#include <assert.h>
#define t 7

struct datos_t
{
    float maximo;
    float minimo;
    float promedio;
};

void pedirArreglo(float a[], int n_max)
{
    int i = 0;
    while (i < n_max)
    {
        printf("Ingrese un valor %d\n", i);
        scanf("%e", &a[i]);
        i = i + 1;
    }
}
struct datos_t stats(float a[], int tam)
{
    struct datos_t D;
    int i = 0;
    D.maximo = a[0];
    D.minimo = a[0];
    D.promedio = a[0];
    while (i < tam)
    {
        if (a[i] < D.minimo)
        {
            D.minimo = a[i];
        }
        if (D.maximo < a[i])
        {
            D.maximo = a[i];
        }
        D.promedio = D.promedio + a[i];
        i = i + 1;
    }
    D.promedio = D.promedio / tam;
    return D;
}

int main()
{
    float a[t];
    struct datos_t b;
    pedirArreglo(a, t);
    b = stats(a, t);
    printf("El promedio es %f\n", b.promedio);
    printf("El maximo es %f\n", b.maximo);
    printf("El minimo es %f\n", b.minimo);
    return 0;
}