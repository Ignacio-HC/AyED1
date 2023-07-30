#include <stdio.h>
#include <limits.h>
#define t 3

int minimo(int n1, int n2)
{
    int MIN_V;
    if (n1 < n2)
    {
        MIN_V = n1;
    }
    else
    {
        MIN_V = n2;
    }
    return MIN_V;
}

int minimo_pares(int a[], int tam)
{
    int i = 0;
    int minimo_par = INT_MAX;
    while (i < tam)
    {
        if (a[i] % 2 == 0)
        {
            minimo_par = minimo(minimo_par, a[i]);
        }
        i++;
    }
    return minimo_par;
}
int minimo_impares(int a[], int tam)
{
    int i = 0;
    int minimo_impar = INT_MAX;
    while (i < tam)
    {
        if (a[i] % 2 != 0)
        {
            minimo_impar = minimo(minimo_impar, a[i]);
        }
        i++;
    }
    return minimo_impar;
}
void pedirArreglo(int a[], int n_max)
{
    int i = 0;
    while (i < n_max)
    {
        printf("Ingrese un para el arreglo %d\n", i);
        scanf("%d", &a[i]);
        i++;
    }
}

int main()
{
    int a[t], n_par, n_impar, elem_min;
    pedirArreglo(a, t);
    n_par = minimo_pares(a, t);
    n_impar = minimo_impares(a, t);
    elem_min = minimo(n_par, n_impar);
    printf("El minimo elemento es %d\n", elem_min);
    return 0;
}
