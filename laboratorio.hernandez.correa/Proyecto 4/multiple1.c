#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main(void)
{
    int x, y, X, Y;
    printf("Ingrese un valor para x\n");
    scanf("%d", &x);
    printf("Ingrese un valor para y\n");
    scanf("%d", &y);

    X = x;
    Y = y;

    assert(x == X && y == Y);
    y = X + Y;
    x = X + 1;

    assert(y == X + Y && x == X + 1);

    printf("El nuevo valor de x es %d\n", x);
    printf("El nuevo valor de y es %d\n", y);

    return 0;
}