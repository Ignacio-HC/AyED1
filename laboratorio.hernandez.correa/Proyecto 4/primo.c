#include <stdio.h>
#include <stdbool.h>

bool es_primo(int p)
{
    int i = 2;
    while (i < p)
    {
        if (p % i == 0)
        {
            return false;
        }
        i++;
    }
    return true;
}

int nesimo_primo(int N)
{
    int res = 2;
    int cant_primos = 0;
    while (cant_primos < N)
    {
        if (es_primo(res))
        {
            cant_primos++;
        }
        res++;
    }
    return res - 1;
}

int main(void)
{
    int N;
    printf("Ingrese un entero: ");
    scanf("%d", &N);

    if (N < 0)
    {
        printf("Error: El número debe ser no negativo.\n");
    }
    else
    {
        int res = nesimo_primo(N);
        printf("El primo número %d es %d\n", N, res);
    }

    return 0;
}