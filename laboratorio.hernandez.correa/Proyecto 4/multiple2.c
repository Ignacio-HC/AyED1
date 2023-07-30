#include <stdio.h>
#include <assert.h>
int main()
{
    int x, y, z, X, Y, Z;
    printf("Ingrese un valor para x\n");
    scanf("%d", &x);
    printf("Ingrese un valor para y\n");
    scanf("%d", &y);
    printf("Ingrese un valor para z\n");
    scanf("%d", &z);

    X = x;
    Y = y;
    Z = z;

    assert(x == X && y == Y && z == Z);

    z = X + Y;
    x = Y;
    y = X + Y + Z;

    assert(x == Y && y == Y + X + Z && z == Y + X);

    printf("x=%x, y=%d, z=%d", x, y, z);

    return 0;
}