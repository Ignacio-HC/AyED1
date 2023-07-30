#include <stdio.h>

int main(void)
{
    int x, y;
    printf("Ingrese un valor para x\n");
    scanf("%d", &x);
    printf("Ingrese un valor para y\n");
    scanf("%d", &y);

    if (x >= y)
        (x = 0);
    else
        (x = 2);
    printf("Estado Final: x = %d, y = %d\n", x, y);
    return 0;
}
