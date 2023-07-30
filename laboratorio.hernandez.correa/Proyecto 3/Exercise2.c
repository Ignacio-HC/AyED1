#include <stdio.h>
int main(void)
{
    int x = 4, y = -4, z = 8, b = 1, w = 1;
    printf("x %% 4 == 0 = %d\n", x % 4 == 0);
    printf("x + y == 0 && y - x == (-1) * z = %d\n", x + y == 0 && y - x == (-1) * z);
    printf("not b && w = %d\n", !(b && w));
    return 0;

    /* Respuestas del cuadro
     (donde 0 es True y 1 es False )
     Expresion                       | (x->(-4), y->3, z->5, b->1 , w->1 )
     x % 4 == 0                      | True
     x + y == 0 && y - x == (-1) * z | True
     not b && w                      | False
     */
}
