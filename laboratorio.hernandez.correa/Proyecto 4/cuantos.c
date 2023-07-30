#include <stdio.h>
#define N 5
int pedirEntero(void)
{
    int x;
    printf("Ingrese un valor entero\n");
    scanf("%d", &x);
    return x;
}

void pedirArreglo(int a[], int n_max)
{
    int i;
    i = 0;
    while (i < n_max)
    {
        printf("Ingrese la posicion %d del arreglo\n", i);
        scanf("%d", &a[i]);
        i = i + 1;
    }
}

struct comp_t
{
    int menores;
    int iguales;
    int mayores;
};

struct comp_t cuantos(int a[], int tam, int elem)
{
    struct comp_t res;
    res.menores = 0;
    res.iguales = 0;
    res.mayores = 0;
    int i = 0;
    while (i < tam)
    {
        if (a[i] < elem)
        {
            res.menores = res.menores + 1;
        }
        else
        {
            if (a[i] == elem)
            {
                res.iguales = res.iguales + 1;
            }
            else
            {
                res.mayores = res.mayores + 1;
            }
        }
        i = i + 1;
    }
    return res;
}

int main()
{
    int elem;
    struct comp_t res;
    int array[N];
    pedirArreglo(array, N);
    elem = pedirEntero();
    res = cuantos(array, N, elem);

    printf("Hay %d elementos menores, %d elementos iguales y %d elementos mayores\n", res.menores, res.iguales, res.mayores);
    return 0;
}