
#include <stdio.h>
int main(void)
{
    int x, y;
    printf("Ingrese el valor de x\n");
    scanf("%d", &x);
    printf("Ingrese el valor de y\n");
    scanf("%d", &y);
    printf("Estado inicial : x = %d, y = %d\n", x, y);
    y = y + y;
    printf("Estado sigma : x = %d, y = %d\n", x, y);
    x = x + y;
    printf("Estado final : x = %d, y = %d\n", x, y);
    return 0;
}