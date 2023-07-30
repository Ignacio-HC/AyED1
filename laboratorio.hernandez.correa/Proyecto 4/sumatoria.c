#include <stdio.h>
#define N 4

int sumatoria(int a[], int tam)
{
    int res = 0, i = 0;

    while (i < tam)
    {
        res = res + a[i];
        i = i + 1;
    }
    return res;
}

void pedir_arreglo(int a[], int n_max)
{
    int i = 0, e = 0;
    do
    {
        printf("Ingrese un valor %d\n", i);
        scanf("%d", &e);
        a[i] = e;
        i = i + 1;

    } while (i < n_max);
}
int main()
{
    int a[N], res = 0;

    pedir_arreglo(a, N);
    res = sumatoria(a, N);

    printf("El resultado es %i\n", res);
    return 0;
}
