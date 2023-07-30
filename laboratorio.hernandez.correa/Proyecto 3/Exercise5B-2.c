#include <stdio.h>
#include <stdbool.h>

int main()
{
    int x, i, tempres;
    bool res;

    printf("Ingrese un valor numerico mayor que 2 a x\n");
    scanf("%d", &x);
    printf("Ingrese un valor numerico a i\n");
    scanf("%d", &i);
    printf("Ingrese 1 (True) o 0 (False) a res\n");
    scanf("%d", &tempres);

    res = tempres;

    i = 2;
    res = true;

    while (i < x && res)
    {
        res = res && ((x % i) != 0);
        i = i + 1;
        printf("x = %d, i = %d, res=%d\n", x, i, res);
    }
    printf("Tu valor ingresado es un numero primo si ves un 1, y no lo es si ves un 0\n");
    printf("Resultado : %d\n", res);
    return 0;
}

/*
Para x=5
x = 5, i = 2
2 < 5
5%2 = 1 --> res = true && 1!=0 -> true
----
i = 3
3 < 5
5%3 = 2 --> res = true && 2!=0 -> true
----
i = 4
4 < 5
5%4 = 1 --> res = true && 1!0 -> true
----
i = 5 --> 5 < 5 ? False, no entra al ciclo.

Con otro estado: por ejemplo x = 3
x = 3, i = 2
2 < 3
3%2 = 1 --> res = true && 1!=0 -> true
----
i = 3 --> 3 < 3 ? False, no entra al ciclo.

*/