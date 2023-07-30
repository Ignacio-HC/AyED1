#include <stdbool.h>
#include <stdio.h>

typedef char clave_t;
typedef int valor_t;

struct asoc
{
    clave_t clave;
    valor_t valor;
};

bool asoc_existe(struct asoc a[], int tam, clave_t c)
{
    int i = 0;
    bool res = false;
    while (i < tam)
    {
        res = res || a[i].clave == c;

        i = i + 1;
    }
    return res;
}

#define N 3

int main(void)
{
    struct asoc a[N];

    int i = 0;
    while (i < N)
    {
        printf("Ingrese una clave: %d\n", i);
        scanf("%c", &a[i].clave);

        printf("Ingrese el valor correspondiente:\n ");
        scanf("%d", &a[i].valor);

        i = i + 1;
    }
    char c;
    printf("Ingrese la clave a buscar: \n ");
    scanf("%c", &c);

    bool res = asoc_existe(a, N, c);

    if (res)
    {
        printf("EXiste la clave en el arreglo\n");
    }
    else
    {
        printf("No existe la clave en el arreglo\n");
    }
    return 0;
}