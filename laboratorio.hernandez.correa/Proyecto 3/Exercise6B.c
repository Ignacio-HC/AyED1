#include <stdio.h>
#include <stdbool.h>

bool pedirBooleano(void)
{
    int x, temp;
    printf("Ingrese un bool: 0 para false, 1 para true\n");
    scanf("%d", &temp);
    x = temp;
    return x;
}
void imprimeBooleano(bool x)
{
    if (x == 1)
    {
        printf("Verdadero\n");
    }
    else
    {
        printf("Falso\n");
    }
}

int main(void)
{
    imprimeBooleano(pedirBooleano());
    return 0;
}
