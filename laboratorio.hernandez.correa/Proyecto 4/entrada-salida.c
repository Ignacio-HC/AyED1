#include <stdio.h>
void pedirArreglo(int a[], int n_max)
{
    int i, b;
    i = 0;
    while (i < n_max)
    {
        printf("Ingrese un valor\n");
        scanf("%d", &b);
        a[i] = b;
        i = i + 1;
    }
}

void imprimeArreglo(int a[], int n_max)
{
    int i, x;
    i = 0;
    while (i < n_max)
    {
        x = a[i];
        printf("El valor del arreglo en la posicion %d es %d\n", i, x);
        i = i + 1;
    }
}
int main(void)
{
    int x;
    printf("Ingrese el tamaño del arreglo\n");
    scanf("%d", &x);
    int a[x];
    pedirArreglo(a, x);
    imprimeArreglo(a, x);
    return 0;
}
