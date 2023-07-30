#include <stdio.h>
#define N 5

void intercambiar(int a[], int i, int j)
{
    int x, y;
    x = a[i];
    y = a[j];
    a[i] = y;
    a[j] = x;
}

void imprimeArreglo(int a[], int n_max)
{
    int i;
    i = 0;
    while (i < n_max)
    {
        printf("|%d|", a[i]);
        i = i + 1;
    }
    printf("\n");
}

int pedirEnteroA(void)
{
    int x;
    printf("Ingrese un entero (para el arreglo) = \n");
    scanf("%d", &x);
    return x;
}

int pedirEntero(void)
{
    int x;
    printf("Ingrese un entero (entre 0 y 4 inclusive) = \n");
    scanf("%d", &x);
    return x;
}

void pedirArreglo(int a[], int n_max)
{
    int i;
    i = 0;
    while (i < n_max)
    {
        a[i] = pedirEnteroA();
        i = i + 1;
    }
}

int main(void)
{
    int x, y, n;
    int a[N];
    n = N;
    x = (-1);
    y = (-1);
    pedirArreglo(a, n);
    imprimeArreglo(a, n);
    while (((x > (n - 1)) || (x <= (-1))) || ((y > (n - 1)) || (y <= (-1))))
    {
        x = pedirEntero();
        y = pedirEntero();
        if ((x < 0 || x > 4) || (y < 0 || y > 4))
        {
            printf("Uno de los numeros fue mal ingresado, debe estar entre 0 y 5\n");
        }
    }
    intercambiar(a, x, y);
    imprimeArreglo(a, n);
    return 0;
}
