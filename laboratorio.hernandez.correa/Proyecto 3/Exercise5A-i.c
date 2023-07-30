#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int main(void)
{
    int i = 0;
    printf("Ingrese un valor para i:\n");
    scanf("%d", &i);
    printf("Estado 0 : i=%d\n", i);
    while (i != 0)
    {
        printf("Estado 1 i=%d\n", i);
        i = 0;
        printf("Estado 2  i=%d\n", i);
    }
    printf("EstadoFinal i=%d\n", i);
    return 0;
}